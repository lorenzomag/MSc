#include <string>
#include <sstream>
#include <iostream>
#include "TTree.h"
#include "TFile.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TDirectory.h"
#include "TTree.h"
#include "ROOT/RDataFrame.hxx"
#include "TStyle.h"
#include "TLatex.h"
//#include "TH2D.h"
//#include "TProfile.h"
//#include "RooGaussian.h"
//#include "RooDataHist.h"
//#include "RooPlot.h"
//#include "RooAddPdf.h"
//#include "TSpectrum.h"
//using namespace RooFit ;

using namespace ROOT;

void set_file_names(TString &signalFileName, TString &bkgInputFileName, TString &exe_dir, TString &outputFileName);
void punzi_fom(TString filename = "../output/TMVA_methodSample.root", TString meth_dir="Method_BDT", TString method="BDT")
{

    TFile *f = TFile::Open(filename);
    TString get_argS = "dataset/" + meth_dir + "/" + method + "/MVA_" + method + "_effS";
    TString get_argB = "dataset/" + meth_dir + "/" + method + "/MVA_" + method + "_effB";
    // TH1F *histS = (TH1F*)f->Get("dataset/Method_BDT/BDTG/MVA_BDTG_effS");
    TH1F *histS = (TH1F *)f->Get(get_argS);
    //TH1F *histS = (TH1F*)f->Get("dataset/Method_BDT/BDT/MVA_BDT_effS");
    TH1F *histB = (TH1F *)f->Get(get_argB);
    // TH1F *histB = (TH1F*)f->Get("dataset/Method_BDT/BDTG/MVA_BDTG_effB");
    // TH1F *histB = (TH1F*)f->Get("dataset/Method_BDT/BDT/MVA_BDT_effB");
    TH1F *histcorrS = (TH1F *)f->Get("dataset/CorrelationMatrixS");
    TH1F *histcorrB = (TH1F *)f->Get("dataset/CorrelationMatrixB");

    //TH1F *h1 = new TH1F("h1", "h1 title", 100, 0, 4.4);
    TH1F *punzi_curve = new TH1F("punzi_curve", "Punzi FoM VS TMVA response", 10000, -1, 1);



    //double numB = 37129;
    //double numS = 75713;
    double mass = 3077.2; // MeV
    double width = 3.6;   // MeV

    TString signalInputFileName, bkgInputFileName, outputFileName, exe_dir;

    set_file_names(signalInputFileName, bkgInputFileName, exe_dir, outputFileName);

    TFile inputFile(bkgInputFileName, "READ");
    TTree *treeS = (TTree *)inputFile.Get("DecayTree");
    RDataFrame tree_df(*treeS);

    auto mass_distribution = tree_df.Histo1D("Xicst_M");

    int min = mass_distribution->FindBin(mass - width);
    int max = mass_distribution->FindBin(mass + width);

    double numB = mass_distribution->Integral(min,max);



    TCanvas *cS = new TCanvas("cS", "", 800, 400);
    histS->Draw();
    cS->SaveAs("effS.pdf");
    TCanvas *cB = new TCanvas("cB", "", 800, 400);
    histB->Draw();
    cB->SaveAs("effB.pdf");

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
        double newB = effB * numB;

        //std::cout << "newS = " << newS << ", newB = " << newB << std::endl;

        //double formula = newS/(sqrt(newS+newB));
        double formula;
        //if (newB != 0){
        formula = newS / (5. / 3. + (sqrt(newB)));
        punzi_curve->SetBinContent(i, formula);
        //}
        //
    }
    float Maximum = punzi_curve->GetMaximum();
    //float cut=punzi_curve->GetX(100);
    int binmax = punzi_curve->GetMaximumBin();
    double cut = punzi_curve->GetXaxis()->GetBinCenter(binmax);
    //std::cout << "effS = " << effS << ", effB = " << effB << std::endl;
    //std::cout << "S = " << newS << ", B = " << newB << std::endl;
    //std::cout << "S + B = " << newS+newB << ", sqrt is " << sqrt(newS+newB) << std::endl;
    //std::cout << "S/sqrt(B) = " << formula << std::endl;
    std::cout << "Maximum  " << Maximum << "  Optimal cut   " << cut << std::endl;

    // }

    gStyle->SetOptStat(0);
    TCanvas *cFOM = new TCanvas("cFOM", "", 800, 400);
    punzi_curve->SetMarkerStyle(22);
    // punzi_curve->GetXaxis()->SetTitle("MLP response");
    punzi_curve->GetXaxis()->SetTitle("BDT response");
    punzi_curve->GetYaxis()->SetTitle("Significance");
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
    TString defaultName = "/home/loren/MSc/datasets/mcsampletruthDecFile26265973_LcCutTruthMatched_IDpart.root";

    bkgInputFileName = getenv("CURRENT_BKG_DATASET");
    if (!bkgInputFileName)
    {
        std::cout << bkgInputFileName << " could not be found." << std::endl;
        bkgInputFileName = defaultName;
        std::cout << "Using default file name: " << bkgInputFileName << std::endl;
    }

    signalFileName = getenv("CURRENT_SIG_DATASET");
    if (!signalFileName)
    {
        std::cout << signalFileName << " could not be found." << std::endl;
        signalFileName = defaultName;
        std::cout << "Using default file name: " << signalFileName << std::endl;
    }

    outputFileName = "features.root";
}

// int main(){
//     punzi_fom();
// }