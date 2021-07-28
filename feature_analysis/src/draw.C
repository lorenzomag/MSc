#include "pch.h"
#include "search.h"
#include "draw.h"
#include "ROOT/RDataFrame.hxx"

#include "lhcbStyle.C"
using namespace ROOT;

std::vector<double> masses = {2942, 2964.3, 3055.9, 3077.2};
std::vector<EColor> colours = {kBlue, kRed, kGreen, kTeal};
bool has_masses = true;

void draw_features(Search &sig, Search &bkg)
{
    set_style();
    std::cout << std::endl
              << "Plotting feature comparisons between Signal and possible background sources (WS1 and/or WS2)" << std::endl;
    std::map<TString, std::vector<TString>> particles;
    std::set<TString> unique_features;

    for (auto particle : bkg.particles)
    {
        auto particle_name = particle.first;
        auto particle_instance = particle.second;
        for (auto feature : particle_instance.features)
        {
            if (unique_features.insert(particle_name + feature).second)
            {
                particles[particle_name].push_back(feature);
            }
        }
    }

    if (has_masses)
        particles["Xicst"].push_back("_MassID");

    RDataFrame sig_df(*sig.GetTree(Search::output));
    RDataFrame bkg_df(*bkg.GetTree(Search::output));
    TCanvas *c1 = new TCanvas("temp", "temp", 900, 700);

    RDF::RResultPtr<TH1D> sigHist;
    RDF::RResultPtr<TH1D> bkgHist;

    for (auto particle : particles)
    {
        std::cout << std::endl
                  << "Scanning particle " << particle.first << std::endl;
        gDirectory->mkdir(particle.first);
        gDirectory->cd(particle.first);
        if (has_masses)
            gDirectory->mkdir("masses");

        for (auto feature_name : particle.second)
        {
            std::vector<RDF::RResultPtr<TH1D>> massHists;
            auto feature = particle.first + feature_name;
            if (feature == "Xicst_MassID")
                continue;
            std::cout << "Producting plots for " << feature << std::endl;

            THStack *hsBkg = new THStack("hsBkg", feature);
            c1->SetName(feature);
            c1->SetTitle(feature);

            auto x_min = sig_df.Min(feature).GetValue();
            auto x_max = sig_df.Max(feature).GetValue();

            if (feature.Contains("CHI2"))
            {
                // std::cout << feature << " contains Chi2" << std::endl;
                std::string filter_req = (std::string)feature + ">= 0";
                sigHist = sig_df.Filter(filter_req).Histo1D({"", "", 600, 0, 0}, feature);
                bkgHist = bkg_df.Filter(filter_req).Histo1D({"", "", 600, 0, 0}, feature);
            }
            else
            {
                sigHist = sig_df.Histo1D({"", "", 600, 0, 0}, feature);
                bkgHist = bkg_df.Histo1D({"", "", 600, 0, 0}, feature);
            }
            sigHist->SetLineColor(kBlack);
            bkgHist->SetLineColor(kRed);

            sigHist->SetNameTitle("Signal", "Signal");
            bkgHist->SetNameTitle("Background", "Background");

            bkgHist->Scale(sigHist->GetEntries() / bkgHist->GetEntries());

            hsBkg->Add(sigHist.GetPtr());
            hsBkg->Add(bkgHist.GetPtr(), "HIST");

            hsBkg->Draw("nostack");
            gPad->BuildLegend(0.6, 0.7, 0.9, 0.9);

            c1->Write();
            // c1->BuildLegend();
            delete hsBkg;

            c1->Clear();

            if (has_masses)
            {
                // /// ------- MASSES

                gDirectory->cd("masses");

                THStack *hsMasses = new THStack("hsMasses", feature);
                auto name_title = feature + " (mass comparison)";
                c1->SetName(name_title);
                c1->SetTitle(name_title);
                // hsMasses->SetNameTitle(name_title, name_title);

                hsMasses->Add(sigHist.GetPtr());

                int i = 0;
                for (auto mass : masses)
                {

                    std::string mass_cut = (std::string) "Xicst_MassID == " + std::to_string(mass);
                    auto mass_df = sig_df.Filter(mass_cut);
                    if (feature.Contains("CHI2"))
                    {
                        // std::cout << feature << " contains Chi2" << std::endl;
                        std::string filter_req = (std::string)feature + ">= 0";
                        massHists.push_back(mass_df.Filter(filter_req).Histo1D({"", "", 600, 0, 0}, feature));
                    }
                    else
                    {
                        massHists.push_back(mass_df.Histo1D({"", "", 600, 0, 0}, feature));
                    }
                    std::string mass_title = std::to_string(mass) + (std::string) " MeV";
                    massHists[i]->SetNameTitle(mass_title.c_str(), mass_title.c_str());
                    massHists[i]->SetLineColor(colours[i]);
                    massHists[i]->Scale(sigHist->GetEntries() / massHists[i]->GetEntries());

                    hsMasses->Add(massHists[i].GetPtr(), "HIST");

                    i++;
                }

                hsMasses->Draw("nostack");
                gPad->BuildLegend(0.6, 0.7, 0.9, 0.9);
                gPad->Modified();
                gPad->Update();


                c1->Write();
                // c1->BuildLegend();
                delete hsMasses;

                c1->Clear();
                gDirectory->cd("../");
            }
        }
        gDirectory->cd("../");
    }

    delete c1;
};

