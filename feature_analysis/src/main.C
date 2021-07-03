#include "pch.h"
#include "search.h"
#include "select_features.h"
#include "draw.h"

#include "main.h"
int main()
{
    json j_db = select_features(feat_source::from_file);

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
    sig.SetTree((TTree *)signalInputFile.Get("LcKPiTree/DecayTree"), Search::input,"LcKPiTree","LcKPiTree");
    ws1.SetTree((TTree *)inputFile.Get("LcKPiTreeWS1/DecayTree"), Search::input,"LcKPiTreeWS1","LcKPiTreeWS1");
    ws2.SetTree((TTree *)inputFile.Get("LcKPiTreeWS2/DecayTree"), Search::input,"LcKPiTreeWS2","LcKPiTreeWS2");

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
        int Xicst_TRUEID, Xicst_ID;

        TTree *input_tree = current_search->GetTree(Search::input);
        input_tree->SetBranchStatus("*", 0);

        branches = input_tree->GetListOfBranches();
        std::cout << std::endl;
        current_search->GetWSDescription();

        for (auto &feature : current_search->globals)
        {
            auto feat_name = feature.first;
            auto feat_val = feature.second;

            currentBranch = (TBranch *)branches->FindObject(feat_name);
            if (currentBranch)
            {
                // currentBranch->SetAddress(&feat_val);
                // current_search->GetTree(Search::output)->Branch(feat_name, &feat_val);
                input_tree->SetBranchStatus(feat_name, 1);
                std::cout << "[INFO] " << feat_name << " added at " << &feat_val << std::endl;
            }
        }

        for (auto &particle : current_search->particles)
        {

            TString particle_name = particle.first;
            std::cout << std::endl
                      << particle_name << std::endl;
            std::cout << "============" << std::endl;

            std::map<TString, double> &feature_map = current_search->particles[particle_name].features;
            std::vector<TString> to_remove;
            for (auto &feature : feature_map)
            {
                TString feature_name = feature.first;
                TString full_feature_name = particle_name + feature_name;

                currentBranch = (TBranch *)branches->FindObject(full_feature_name);

                if (currentBranch)
                {
                    // currentBranch->SetAddress(&feature.second);
                    // current_search->GetTree(Search::output)->Branch(full_feature_name, &feature.second);
                    input_tree->SetBranchStatus(full_feature_name, 1);
                    std::cout << "[INFO] " << full_feature_name << " added " << std::endl;

                    if (full_feature_name == "Xicst_TRUEID")
                        has_TRUEID = true;
                    if (full_feature_name == "Xicst_ID")
                        has_ID = true;
                }
                else
                {
                    to_remove.push_back(feature_name);
                }
            }

            std::cout << std::endl;
            for (auto feature : to_remove)
            {
                feature_map.erase(feature);
                std::cout << "[WARNING] " << particle_name << feature << " is not a valid branch; ignored." << std::endl;
            }

            if (is_MC)
            {
                std::cout << "[INFO] Checking for presence of truth branches." << std::endl;
                if (!has_ID)
                {
                    input_tree->SetBranchStatus("Xicst_ID", 1);
                    input_tree->SetBranchAddress("Xicst_ID", &Xicst_ID);
                }

                if (!has_TRUEID)
                {
                    input_tree->SetBranchStatus("Xicst_TRUEID", 1);
                    input_tree->SetBranchAddress("Xicst_TRUEID", &Xicst_TRUEID);
                }
            }
        }

        std::cout << "\nFilling output trees" << std::endl;
        TTree *output_tree = current_search->SetTree(input_tree->CloneTree(0), Search::clone);

        std::cout << output_tree << "  " << current_search->GetTree(Search::output) << std::endl;
        std::cout << output_tree << "  " << current_search->GetTree(Search::output) << std::endl;

        auto n_entries = input_tree->GetEntries();

        if (is_MC)
            std::cout << "Filling for " << current_search->GetName() << std::endl;
        for (int i = 0; i < n_entries; i++)
        {
            input_tree->GetEntry(i);
            if (Xicst_TRUEID == Xicst_ID)
            {
                output_tree->Fill();
            }

            if (i % 10000 == 0)
            {
                // std::cout << (double)i * 100 / n_entries << "% : " << i << "/" << n_entries << std::endl;
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
