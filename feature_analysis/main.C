#include "pch.h"

int main()
{
    TFile inFile("/home/loren/MSc/datasets/MC_Xi_DecFile26265970_Beam6500GeV-2016-MagDown-Nu1.6-25ns-Pythia8.root", "READ");

    TTree *sig = (TTree *)inFile->Get("LcKPiTree/DecayTree");
    TTree *ws1 = (TTree *)inFile.Get("LcKPiTreeWS1/DecayTree");
    TTree *ws2 = (TTree *)inFile.Get("LcKPiTreeWS2/DecayTree");

    


    return 0;
}