#include <cstdlib>
#include <array>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <fstream>

#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TChain.h"

enum data_type : int
{
    kSIGNAL,
    kWS1,
    kWS2,
    kWS3
};
void add_branch(TTree *tree, data_type dt);

void tag_datasets()
{
    TString signal_inFileName = getenv("CURRENT_WS2_DATASET");
    int ext_length = ((TString) ".root").Length();
    TString signal_outFileName(signal_inFileName);
    signal_outFileName.Insert(signal_inFileName.Length() - ext_length, "_typeID");

    std::cout << "[INFO] Input Signal File: " << signal_inFileName << std::endl
              << "[INFO] Output Signal File: " << signal_outFileName << std::endl;

    TString background_inFileName = getenv("CURRENT_WS2_DATASET");
    TString background_outFileName(background_inFileName);
    background_outFileName.Insert(background_inFileName.Length() - ext_length, "_typeID");

    std::cout << "[INFO] Input Background File: " << background_inFileName << std::endl
              << "[INFO] Output Background File: " << background_outFileName << std::endl;

    TFile mc_file(signal_inFileName);
    TFile ws_file(background_inFileName);

    TTree *mc_tree = (TTree *)mc_file.Get("DecayTree");
    TTree *ws_tree = (TTree *)ws_file.Get("DecayTree");

    TFile *out_file = new TFile(signal_outFileName, "RECREATE");

    std::cout << "---> Cloning DecayTree from Signal data set" << std::endl;
    TTree *cloned_mc_tree = (TTree *)mc_tree->CloneTree();
    std::cout << "---> Adding id branch to signal tree" << std::endl;
    add_branch(cloned_mc_tree, data_type::kWS2);
    std::cout << "---> Writing signal tree to file" << std::endl;
    cloned_mc_tree->Write("", TObject::kOverwrite);
    out_file->Close();

    delete out_file;

    // out_file = new TFile(background_outFileName, "RECREATE");
    // std::cout << "---> Cloning DecayTree from Background data set" << std::endl;
    // TTree *cloned_ws_tree = (TTree *)ws_tree->CloneTree();
    // std::cout << "---> Adding id branch to background tree" << std::endl;
    // add_branch(cloned_ws_tree, data_type::kBACKGROUND);
    // std::cout << "---> Writing background tree to file" << std::endl;
    // cloned_ws_tree->Write("", TObject::kOverwrite);
    // out_file->Close();
    // delete out_file;
}

void add_branch(TTree *tree, data_type dt)
{
    int var = (int)dt;
    auto new_branch = tree->Branch("data_type", &var);
    size_t nentries = tree->GetEntries();
    int intervals = (int)(nentries / 100);
    for (int entry = 0; entry < nentries; entry++)
    {
        if (entry % intervals == 0)
            std::cout << "Entry " << entry << "/" << nentries << " (" << (entry / intervals) << "%)" << std::endl;

        tree->GetEntry(entry);
        new_branch->Fill();
    }
}