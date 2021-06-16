#pragma once

#include <map>
#include <vector>
#include <iostream>

#include "TString.h"
#include "TTree.h"
#include "TFile.h"
#include "TROOT.h"
#include "TRandom.h"
#include "TSystem.h"

// Particle struct, to contain info for each reconstructed particle flavour
struct PARTICLE
{
    PARTICLE(TString name){};
    int PID;
    double M, MM;
    double ORIVX_X, ORIVX_Y, ORIVX_Z;
    double p, pt;
    double ENDVERTEX_CHI2;
    double IPCHI2_OWNPV, IP_OWNPV;
    double TAU, cTAU;
    double ProbNNp, ProbNNk, ProbNNpi;
};

// Class to contain everything relative to a run.
// Which process was run, what particles were reconstructed,
// relative analysis.
class Search
{

public:
    enum IO
    {
        input,
        output
    };

private:
    int m_nParticles;
    TString m_WSDescription;
    TTree *inTree, *outTree;

public:

    std::map<TString, PARTICLE *> particles;

    Search(std::vector<TString> particle_list);
    Search(std::vector<TString> particle_list, TString desc);
    ~Search();

    void SetWSDescription(TString desc);
    void GetWSDescription();
    int SetTree(TTree *tree, IO isInput);
    TTree *GetTree(IO isInput) const;
};
