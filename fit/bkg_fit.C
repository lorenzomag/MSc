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
#include "MarksBG.h"
#include "modErf.h"

using namespace RooFit;

#include "ROOT/RDataFrame.hxx"

using ROOT::RDataFrame;

#define CASE MARK // Can be MARK, RYUN, EMMY, or DstD0 depending on PDF

RooFitResult *fit_results;

void fit(const int ws = 1, const std::string method = "MLP", const double cut = 0.89)
{
  RDataFrame ds(0);
  if (ws == 0)
  {
    TChain *tree = new TChain("DecayTree");
    for (int i = 1; i < 3; i++){
      std::cout << getenv(Form("CURRENT_WS%d_DATASET", i)) << std::endl;
      tree->Add(getenv(Form("CURRENT_WS%d_DATASET", i)));}
    ds = RDataFrame(*tree);
  }
  else
  {
    TFile *file = new TFile(getenv(Form("CURRENT_WS%d_DATASET", ws)));
    TTree *tree = (TTree *)file->Get("DecayTree");
    ds = RDataFrame(*tree);
  }
  // Get subset of dataframe
  auto ds_cut = ds.Filter(Form("MVA_%s > %f", method.c_str(), cut));

  auto bkg_cut = ds_cut.Filter("data_type != 0");

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

  // ******************************************************
  // * RYUN
  // ******************************************************
  // RooRealVar slope("slope", "Slope", 0.0003, 0.0, 0.01);
  // RooRealVar power("power", "Power", 0.3, 0.0, 1.0);
  // RooRealVar cutoff("cutoff", "Cutoff", 20, 10, 40);
  // RooProduct mcutoff("mcutoff", "mcutoff", RooArgList(RooConst(-1), cutoff));
  // RooAddition xshift("x_cutoff_shift", "x+cutoff", RooArgList(x, mcutoff));
  // PowerLaw pow_pdf("powerlaw", "x^k", xshift, power);
  // RooProduct exp_c("exp_c", "exp_c", RooArgList(RooConst(-1), slope));
  // RooExponential exp_pdf("exp", "exponential pdf", xshift, exp_c);
  // RooProdPdf bg("pow_exp", "pow*exp", RooArgSet(pow_pdf, exp_pdf));

  // bg.fitTo(rooDataSet,Range(0.0, 840.0));
  // ******************************************************

  // ******************************************************
  // * EMMY
  // ******************************************************
  // RooRealVar slope("slope", "slope", -0.001, -0.05, 0.0);
  // RooRealVar power("power", "Power", 0.02, 0.0, 0.1);
  // PowerLaw pow_pdf("powerlaw", "x^k", x, power);
  // RooProduct exp_c("exp_c", "exp_c", RooArgList(RooConst(-1), slope));
  // RooExponential exp_pdf("exp", "exponential pdf", x, exp_c);
  // RooProdPdf bg("pow_exp", "pow*exp", RooArgSet(pow_pdf, exp_pdf));

  // bg.fitTo(rooDataSet,Range(0.0, 840.0));
  // ******************************************************

  // ******************************************************
  // * D0
  // * From https://root.cern/doc/master/classRooDstD0BG.html
  // ******************************************************
  // RooRealVar a("a", "a", 1, 0, 18);
  // RooRealVar b("b", "b", -0.001, -0.05, 0.0);
  // RooRealVar power("power", "Power", 0.02, 0.0, 0.1);
  // RooRealVar cutoff("cutoff", "Cutoff", 22, 0, 40);
  // RooDstD0BG bg("bg", "bg", x, cutoff, power, a, b);
  // bg.fitTo(rooDataSet, Range(0.0, 840.0));
  // ******************************************************

  // ******************************************************
  // * MARKS
  // * $a(x-cutoff)^{power} + b(x-cutoff)$
  // ******************************************************
  RooRealVar a("a", "a", 1, 0, 18);
  RooRealVar b("b", "b", -0.001, -0.05, 0.0);
  RooRealVar power("power", "Power", 0.02, 0.0, 0.1);
  RooRealVar cutoff("cutoff", "Cutoff", 22, 0, 40);

  MarksBG bg("bg", "bg", x, a, b, power, cutoff);

  a.setConstant();
  power.setConstant();
  bg.fitTo(rooDataSet, Range(200, 800));

  b.setConstant();
  a.setConstant(kFALSE);
  bg.fitTo(rooDataSet, Range(0.0, 40.0));

  power.setConstant(kFALSE);
  bg.fitTo(rooDataSet, Range(40.0, 840.0));
  // ******************************************************

  // ******************************************************
  // * MARKS + erf
  // * $a(x-cutoff)^{power} + b(x-cutoff)$
  // ******************************************************
  // RooRealVar a("a", "a", 1, 0, 18);
  // RooRealVar b("b", "b", -0.001, -0.05, 0.0);
  // RooRealVar power("power", "Power", 0.02, 0.0, 0.1);
  // RooRealVar cutoff("cutoff", "Cutoff", 22.1, 0, 40);

  // RooRealVar shift("shift", "shift", 2, -10.0, 10.0);
  // RooRealVar shrink("shrink", "shrink", 1.2, 0.0, 2.0);

  // modErf er("er", "er", x, cutoff, shift, shrink);

  // MarksBG mark_bg("mark_bg", "mark_bg", x, a, b, power, cutoff);

  // RooProdPdf bg("bg", "mark_bg*er", RooArgList(er, mark_bg));

  // b.setConstant(kTRUE);
  // bg.fitTo(rooDataSet, NumCPU(8),Range(0.0, 840.0));
  // ******************************************************
  
  // ******************************************************
  // * RYUN + erf
  // ******************************************************
  // RooRealVar slope("slope", "Slope", 0.0003, 0.0, 0.01);
  // RooRealVar power("power", "Power", 0.3, 0.0, 1.0);
  // RooRealVar cutoff("cutoff", "Cutoff", 20, 10, 40);
  // RooProduct mcutoff("mcutoff", "mcutoff", RooArgList(RooConst(-1), cutoff));
  // RooAddition xshift("x_cutoff_shift", "x+cutoff", RooArgList(x, mcutoff));
  // PowerLaw pow_pdf("powerlaw", "x^k", xshift, power);
  // RooProduct exp_c("exp_c", "exp_c", RooArgList(RooConst(-1), slope));
  // RooExponential exp_pdf("exp", "exponential pdf", xshift, exp_c);
  // RooProdPdf ryun_bg("ryun_bg", "pow*exp", RooArgSet(pow_pdf, exp_pdf));

  // RooRealVar shift("shift", "shift", 2, -10.0, 10.0);
  // RooRealVar shrink("shrink", "shrink", 1.2, 0.0, 2.0);

  // modErf er("er", "er", x, cutoff, shift, shrink);
  // RooProdPdf bg("bg", "ryun_bg*er", RooArgList(er, ryun_bg));

  // bg.fitTo(rooDataSet,Range(0.0, 840.0));
  // ******************************************************

  // Plot
  TCanvas *canv = new TCanvas("canv", "canv");
  canv->Divide(1, 2);
  canv->cd(1);
  RooPlot *frame = x.frame(Bins(200));
  rooDataSet.plotOn(frame);
  bg.plotOn(frame);
  bg.paramOn(frame);
  frame->DrawClone();

  canv->cd(2);
  RooPlot *frame_pull = x.frame(Title("Pull"), Bins(200));
  auto pull_hist = frame->pullHist();
  frame_pull->addPlotable(pull_hist, "P");
  frame_pull->DrawClone();
  canv->Draw();
}

int main(int argc, char **argv)
{
  fit();
}
