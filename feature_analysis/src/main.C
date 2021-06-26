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
    TFile signalInputFile(signalInputFileName, "READ");
    if (inputFile.IsOpen())
    {
        std::cout << "Reading data from " << inputFileName << std::endl;
    }
    else
    {
        std::cout << "[ERROR] Input file " << inputFileName << " could not be found." << std::endl;
        exit(3);
    }
    if (signalInputFile.IsOpen())
    {
        std::cout << "Reading data from " << inputFileName << std::endl;
    }
    else
    {
        std::cout << "[ERROR] Input file " << inputFileName << " could not be found." << std::endl;
        exit(3);
    }

    // Get input trees
    sig.SetTree((TTree *)signalInputFile.Get("LcKPiTree/DecayTree"), Search::input);
    ws1.SetTree((TTree *)inputFile.Get("LcKPiTreeWS1/DecayTree"), Search::input);
    ws2.SetTree((TTree *)inputFile.Get("LcKPiTreeWS2/DecayTree"), Search::input);

    // Set output trees
    TFile outputFile(outputFileName, "RECREATE");
    // sig.SetTree("FeaturesSig", "Features Tree for signal (Lc+ K- pi+)", Search::output);
    // ws1.SetTree("FeaturesWS1", "Features Tree for WS1 (Lc+ K+ pi-)", Search::output);
    // ws2.SetTree("FeaturesWS2", "Features Tree for WS2 (Lc+ K+ pi+)", Search::output);

    std::vector<Search *> searches = {&sig, &ws1}; //, &ws2};

    TBranch *currentBranch;
    TObjArray *branches;

    for (Search *current_search : searches)
    {
        branches = current_search->GetTree(Search::input)->GetListOfBranches();
        std::cout << std::endl;
        current_search->GetWSDescription();

        for (auto &[feat_name, feat_val] : current_search->globals)
        {
            currentBranch = (TBranch *)branches->FindObject(feat_name);
            if (currentBranch)
            {
                currentBranch->SetAddress(&feat_val);
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
                    currentBranch->SetAddress(&feature.second);
                    std::cout << "[INFO] " << full_feature_name << " added " << std::endl;
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
        }
    }

    draw_features(sig, ws1, ws2);

    inputFile.Close();
    outputFile.Close();

    return 0;
}

void set_file_names(TString& signalFileName, TString &inputFileName, TString &exe_dir, TString &outputFileName)
{
    inputFileName = getenv("CURRENT_DATASET");
    exe_dir = getenv("WORKSPACE_DIR");
    if (exe_dir)
    {
        outputFileName = exe_dir + "/feature_analysis/features.root";
    }
    else
    {
        outputFileName = "../features.root";
    }
    if (!inputFileName)
    {
        std::cout << inputFileName << " could not be found." << std::endl;
        inputFileName = "/home/loren/MSc/datasets/MC_Xi_DecFile26265970_Beam6500GeV-2016-MagDown-Nu1.6-25ns-Pythia8.root";
        std::cout << "Using default file name: " << inputFileName << std::endl;
    }

    signalFileName = "/home/loren/MSc/datasets/MC_Xi_DecFile26265970_Beam6500GeV-2016-MagDown-Nu1.6-25ns-Pythia8.root";
}
