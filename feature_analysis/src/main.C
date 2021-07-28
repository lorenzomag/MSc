#include "pch.h"
#include "search.h"
#include "select_features.h"
#include "draw.h"
// #include "settings_selection.hpp"

#include "main.h"

bool truth_match = false;

// namespace setting = settings_selection;
// extern int setting::version;
int main(int ac, char **av)
{

    json j_db = select_features(feat_source::default_values);

    Search sig(j_db, "Sig", "-+");
    Search ws1(j_db, "Ws1", "+-");
    Search ws2(j_db, "Ws2", "++");

    TString signalInputFileName, inputFileName, outputFileName, exe_dir;
    set_file_names(signalInputFileName, inputFileName, exe_dir, outputFileName);

    TFile inputFile(inputFileName, "READ");
    if (inputFile.IsOpen())
    {
        std::cout << "Reading data from " << inputFileName << " for background data." << std::endl;
    }
    else
    {
        std::cout << "[ERROR] Input file " << inputFileName << " could not be found." << std::endl;
        exit(3);
    }

    TFile signalInputFile(signalInputFileName, "READ");
    if (signalInputFile.IsOpen())
    {
        std::cout << "Reading data from " << signalInputFileName << " for signal data." << std::endl;
    }
    else
    {
        std::cout << "[ERROR] Input file " << signalInputFileName << " could not be found." << std::endl;
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
            case set::type::signal:
                std::cout << "SIGNAL is in" << std::endl;
                tree_name = "LcKPiTree/DecayTree";
                if (signalInputFile.Get(tree_name))
                    sig.SetTree((TTree *)signalInputFile.Get(tree_name), Search::input, "LcKPiTree", "LcKPiTree");
                else if (inputFile.Get("DecayTree"))
                    sig.SetTree((TTree *)signalInputFile.Get("DecayTree"), Search::input, "LcKPiTree", "LcKPiTree");
                else
                    return (-1);

                searches.push_back(&sig);
                break;
            case set::type::ws1:
                tree_name = "LcKPiTreeWS1/DecayTree";
                if (inputFile.Get(tree_name))
                    ws1.SetTree((TTree *)inputFile.Get(tree_name), Search::input, "LcKPiTreeWS1", "LcKPiTreeWS1");
                else if (inputFile.Get("DecayTree"))
                    ws1.SetTree((TTree *)inputFile.Get("DecayTree"), Search::input, "LcKPiTreeWS1", "LcKPiTreeWS1");
                else
                    return (-1);

                std::cout << "WS1 is in" << std::endl;
                searches.push_back(&ws1);
                break;
            case set::type::ws2:
                tree_name = "LcKPiTreeWS2/DecayTree";
                if (inputFile.Get(tree_name))
                    ws2.SetTree((TTree *)inputFile.Get(tree_name), Search::input, "LcKPiTreeWS2", "LcKPiTreeWS2");
                else if (inputFile.Get("DecayTree"))
                    ws2.SetTree((TTree *)inputFile.Get("DecayTree"), Search::input, "LcKPiTreeWS2", "LcKPiTreeWS2");
                else
                    return (-1);
                searches.push_back(&ws2);
                std::cout << "WS2 is in" << std::endl;
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
        bool has_ID = false;
        bool has_M = false;
        bool has_MassID = false;
        int Xicst_TRUEID, Xicst_ID;

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
                    if (full_feature_name == "Xicst_ID")
                        has_ID = true;
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

            if (!has_ID)
            {
                input_tree->SetBranchStatus("Xicst_ID", 1);
                std::cout << "[INFO] Xicst_ID added\n";
            }
            if (!has_M)
            {
                input_tree->SetBranchStatus("Xicst_M", 1);
                std::cout << "[INFO] Xicst_M added\n";
            }
            if (is_MC)
            {
                std::cout << "[INFO] Checking for presence of truth branches." << std::endl;
                input_tree->SetBranchAddress("Xicst_ID", &Xicst_ID);
                if (!has_MassID)
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
            if ((is_MC && (truth_match && Xicst_TRUEID == Xicst_ID)) || !is_MC || !truth_match)
            {
                output_tree->Fill();
            }

            if (i % 20000 == 0)
            {
                std::cout << (double)i * 100 / n_entries << "% : " << i << "/" << n_entries << std::endl;
            }
        }

        output_tree->Write();
    }

    bool is_sig = set::use.at(set::type::signal);
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

    inputFile.Close();
    outputFile.Close();

    return 0;
}

void set_file_names(TString &signalFileName, TString &bkgInputFileName, TString &exe_dir, TString &outputFileName)
{
    TString defaultName = "/home/loren/MSc/datasets/MC_Xi_DecFile26265970_Beam6500GeV-2016-MagDown-Nu1.6-25ns-Pythia8.root";

    bkgInputFileName = getenv("CURRENT_BKG_DATASET");
    if (!bkgInputFileName)
    {
        std::cout << bkgInputFileName << " could not be found." << std::endl;
        bkgInputFileName = defaultName;
        std::cout << "Using default file name: " << bkgInputFileName << std::endl;
    }

    signalFileName = getenv("CURRENT_SIG_DATASET");
    if (!signalFileName)
    {
        std::cout << signalFileName << " could not be found." << std::endl;
        signalFileName = defaultName;
        std::cout << "Using default file name: " << signalFileName << std::endl;
    }

    outputFileName = "features.root";
}
