#include "draw.h"

int draw_features(Search &sig, Search &ws1, Search &ws2)
{
    // std::map<TString, std::vector<TString>> particles;
    // std::set<TString> unique_features;

    // sig.GetTree(Search::input)->GetEntry(3);

    // for (auto [particle_name, particle] : sig.particles)
    // {
    //     for (auto feature : particle.features)
    //     {
    //         if (unique_features.insert(particle_name + feature.first).second)
    //         {
    //             std::cout << particle_name << feature.first << std::endl;
    //             particles[particle_name].push_back(feature.first);
    //         }
    //     }
    // }
    // for (auto [name, feat] : sig.globals)
    // {
    //     std::cout << name << " " << feat << std::endl;
    // }
    
    // // std::cout << ws2.GetTree(Search::input) << std::endl;

    TCanvas c1("c1", "A Simple Graph Example", 200, 10, 700, 500);
    TH1D h1("temp", "Aacca", 1000, 2000, 5000);

    ws2.GetTree(Search::input)->Draw("Lc_M >> temp");
    ws1.GetTree(Search::input)->SetLineColor(kRed);
    ws1.GetTree(Search::input)->Draw("Lc_M", "", "SAME");

    c1.Write();

    return 0;
};