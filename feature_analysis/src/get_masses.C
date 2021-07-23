#include "pch.h"
#include "TChain.h"

using namespace ROOT::Math;

TString get_name_root(TString);

void get_masses()
{
    const std::map<int, std::pair<float, float>> masses = {
        {2930, {2942, 15}},
        {2970, {2964.3, 20.9}},
        {3055, {3055.9, 7.8}},
        {3080, {3077.2, 3.6}}};

    for (int i = 0; i < 4; i++)
    {

        TString dataset_dir = (TString)getenv("WORKSPACE_DIR") + (TString) "/datasets/temp/";
        TString dataset_name = (TString) "mcsampletruthDecFile2626597" + i + (TString) "_LcCutTruthMatched_IDpart";
        TString in_dataset_name = dataset_dir + dataset_name + (TString) ".root";
        TString out_dataset_name = dataset_name + (TString) "_M.root";

        std::cout << in_dataset_name << std::endl;
        std::cout << out_dataset_name << std::endl;

        TFile f(in_dataset_name, "READ");

        TFile outF(out_dataset_name, "RECREATE");
        TTree *t = ((TTree *)f.Get("DecayTree"))->CloneTree();

        int m = masses[i].first;
        double w = masses[i].second;

        TBranch *mass_branch = (TBranch *)t->Branch("Xicst_MassID", &m);
        TBranch *width_branch = (TBranch *)t->Branch("Xicst_WidthID", &w);

        int nentries = t->GetEntries();

        for (int j = 0; j < nentries; j++)
        {
            t->GetEntry(j);

            mass_branch->Fill();
            width_branch->Fill();
        }
        t->Write();
    }
}
