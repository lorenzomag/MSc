#include "pch.h"
#include "search.h"
#include "select_features.h"
#include "draw.h"

#include "main.h"
int main()
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
    sig.SetTree((TTree *)signalInputFile.Get("LcKPiTree/DecayTree"), Search::input, "LcKPiTree", "LcKPiTree");
    ws1.SetTree((TTree *)inputFile.Get("LcKPiTreeWS1/DecayTree"), Search::input, "LcKPiTreeWS1", "LcKPiTreeWS1");
    ws2.SetTree((TTree *)inputFile.Get("LcKPiTreeWS2/DecayTree"), Search::input, "LcKPiTreeWS2", "LcKPiTreeWS2");

    // Set output trees
    TFile outputFile(outputFileName, "RECREATE");

    std::vector<Search *> searches = {&sig, &ws1, &ws2};

    TBranch *currentBranch;
    TObjArray *branches;

    for (Search *current_search : searches)
    {
        auto is_MC = current_search->GetName() == "Sig" ? true : false;
        bool has_TRUEID = false;
        bool has_ID = false;
        bool has_M = false;
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
            }
            if (!has_M)
            {
                input_tree->SetBranchStatus("Xicst_M", 1);
            }
            if (is_MC)
            {
                std::cout << "[INFO] Checking for presence of truth branches." << std::endl;
                input_tree->SetBranchAddress("Xicst_ID", &Xicst_ID);

                if (!has_TRUEID)
                {
                    input_tree->SetBranchStatus("Xicst_TRUEID", 1);
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
            if ((is_MC && (Xicst_TRUEID == Xicst_ID)) || !is_MC)
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

    draw_features(sig, ws1, ws2);

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
