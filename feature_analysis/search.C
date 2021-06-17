#include "search.h"

// Class to contain everything relative to a run.
// Which process was run, what particles were reconstructed,
// relative analysis.
Search::Search(json &particle_list) : m_nParticles(0), m_WSDescription("null")
{
    TString name;
    for (auto particle : particle_list["particles"].items())
    {
        std::string particle_name = particle.key();
        if (particle_list["particles"][particle_name]["include"])
        {

            particles[particle_name] = PARTICLE();
            particles[particle_name].name = particle_name;
            m_nParticles++;

            for (auto feature : particle_list["particles"][particle_name]["features"].items())
                if (feature.value())
                    particles[particle_name].features[feature.key()] = 0.0d;
        }
    }
};

Search::Search(json &particle_list, TString desc) : Search(particle_list) { SetWSDescription(desc); };

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
        std::cout << "Object representing / Xicst -> Lc+ K" << m_WSDescription[0]
                  << " pi" << m_WSDescription[1] << " / decays" << std::endl;
};

int Search::SetTree(TTree *tree, IO isInput)
{
    if (isInput)
    {
        m_inTree = tree;
    }
    else
        m_outTree = tree;

    return 0;
};

TTree *Search::GetTree(IO isInput) const
{
    if (isInput)
        return m_inTree;
    else
        return m_outTree;
};
