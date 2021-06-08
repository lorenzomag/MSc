#ifndef DATASETS_DIR
#define DATASETS_DIR "/home/loren/MSc/datasets/" // modify as needed
#endif

// Import recently implemented LorentzVector class and using its namespace by default
#include "Math/Vector4D.h"
#include "Math/Vector4Dfwd.h"
using namespace ROOT::Math;

// Create a struct to contain particle info
struct PARTICLE
{
    TVector3 ORIVX;
};

void features()
{

    TString dataset = "Lc_sample_1000files_2016MagDown.root";

    TFile *inFile = new TFile(DATASETS_DIR + dataset, "READ");

    PARTICLE Km, pip, p;

    Km.ORIVX.SetXYZ(3, 2, 1);
    pip.ORIVX.SetXYZ(2, 1, 2);
    p.ORIVX.SetXYZ(2, 1, 2);
    PtEtaPhiEVector Lc(2,3,2,22);
    TTree *tree = new TTree("Ciaone", "Ciaonissimo");

    for (int i = 0; i < 100; i++)
    {
        Km.ORIVX.SetX(i);
        Km.ORIVX.SetY(i*2);
        pip.ORIVX.SetX(i);
        pip.ORIVX.SetY(i*2);
        p.ORIVX.SetX(i);
        p.ORIVX.SetY(i*2);
        Lc.SetX(i);
        Lc.SetY(i*2);

        tree->Fill();
    }

    TFile outFile("test.root", "RECREATE");
    XYZTVector v(1,2,3,4);
    tree->Branch("Lc", &Lc);
    tree->Branch("Km", &Km);
    tree->Branch("pip", &pip);
    tree->Branch("p", &p);

    tree->Write();
}