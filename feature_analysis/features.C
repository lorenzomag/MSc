#include "features.h"

int features()
{
    json j_db = select_features(feat_source::from_file);

    Search sig(j_db, "-+");
    Search ws1(j_db, "+-");
    Search ws2(j_db, "++");

    TString inputFileName, outputFileName, exe_dir;
    set_file_names(inputFileName, exe_dir, outputFileName);

    TFile *inputFile;
    if (inputFile = new TFile(inputFileName, "READ"))
    {
        std::cout << "Reading data from " << inputFileName << std::endl;
    }
    else
    {
        std::cout << "ERROR: Input file " << inputFileName << " could not be found." << std::endl;
        exit(3);
    }

    // Get input trees
    sig.SetTree((TTree *)inputFile->Get("LcKPiTree/DecayTree"), Search::input);
    ws1.SetTree((TTree *)inputFile->Get("LcKPiTreeWS1/DecayTree"), Search::input);
    ws2.SetTree((TTree *)inputFile->Get("LcKPiTreeWS2/DecayTree"), Search::input);

    // Set output trees
    TFile *outputFile = new TFile(outputFileName, "RECREATE");
    sig.SetTree(new TTree("FeaturesSig", "Features Tree for signal (Lc+ K- pi+)"), Search::output);
    ws1.SetTree(new TTree("FeaturesWS1", "Features Tree for WS1 (Lc+ K+ pi-)"), Search::output);
    ws2.SetTree(new TTree("FeaturesWS2", "Features Tree for WS2 (Lc+ K+ pi+)"), Search::output);

    std::vector<Search *> searches = {&sig}; //, &ws1, &ws2};

    TBranch *currentBranch;
    TObjArray *branches;
    for (Search *current_search : searches)
    {
        branches = current_search->GetTree(Search::input)->GetListOfBranches();
        current_search->GetWSDescription();
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
                // std::cout << full_feature_name << std::endl;

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
                std::cout << "[INFO] " << particle_name << feature << " is not a valid branch; ignored." << std::endl;
            }
        }
        // current_search->GetTree(Search::input)->GetEntry(4);
        // // current_search->GetTree(Search::output)->Branch(particle_name, &current_search->particles[particle_name].features);
        // set_branch_args(current_search->particles["Lc"]);

        // current_search->GetTree(Search::output)->Write();
        // sig.GetTree(Search::input)->GetEntry(2);
        // for (auto feature : sig.particles[particle_name].features)
        // {
        //     // TString feature_name = feature.first;
        //     // TString full_feature_name = particle_name + feature_name;

        //     // std::cout << feature.first << " " << feature.second << std::endl;
        // }
        // set_branch_args(particle.second);
        std::cout << std::endl;
    }

    // for (Search *current_search : searches)
    // {
    for (int i = 0; i < sig.GetTree(Search::input)->GetEntries(); i++)
    {
        sig.GetTree(Search::input)->GetEntry(i);
        // std::cout << sig.particles["Lc"].features["_MM"] << std::endl;
    }
    // for (auto &particle : current_search->particles)
    // {
    //     set_branch_args(particle.second);
    // }
    // }
    // // for (int i = 0; i < 10; i++)
    // // {
    // //     ws1.GetTree(Search::input)->GetEntry(i);
    // //     // std::cout << ws1.particles["pip"]->ORIVX_X << std::endl
    // //     //           << ws1.particles["pip"]->ORIVX_Y << std::endl
    // //     //           << ws1.particles["pip"]->ORIVX_Z << std::endl;
    // //     ws1.GetTree(Search::output)->Fill();
    // // }

    // // ws1.GetTree(Search::output)->Write();

    // inputFile->Close();
    // outputFile->Close();

    // delete inputFile, outputFile;
    return 0;
}

void set_file_names(TString &inputFileName, TString &exe_dir, TString &outputFileName)
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
}

void set_branch_args(PARTICLE &particle)
{
    TString particle_name = particle.name;

    for (auto &feat : particle.features)
    {
        // std::cout << particle_name << feat.first << " = " << feat.second << std::endl;
    }
}

int main()
{
    return features();
}