#pragma once
#include "pch.h"

using json = nlohmann::json;

// Particle struct, to contain info for each reconstructed particle flavour
struct PARTICLE
{
    TString name;
    std::map<TString, double> features;
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
    TTree *m_inTree, *m_outTree;

public:
    std::map<TString, PARTICLE> particles;

    Search(json &particle_list);
    Search(json &particle_list, TString desc);
    void SetWSDescription(TString desc);
    void GetWSDescription();
    void SetTree(TTree *tree, IO isInput);
    void SetTree(TString name, TString title, IO isInput);
    TTree *GetTree(IO isInput) const;
};
