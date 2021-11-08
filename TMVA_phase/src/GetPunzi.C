#include "pch.h"
#include "GetPunzi.hpp"

using namespace ROOT;

void GetPunzi(int run = 1, TString method = "BDTG", TString method_dir = "Method_BDT", bool use_SQL = false, TApplication *app = gApplication)
{
    // Open TMVA output file
    TString TMVA_output_filename = (TString) "/home/loren/MSc/TMVA_phase/output/TMVA_run" + run + (TString) ".root";
    TFile *TMVA_output = TFile::Open(TMVA_output_filename);

    if (TMVA_output->IsZombie())
    {
        std::cout << "[ERROR] --- " << TMVA_output_filename << " could not be found!\n";
        exit(1);
    }

    // Get signal and background efficiencies
    TString get_effS = (TString) "dataset/" + method_dir + (TString) "/" + method + (TString) "/MVA_" + method + (TString) "_effS";
    TString get_effB = (TString) "dataset/" + method_dir + (TString) "/" + method + (TString) "/MVA_" + method + (TString) "_effB";

    // Create stack of histograms
    TString artist_name;
    TString run_method_name = method + (TString) " r" + run;
    TString title_stack = (TString) "Run: " + run + (TString) "     Method: " + method + (TString) ";TMVA Response; Efficiency";

    artist_name = (TString) "c" + run_method_name;
    TCanvas *cS = new TCanvas(artist_name, "", 800, 400);
    artist_name = (TString) "HStack" + run_method_name;
    THStack *hs = new THStack(artist_name, title_stack);
    // --- Hists for signal efficiency
    TH1F *histS = (TH1F *)TMVA_output->Get(get_effS);
    artist_name = (TString) "Signal " + run_method_name;
    histS->SetNameTitle(artist_name, "Efficiency");
    // --- Hists for bkg efficiency
    TH1F *histB = (TH1F *)TMVA_output->Get(get_effB);
    artist_name = (TString) "Background " + run_method_name;
    histB->SetNameTitle(artist_name, "Efficiency");

    // --- Hists for correlations
    artist_name = (TString) "histcorrS" + run_method_name;
    TH1F *histcorrS = (TH1F *)TMVA_output->Get("dataset/CorrelationMatrixS");
    histcorrS->SetName(artist_name);
    artist_name = (TString) "histcorrB" + run_method_name;
    TH1F *histcorrB = (TH1F *)TMVA_output->Get("dataset/CorrelationMatrixB");
    histcorrB->SetName(artist_name);

    // --- Hists for punzi
    artist_name = (TString) "Punzi " + run_method_name;
    TH1F *punzi_curve = new TH1F(artist_name, "Punzi FoM", 10000, -1, 1);

    // Select mass and width of particle
    double mass = 3077.2; // MeV
    double width = 3.6;   // MeV

    // Get dataset filenames
    TString bkgInputFileName = getenv("LOCAL_CURRENT_DATA");
    if (!bkgInputFileName)
    {
        std::cout << bkgInputFileName << " could not be found." << std::endl;
    }

    // Defnie RDataFrame for background dataset
    RDataFrame tree_df("DecayTree", bkgInputFileName);
    // Obtain Xicst mass distribution
    auto mass_distribution = tree_df.Histo1D("Xicst_M");

    // Determine background window based on candidate's mass and width from PDG
    int min_m = mass - 3 * width;
    int max_m = mass + 3 * width;
    // Lambda function to check value is within mass range
    auto massCut = [&min_m, &max_m](double m)
    { return (m > min_m) && (m < max_m); };

    // Appliy mass cut and count events within window
    auto numB = tree_df.Filter(massCut, {"Xicst_M"}).Count();

    hs->Add(histS);
    hs->Add(histB);

    gStyle->SetPalette(kRainBow);
    artist_name = (TString) "corrS " + run_method_name;
    TCanvas *corrS = new TCanvas(artist_name, "", 800, 400);
    artist_name = (TString) "corrB " + run_method_name;
    TCanvas *corrB = new TCanvas(artist_name, "", 800, 400);
    corrS->cd();
    histcorrS->Draw("zcol text");
    corrB->cd();
    histcorrB->Draw("zcol text");

    //    double effS = 0;
    //    double effB = 0;

    float lumi_2016 = 1.6;                     // /fb
    float lumi_all = 5.6;                      // /fb
    float lumi_2016_MagDown = lumi_2016 * 0.5; // assumption
    float bkgScaleFactor = lumi_all / lumi_2016_MagDown;
    std::cout << "Background scale factor is: " << bkgScaleFactor << std::endl;

    for (int i = 0; i < 10000; i = i + 100)
    {
        double effS = 0;
        double effB = 0;
        effS = histS->GetBinContent(i);
        effB = histB->GetBinContent(i);

        //double newS = 0;
        //double newB = 0;
        double newS = effS;
        double newB = effB * numB.GetValue() * bkgScaleFactor;

        //std::cout << "newS = " << newS << ", newB = " << newB << std::endl;

        //double formula = newS/(sqrt(newS+newB));
        double formula;
        //if (newB != 0){
        formula = newS / (5. / 2. + (sqrt(newB)));
        punzi_curve->SetBinContent(i, formula);
        //}
        //
    }
    float Maximum = punzi_curve->GetMaximum();
    int binmax = punzi_curve->GetMaximumBin();
    double cut = punzi_curve->GetXaxis()->GetBinCenter(binmax);
    std::cout << "Maximum  " << Maximum << "  Optimal cut   " << cut << std::endl;

    // }

    gStyle->SetOptStat(0);
    artist_name = (TString) "cFOM" + run_method_name;
    TCanvas *cFOM = new TCanvas(artist_name, "", 800, 400);
    punzi_curve->SetMarkerStyle(22);
    // punzi_curve->GetXaxis()->SetTitle("MLP response");
    punzi_curve->GetXaxis()->SetTitle("BDT response");
    punzi_curve->GetYaxis()->SetTitle("Punzi FoM");
    punzi_curve->SetMarkerColor(kOrange);
    punzi_curve->Draw("p");
    //cFOM->SaveAs("FOMcurve.pdf");

    TLatex *myLatex = new TLatex(0.5, 0.5, "");
    myLatex->SetTextFont(132);
    myLatex->SetTextColor(1);
    myLatex->SetTextSize(0.05);
    myLatex->SetNDC(kTRUE);
    myLatex->SetTextAlign(11);
    char maxvalue[40], optcut[30];
    sprintf(maxvalue, "%f ", Maximum);
    myLatex->DrawLatex(0.2, 0.5, "Max Punzi");
    myLatex->DrawLatex(0.4, 0.5, maxvalue);
    sprintf(optcut, "%f ", cut);
    myLatex->DrawLatex(0.2, 0.4, "Optimal Cut");
    myLatex->DrawLatex(0.4, 0.4, optcut);

    
}