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
#include "TSystem.h"
#include "TROOT.h"
#include "TRint.h"
#include "TStopwatch.h"

#include "TStyle.h"

#include "ROOT/RDataFrame.hxx"

#include "json.hpp"

using nlohmann::json;
using ROOT::RDataFrame;

void TMVAnalyse(const int FEATURE_SET = 11, const int HYPERPARAM_SET = 1, std::string method = "BDTG", const double cut = 0.80)
{
    ROOT::EnableImplicitMT();

    TFile *file = new TFile(getenv("CURRENT_APPLICATION_DATASET"));
    TTree *tree = (TTree *)file->Get("DecayTree");

    tree->AddFriend("mva_response", Form("runs/run_fs%d_hp%d/TMVApp.root", FEATURE_SET, HYPERPARAM_SET));

    RDataFrame ds(*tree);

    auto sig = ds.Filter("data_type == 0");
    auto bkg = ds.Filter("data_type == 1");

    auto ds_cut = ds.Filter(Form("MVA_%s > %f", method.c_str(), cut));
    auto sig_cut = ds_cut.Filter("data_type == 0");
    auto bkg_cut = ds_cut.Filter("data_type == 1");

    ROOT::RDF::TH1DModel hist_model = {"","",200,2800,4000};

    auto massHist = ds.Histo1D(hist_model,"Xicst_M");
    auto massHist_cut = ds_cut.Histo1D(hist_model,"Xicst_M");

    auto sigHist = sig.Histo1D(hist_model,"Xicst_M");
    auto sigHist_cut = sig_cut.Histo1D(hist_model,"Xicst_M");

    auto bkgHist = bkg.Histo1D(hist_model,"Xicst_M");
    auto bkgHist_cut = bkg_cut.Histo1D(hist_model,"Xicst_M");

    TCanvas *c1 = new TCanvas("c1", "c1");
    bkgHist->DrawClone();
    bkgHist_cut->DrawClone("same");

    TCanvas *c2 = new TCanvas("c2", "c2");
    sigHist->DrawClone();
    sigHist_cut->DrawClone("same");

    TCanvas *c3 = new TCanvas("c3", "c3");
    massHist->DrawClone();
    massHist_cut->DrawClone("same");

    TCanvas *c4 = new TCanvas("c4","c4");
    massHist_cut->DrawClone();
    sigHist_cut->DrawClone("same");
    bkgHist_cut->DrawClone("same");

    
}