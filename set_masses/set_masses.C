#include "pch.h"
#include <nfd.hpp>

using namespace ROOT::Math;

void manip_file_name(TString, int &);
nfdpathsetsize_t get_files(NFD::UniquePathSet &inputFiles, nfdfilteritem_t *filterItem);

int set_masses()
{
    const std::map<int, std::pair<double, double>> masses = {
        {2930, {2942, 15}},
        {2970, {2964.3, 20.9}},
        {3055, {3055.9, 7.8}},
        {3080, {3077.2, 3.6}}};

    // initialize NFD
    NFD::Guard nfdGuard;

    // auto-freeing memory
    NFD::UniquePathSet inputFiles;
    NFD::UniquePathSetPath path;
    nfdfilteritem_t filterItem[1] = {"ROOT file", "root"};
    nfdpathsetsize_t numPaths = get_files(inputFiles, filterItem);

    double m, w;

    int mass_case;
    for (int i = 0; i < numPaths; i++)
    {
        std::cout << std::endl;
        NFD::PathSet::GetPath(inputFiles, i, path);
        manip_file_name(path.get(), mass_case);

        if (mass_case == 0) continue;
        m = masses.at(mass_case).first;
        w = masses.at(mass_case).second;

        TString inFileName = (TString)path.get();
        int ext_length = ((TString) ".root").Length();
        TString outFileName(inFileName);
        outFileName.Insert(inFileName.Length() - ext_length, "_mID");

        std::cout << "[INFO] Input File: " << inFileName << std::endl
                  << "[INFO] Output File: " << outFileName << std::endl;

        TFile f(inFileName, "READ");

        TFile outF(outFileName, "RECREATE");

        TString tree_name = "LcKPiTree/DecayTree";
        TTree *t;
        if (f.Get(tree_name))
            t = ((TTree *)f.Get(tree_name))->CloneTree();
        else if (f.Get("DecayTree"))
            t = ((TTree *)f.Get("DecayTree"))->CloneTree();
        else
            return (-1);

        TBranch *mass_branch = (TBranch *)t->Branch("Xicst_MassID", &m,"m/D");
        TBranch *width_branch = (TBranch *)t->Branch("Xicst_WidthID", &w,"w/D");

        int nentries = t->GetEntries();
        for (int j = 0; j < nentries; j++)
        {
            t->GetEntry(j);

            mass_branch->Fill();
            width_branch->Fill();
        }
        t->Write();
    }

    return 0;
}

void manip_file_name(TString filename, int &mass_case)
{
    if (filename.Contains("_mID"))
    {
        std::cout << "[WARNING]    Xicst_MassID branch is already present, according to title of file:" << std::endl
                  << "[WARNING]\t\t" << filename << std::endl
                  << "[WARNING]    If this is not the case, please remove \"_mID\" from the file name.\n";
        mass_case = 0;
    }
    else if (filename.Contains("26265970"))
        mass_case = 2930;
    else if (filename.Contains("26265971"))
        mass_case = 2970;
    else if (filename.Contains("26265972"))
        mass_case = 3055;
    else if (filename.Contains("26265973"))
        mass_case = 3080;
    else
    {
        std::cerr << "[ERROR] Could not identify mass of Xicst particle from title of file:" << std::endl
                  << "[ERROR] \t" << filename << std::endl
                  << "[ERROR] Please include DecFile number 2626597* where * is 0,1,2,3 for "
                     "Xicst masses 2942, 2964.3, 3055.9, 3077.2 respectively\n";
        exit(2);
    }
}

nfdpathsetsize_t get_files(NFD::UniquePathSet &inputFiles, nfdfilteritem_t *filterItem)
{
    // show the dialog
    nfdresult_t result = NFD::OpenDialogMultiple(inputFiles, filterItem, 1, "../datasets");
    nfdpathsetsize_t numPaths;
    if (result == NFD_OKAY)
    {
        NFD::PathSet::Count(inputFiles, numPaths);
        NFD::UniquePathSetPath path;
        for (int i = 0; i < numPaths; i++)
        {
            NFD::PathSet::GetPath(inputFiles, i, path);
            std::cout << "Opening file " << i + 1 << "/" << numPaths
                      << ":  " << path.get() << std::endl;
        }
    }
    else if (result == NFD_CANCEL)
    {
        std::cout << "User pressed cancel." << std::endl;
        exit(1);
    }
    else
    {
        std::cout << "Error: " << NFD::GetError() << std::endl;

        get_files(inputFiles, filterItem);
    }

    return numPaths;
}

int main()
{
    return set_masses();
}
