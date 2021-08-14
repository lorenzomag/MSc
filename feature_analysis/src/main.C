#include "pch.h"
#include "search.h"
#include "select_features.h"
#include "draw.h"
// #include "settings_selection.hpp"

#include "main.h"

bool truth_match = true;
bool has_masses = false;

int main(int ac, char **av)
{

    json j_db = select_features(feat_source::default_values);

    Search sig(j_db, "MC", "-+");
    Search ws1(j_db, "Ws1", "+-");
    Search ws2(j_db, "Ws2", "++");

    TString MC_inputFileName, WS1_inputFileName,  WS2_inputFileName, outputFileName, exe_dir;
    set_file_names(MC_inputFileName, WS1_inputFileName, WS2_inputFileName, exe_dir, outputFileName);


    TFile MC_inputFile(MC_inputFileName, "READ");
    if (MC_inputFile.IsOpen())
    {
        std::cout << "Reading data from " << MC_inputFileName << " for signal data." << std::endl;
    }
    else
    {
        std::cout << "[ERROR] Input file " << MC_inputFileName << " could not be found." << std::endl;
        exit(3);
    }

    TFile WS1_inputFile(WS1_inputFileName, "READ");
    if (WS1_inputFile.IsOpen())
    {
        std::cout << "Reading data from " << WS1_inputFileName << " for background data." << std::endl;
    }
    else
    {
        std::cout << "[ERROR] Input file " << WS1_inputFileName << " could not be found." << std::endl;
        exit(3);
    }
    
    TFile WS2_inputFile(WS2_inputFileName, "READ");
    if (WS2_inputFile.IsOpen())
    {
        std::cout << "Reading data from " << WS2_inputFileName << " for background data." << std::endl;
    }
    else
    {
        std::cout << "[ERROR] Input file " << WS2_inputFileName << " could not be found." << std::endl;
        exit(3);
    }

    // Get input trees
    std::vector<Search *> searches;
    for (auto search : set::use)
    {
        TString tree_name;
        if (search.second)
        {
            switch (search.first)
            {
            case set::type::MC:
                tree_name = "LcKPiTree/DecayTree";
                if (MC_inputFile.Get(tree_name))
                    sig.SetTree((TTree *)MC_inputFile.Get(tree_name), Search::input, "LcKPiTree", "LcKPiTree");
                else if (MC_inputFile.Get("DecayTree"))
                    sig.SetTree((TTree *)MC_inputFile.Get("DecayTree"), Search::input, "LcKPiTree", "LcKPiTree");
                else
                    return (-1);

                searches.push_back(&sig);
                break;
            case set::type::ws1:
                tree_name = "LcKPiTreeWS1/DecayTree";
                if (WS1_inputFile.Get(tree_name))
                    ws1.SetTree((TTree *)WS1_inputFile.Get(tree_name), Search::input, "LcKPiTreeWS1", "LcKPiTreeWS1");
                else if (WS1_inputFile.Get("DecayTree"))
                    ws1.SetTree((TTree *)WS1_inputFile.Get("DecayTree"), Search::input, "LcKPiTreeWS1", "LcKPiTreeWS1");
                else
                    return (-1);

                searches.push_back(&ws1);
                break;
            case set::type::ws2:
                tree_name = "LcKPiTreeWS2/DecayTree";
                if (WS2_inputFile.Get(tree_name))
                    ws2.SetTree((TTree *)WS2_inputFile.Get(tree_name), Search::input, "LcKPiTreeWS2", "LcKPiTreeWS2");
                else if (WS2_inputFile.Get("DecayTree"))
                    ws2.SetTree((TTree *)WS2_inputFile.Get("DecayTree"), Search::input, "LcKPiTreeWS2", "LcKPiTreeWS2");
                else
                    return (-1);
                searches.push_back(&ws2);
                break;
            }
        }
    }

    // Set output trees
    TFile outputFile(outputFileName, "RECREATE");

    TBranch *currentBranch;
    TObjArray *branches;

    for (Search *current_search : searches)
    {
        auto is_MC = current_search->GetName() == "Sig" ? true : false;
        bool has_TRUEID = false;
        bool has_M = false;
        bool has_MassID = false;
        int Xicst_TRUEID;

        TTree *input_tree = current_search->GetTree(Search::input);
        input_tree->SetBranchStatus("*", 0);

        branches = input_tree->GetListOfBranches();
        std::cout << std::endl;
        current_search->GetWSDescription();

        for (auto &feature : current_search->globals)
        {
            currentBranch = (TBranch *)branches->FindObject(feature);
            if (currentBranch)
            {
                input_tree->SetBranchStatus(feature, 1);
                std::cout << "[INFO] " << feature << " added" << std::endl;
            }
        }

        for (auto &particle : current_search->particles)
        {

            TString particle_name = particle.first;
            std::cout << std::endl
                      << particle_name << std::endl;
            std::cout << "============" << std::endl;

            std::vector<TString> &feature_vector = current_search->particles[particle_name].features;
            std::vector<TString> to_remove;
            for (auto feature : feature_vector)
            {
                TString full_feature_name = particle_name + feature;

                currentBranch = (TBranch *)branches->FindObject(full_feature_name);

                if (currentBranch)
                {
                    input_tree->SetBranchStatus(full_feature_name, 1);
                    std::cout << "[INFO] " << full_feature_name << " added " << std::endl;

                    if (full_feature_name == "Xicst_TRUEID")
                        has_TRUEID = true;
                    if (full_feature_name == "Xicst_M")
                        has_M = true;
                    if (full_feature_name == "Xicst_MassID")
                        has_MassID = true;
                }
                else
                {
                    to_remove.push_back(feature);
                }
            }

            std::cout << std::endl;
            for (auto feature_it = to_remove.begin(); feature_it != to_remove.end(); feature_it++)
            {
                auto pos = std::find(feature_vector.begin(), feature_vector.end(), *feature_it);
                if (pos != feature_vector.end())
                {
                    std::cout << "[WARNING] " << particle_name << *feature_it << " is not a valid branch; ignored." << std::endl;
                    feature_vector.erase(pos);
                }
            }


            if (!has_M)
            {
                input_tree->SetBranchStatus("Xicst_M", 1);
                std::cout << "[INFO] Xicst_M added\n";
            }
            if (is_MC)
            {
                std::cout << "[INFO] Checking for presence of truth branches." << std::endl;
                
                if (!has_MassID && has_masses)
                {
                    input_tree->SetBranchStatus("Xicst_MassID", 1);
                    std::cout << "[INFO] Xicst_MassID added\n";
                }

                if (!has_TRUEID)
                {
                    input_tree->SetBranchStatus("Xicst_TRUEID", 1);
                    std::cout << "[INFO] Xicst_TRUEID added\n";
                    input_tree->SetBranchAddress("Xicst_TRUEID", &Xicst_TRUEID);
                }
            }
        }

        std::cout << "\n[INFO] Filling output trees" << std::endl;
        TTree *output_tree = current_search->SetTree(input_tree->CloneTree(0), Search::clone);

        auto n_entries = input_tree->GetEntries();

        for (int i = 0; i < n_entries; i++)
        {
            input_tree->GetEntry(i);
            if ((is_MC && (truth_match && abs(Xicst_TRUEID) == 4214)) || !is_MC || !truth_match)
            {
                output_tree->Fill();
            }

            if (i % 50000 == 0)
            {
                std::cout << (double)i * 100 / n_entries << "% : " << i << "/" << n_entries << std::endl;
            }
        }

        output_tree->Write();
    }

    bool is_sig = set::use.at(set::type::MC);
    bool is_ws1 = set::use.at(set::type::ws1);
    bool is_ws2 = set::use.at(set::type::ws2);

    if (is_sig && is_ws1 && is_ws2)
        draw_features(sig, ws1, ws2);
    else if (is_sig && is_ws1 && !is_ws2)
        draw_features(sig, ws1);
    else if (is_sig && is_ws2 && !is_ws1)
        draw_features(sig, ws2);
    else
        std::cout << "For the output file to be populated by histograms,"
                     " a signal tree and at least a Wrong Sign background tree must be properly provided.";

    MC_inputFile.Close();
    WS1_inputFile.Close();
    WS2_inputFile.Close();
    outputFile.Close();

    return 0;
}

