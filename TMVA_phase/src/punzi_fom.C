#include "pch.h"
#include "ROOT/RDataFrame.hxx"
#include "TLatex.h"

using namespace ROOT;

void set_file_names(TString &signalFileName, TString &bkgInputFileName, TString &exe_dir, TString &outputFileName);

void punzi_fom(int run = 1, TString method = "BDTG", TString meth_dir = "Method_BDT")
{

    // Open TMVA output file
    TString filename = (TString) "/home/loren/MSc/TMVA_phase/output/TMVA_run" + run + (TString) ".root";
    TFile *f = TFile::Open(filename);

    // Get signal and background efficiencies
    TString get_argS = "dataset/" + meth_dir + "/" + method + "/MVA_" + method + "_effS";
    TString get_argB = "dataset/" + meth_dir + "/" + method + "/MVA_" + method + "_effB";

    // Create stack of histograms
    TCanvas *cS = new TCanvas("cS", "", 800, 400);
    TString title_stack = (TString) "Run: " + run + (TString) "     Method: " + method + (TString) ";TMVA Response; Efficiency";
    THStack *hs = new THStack("Efficiencies", title_stack);
    // --- Hists for signal efficiency
    TH1F *histS = (TH1F *)f->Get(get_argS);
    histS->SetNameTitle("Signal", "Efficiency");
    // --- Hists for bkg efficiency
    TH1F *histB = (TH1F *)f->Get(get_argB);
    histB->SetNameTitle("Background", "Efficiency");

    // // --- Hists for correlations
    // TH1F *histcorrS = (TH1F *)f->Get("dataset/CorrelationMatrixS");
    // TH1F *histcorrB = (TH1F *)f->Get("dataset/CorrelationMatrixB");

    // --- Hists for punzi
    TH1F *punzi_curve = new TH1F("punzi_curve", "Punzi FoM", 10000, -1, 1);

    // Select mass and width of particle
    double mass = 3077.2; // MeV
    double width = 3.6;   // MeV

    // Get dataset filenames
    TString signalInputFileName, bkgInputFileName, outputFileName, exe_dir;
    set_file_names(signalInputFileName, bkgInputFileName, exe_dir, outputFileName);

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
    TCanvas *corrS = new TCanvas("corrS", "", 800, 400);
    TCanvas *corrB = new TCanvas("corrB", "", 800, 400);
    //corrS->cd();
    //histcorrS->Draw("zcol text");
    //corrB->cd();
    //histcorrB->Draw("zcol text");

    //    double effS = 0;
    //    double effB = 0;

    for (int i = 0; i < 10000; i = i + 100)
    {
        double effS = 0;
        double effB = 0;
        effS = histS->GetBinContent(i);
        effB = histB->GetBinContent(i);

        //double newS = 0;
        //double newB = 0;
        double newS = effS;
        double newB = effB * *numB;

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
    TCanvas *cFOM = new TCanvas("cFOM", "", 800, 400);
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

void set_file_names(TString &signalFileName, TString &bkgInputFileName, TString &exe_dir, TString &outputFileName)
{
    bkgInputFileName = getenv("CURRENT_WS1_DATASET");
    if (!bkgInputFileName)
    {
        std::cout << bkgInputFileName << " could not be found." << std::endl;
    }

    signalFileName = getenv("CURRENT_MC_DATASET");
    if (!signalFileName)
    {
        std::cout << signalFileName << " could not be found." << std::endl;
    }

    outputFileName = "analysed_" + signalFileName;
}

int main(int argc, char **argv)
{
    TApplication app("Application", &argc, argv);

    punzi_fom();

    std::thread t([&app]()
                  {
                      std::cout << "To stop the application, press Enter\n";
                      std::cin.get();
                      app.Terminate(0);
                  });

    app.Run();
}