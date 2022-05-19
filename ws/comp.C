#include <cstdlib>
#include <array>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <fstream>

#include "TRatioPlot.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TCanvas.h"
#include "THStack.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TMVA/tmvaglob.h"

#include "TMVA/Factory.h"
#include "TMVA/DataLoader.h"
#include "TMVA/Tools.h"
#include "TMVA/TMVAGui.h"
#include "TRint.h"
#include "TStopwatch.h"

#include "TStyle.h"

#include "ROOT/RDataFrame.hxx"

#include "json.hpp"

using nlohmann::json;
using ROOT::RDataFrame;

void setStyles(TH1 *ws1, TH1 *ws2, TH1 *ws3);

void comp(std::string method = "MLP", const double cut = 0.89)
{

    TChain *tree = new TChain("DecayTree");
    tree->Add(getenv("CURRENT_WS1_2016_DATASET"));
    tree->Add(getenv("CURRENT_WS2_2016_DATASET"));
    tree->Add(getenv("CURRENT_WS3_2016_DATASET"));

    RDataFrame ds(*tree);

    auto ws1 = ds.Filter("data_type == 1");
    auto ws2 = ds.Filter("data_type == 2");
    auto ws3 = ds.Filter("data_type == 3");

    const char *cut_string = Form("MVA_%s > %f", method.c_str(), cut);
    auto ws1_cut = ws1.Filter(cut_string);
    auto ws2_cut = ws2.Filter(cut_string);
    auto ws3_cut = ws3.Filter(cut_string);

    //  Make Hists
    ROOT::RDF::TH1DModel hist_model = {"", "", 100, 2800, 4000};

    auto ws1_hist = ws1.Histo1D(hist_model, "Xicst_M");
    auto ws2_hist = ws2.Histo1D(hist_model, "Xicst_M");
    auto ws3_hist = ws3.Histo1D(hist_model, "Xicst_M");
    auto ws1_cut_hist = ws1_cut.Histo1D(hist_model, "Xicst_M");
    auto ws2_cut_hist = ws2_cut.Histo1D(hist_model, "Xicst_M");
    auto ws3_cut_hist = ws3_cut.Histo1D(hist_model, "Xicst_M");

    ws1_hist->SetNameTitle("WS1", "WS1");
    ws2_hist->SetNameTitle("WS2", "WS2");
    ws3_hist->SetNameTitle("WS3", "WS3");
    ws1_cut_hist->SetNameTitle("WS1", "WS1");
    ws2_cut_hist->SetNameTitle("WS2", "WS2");
    ws3_cut_hist->SetNameTitle("WS3", "WS3");
    setStyles(ws1_hist.GetPtr(), ws2_hist.GetPtr(), ws3_hist.GetPtr());
    setStyles(ws1_cut_hist.GetPtr(), ws2_cut_hist.GetPtr(), ws3_cut_hist.GetPtr());

    // TCanvas *c1 = new TCanvas("c1", "c1");
    // THStack *hs_before = new THStack("Before MVA", "Before MVA");
    // hs_before->Add(ws1_hist.GetPtr());
    // hs_before->Add(ws2_hist.GetPtr());
    // hs_before->Add(ws3_hist.GetPtr());
    // hs_before->DrawClone("nostack");
    // c1->BuildLegend();

    // TCanvas *c2 = new TCanvas("c2", "c2");
    // THStack *hs_after = new THStack("After MVA", "After MVA");
    // hs_after->Add(ws1_cut_hist.GetPtr());
    // hs_after->Add(ws2_cut_hist.GetPtr());
    // hs_after->Add(ws3_cut_hist.GetPtr());
    // hs_after->DrawClone("nostack");
    // c2->BuildLegend();

    TCanvas *c5 = new TCanvas("c5", "c5");
    TH1D *rh1 = new TH1D("MVA Efficiency on WS1", "MVA Efficiency on WS1", 100, 2800, 4000);
    rh1->Divide(ws1_cut_hist.GetPtr(), ws1_hist.GetPtr());
    rh1->DrawClone();

    TCanvas *c6 = new TCanvas("c6", "c6");
    TH1D *rh2 = new TH1D("MVA Efficiency on WS2", "MVA Efficiency on WS2", 100, 2800, 4000);
    rh2->Divide(ws2_cut_hist.GetPtr(), ws2_hist.GetPtr());
    rh2->DrawClone();

    TCanvas *c7 = new TCanvas("c7", "c7");
    TH1D *rh3 = new TH1D("MVA Efficiency on WS3", "MVA Efficiency on WS3", 100, 2800, 4000);
    rh3->Divide(ws3_cut_hist.GetPtr(), ws3_hist.GetPtr());
    rh3->DrawClone();


    
    setStyles(rh1, rh2, rh3);
    Double_t r_factor = rh1->Integral();
    rh1->Scale(r_factor / rh1->Integral());
    rh2->Scale(r_factor / rh2->Integral());
    rh3->Scale(r_factor / rh3->Integral());

    TCanvas *c8 = new TCanvas("c8", "c8");
    THStack *hs_ratios = new THStack("MVA efficiency", "MVA efficiency");
    hs_ratios->Add(rh1);
    hs_ratios->Add(rh2);
    hs_ratios->Add(rh3);
    hs_ratios->DrawClone("nostack hist");
    c8->BuildLegend();


    // // Normalised to WS1
    // Double_t factor = ws1_hist->Integral();
    // ws1_hist->Scale(factor / ws1_hist->Integral());
    // ws2_hist->Scale(factor / ws2_hist->Integral());
    // ws3_hist->Scale(factor / ws3_hist->Integral());
    // factor = ws1_cut_hist->Integral();
    // ws1_cut_hist->Scale(factor / ws1_cut_hist->Integral());
    // ws2_cut_hist->Scale(factor / ws2_cut_hist->Integral());
    // ws3_cut_hist->Scale(factor / ws3_cut_hist->Integral());

    // TCanvas *c3 = new TCanvas("c3", "c3");
    // THStack *hs_before_norm = new THStack("Before MVA (Normalised to WS1)", "Before MVA (Normalised to WS1)");
    // hs_before_norm->Add(ws1_hist.GetPtr());
    // hs_before_norm->Add(ws2_hist.GetPtr());
    // hs_before_norm->Add(ws3_hist.GetPtr());
    // hs_before_norm->DrawClone("nostack hist");
    // c3->BuildLegend();

    // TCanvas *c4 = new TCanvas("c4", "c4");
    // THStack *hs_after_norm = new THStack("After MVA (Normalised to WS1)", "After MVA (Normalised to WS1)");
    // hs_after_norm->Add(ws1_cut_hist.GetPtr());
    // hs_after_norm->Add(ws2_cut_hist.GetPtr());
    // hs_after_norm->Add(ws3_cut_hist.GetPtr());
    // hs_after_norm->DrawClone("nostack hist");
    // c4->BuildLegend();

    // gSystem->Exec("mkdir -p figures");
    // c1->Print("figures/ws_before_MVA.svg");
    // c2->Print("figures/ws_after_MVA.svg");
    // c3->Print("figures/norm_ws_before_MVA.svg");
    // c4->Print("figures/norm_ws_after_MVA.svg");
    c5->Print("figures/ws1_MVA_eff.png");
    c6->Print("figures/ws2_MVA_eff.png");
    c7->Print("figures/ws3_MVA_eff.png");
    c8->Print("figures/MVA_eff.png");
}

void setStyles(TH1 *ws1, TH1 *ws2, TH1 *ws3)
{
    ws1->SetLineColor(46);
    ws1->SetLineWidth(2);
    ws1->SetLineStyle(1);
    ws1->SetNameTitle("WS1", "WS1");

    ws2->SetLineColor(30);
    ws2->SetLineWidth(2);
    ws2->SetLineStyle(1);
    ws2->SetNameTitle("WS2", "WS2");

    ws3->SetLineColor(38);
    ws3->SetLineWidth(2);
    ws3->SetLineStyle(1);
    ws3->SetNameTitle("WS3", "WS3");
}