void set_file_names(TString &MC_inputFileName, TString &WS1_inputFileName, TString &WS2_inputFileName, TString &exe_dir, TString &outputFileName)
{
    TString defaultName = "/home/loren/MSc/datasets/MC_Xi_DecFile26265970_Beam6500GeV-2016-MagDown-Nu1.6-25ns-Pythia8.root";

    WS1_inputFileName = getenv("CURRENT_WS1_DATASET");
    if (!WS1_inputFileName)
    {
        std::cout << WS1_inputFileName << " could not be found." << std::endl;
        WS1_inputFileName = defaultName;
        std::cout << "Using default file name: " << WS1_inputFileName << std::endl;
    }

    WS2_inputFileName = getenv("CURRENT_WS2_DATASET");
    if (!WS2_inputFileName)
    {
        std::cout << WS2_inputFileName << " could not be found." << std::endl;
        WS2_inputFileName = defaultName;
        std::cout << "Using default file name: " << WS2_inputFileName << std::endl;
    }

    MC_inputFileName = getenv("CURRENT_MC_DATASET");
    if (!MC_inputFileName)
    {
        std::cout << MC_inputFileName << " could not be found." << std::endl;
        MC_inputFileName = defaultName;
        std::cout << "Using default file name: " << MC_inputFileName << std::endl;
    }

    outputFileName = "features.root";
}
