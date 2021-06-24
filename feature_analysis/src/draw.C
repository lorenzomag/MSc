#include "pch.h"
#include "search.h"
#include "main.h"
#include "draw.h"

void draw_features(Search &sig, Search &ws1, Search &ws2)
{
    std::map<TString, std::vector<TString>> particles;
    std::set<TString> unique_features;

    for (auto [particle_name, particle] : sig.particles)
    {
        for (auto feature : particle.features)
        {
            if (unique_features.insert(particle_name + feature.first).second)
            {
                std::cout << particle_name << feature.first << " = " << feature.second << std::endl;
                particles[particle_name].push_back(feature.first);
            }
        }
    }
    for (auto [name, feat] : sig.globals)
    {
        std::cout << name << " " << feat << std::endl;
    }

    TObjArray Clist(0);
    TCanvas *c1 = new TCanvas("temp", "temp", 0, 0, 300, 200);
    TH1D *h1 = new TH1D("sig", "temp", 1000, 0, 100);
    TH1D *h2 = new TH1D("bkg1", "temp", 1000, 0, 100);
    TH1D *h3 = new TH1D("bkg2", "temp", 1000, 0, 100);

    h1->SetLineColor(kBlack);
    h2->SetLineColor(kRed);
    h2->SetLineColor(kGreen);

    sig.GetTree(Search::input)->Draw("Xicst_ENDVERTEX_CHI2>>sig");
    ws1.GetTree(Search::input)->Draw("Xicst_ENDVERTEX_CHI2>>bkg1");
    ws2.GetTree(Search::input)->Draw("Xicst_ENDVERTEX_CHI2>>bkg2");

    // float scaleFactor2 = h1->GetEntries() / h2->GetEntries();
    // float scaleFactor3 = h1->GetEntries() / h3->GetEntries();
    float scaleFactor23 = h2->GetEntries() / h3->GetEntries();

    // h2->Scale(scaleFactor2);
    h3->Scale(scaleFactor23);

    h2->Draw();
    h3->Draw("SAME");
    c1->Write();
    c1->Clear();

    // ws1.GetTree(Search::input)->SetLineColor(kGreen);
    // sig.GetTree(Search::input)->SetLineColor(kRed);

    // ws1.GetTree(Search::input)->Draw("Lc_M");
    // sig.GetTree(Search::input)->Draw("Lc_M", "", "SAME");
    // c1->Write();

    // for (TString feature : unique_features)
    // {

    //     TString name1 = feature + ">>sig";
    //     TString name2 = feature + ">>bgk";

    //     h1->SetLineColor(kBlack);
    //     h2->SetLineColor(kRed);
    //     std::cout << name1 << std::endl << name2 << std::endl;

    //     sig.GetTree(Search::input)->Draw(feature);
    //     ws1.GetTree(Search::input)->Draw(feature);

    //     float scaleFactor = h1->GetEntries() / h2->GetEntries();

    //     h2->Scale(scaleFactor);

    //     h2->Draw();
    //     h1->Draw("SAME");
    //     h1->Write();
    //     h2->Write();

    //     delete h1;
    //     delete h2;
    // }

    // TH1D hist("asd", "fe ", 100, 10, 20);

#ifndef run_with_root

    delete c1;
    // gDirectory->GetList()->ls();

#endif
};