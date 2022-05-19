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

void setStyles(TH1 *ws1, TH1 *ws2, TH1 *ws3);

void feature_comp(std::string method = "MLP", const double cut = 0.89)
{
    ROOT::EnableImplicitMT();

    std::ifstream settings_file("feature_settings.json");
    json js;
    settings_file >> js;

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

    gSystem->Exec("mkdir -p figures");

    TCanvas *c = new TCanvas("", "");
    c->Divide(3, 3);
    //  Make Hists
    int c_counter = 0;
    ROOT::RDF::RResultPtr<TH1D> ws1_hist;
    ROOT::RDF::RResultPtr<TH1D> ws2_hist;
    ROOT::RDF::RResultPtr<TH1D> ws3_hist;
    for (auto feature : js["features"])
    {
        auto range = feature["range"];
        ROOT::RDF::TH1DModel hist_model = {"", "", 100, range[0], range[1]};
        std::string feature_name = feature["expr"];
        std::cout << feature_name.c_str() << std::endl;
        ws1_hist = ws1.Histo1D(hist_model, feature_name);
        ws2_hist = ws2.Histo1D(hist_model, feature_name);
        ws3_hist = ws3.Histo1D(hist_model, feature_name);

        ws1_hist->SetNameTitle("WS1", "WS1");
        ws2_hist->SetNameTitle("WS2", "WS2");
        ws3_hist->SetNameTitle("WS3", "WS3");
        setStyles(ws1_hist.GetPtr(), ws2_hist.GetPtr(), ws3_hist.GetPtr());

        // Normalised to WS1
        Double_t factor = ws1_hist->Integral();
        ws1_hist->Scale(factor / ws1_hist->Integral());
        ws2_hist->Scale(factor / ws2_hist->Integral());
        ws3_hist->Scale(factor / ws3_hist->Integral());

        // TCanvas *c3 = new TCanvas(Form("c2 - %s", feature_name.c_str()), Form("c2 - %s", feature_name.c_str()));
        c->cd(++c_counter);
        THStack *hs_before_norm = new THStack(Form("%s (Normalised to WS1)", feature_name.c_str()), Form("%s (Normalised to WS1)", feature_name.c_str()));
        hs_before_norm->Add(ws1_hist.GetPtr());
        hs_before_norm->Add(ws2_hist.GetPtr());
        hs_before_norm->Add(ws3_hist.GetPtr());
        hs_before_norm->DrawClone("nostack hist");
    }
    c->cd(9);
    TLegend *legend = new TLegend(0.1, 0.1, 0.9, 0.9);
    legend->AddEntry(ws1_hist.GetPtr());
    legend->AddEntry(ws2_hist.GetPtr());
    legend->AddEntry(ws3_hist.GetPtr());
    legend->DrawClone();
    c->Update();
    c->Print("figures/features_before.svg");
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