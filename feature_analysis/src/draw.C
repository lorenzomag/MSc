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

    TCanvas *c1 = new TCanvas("Overlap", "Overlapping histograms", 0, 0, 300, 200);
    // TH1D h1("temp", "Aacca", 5000, 2000, 5000);
    // TH1D h2("temp2", "Aacca2", 5000, 2000, 5000);
    ws1.GetTree(Search::input)->SetLineColor(kBlack);
    ws2.GetTree(Search::input)->SetLineColor(kBlue);

    ws2.GetTree(Search::input)->Draw("Lc_M");
    ws1.GetTree(Search::input)->Draw("Lc_M", "", "SAME");

    // h1.Draw();
    // h2.Draw("same");
    c1->Write();
    c1->Clear();
    c1->SetName("ciao");

    ws1.GetTree(Search::input)->SetLineColor(kGreen);
    ws2.GetTree(Search::input)->SetLineColor(kRed);

    ws1.GetTree(Search::input)->Draw("Lc_M");
    ws2.GetTree(Search::input)->Draw("Lc_M", "", "SAME");
    c1->Write();

    // h1.Write();
    // h2.Write();

    TH1D hist("asd", "fe ", 100, 10, 20);


#ifndef run_with_root

    // gDirectory->GetList()->ls();

    delete c1;
#endif
};