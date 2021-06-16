#include "search.h"

#define getName(var) #var

int features()
{
    std::vector<TString> particle_list = {
        "Lc",
        "Km",
        "p",
        "pip",
        "Kbach",
        "pibach",
        "Xicst"};

    std::vector<TString> feature_list = {
        "_ORIVX_X",
        "_ORIVX_Y",
        "_ORIVX_Z"};

    Search *sig = new Search(particle_list, "-+");
    Search *ws1 = new Search(particle_list, "+-");
    Search *ws2 = new Search(particle_list, "++");

    TString inputFileName, outputFileName, exe_dir;
    inputFileName = getenv("CURRENT_DATASET");
    exe_dir = getenv("WORKSPACE_DIR");
    if (inputFileName && exe_dir)
    {
        outputFileName = exe_dir + "feature_analysis/features.root";
    }
    else
    {
        std::cout << outputFileName << " could not be found." << std::endl;

        outputFileName = "/home/loren/MSc/datasets/Lc_sample_1000files_2016M agDown.root";

        std::cout << "Using default file name: " << outputFileName << std::endl;
    }

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
    sig->SetTree((TTree *)inputFile->Get("LcKPiTree/DecayTree"), Search::input);
    ws1->SetTree((TTree *)inputFile->Get("LcKPiTreeWS1/DecayTree"), Search::input);
    ws2->SetTree((TTree *)inputFile->Get("LcKPiTreeWS2/DecayTree"), Search::input);

    auto sigBranches = sig->GetTree(Search::input)->GetListOfBranches();
    auto ws1Branches = ws1->GetTree(Search::input)->GetListOfBranches();
    auto ws2Branches = ws2->GetTree(Search::input)->GetListOfBranches();

    TFile *outputFile = new TFile(outputFileName, "RECREATE");
    // Set output trees
    sig->SetTree(new TTree("FeaturesSig", "Features Tree for signal (Lc+ K- pi+) "), Search::output);
    ws1->SetTree(new TTree("FeaturesWS1", "Features Tree for WS1 (Lc+ K+ pi-) "), Search::output);
    ws2->SetTree(new TTree("FeaturesWS2", "Features Tree for WS2 (Lc+ K+ pi+) "), Search::output);

    TBranch *currentBranch;
    for (auto particle_name : particle_list)
    {
        std::cout << particle_name << std::endl;
        std::cout << "============" << std::endl;
        for (auto feature_name : feature_list)
        {
            currentBranch = (TBranch *)ws1Branches->FindObject(particle_name + feature_name);

            if (currentBranch)
            {
                if (feature_name == "_ORIVX_X")
                {
                    currentBranch->SetAddress(&ws1->particles[particle_name]->ORIVX_X);
                    std::cout << "Ok for X" << std::endl;
                }
                else if (feature_name == "_ORIVX_Y")
                {
                    currentBranch->SetAddress(&ws1->particles[particle_name]->ORIVX_Y);
                    std::cout << "Ok for Y" << std::endl;
                }
                else if (feature_name == "_ORIVX_Z")
                {
                    currentBranch->SetAddress(&ws1->particles[particle_name]->ORIVX_Z);
                    std::cout << "Ok for Z" << std::endl;
                }
            }
        }

        ws1->GetTree(Search::output)->Branch(particle_name, &ws1->particles[particle_name], "ORIVX_X/D:ORIVX_Y/D:ORIVX_Z/D");
        std::cout << std::endl;
    }

    for (int i = 0; i < 10; i++)
    {
        ws1->GetTree(Search::output)->GetEntry(i);
        std::cout << ws1->particles["pip"]->ORIVX_X << std::endl
                  << ws1->particles["pip"]->ORIVX_Y << std::endl
                  << ws1->particles["pip"]->ORIVX_Z << std::endl;
        ws1->GetTree(Search::output)->Fill();
    }

    ws1->GetTree(Search::output)->Write();

    inputFile->Close();
    outputFile->Close();

    return 0;
}

int main()
{
    return features();
}
