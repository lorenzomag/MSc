#ifndef SEARCH
#define SEARCH

using json = nlohmann::json;

// Particle struct, to contain info for each reconstructed particle flavour
struct PARTICLE
{
    TString name;
    std::vector<TString> features;
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
        output,
        clone
    };

private:
    int m_nParticles;
    int m_nGlobals;
    TString m_name;
    TString m_WSDescription;
    TTree *m_inTree, *m_outTree;

public:
    std::map<TString, PARTICLE> particles;
    std::vector<TString> globals;

    Search(json &feature_list);
    Search(json &feature_list, TString desc);
    Search(json &feature_list, TString name, TString desc);
    void SetWSDescription(TString desc);
    void GetWSDescription();
    TTree* SetTree(TString name, TString title, IO isInput);
    TTree *SetTree(TTree *tree, IO isInput, TString name="", TString title="");
    TTree *GetTree(IO isInput) const;
    void SetName(TString);
    TString GetName();
    int GetNGlobals();
    int GetNParticles();
};

#endif // SEARCH