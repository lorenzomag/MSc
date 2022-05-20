#include <cstdlib>
#include <array>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>

#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TCanvas.h"
#include "THStack.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TH1D.h"
#include "TRandom.h"
#include "TAxis.h"
#include "TStyle.h"

#include "TRint.h"
#include "TStopwatch.h"

#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooGaussian.h"
#include "RooHist.h"
#include "RooPlot.h"
#include "RooFitResult.h"
#include "RooGenericPdf.h"
#include "RooArgusBG.h"
#include "RooAbsDataHelper.h"
#include "RooConstVar.h"
#include "RooTFnBinding.h"

#include "RooProduct.h"
#include "RooAddition.h"
#include "RooExponential.h"
#include "RooProdPdf.h"
#include "RooDstD0BG.h"

#include "PowerLaw.h"
#include "MarksBG.h"
#include "modErf.h"

using namespace RooFit;

#include "ROOT/RDataFrame.hxx"

using ROOT::RDataFrame;

RooFitResult *fit_results;

const std::map<int, double> masses = {{1, 2942.0},
                                      {2, 2964.3},
                                      {3, 3055.9},
                                      {4, 3077.2}};

const std::map<int, double> widths = {
    {1, 15.0},
    {2, 20.9},
    {3, 7.8},
    {4, 3.6}};

void sig_fit(const int mass_case = 1, const std::string method = "MLP", const double cut = 0.89)
{
  TFile *file = new TFile(getenv("CURRENT_MC_DATASET"));
  TTree *tree = (TTree *)file->Get("DecayTree");
  RDataFrame ds = RDataFrame(*tree);

  // Get subset of dataframe
  auto ds_cut = ds.Filter(Form("MVA_%s > %f", method.c_str(), cut));

  auto mc_cut = ds_cut.Filter("data_type == 0");

  const double K_mass = 493.677;    // K mass from PDG
  const double pi_mass = 139.57039; // pi mass from PDG
  mc_cut = mc_cut.Define("Xicst_TRUEM", "sqrt(pow(Xicst_TRUEP_E,2) - (pow(Xicst_TRUEP_X,2) + pow(Xicst_TRUEP_Y,2) + pow(Xicst_TRUEP_Z,2)))");
  mc_cut = mc_cut.Define("Lc_TRUEM", "sqrt(pow(Lc_TRUEP_E,2) - (pow(Lc_TRUEP_X,2) + pow(Lc_TRUEP_Y,2) + pow(Lc_TRUEP_Z,2)))");
  mc_cut = mc_cut.Define("DM", "Xicst_M -Lc_M - Xicst_TRUEM + Lc_TRUEM");

  double min_val = -7;
  double max_val = 7;

  auto mass_cut = mc_cut.Filter(Form("Xicst_MassID == %f", masses.at(mass_case)));
  // Convert from RDataFrame to RooDataSet
  RooRealVar x("x", "Xicst_M - Xicst_TRUEM - (Lc_M - Lc_TRUEM)", min_val, max_val);
  RooDataSet rooDataSet = mass_cut.Book<double>(
                                      RooDataSetHelper("dataset",          // Name
                                                       "Title of dataset", // Title
                                                       RooArgSet(x)        // Variables in this dataset
                                                       ),
                                      {"DM"} // Column names in RDataFrame.
                                      )
                              .GetValue();


  RooRealVar sigmean("sigmean", "mean", 0.0, -10, 10);
  RooRealVar sigwidth("sigwidth", "width", 3.0, 0.5, 10.0);

  // Build a Gaussian PDF:
  RooGaussian sig("signal", "signal PDF", x, sigmean, sigwidth);

  RooRealVar sigmean2("sigmean2", "mean", 0, -10, 10);
  RooRealVar sigwidth2("sigwidth2", "width", 3.0, 0.1, 10.0);

  // Build a Gaussian PDF:
  RooGaussian sig2("signal2", "signal PDF", x, sigmean2, sigwidth2);

  RooRealVar fr("fr","fraction",0.5,0.0,1.0);

  RooAddPdf model("model","model",RooArgList(sig,sig2),fr);

  // // Fit
  model.fitTo(rooDataSet);

  // Plot
  TCanvas *canv = new TCanvas("canv", "canv");
  canv->Divide(1, 2);
  canv->cd(1);
  RooPlot *frame = x.frame(Bins(200));
  rooDataSet.plotOn(frame);
  model.plotOn(frame);
  model.paramOn(frame);
  frame->DrawClone();

  canv->cd(2);
  RooPlot *frame_pull = x.frame(Title("Pull"), Bins(200));
  auto pull_hist = frame->pullHist();
  frame_pull->addPlotable(pull_hist, "P");
  frame_pull->DrawClone();
  canv->Draw();
}