#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <string_view>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "THStack.h"
#include "TObjString.h"
#include "TLatex.h"
#include "TSystem.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TMVA/tmvaglob.h"

#include "TMVA/Factory.h"
#include "TMVA/DataLoader.h"
#include "TMVA/Tools.h"
#include "TMVA/TMVAGui.h"

#include "ROOT/RDataFrame.hxx"

using namespace ROOT;
TString GetFormula();
int calculate_background_integral(RDataFrame tree_df, double mass = 3077.2, double width = 3.6);

std::map<int, std::pair<double, double>> mass_cases = {
    // {1, {2942., 15.}},
    // {2, {2964.3, 20.9}},
    // {3, {3055.9, 7.8}},
    {4, {3077.2, 3.6}}};

void get_punzi()
{
    // Open TMVA Classification output file
    TString TMVA_output_filename = (TString) "TMVA.root";
    TFile *TMVA_output = TFile::Open(TMVA_output_filename);

    if (TMVA_output->IsZombie())
    {
        std::cout << "[ERROR] --- " << TMVA_output_filename << " could not be found!\n";
        exit(1);
    }

    // Get dataset filenames
    std::string_view bkgInputFileName = getenv("CURRENT_WS1_DATASET");

    if (bkgInputFileName == "")
    {
        std::cout << bkgInputFileName << " could not be found." << std::endl;
    }

    // Defnie RDataFrame for background dataset
    // Obtain Xicst mass distribution
    RDataFrame tree_df("DecayTree", bkgInputFileName);

    TString method = "MLP";
    TString method_dir = "Method_MLP";
    for (auto mass_case : mass_cases)
    {
        int mass_case_id = mass_case.first;
        double mass = mass_case.second.first;
        double width = mass_case.second.second;

        auto numB = calculate_background_integral(tree_df, mass, width);
        std::cout << "For mass case " << mass_case.first << ": " << numB << std::endl;

        TIter next(TMVA_output->GetDirectory("dataset")->GetListOfKeys());
        TKey *key(0);
        while ((key = (TKey *)next()))
        {
            if (!TString(key->GetName()).BeginsWith("Method_"))
                continue;
            if (!gROOT->GetClass(key->GetClassName())->InheritsFrom("TDirectory"))
                continue;

            TDirectory *mDir = (TDirectory *)key->ReadObj();
            std::cout << "--- Found directory: " << mDir->GetName() << std::endl;

            TIter keyIt(mDir->GetListOfKeys());
            TKey *titkey;
            while ((titkey = (TKey *)keyIt()))
            {
                if (!gROOT->GetClass(titkey->GetClassName())->InheritsFrom("TDirectory"))
                    continue;
                TDirectory *titDir = (TDirectory *)titkey->ReadObj();
                TMVA::TMVAGlob::GetMethodName(method_dir, key);
                TMVA::TMVAGlob::GetMethodTitle(method, titDir);
                std::cout << "Method: " << method << "\tDir:" << method_dir << std::endl;

                // Get signal and background efficiencies
                TString get_effS = (TString) "dataset/Method_" + method_dir + (TString) "/" + method + (TString) "/MVA_" + method + (TString) "_effS";
                TString get_effB = (TString) "dataset/Method_" + method_dir + (TString) "/" + method + (TString) "/MVA_" + method + (TString) "_effB";
                TString get_ROC = (TString) "dataset/Method_" + method_dir + (TString) "/" + method + (TString) "/MVA_" + method + (TString) "_effB";

                // Create stack of histograms
                TString artist_name;
                TString title_stack = (TString) "Method: " + method + (TString) " - Mass Case " + mass_case_id + (TString) ";TMVA Response; Efficiency";
                artist_name = method + (TString) " - MassID" + mass_case_id;
                TCanvas *cS = new TCanvas(artist_name, artist_name, 800, 400);
                artist_name = (TString) "HStack" + method + (TString) " - MassID" + mass_case_id;
                THStack *hs = new THStack(artist_name, title_stack);

                // --- Hists for signal efficiency
                TH1F *histS = (TH1F *)TMVA_output->Get(get_effS);
                artist_name = (TString) "Signal Efficiency " + method + (TString) " - MassID" + mass_case_id;
                histS->SetNameTitle(artist_name, artist_name);

                // --- Hists for bkg efficiency
                TH1F *histB = (TH1F *)TMVA_output->Get(get_effB);
                artist_name = (TString) "Background Efficiency " + method + (TString) " - MassID" + mass_case_id;
                histB->SetNameTitle(artist_name, artist_name);

                // --- Hists for punzi
                artist_name = (TString) "Punzi " + method + (TString) " - MassID" + mass_case_id;
                TH1F *punzi_curve = new TH1F(artist_name, artist_name, 10000, -1, 1);

                hs->Add(histB);
                hs->Add(histS);

                cS->SetTicks(0, 0);

                TStyle *TMVAStyle = gROOT->GetStyle("Plain");
                TMVAStyle->SetLineStyleString(5, "[32 32]");
                TMVAStyle->SetLineStyleString(6, "[12 22]");

                cS->SetTopMargin(.2);

                for (int i = 0; i < 10000; i = i + 100)
                {
                    double effS = histS->GetBinContent(i);
                    double effB = histB->GetBinContent(i);

                    double newB = effB * numB;

                    double formula = effS / (5. / 2. + sqrt(newB));
                    punzi_curve->SetBinContent(i, formula);
                }

                float maximum = punzi_curve->GetMaximum();
                int binmax = punzi_curve->GetMaximumBin();
                double cut = punzi_curve->GetXaxis()->GetBinCenter(binmax);

                // hs->Add(punzi_curve);
                std::cout << "Maximum  " << maximum << "  Optimal cut   " << cut << std::endl;

                gSystem->Exec("mkdir -p plots");
                TString filename = (TString) "plots/" + method + (TString) "m" + mass_case_id + (TString) ".svg";

                punzi_curve->Draw("p");
                cS->Print(filename);
            }
        }
    }
}
// Mass and width in MeV
int calculate_background_integral(RDataFrame tree_df, double mass, double width)
{

    auto mass_distribution = tree_df.Histo1D("Xicst_M");

    // Determine background window based on candidate's mass and width from PDG
    int min_m = mass - 3 * width;
    int max_m = mass + 3 * width;
    // Lambda function to check value is within mass range
    auto massCut = [&min_m, &max_m](double m)
    { return (m > min_m) && (m < max_m); };

    // Appliy mass cut and count events within window
    auto numB = tree_df.Filter(massCut, {"Xicst_M"}).Count();

    return numB.GetValue();
}

TString GetFormula()
{
   // replace all occurrence of S and B but only if neighbours are not alphanumerics
   auto replace_vars = [](TString & f, char oldLetter, char newLetter ) {
      auto pos = f.First(oldLetter);
      while(pos != kNPOS) {
         if ( ( pos > 0 && !TString(f[pos-1]).IsAlpha() ) ||
              ( pos < f.Length()-1 &&  !TString(f[pos+1]).IsAlpha() ) )
         {
            f[pos] = newLetter;
         }
      int pos2 = pos+1;
      pos = f.Index(oldLetter,pos2);
      }
   };

   TString formula = "S / ((5./3.) * sqrt(B))";
   replace_vars(formula,'S','x');
   replace_vars(formula,'B','y');
   // f.ReplaceAll("S","x");
   // f.ReplaceAll("B","y");
   return formula;
}