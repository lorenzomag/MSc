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

void TMVAnalyse(std::string method = "BDTG", const double cut = 0.84)
{
    ROOT::EnableImplicitMT();

    TFile *file = new TFile(getenv("CURRENT_APPLICATION_DATASET"));
    TTree *tree = (TTree *)file->Get("DecayTree");

    RDataFrame ds(*tree);

    auto sig = ds.Filter("data_type == 0");
    auto bkg = ds.Filter("data_type == 1");

    auto ds_cut = ds.Filter(Form("MVA_%s > %f", method.c_str(), cut));
    auto sig_cut = ds_cut.Filter("data_type == 0");
    auto bkg_cut = ds_cut.Filter("data_type == 1");

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
    SetBeforeAfterStyle(bkgHist.GetPtr(),bkgHist_cut.GetPtr());
    // c1->Divide(1,3);
    // c1->cd(1);

    // c1->cd(2);
    // c1->cd(3);
    THStack *hs_bkg = new THStack("WS1", "WS1");
    // bkgHist->SetTitle("Before MVA");
    // hs_bkg->Add(bkgHist.GetPtr());
    bkgHist_cut->SetTitle("After MVA");
    hs_bkg->Add(bkgHist_cut.GetPtr());
    hs_bkg->DrawClone("nostack");
    c1->BuildLegend();

    TCanvas *c2 = new TCanvas("c2", "c2");
    THStack *hs_sig = new THStack("MC", "MC");
    SetBeforeAfterStyle(sigHist.GetPtr(),sigHist_cut.GetPtr());
    // sigHist->SetTitle("Before MVA");
    // hs_sig->Add(sigHist.GetPtr());
    sigHist_cut->SetTitle("After MVA");
    hs_sig->Add(sigHist_cut.GetPtr());
    hs_sig->DrawClone("nostack");
    c2->BuildLegend();

    // TCanvas *c3 = new TCanvas("c3", "c3");
    // THStack *hs_mass = new THStack("MC + WS1", "MC + WS1");
    // SetBeforeAfterStyle(massHist.GetPtr(),massHist_cut.GetPtr());
    // massHist->SetTitle("Before MVA");
    // hs_mass->Add(massHist.GetPtr());
    // massHist_cut->SetTitle("After MVA");
    // hs_mass->Add(massHist_cut.GetPtr());
    // hs_mass->DrawClone("nostack");
    // c3->BuildLegend();

    // TCanvas *c4 = new TCanvas("c4", "c4");
    // THStack *hs_all = new THStack("After MVA", "After MVA");
    // sigHist_cut->SetLineColor(9);
    // bkgHist_cut->SetLineColor(8);
    // massHist_cut->SetLineColor(2);

    // sigHist_cut->SetTitle("MC");
    // bkgHist_cut->SetTitle("WS1");
    // massHist_cut->SetTitle("MC+WS1");
    // hs_all->Add(massHist_cut.GetPtr());
    // hs_all->Add(sigHist_cut.GetPtr());
    // hs_all->Add(bkgHist_cut.GetPtr());
    // hs_all->DrawClone("nostack");
    // c4->BuildLegend();
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