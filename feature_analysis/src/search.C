#include "pch.h"

#include "search.h"

// Class to contain everything relative to a run.
// Which process was run, what particles were reconstructed,
// relative analysis.
Search::Search(json &feature_list) : m_nParticles(0), m_nGlobals(0), m_WSDescription("null"), m_name("null")
{
    for (auto feature : feature_list["global"].items())
    {
        if (feature.value())
        {
            m_nGlobals++;
            globals[feature.key()] = 0.0;
        }
    }

    for (auto particle : feature_list["particles"].items())
    {
        std::string particle_name = particle.key();
        if (feature_list["particles"][particle_name]["include"])
        {

            particles[particle_name] = PARTICLE();
            particles[particle_name].name = particle_name;
            m_nParticles++;

            for (auto feature : feature_list["particles"][particle_name]["features"].items())
                if (feature.value())
                    particles[particle_name].features[feature.key()] = 0.0;
        }
    }
};

Search::Search(json &feature_list, TString desc) : Search(feature_list) { SetWSDescription(desc); };
Search::Search(json &feature_list, TString name, TString desc) : Search(feature_list, desc) { m_name = name; };

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
        if (m_name == "null")
        {
            std::cout << "Object representing / Xicst -> Lc+ K" << m_WSDescription[0]
                      << " pi" << m_WSDescription[1] << " / decays" << std::endl;
        }
        else
        {
            std::cout << "\"" << this->GetName() << "\" search represents / Xicst -> Lc+ K" << m_WSDescription[0]
                      << " pi" << m_WSDescription[1] << " / decays" << std::endl;
        }
    }
    else
    {
        std::cout << "[WARNING] Description of search has not been set yet!" << std::endl;
    }
};

TTree *Search::SetTree(TTree *tree, IO isInput, TString name, TString title)
{
    if (name != "")
        tree->SetName(name);
    if (title != "")
        tree->SetTitle(title);
        
    if (isInput == Search::input)
    {
        m_inTree = tree;
    }
    else if (isInput == Search::clone)
    {
        m_outTree = tree;
    }
    else
    {
        std::cerr << "[ERROR] Use \"int Search::SetTree(TString name, TString title, IO isInput)\" setter to set output tree." << std::endl
                  << "If you want to set an input tree, IO argument needs to be \"input\"." << std::endl;
        exit(5);
    }

    if (isInput == Search::input)
        return m_inTree;
    else
        return m_outTree;
};
TTree *Search::SetTree(TString name, TString title, IO isInput)
{
    if (isInput == Search::input || isInput == Search::clone)
    {
        std::cerr << "[ERROR] Use \"int Search::SetTree(TTree *tree, IO isInput)\" setter to set input tree or to clone a tree." << std::endl
                  << "If you want to set an output tree, IO argument needs to be \"output\"." << std::endl;
        exit(6);
    }
    else
    {
        m_outTree = new TTree(name, title);
    }

    if (isInput == Search::input)
        return m_inTree;
    else
        return m_outTree;
};

void Search::SetName(TString name)
{
    m_name = name;
};

TString Search::GetName()
{
    if (m_name == "null")
    {
        std::cout << "[WARNING] Name of search has not been set yet!" << std::endl;
    }
    return m_name;
}

TTree *Search::GetTree(IO isInput) const
{
    if (isInput == Search::input)
        return m_inTree;
    else
        return m_outTree;
};

int Search::GetNGlobals()
{
    return m_nGlobals;
};

int Search::GetNParticles()
{
    return m_nParticles;
};