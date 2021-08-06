#include <nfd.hpp>

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"

#include "TMVA/Factory.h"
#include "TMVA/DataLoader.h"
#include "TMVA/Tools.h"
#include "TMVA/TMVAGui.h"
#include "ROOT/RDataFrame.hxx"

// #include "punzi_fom.C"

void get_file(NFD::UniquePath &inputFile, nfdfilteritem_t *filterItem);

void exploreOutput()
{
    // initialize NFD
    NFD::Guard nfdGuard;

    // auto-freeing memory
    NFD::UniquePath inputFile;
    nfdfilteritem_t filterItem[1] = {"ROOT file", "root"};
    get_file(inputFile, filterItem);

    TFile *TMVA_output = new TFile(inputFile.get());
    gDirectory->cd("dataset");

    TTree *testTree = (TTree *)TMVA_output->Get("TestTree");
    TTree *trainTree = (TTree *)TMVA_output->Get("TrainTree");

    ROOT::RDataFrame test_df = ROOT::RDataFrame(*testTree);
    ROOT::RDataFrame train_df = ROOT::RDataFrame(*trainTree);

    std::string method_dir_prefix = "Method_";
    TFile* outFile = new TFile("analysis_output.root","RECREATE");
    auto method_dirs = gDirectory->GetListOfKeys()->MakeIterator();

    // double opt_cut_bdt = punzi_fom("../output/TMVA_methodSample.root","Method_BDT", "BDT");
    // double opt_cut_bdtg = punzi_fom("../output/TMVA_methodSample.root","Method_BDT", "BDTG");

    // TH1D *hist;
    // while (auto key = (TObject *)method_dirs->Next())
    // {
    //     if (((TString)key->GetName()).BeginsWith(method_dir_prefix))
    //     {
    //         gDirectory->cd(key->GetName());

    //         auto methods = gDirectory->GetListOfKeys()->MakeIterator();
    //         while (auto method = (TDirectory *)methods->Next())
    //         {
    //             gDirectory->cd(method->GetName());
    //             std::cout << method->GetName() << std::endl;

    //             TString hist_name = "MVA_" + (TString)method->GetName() + "rejBvsS";
    //             hist = (TH1D *)method->Get(  hist_name  );
    //             hist->Write();

    //             gDirectory->cd("..");
    //         }
    //         gDirectory->cd("..");
    //     }
    // }
    // delete hist;
    // TCanvas *canv = new TCanvas("canv", "canv");
    // canv->Divide(2, 2);

    // canv->cd(1);
    // auto hist1 = test_df.Filter("BDT>0").Histo1D("Xicst_M");
    // hist1->Draw();

    // auto ROC_1 = (TH1D *)TMVA_output->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
    // std::cout << ROC_1->Integral() << std::endl;
    // canv->cd(2);
    // auto hist2 = test_df.Filter("BDT<0").Histo1D("Xicst_M");
    // hist2->Draw();

    // canv->cd(3);
    // auto hist3 = test_df.Filter("BDTG>0").Histo1D("Xicst_M");
    // hist3->Draw();

    // auto ROC_2 = (TH1D *)TMVA_output->Get("dataset/Method_BDT/BDTG/MVA_BDTG_rejBvsS");
    // std::cout << "Integral of ROC for " <<   ": " << ROC_2->Integral()/100 << std::endl;
    // canv->cd(4);
    // auto hist4 = test_df.Filter("BDTG<0").Histo1D("Xicst_M");
    // hist4->Draw();

    // canv->SaveAs("Canv.png");
}

void get_file(NFD::UniquePath &inputFile, nfdfilteritem_t *filterItem)
{
    // show the dialog
    nfdresult_t result = NFD::OpenDialog(inputFile, filterItem, 1, "./output");
    if (result == NFD_OKAY)
    {
        std::cout << "Opening "
                  << inputFile.get() << std::endl;
    }
    else if (result == NFD_CANCEL)
    {
        std::cout << "User pressed cancel." << std::endl;
    }
    else
    {
        std::cout << "Error: " << NFD::GetError() << std::endl;

        get_file(inputFile, filterItem);
    }
}

int main()
{
    exploreOutput();
}
