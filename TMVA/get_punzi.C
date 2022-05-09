#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "THStack.h"
#include "TObjString.h"
#include "TLine.h"
#include "TFormula.h"
#include "TLatex.h"
#include "TGaxis.h"
#include "TSystem.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TMVA/tmvaglob.h"

#include "TMVA/Factory.h"
#include "TMVA/DataLoader.h"
#include "TMVA/Tools.h"
#include "TMVA/TMVAGui.h"

#include "ROOT/RDataFrame.hxx"

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <fstream>

using namespace ROOT;
TString GetFormula();
TString GetLatexFormula();
int calculate_background_integral(RDataFrame tree_df, double mass = 3077.2, double width = 3.6);

int maxLenTitle(0);

TString fFormula = "S / ((5./3.) + sqrt(B))";
std::map<int, std::pair<double, double>> mass_cases = {
    {1, {2942., 15.}},
    {2, {2964.3, 20.9}},
    {3, {3055.9, 7.8}},
    {4, {3077.2, 3.6}}};

void get_punzi(double bkgCut = 0)
{
    // Open TMVA Classification output file
    TString TMVA_output_filename = (TString) "TMVA.root";
    TFile *TMVA_output = TFile::Open(TMVA_output_filename);

    if (TMVA_output->IsZombie())
    {
        std::cout << "[ERROR] --- " << TMVA_output_filename << " could not be found!\n";
        exit(1);
    }
    std::ofstream logFile;
    if (bkgCut)
    {
        gSystem->Exec("mkdir -p punzi_cut");
        logFile = std::ofstream("punzi_cut/punzi.csv");
    }
    else
    {
        gSystem->Exec("mkdir -p punzi");
        logFile = std::ofstream("punzi/punzi.csv");
    }
    logFile << "Mass ID, Method, Max Punzi" << std::endl;

    // Get dataset filenames
    std::string_view bkgInputFileName = getenv("CURRENT_WS1_DATASET");

    if (bkgInputFileName == "")
    {
        std::cout << bkgInputFileName << " could not be found." << std::endl;
    }
    // Defnie RDataFrame for background dataset
    // Obtain Xicst mass distribution
    RDataFrame tree_df("DecayTree", bkgInputFileName);

    TFormula f("punzi", GetFormula());
    TString cname = "Classifier";
    if (cname.Length() > maxLenTitle)
        maxLenTitle = cname.Length();

    if (bkgCut)
        std::cout << "Operating with cut on background efficiency lower than " << bkgCut << std::endl;

    TString method, method_dir;
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

                // Strings to get signal and background efficiencies
                TString get_effS = (TString) "dataset/Method_" + method_dir + (TString) "/" + method + (TString) "/MVA_" + method + (TString) "_effS";
                TString get_effB = (TString) "dataset/Method_" + method_dir + (TString) "/" + method + (TString) "/MVA_" + method + (TString) "_effB";

                TString artist_name;
                // Create canvas
                artist_name = method + (TString) " - MassID" + mass_case_id;
                TCanvas *c = new TCanvas(artist_name, artist_name, 800, 400);

                c->SetGrid(1);
                c->SetTicks(0, 0);

                TStyle *TMVAStyle = gROOT->GetStyle("Plain"); // our style is based on Plain
                c->SetTopMargin(.2);
                if (method == "BDTG")
                {
                    c->SetRightMargin(3.0);
                    TMVAStyle->SetLineStyleString(5, "[32 22]");
                    TMVAStyle->SetLineStyleString(6, "[12 22]");
                }

                // Create stack of histograms
                TString title_stack = (TString) "Method: " + method + (TString) " - Mass Case " + mass_case_id + (TString) ";TMVA Response; Efficiency";
                artist_name = (TString) "HStack" + method + (TString) " - MassID" + mass_case_id;
                THStack *hs = new THStack(artist_name, title_stack);

                // --- Hists for signal efficiency
                TH1F *histS = (TH1F *)TMVA_output->Get(get_effS);
                artist_name = (TString) "Punzi Curve " + method + (TString) " - MassID" + mass_case_id;
                if (bkgCut)
                    artist_name = artist_name + (TString) " (Cut: b_eff >  " + bkgCut + (TString) ")";
                histS->SetNameTitle(artist_name, artist_name);

                // --- Hists for bkg efficiency
                TH1F *histB = (TH1F *)TMVA_output->Get(get_effB);
                artist_name = (TString) "Background Efficiency " + method + (TString) " - MassID" + mass_case_id;
                histB->SetNameTitle(artist_name, artist_name);

                int nbins = histS->GetNbinsX();
                double low = histS->GetBinLowEdge(1);
                double high = histS->GetBinLowEdge(nbins + 1);

                // --- Hists for punzi
                artist_name = (TString) "Punzi " + method + (TString) " - MassID" + mass_case_id;
                TH1F *punzi_curve = new TH1F(artist_name, artist_name, nbins, low, high);

                // set the histogram style
                TMVA::TMVAGlob::SetSignalAndBackgroundStyle(histS, histB);
                histS->SetFillStyle(0);
                histB->SetFillStyle(0);
                punzi_curve->SetFillStyle(0);
                histS->SetLineWidth(3);
                histB->SetLineWidth(3);
                punzi_curve->SetLineWidth(3);

                // TStyle *TMVAStyle = gROOT->GetStyle("Plain");
                // c->SetTopMargin(.2);

                double maxPunzi = -1;
                for (int i = 1; i <= nbins; i++)
                {
                    double eS = histS->GetBinContent(i);
                    double eB = histB->GetBinContent(i);
                    if (eB < bkgCut)
                        continue;
                    double B = eB * numB;

                    double punzi = f.Eval(eS, B);

                    if (punzi > maxPunzi)
                        maxPunzi = punzi;

                    if (eS < 0.3 && method == "BDTG" && mass_case_id == 2)
                    {
                        std::cout << std::setw(10) << std::left << eB
                                  << std::setw(10) << punzi << std::endl;
                    }

                    punzi_curve->SetBinContent(i, punzi);
                }

                int binmax = punzi_curve->GetMaximumBin();
                double cut = punzi_curve->GetXaxis()->GetBinCenter(binmax);
                punzi_curve->Scale(1 / maxPunzi);

                // hs->Add(punzi_curve);
                std::cout << "Maximum  " << maxPunzi << "  Optimal cut   " << cut << std::endl;

                logFile << mass_case_id << ", "
                        << method << ", "
                        << std::scientific << maxPunzi << std::endl;

                // TMVA::TMVAGlob::SetFrameStyle(histS);

                histS->SetMaximum(1.1);
                histS->Draw("histl");
                histB->Draw("samehistl");

                Int_t signifColor = TColor::GetColor("#00aa00");
                punzi_curve->SetLineColor(signifColor);
                punzi_curve->Draw("samehistl");

                histS->Draw("sameaxis");

                // Draw legend
                TLegend *legend1 = new TLegend(c->GetLeftMargin(), 1 - c->GetTopMargin(),
                                               c->GetLeftMargin() + 0.4, 1 - c->GetTopMargin() + 0.12);
                legend1->SetFillStyle(1);
                legend1->AddEntry(histS, "Signal efficiency", "L");
                legend1->AddEntry(histB, "Background efficiency", "L");
                legend1->Draw("same");
                legend1->SetBorderSize(1);
                legend1->SetMargin(0.3);

                TLegend *legend2 = new TLegend(c->GetLeftMargin() + 0.4, 1 - c->GetTopMargin(),
                                               1 - c->GetRightMargin(), 1 - c->GetTopMargin() + 0.12);
                legend2->SetFillStyle(1);
                legend2->AddEntry(punzi_curve, GetLatexFormula().Data(), "L");
                legend2->Draw("same");
                legend2->SetBorderSize(1);
                legend2->SetMargin(0.3);
                gStyle->SetOptStat(0);
                c->Update();

                TLine *effline = new TLine(punzi_curve->GetXaxis()->GetXmin(), 1, punzi_curve->GetXaxis()->GetXmax(), 1);
                effline->SetLineWidth(1);
                effline->SetLineColor(1);
                effline->Draw();

                // print comments
                TLatex tl, *line1, *line2;
                tl.SetNDC();
                tl.SetTextSize(0.033);
                Int_t maxbin = punzi_curve->GetMaximumBin();
                line1 = tl.DrawLatex(0.15, 0.23, Form("For %1.0d background", numB));
                tl.DrawLatex(0.15, 0.19, "events the maximum Punzi is");

                line2 = tl.DrawLatex(0.15, 0.15, Form("%4.2e when cutting at %5.2f", maxPunzi, punzi_curve->GetXaxis()->GetBinCenter(maxbin)));
                // save canvas to file
                c->Update();

                // Draw second axes
                TGaxis *rightAxis = new TGaxis(c->GetUxmax(), c->GetUymin(),
                                               c->GetUxmax(), c->GetUymax(), 0, 1.1 * maxPunzi, 510, "+L");
                rightAxis->SetLineColor(signifColor);
                rightAxis->SetLabelColor(signifColor);
                rightAxis->SetTitleColor(signifColor);

                rightAxis->SetTitleSize(punzi_curve->GetXaxis()->GetTitleSize());
                rightAxis->SetTitle("Punzi Figure of Merit");
                rightAxis->Draw();

                c->Update();

                TString filename; 
                if (bkgCut)
                    filename = (TString) "punzi_cut/" + method + (TString) "m" + mass_case_id + (TString) "_cut.svg";
                else
                    filename = (TString) "punzi/" + method + (TString) "m" + mass_case_id + (TString) ".svg";
                c->Print(filename);
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

TString GetLatexFormula()
{
    TString f = fFormula;
    f.ReplaceAll("(", "{");
    f.ReplaceAll(")", "}");
    f.ReplaceAll("S", "eS");
    f.ReplaceAll("sqrt", "#sqrt");
    return f;
}


// Copied from mvaeffs.cxx in ROOT src
TString GetFormula()
{
    // replace all occurrence of S and B but only if neighbours are not alphanumerics
    auto replace_vars = [](TString &f, char oldLetter, char newLetter)
    {
        auto pos = f.First(oldLetter);
        while (pos != kNPOS)
        {
            if ((pos > 0 && !TString(f[pos - 1]).IsAlpha()) ||
                (pos < f.Length() - 1 && !TString(f[pos + 1]).IsAlpha()))
            {
                f[pos] = newLetter;
            }
            int pos2 = pos + 1;
            pos = f.Index(oldLetter, pos2);
        }
    };
    TString formula = fFormula;
    replace_vars(formula, 'S', 'x');
    replace_vars(formula, 'B', 'y');
    return formula;
}