void draw_features(Search &sig, Search &ws1, Search &ws2)
{

    std::cout << std::endl
              << "Plotting feature comparisons between Signal and possible background sources (WS1 and WS2)" << std::endl;
    std::map<TString, std::vector<TString>> particles;
    std::set<TString> unique_features;

    for (auto particle : ws1.particles)
    {
        auto particle_name = particle.first;
        auto particle_instance = particle.second;
        for (auto feature : particle_instance.features)
        {
            if (unique_features.insert(particle_name + feature).second)
            {
                particles[particle_name].push_back(feature);
            }
        }
    }

    RDataFrame sig_df(*sig.GetTree(Search::output));
    RDataFrame ws1_df(*ws1.GetTree(Search::output));
    RDataFrame ws2_df(*ws2.GetTree(Search::output));
    TCanvas *c1 = new TCanvas("temp", "temp", 1000, 2000);

    RDF::RResultPtr<TH1D> sigHist;
    RDF::RResultPtr<TH1D> bkgHist1;
    RDF::RResultPtr<TH1D> bkgHist2;

    for (auto particle : particles)
    {
        std::cout << std::endl
                  << "Scanning particle " << particle.first << std::endl;
        gDirectory->mkdir(particle.first);
        gDirectory->cd(particle.first);

        for (auto feature_name : particle.second)
        {
            c1->Divide(1, 3);
            auto feature = particle.first + feature_name;
            std::cout << "Producting plots for " << feature << std::endl;

            THStack *hsBkg = new THStack("hsBkg", feature);
            THStack *hsWS1 = new THStack("hsWS1", feature);
            THStack *hsWS2 = new THStack("hsWS2", feature);
            c1->SetName(feature);
            c1->SetTitle(feature);

            auto x_min = sig_df.Min(feature).GetValue();
            auto x_max = sig_df.Max(feature).GetValue();

            if (feature.Contains("CHI2"))
            {
                // std::cout << feature << " contains Chi2" << std::endl;
                std::string filter_req = (std::string)feature + ">= 0";
                sigHist = sig_df.Filter(filter_req).Histo1D({"", "", 1000, 0, 0}, feature);
                bkgHist1 = ws1_df.Filter(filter_req).Histo1D({"", "", 1000, 0, 0}, feature);
                bkgHist2 = ws2_df.Filter(filter_req).Histo1D({"", "", 1000, 0, 0}, feature);
            }
            else
            {
                sigHist = sig_df.Histo1D({"", "", 1000, 0, 0}, feature);
                bkgHist1 = ws1_df.Histo1D({"", "", 1000, 0, 0}, feature);
                bkgHist2 = ws2_df.Histo1D({"", "", 1000, 0, 0}, feature);
            }
            sigHist->SetLineColor(kBlack);
            bkgHist1->SetLineColor(kRed);
            bkgHist2->SetLineColor(kGreen);

            // sigHist->SetLineWidth();
            // bkgHist1->SetLineWidth(2);
            // bkgHist2->SetLineWidth(2);

            sigHist->SetNameTitle("Signal", "Signal");
            bkgHist1->SetNameTitle("WS1", "Wrong Sign 1");
            bkgHist2->SetNameTitle("WS2", "Wrong Sign 2");

            bkgHist1->Scale(sigHist->GetEntries() / bkgHist1->GetEntries());
            bkgHist2->Scale(sigHist->GetEntries() / bkgHist2->GetEntries());

            hsWS1->Add(sigHist.GetPtr());
            hsWS1->Add(bkgHist1.GetPtr(), "HIST");

            hsWS2->Add(sigHist.GetPtr());
            hsWS2->Add(bkgHist2.GetPtr(), "HIST");

            hsBkg->Add(bkgHist1.GetPtr(), "HIST");
            hsBkg->Add(bkgHist2.GetPtr(), "HIST");

            c1->cd(1);
            hsWS1->Draw("nostack");
            gPad->BuildLegend(0.8, 0.7, 0.9, 0.9);
            c1->cd(2);
            hsWS2->Draw("nostack");
            gPad->BuildLegend(0.8, 0.7, 0.9, 0.9);
            c1->cd(3);
            hsBkg->Draw("nostack");
            gPad->BuildLegend(0.8, 0.7, 0.9, 0.9);

            c1->Write();
            // c1->BuildLegend();
            delete hsWS1;
            delete hsWS2;
            delete hsBkg;

            c1->Clear();
            std::cout << std::endl;
        }
        gDirectory->cd("../");
    }

    delete c1;
};