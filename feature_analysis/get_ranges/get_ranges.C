#include "TString.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TCut.h"

#include <iostream>

void get_ranges()
{
    TString WS1_inputFileName = getenv("CURRENT_WS1_DATASET");
    TString MC_inputFileName = getenv("CURRENT_MC_DATASET");

    TFile *mc_file = new TFile(WS1_inputFileName);
    TFile *ws_file = new TFile(MC_inputFileName);

    TTree *mc_tree = (TTree *)mc_file->Get("DecayTree");
    TTree *ws_tree = (TTree *)ws_file->Get("DecayTree");

    std::vector<TString> features{
        "Kbach_PT",
        "Kbach_ProbNNk"
        // "Lc_PT",
        // "pibach_PT",
        // "pibach_ProbNNpi",
        // "Xicst_IPCHI2_OWNPV",
        // "Lc_IPCHI2_OWNPV",
        // "Xicst_FDCHI2_OWNPV",
        // "Xicst_ENDVERTEX_CHI2",
        // "pibach_IPCHI2_OWNPV",
        // "Kbach_IPCHI2_OWNPV"
    };

    for (auto feature : features)
    {
        TCanvas *c_sig, *c_bkg;

        TString c_name_sig = feature + (TString) "sig_canvas";
        TString c_name_bkg = feature + (TString) "bkg_canvas";

        c_sig = new TCanvas(c_name_sig, "Signal feature");
        c_bkg = new TCanvas(c_name_bkg, "Background feature");

        std::cout << "Processing " << feature << std::endl;

        // TString cut = feature+(TString)"<100";

        c_sig->cd();
        mc_tree->Draw(feature);
        c_sig->Draw();

        c_bkg->cd();
        ws_tree->Draw(feature);
        c_bkg->Draw();
    }

    mc_file->Close();
    ws_file->Close();
}