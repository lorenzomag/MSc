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
    int m_nGlobals;
    TString m_name;
    TString m_WSDescription;
    TTree *m_inTree, *m_outTree;

public:
    std::map<TString, PARTICLE> particles;
    std::map<TString, double> globals;

    Search(json &feature_list);
    Search(json &feature_list, TString desc);
    Search(json &feature_list, TString name, TString desc);
    void SetWSDescription(TString desc);
    void GetWSDescription();
    void SetTree(TTree *tree, IO isInput);
    void SetTree(TString name, TString title, IO isInput);
    TTree *GetTree(IO isInput) const;
    void SetName(TString name);
    TString GetName();
    int GetNGlobals();
    int GetNParticles();
};
