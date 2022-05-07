#include <cstdlib>
#include <array>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <fstream>

#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TCanvas.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TRint.h"
#include "TStopwatch.h"

#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TStyle.h"
#include "TMVA/MethodCuts.h"

#include "json.hpp"

using nlohmann::json;

void TMVAnalyse()
{

    TString dataset_name = getenv("CURRENT_APPLICATION_DATASET");
    TFile dataset_file(dataset_name);

    TTree *dataset = (TTree *)dataset_file.Get("DecayTree");
    dataset->AddFriend("mva_response", "TMVApp.root");

    TCanvas *c1 = new TCanvas("c1", "c1", 700, 600);
    dataset->Draw("Xicst_M");
    dataset->Draw("Xicst_M", "data_type==0", "same");
    dataset->Draw("Xicst_M", "data_type==1", "same");

    TCanvas *c2 = new TCanvas("c2", "c2", 700, 600);
    gStyle->SetLineColor(kRed);
    dataset->Draw("Xicst_M", "data_type==0");
    gStyle->SetLineColor(kBlue);
    dataset->Draw("Xicst_M", "MVA_MLP>0.94","same");
    

    TCanvas *c3 = new TCanvas("c3", "c3", 700, 600);
    dataset->Draw("Xicst_M");
    dataset->Draw("Xicst_M", "MVA_MLP>0.94", "same");
}