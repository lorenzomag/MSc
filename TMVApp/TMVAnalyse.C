#include <cstdlib>
#include <array>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <fstream>

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

void SetBeforeAfterStyle(TH1 *before, TH1 *after);

void TMVAnalyse(const int ws = 0, std::string method = "BDTG", const double cut = 0.72)
{
    ROOT::EnableImplicitMT();

    // TFile *file = new TFile(getenv("CURRENT_APPLICATION_DATASET"));
    // TTree *tree = (TTree *)file->Get("DecayTree");

    TChain *tree = new TChain("DecayTree");
    tree->Add(getenv("CURRENT_MC_DATASET"));
    tree->Add(getenv("CURRENT_WS1_DATASET"));
    tree->Add(getenv("CURRENT_WS2_DATASET"));
    tree->Add(getenv("CURRENT_WS3_DATASET"));

    RDataFrame ds(*tree);

    const char *ws_condition = ws == 0 ? "data_type == 1 || data_type == 2" : Form("data_type == %d", ws);
    const char *ws_type = ws == 0 ? "WS1 + WS2" : Form("WS%d", ws);

    auto sig = ds.Filter("data_type == 0");
    auto bkg = ds.Filter(ws_condition);

    auto ds_cut = ds.Filter(Form("MVA_%s > %f", method.c_str(), cut));
    auto sig_cut = ds_cut.Filter("data_type == 0");
    auto bkg_cut = ds_cut.Filter(ws_condition);

    ROOT::RDF::TH1DModel hist_model = {"", "", 150, 2800, 4000};

    auto massHist = ds.Histo1D(hist_model, "Xicst_M");
    auto massHist_cut = ds_cut.Histo1D(hist_model, "Xicst_M");
    auto sigHist = sig.Histo1D(hist_model, "Xicst_M");
    auto sigHist_cut = sig_cut.Histo1D(hist_model, "Xicst_M");
    auto bkgHist = bkg.Histo1D(hist_model, "Xicst_M");
    auto bkgHist_cut = bkg_cut.Histo1D(hist_model, "Xicst_M");

    massHist->SetLineColor(7);
    massHist->SetLineWidth(2);
    massHist->SetLineStyle(1);

    massHist_cut->SetLineColor(38);
    massHist_cut->SetLineWidth(2);
    massHist_cut->SetLineStyle(1);

    sigHist->SetLineColor(3);
    sigHist->SetLineWidth(2);
    sigHist->SetLineStyle(1);

    sigHist_cut->SetLineColor(30);
    sigHist_cut->SetLineWidth(2);
    sigHist_cut->SetLineStyle(1);

    bkgHist->SetLineColor(2);
    bkgHist->SetLineWidth(2);
    bkgHist->SetLineStyle(1);

    bkgHist_cut->SetLineColor(46);
    bkgHist_cut->SetLineWidth(2);
    bkgHist_cut->SetLineStyle(1);

    TCanvas *c1 = new TCanvas("c1", "c1");
    SetBeforeAfterStyle(bkgHist.GetPtr(), bkgHist_cut.GetPtr());

    THStack *hs_bkg = new THStack(ws_type, ws_type);
    bkgHist->SetTitle("Before MVA");
    hs_bkg->Add(bkgHist.GetPtr());
    bkgHist_cut->SetTitle("After MVA");
    hs_bkg->Add(bkgHist_cut.GetPtr());
    hs_bkg->DrawClone("nostack");
    c1->BuildLegend();

    TCanvas *c2 = new TCanvas("c2", "c2");
    THStack *hs_sig = new THStack("MC", "MC");
    SetBeforeAfterStyle(sigHist.GetPtr(), sigHist_cut.GetPtr());
    sigHist->SetTitle("Before MVA");
    hs_sig->Add(sigHist.GetPtr());
    sigHist_cut->SetTitle("After MVA");
    hs_sig->Add(sigHist_cut.GetPtr());
    hs_sig->DrawClone("nostack");
    c2->BuildLegend();

    TCanvas *c3 = new TCanvas("c3", "c3");
    THStack *hs_mass = new THStack(Form("MC + %s", ws_type), Form("MC + %s", ws_type));
    SetBeforeAfterStyle(massHist.GetPtr(), massHist_cut.GetPtr());
    massHist->SetTitle("Before MVA");
    hs_mass->Add(massHist.GetPtr());
    massHist_cut->SetTitle("After MVA");
    hs_mass->Add(massHist_cut.GetPtr());
    hs_mass->DrawClone("nostack");
    c3->BuildLegend();

    TCanvas *c4 = new TCanvas("c4", "c4");
    THStack *hs_all = new THStack("After MVA", "After MVA");
    sigHist_cut->SetLineColor(9);
    bkgHist_cut->SetLineColor(8);
    massHist_cut->SetLineColor(2);

    sigHist_cut->SetTitle("MC");
    bkgHist_cut->SetTitle(ws_type);
    massHist_cut->SetTitle(Form("MC + %s", ws_type));
    hs_all->Add(massHist_cut.GetPtr());
    hs_all->Add(sigHist_cut.GetPtr());
    hs_all->Add(bkgHist_cut.GetPtr());
    hs_all->DrawClone("nostack");
    c4->BuildLegend();

    if (ws == 0)
    {
        auto ws1 = bkg.Filter("data_type == 1");
        auto ws2 = bkg.Filter("data_type == 2");
        auto ws1_cut = bkg_cut.Filter("data_type == 1");
        auto ws2_cut = bkg_cut.Filter("data_type == 2");

        auto ws1_hist = ws1.Histo1D(hist_model, "Xicst_M");
        auto ws2_hist = ws2.Histo1D(hist_model, "Xicst_M");
        auto ws1_cut_hist = ws1_cut.Histo1D(hist_model, "Xicst_M");
        auto ws2_cut_hist = ws2_cut.Histo1D(hist_model, "Xicst_M");


        TCanvas *c5 = new TCanvas("c5", "c5");
        THStack *hs_ws1 = new THStack("WS1", "WS1");
        SetBeforeAfterStyle(ws1_hist.GetPtr(), ws1_cut_hist.GetPtr());
        ws1_hist->SetTitle("Before MVA");
        hs_ws1->Add(ws1_hist.GetPtr());
        ws1_cut_hist->SetTitle("After MVA");
        hs_ws1->Add(ws1_cut_hist.GetPtr());
        hs_ws1->DrawClone("nostack");
        c5->BuildLegend();

        TCanvas *c6 = new TCanvas("c6", "c6");
        THStack *hs_ws2 = new THStack("WS2", "WS2");
        SetBeforeAfterStyle(ws2_hist.GetPtr(), ws2_cut_hist.GetPtr());
        ws2_hist->SetTitle("Before MVA");
        hs_ws2->Add(ws2_hist.GetPtr());
        ws2_cut_hist->SetTitle("After MVA");
        hs_ws2->Add(ws2_cut_hist.GetPtr());
        hs_ws2->DrawClone("nostack");
        c6->BuildLegend();

        TCanvas *c7 = new TCanvas("c7", "c7");
        THStack *hs_before = new THStack("Before Cut", "Before Cut");
        SetBeforeAfterStyle(ws1_hist.GetPtr(), ws2_hist.GetPtr());
        ws1_hist->SetTitle("WS1");
        hs_before->Add(ws1_hist.GetPtr());
        ws2_hist->SetTitle("WS2");
        hs_before->Add(ws2_hist.GetPtr());
        hs_before->DrawClone("nostack");
        c7->BuildLegend();

        TCanvas *c8 = new TCanvas("c8", "c8");
        THStack *hs_after = new THStack("After Cut", "After Cut");
        SetBeforeAfterStyle(ws1_cut_hist.GetPtr(), ws2_cut_hist.GetPtr());
        ws1_cut_hist->SetTitle("WS1");
        hs_after->Add(ws1_cut_hist.GetPtr());
        ws2_cut_hist->SetTitle("WS2");
        hs_after->Add(ws2_cut_hist.GetPtr());
        hs_after->DrawClone("nostack");
        c8->BuildLegend();
    }
}

void SetBeforeAfterStyle(TH1 *before, TH1 *after)
{
    before->SetLineColor(46);
    before->SetLineWidth(2);
    before->SetLineStyle(1);

    after->SetLineColor(30);
    after->SetLineWidth(2);
    after->SetLineStyle(1);
}