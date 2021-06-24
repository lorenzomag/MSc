#include "pch.h"
#include "search.h"
#include "main.h"
#include "draw.h"

void draw_features(Search &sig, Search &ws1, Search &ws2)
{
    std::cout << std::endl << "Plotting feature comparisons between Signal and possible background sources (WS1 and WS2)" << std::endl;
    std::map<TString, std::vector<TString>> particles;
    std::set<TString> unique_features;

    for (auto [particle_name, particle] : sig.particles)
    {
        for (auto feature : particle.features)
        {
            if (unique_features.insert(particle_name + feature.first).second)
            {
                particles[particle_name].push_back(feature.first);
            }
        }
    }

    TObjArray Clist(0);

    TCanvas *c1 = new TCanvas("temp", "temp", 0, 0, 300, 200);
    TH1D *sigHist = new TH1D("Signal", "Signal", 1000, 0, 100);
    TH1D *bkgHist1 = new TH1D("WS1", "WS1", 1000, 0, 100);
    TH1D *bkgHist2 = new TH1D("WS2", "WS2", 1000, 0, 100);

    sigHist->SetLineColor(kBlack);
    bkgHist1->SetLineColor(kRed);
    bkgHist2->SetLineColor(kGreen + 1);

    for (auto feature : unique_features)
    {
        std::cout << "Producting plots for " << feature << std::endl;
        c1->SetTitle(feature);
        c1->SetName(feature);

        auto sigHistName = feature + ">>Signal";
        auto bkgHistName1= feature + ">>WS1";
        auto bkgHistName2 = feature + ">>WS2";
        
        // sigHist->SetTitle(feature);
        // bkgHist1->SetTitle(feature);
        // bkgHist2->SetTitle(feature);

        sig.GetTree(Search::input)->Draw(sigHistName);
        ws1.GetTree(Search::input)->Draw(bkgHistName1);
        ws2.GetTree(Search::input)->Draw(bkgHistName2);

        float scaleFactorSig_WS1 = sigHist->GetEntries() / bkgHist1->GetEntries();
        float scaleFactorSig_WS2 = sigHist->GetEntries() / bkgHist2->GetEntries();
        float scaleFactorWS1_WS2 = bkgHist1->GetEntries() / bkgHist2->GetEntries();

        bkgHist1->Scale(scaleFactorSig_WS1);
        bkgHist2->Scale(scaleFactorSig_WS2);

        sigHist->Draw();
        bkgHist1->Draw("SAME");
        bkgHist2->Draw("SAME");
        c1->BuildLegend();
        c1->Write();
        c1->Clear();
    }

#ifndef run_with_root

    delete c1;
    // gDirectory->GetList()->ls();

#endif
};