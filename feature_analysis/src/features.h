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

// Create map of particles names -> particle instances
std::map<TString, PARTICLE *> particles;

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

    Search(std::vector<TString> particle_list) : m_nParticles(0), m_WSDescription("null")
    {
        for (auto particle_name : particle_list)
        {
            particles[particle_name] = new PARTICLE(particle_name);
            m_nParticles++;
        }
    };

    ~Search()
    {
        delete inTree, outTree;
        for (auto particle : particles){
            delete particle.second;
        }
    }

    Search(std::vector<TString> particle_list, TString desc) : Search(particle_list) { SetWSDescription(desc); };

    void SetWSDescription(TString desc)
    {
        if (desc.Length() != 2)
        {
            std::cout << std::endl
                      << std::endl
                      << "WARNING: SetWSDescription usage: " << std::endl
                      << "      Input two symbols representing the charge of K and pi respectively." << std::endl
                      << "      For instance, \"-+\" would represent a Lc+ K- pi+ decay;" << std::endl
                      << "      \"+-\" would represent a Lc+ K+ pi- decay." << std::endl
                      << std::endl;
        }
        m_WSDescription = desc;
    };

    void GetWSDescription()
    {
        if (m_WSDescription != "null")
        {
            std::cout << "This class represents / Xicst -> Lc+ K" << m_WSDescription[0]
                      << " pi" << m_WSDescription[1] << " / decays" << std::endl;
        }
    };

    int SetTree(TTree *tree, IO isInput)
    {
        if (isInput)
        {
            Search::inTree = tree;
        }
        else
        {
            Search::outTree = tree;
        }
        return 0;
    };

    TTree *GetTree(IO isInput) const
    {
        if (isInput)
        {
            return inTree;
        }
        else
        {
            return outTree;
        }
    };
};
