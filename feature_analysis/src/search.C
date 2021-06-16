#include "search.h"


// Class to contain everything relative to a run.
// Which process was run, what particles were reconstructed,
// relative analysis.
Search::Search(std::vector<TString> particle_list) : m_nParticles(0), m_WSDescription("null")
{
    for (auto particle_name : particle_list)
    {
        particles[particle_name] = new PARTICLE(particle_name);
        m_nParticles++;
    }
};

Search::~Search()
{
    delete inTree, outTree;
    for (auto particle : particles)
    {
        delete particle.second;
    }
}

Search::Search(std::vector<TString> particle_list, TString desc) : Search(particle_list) { SetWSDescription(desc); };

void Search::SetWSDescription(TString desc)
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

void Search::GetWSDescription()
{
    if (m_WSDescription != "null")
    {
        std::cout << "This class represents / Xicst -> Lc+ K" << m_WSDescription[0]
                  << " pi" << m_WSDescription[1] << " / decays" << std::endl;
    }
};

int Search::SetTree(TTree *tree, IO isInput)
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

TTree *Search::GetTree(IO isInput) const
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
