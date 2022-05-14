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

#include "RooProduct.h"
#include "RooAddition.h"
#include "RooExponential.h"
#include "RooProdPdf.h"
#include "RooDstD0BG.h"

#include "PowerLaw.h"
#include "XicstBG.h"

using namespace RooFit;

#include "ROOT/RDataFrame.hxx"

using ROOT::RDataFrame;

RooFitResult *fit_results;

void TMVAnalyse(const std::string method = "MLP", const double cut = 0.89)
{
  ROOT::EnableImplicitMT(4);

  TFile *file = new TFile(getenv("CURRENT_WS1_DATASET"));
  TTree *tree = (TTree *)file->Get("DecayTree");

  // Get subset of dataframe
  RDataFrame ds(*tree);
  auto ds_cut = ds.Filter(Form("MVA_%s > %f", method.c_str(), cut));
  auto bkg_cut = ds_cut.Filter("data_type == 1");

  const double K_mass = 493.677;    // K mass from PDG
  const double pi_mass = 139.57039; // pi mass from PDG

  bkg_cut = bkg_cut.Define("DM", Form("Xicst_M-Lc_M-%f-%f", K_mass, pi_mass));

  // Convert from RDataFrame to RooDataSet
  RooRealVar x("x", "Xicst_M - Lc_M - M_{PDG}(K) - M_{PDG}(#pi)", 0, 850);
  RooDataSet rooDataSet = bkg_cut.Book<double>(
                                     RooDataSetHelper("dataset",          // Name
                                                      "Title of dataset", // Title
                                                      RooArgSet(x)        // Variables in this dataset
                                                      ),
                                     {"DM"} // Column names in RDataFrame.
                                     )
                              .GetValue();

  // Define variables
  // double slope_start(0.003), power_start(0.3), cutoff_start(30);
  // RooRealVar slope("slope", "Slope", 0, 0.01);
  // slope.setConstant();
  // RooRealVar power("power", "Power", 0.0, 1.0);
  // RooRealVar cutoff("cutoff", "Cutoff", 0, 100);

  // // Build PDF
  // RooProduct mcutoff("mcutoff", "mcutoff", RooArgList(RooConst(-1), cutoff));
  // RooAddition xshift("x_cutoff_shift", "x+cutoff", RooArgList(x, mcutoff));
  // PowerLaw pow_pdf("powerlaw", "x^k", xshift, power);
  // RooProduct exp_c("exp_c", "exp_c", RooArgList(RooConst(-1), slope));
  // RooExponential exp_pdf("exp", "exponential pdf", xshift, exp_c);
  // RooProdPdf bg("pow_exp", "pow*exp", RooArgSet(pow_pdf, exp_pdf));   //Ryun

  RooRealVar a("a", "a", 1, 0, 18);
  RooRealVar b("b", "b", -0.001, -0.05, 0.0);
  RooRealVar power("power", "Power", 0.02, 0.0, 0.1);
  RooRealVar cutoff("cutoff", "Cutoff", 22, 0, 40);


  // // Build PDF
  // // RooGenericPdf bg("bg", "bg", "a*((x-cutoff)^(power)) +(b*(x-cutoff))", RooArgList(x, a, b, cutoff, power));
  // RooDstD0BG bg("bg","bg",x,cutoff,power,a,b);
  MarksBG bg("bg", "bg", x, a, b, power, cutoff);

  // // Fit PDF
  a.setConstant();
  power.setConstant();
  bg.fitTo(rooDataSet,Range(200,800));
  
  b.setConstant();
  a.setConstant(kFALSE);
  bg.fitTo(rooDataSet, Range(0.0,40.0));
  
  power.setConstant(kFALSE);
  bg.fitTo(rooDataSet, Range(0.0,840.0));


  // Plot
  TCanvas *canv = new TCanvas("canv", "canv");
  canv->Divide(1, 2);
  canv->cd(1);
  RooPlot *frame = x.frame();
  rooDataSet.plotOn(frame,Binning(1000));
  bg.plotOn(frame);
  bg.paramOn(frame);
  frame->DrawClone();

  canv->cd(2);
  RooPlot *frame_pull = x.frame(Title("Pull"));
  auto pull_hist = frame->pullHist();
  frame_pull->addPlotable(pull_hist, "P");
  frame_pull->DrawClone();
  canv->Draw();


  // canv.Print("asd.svg");
}

int main(int argc, char **argv)
{
  TMVAnalyse();
}