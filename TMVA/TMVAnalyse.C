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

void TMVAnalyse(const int FEATURE_SET = 9, const int HYPERPARAM_SET = 1)
{
    ROOT::EnableImplicitMT();

    TFile *file = new TFile(getenv("CURRENT_APPLICATION_DATASET"));
    TTree *tree = (TTree *)file->Get("DecayTree");

    tree->AddFriend("mva_response", Form("runs/run_fs%d_hp%d/TMVApp.root", FEATURE_SET, HYPERPARAM_SET));

    RDataFrame ds(*tree);

    auto sig = ds.Filter("data_type == 0");
    auto bkg = ds.Filter("data_type == 1");
    auto ds_app = ds.Filter("MVA_BDTG > 0.94").Filter("MassID == 1");

        auto massHist = ds_app.Histo1D("Xicst_M");
    auto sigHist = sig.Histo1D("Xicst_M");
    auto bkgHist = bkg.Histo1D("Xicst_M");

    // TCanvas *c1 = new TCanvas("c1","c3");
    TCanvas *c2 = new TCanvas("c2", "c4");

    // massHist->DrawClone();
    // sigHist->DrawClone();
    massHist->DrawClone();
}