#include "pch.h"
#include "search.h"
#include "main.h"
#include "draw.h"
#include "ROOT/RDataFrame.hxx"

using namespace ROOT;

void draw_features(Search &sig, Search &ws1, Search &ws2)
{
    RDF::RResultPtr<TH1D> aaas();
    std::cout << std::endl
              << "Plotting feature comparisons between Signal and possible background sources (WS1 and WS2)" << std::endl;
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

    RDataFrame sig_df(*sig.GetTree(Search::input));
    RDataFrame ws1_df(*ws1.GetTree(Search::input));
    RDataFrame ws2_df(*ws2.GetTree(Search::input));

    TCanvas *c1 = new TCanvas("temp", "temp", 300, 300, 500, 500);
    RDF::RResultPtr<TH1D> sigHist;
    RDF::RResultPtr<TH1D> bkgHist1;
    RDF::RResultPtr<TH1D> bkgHist2;

    for (auto feature : unique_features)
    {
        std::cout << "Producting plots for " << feature << std::endl;
        THStack *hs = new THStack("hs", "temp");
        c1->SetName(feature);
        c1->SetTitle(feature);
        hs->SetTitle(feature);

        if (feature.Contains("CHI2"))
        {
            std::cout << feature << " contains Chi2" << std::endl;
            std::string filter_req = (std::string)feature + ">0";
            sigHist = sig_df.Filter(filter_req).Histo1D(feature);
            bkgHist1 = ws1_df.Filter(filter_req).Histo1D(feature);
            bkgHist2 = ws2_df.Filter(filter_req).Histo1D(feature);
        }
        else
        {
            sigHist = sig_df.Histo1D(feature);
            bkgHist1 = ws1_df.Histo1D(feature);
            bkgHist2 = ws2_df.Histo1D(feature);
        }
        sigHist->SetLineColor(kBlack);
        bkgHist1->SetLineColor(kRed);
        bkgHist2->SetLineColor(kGreen);

        sigHist->SetNameTitle("Signal", "Signal");
        bkgHist1->SetNameTitle("WS1", "Wrong Sign 1");
        bkgHist2->SetNameTitle("WS2", "Wrong Sign 2");

        bkgHist1->Scale(sigHist->GetEntries() / bkgHist1->GetEntries());
        bkgHist2->Scale(sigHist->GetEntries() / bkgHist2->GetEntries());

        hs->Add(sigHist.GetPtr());
        hs->Add(bkgHist1.GetPtr(), "HIST");
        hs->Add(bkgHist2.GetPtr(), "HIST");

        // gStyle->SetOptStat(kFALSE);
        // sigHist->Draw();
        // bkgHist1->Draw("SAME HIST");
        // bkgHist2->Draw("SAME HIST");
        // htemp->Reset();
        hs->Draw("nostack");
        c1->BuildLegend();
        c1->Write();
        delete hs;

        c1->Clear();
    }

#ifndef run_with_root

    delete c1;
    // gDirectory->GetList()->ls();

#endif
};