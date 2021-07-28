/// \file
/// \ingroup tutorial_tmva
/// \notebook -nodraw
/// This macro provides a simple example on how to use the trained classifiers
/// within an analysis module
/// - Project   : TMVA - a Root-integrated toolkit for multivariate data analysis
/// - Package   : TMVA
/// - Exectuable: TMVAClassificationApplication
///
/// \macro_output
/// \macro_code
/// \author Andreas Hoecker

#include <cstdlib>
#include <vector>
#include <iostream>
#include <map>
#include <string>

#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TStopwatch.h"

#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"

using namespace TMVA;

enum input_type
{
   sig,
   bkg,
   def
};

int input = input_type::bkg;

//void TMVAClassificationApplication(std::string filename = "/eos/lhcb/user/f/feoliva/Lc2pKpi/LcStudy_sweights.root", std::string outname = "Lc_100ktrain_100ktesting_1_6Mkevents.root" , TString myMethodList = "" )
//void TMVAClassificationApplication(std::string filename = "/eos/lhcb/user/f/feoliva/Lc2pKpi/LcStudy_sweights.root", std::string outname = "Lc_100ktrain_100ktesting_1_6Mkevents.root" , TString myMethodList = "" )
//void TMVAClassificationApplication(std::string filename = "/eos/lhcb/user/f/feoliva/Analysis/Xicpstar_100files/XicpStStToLcKPi_all.root", std::string outname = "Lc_3ktrain_3ktesting_150kevents.root" , TString myMethodList = "" )
//void TMVAClassificationApplication(std::string filename = "/eos/lhcb/user/f/feoliva/Analysis/May/XicpStStToLcKPi_all.root", std::string outname = "Lc_3ktrain_3ktesting_95kevents.root" , TString myMethodList = "" )
//void TMVAClassificationApplication(std::string filename = "/eos/lhcb/user/f/feoliva/Lc2pKpi/Lc_sample_1000files_2016MagDown.root", std::string outname = "Lc_100ktrain_100ktesting_1_6Mevents.root" , TString myMethodList = "" )
//void TMVAClassificationApplication(std::string filename = "/eos/lhcb/user/f/feoliva/Lc2pKpi/Lc_sample_1000files_2016MagDown.root", std::string outname = "Lc_100ktrain_100ktesting_1_6Mevents_fixed.root" , TString myMethodList = "" )
void TMVAClassificationApplication(std::string filename = "", std::string outname = "", TString myMethodList = "")
{
   std::string sig_dataset = getenv("CURRENT_SIG_DATASET");
   std::string bkg_dataset = getenv("CURRENT_BKG_DATASET");

   switch (input)
   {
   case input_type::sig:
      filename = sig_dataset;
      break;

   case input_type::bkg:
      filename = bkg_dataset;
      break;

   default:
      std::cout << "Using default name for input dataset: " << filename << std::endl;
      break;
   }

   std::string outname = "TMVA_" + filename;

   //---------------------------------------------------------------
   // This loads the library
   TMVA::Tools::Instance();

   // Default MVA methods to be trained + tested
   std::map<std::string, int> Use;

   // Cut optimisation
   Use["Cuts"] = 0;
   Use["CutsD"] = 0;
   Use["CutsPCA"] = 0;
   Use["CutsGA"] = 0;
   Use["CutsSA"] = 0;
   //
   // 1-dimensional likelihood ("naive Bayes estimator")
   Use["Likelihood"] = 0;
   Use["LikelihoodD"] = 0;   // the "D" extension indicates decorrelated input variables (see option strings)
   Use["LikelihoodPCA"] = 0; // the "PCA" extension indicates PCA-transformed input variables (see option strings)
   Use["LikelihoodKDE"] = 0;
   Use["LikelihoodMIX"] = 0;
   //
   // Mutidimensional likelihood and Nearest-Neighbour methods
   Use["PDERS"] = 0;
   Use["PDERSD"] = 0;
   Use["PDERSPCA"] = 0;
   Use["PDEFoam"] = 0;
   Use["PDEFoamBoost"] = 0; // uses generalised MVA method boosting
   Use["KNN"] = 0;          // k-nearest neighbour method
   //
   // Linear Discriminant Analysis
   Use["LD"] = 0; // Linear Discriminant identical to Fisher
   Use["Fisher"] = 0;
   Use["FisherG"] = 0;
   Use["BoostedFisher"] = 0; // uses generalised MVA method boosting
   Use["HMatrix"] = 0;
   //
   // Function Discriminant analysis
   Use["FDA_GA"] = 0; // minimisation of user-defined function using Genetics Algorithm
   Use["FDA_SA"] = 0;
   Use["FDA_MC"] = 0;
   Use["FDA_MT"] = 0;
   Use["FDA_GAMT"] = 0;
   Use["FDA_MCMT"] = 0;
   //
   // Neural Networks (all are feed-forward Multilayer Perceptrons)
   Use["MLP"] = 1;      // Recommended ANN
   Use["MLPBFGS"] = 0;  // Recommended ANN with optional training method
   Use["MLPBNN"] = 0;   // Recommended ANN with BFGS training method and bayesian regulator
   Use["CFMlpANN"] = 0; // Depreciated ANN from ALEPH
   Use["TMlpANN"] = 0;  // ROOT's own ANN
   Use["DNN_CPU"] = 0;  // CUDA-accelerated DNN training.
   Use["DNN_GPU"] = 0;  // Multi-core accelerated DNN.
   //
   // Support Vector Machine
   Use["SVM"] = 0;
   //
   // Boosted Decision Trees
   Use["BDT"] = 1;  // uses Adaptive Boost
   Use["BDTG"] = 1; // uses Gradient Boost
   Use["BDTB"] = 0; // uses Bagging
   Use["BDTD"] = 0; // decorrelation + Adaptive Boost
   Use["BDTF"] = 0; // allow usage of fisher discriminant for node splitting
   //
   // Friedman's RuleFit method, ie, an optimised series of cuts ("rules")
   Use["RuleFit"] = 0;
   // ---------------------------------------------------------------
   Use["Plugin"] = 0;
   Use["Category"] = 0;
   Use["SVM_Gauss"] = 0;
   Use["SVM_Poly"] = 0;
   Use["SVM_Lin"] = 0;

   std::cout << std::endl;
   std::cout << "==> Start TMVAClassificationApplication" << std::endl;

   // Select methods (don't look at this code - not of interest)
   if (myMethodList != "")
   {
      for (std::map<std::string, int>::iterator it = Use.begin(); it != Use.end(); it++)
         it->second = 0;

      std::vector<TString> mlist = gTools().SplitString(myMethodList, ',');
      for (UInt_t i = 0; i < mlist.size(); i++)
      {
         std::string regMethod(mlist[i]);

         if (Use.find(regMethod) == Use.end())
         {
            std::cout << "Method \"" << regMethod
                      << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
            for (std::map<std::string, int>::iterator it = Use.begin(); it != Use.end(); it++)
            {
               std::cout << it->first << " ";
            }
            std::cout << std::endl;
            return;
         }
         Use[regMethod] = 1;
      }
   }

   // --------------------------------------------------------------------------------------------------

   // Create the Reader object

   TMVA::Reader *reader = new TMVA::Reader("!Color:!Silent");

   // Create a set of variables and declare them to the reader
   // - the variable names MUST corresponds in name and type to those given in the weight file(s) used
   //Float_t  Lc_ENDVERTEX_CHI2, Lc_DIRA_OWNPV, Lc_IPCHI2_OWNPV, Lc_FDCHI2_OWNPV, p_PT, p_IPCHI2_OWNPV, p_ProbNNp, Km_PT, Km_IPCHI2_OWNPV, Km_ProbNNk, pip_PT, pip_IPCHI2_OWNPV, pip_ProbNNpi, p_MC15TuneV1_ProbNNp,  Km_MC15TuneV1_ProbNNk,  pip_MC15TuneV1_ProbNNpi, Lc_ETA, Lc_DOCAMAX, Lc_DOCAMIN, Lc_DOCACHI2MAX, Lc_DOCA12, Lc_DOCA13, Lc_DOCA23;
   Float_t Lc_ENDVERTEX_CHI2, Lc_DIRA_OWNPV, Lc_IPCHI2_OWNPV, Lc_FDCHI2_OWNPV, p_PT, p_IPCHI2_OWNPV, p_ProbNNp, Km_PT, Km_IPCHI2_OWNPV, Km_ProbNNk, pip_PT, pip_IPCHI2_OWNPV, pip_ProbNNpi;

   reader->AddVariable("Lc_ENDVERTEX_CHI2:=log(Lc_ENDVERTEX_CHI2)", &Lc_ENDVERTEX_CHI2);
   reader->AddVariable("Lc_DIRA_OWNPV:=log(1-Lc_DIRA_OWNPV)", &Lc_DIRA_OWNPV);
   reader->AddVariable("Lc_IPCHI2_OWNPV:=log(Lc_IPCHI2_OWNPV)", &Lc_IPCHI2_OWNPV);
   reader->AddVariable("Lc_FDCHI2_OWNPV:=log(Lc_FDCHI2_OWNPV)", &Lc_FDCHI2_OWNPV);
   reader->AddVariable("p_PT:=log(p_PT)", &p_PT);
   reader->AddVariable("p_IPCHI2_OWNPV:=log(p_IPCHI2_OWNPV)", &p_IPCHI2_OWNPV);
   reader->AddVariable("p_ProbNNp:=1-sqrt(1-p_ProbNNp)", &p_ProbNNp);
   reader->AddVariable("Km_PT:=log(Km_PT)", &Km_PT);
   reader->AddVariable("Km_IPCHI2_OWNPV:=log(Km_IPCHI2_OWNPV)", &Km_IPCHI2_OWNPV);
   reader->AddVariable("Km_ProbNNk:=1-sqrt(1-Km_ProbNNk)", &Km_ProbNNk);
   reader->AddVariable("pip_PT:=log(pip_PT)", &pip_PT);
   reader->AddVariable("pip_IPCHI2_OWNPV:=log(pip_IPCHI2_OWNPV)", &pip_IPCHI2_OWNPV);
   reader->AddVariable("pip_ProbNNpi:=1-sqrt(1-pip_ProbNNpi)", &pip_ProbNNpi);

   //reader->AddVariable("p_MC15TuneV1_ProbNNp:=1-sqrt(1-p_MC15TuneV1_ProbNNp)", &p_MC15TuneV1_ProbNNp);

   //reader->AddVariable("Km_MC15TuneV1_ProbNNk:=1-sqrt(1-Km_MC15TuneV1_ProbNNk)", &Km_MC15TuneV1_ProbNNk);
   //reader->AddVariable("pi_MC15TuneV1_ProbNNpi:=1-sqrt(1-pip_MC15TuneV1_ProbNNpi)", &pip_MC15TuneV1_ProbNNpi);

   //reader->AddVariable("Lc_ETA", &Lc_ETA);
   //reader->AddVariable("Lc_DOCAMAX:=log(Lc_DOCAMAX)", &Lc_DOCAMAX);
   //reader->AddVariable("Lc_DOCAMIN:=log(Lc_DOCAMIN)", &Lc_DOCAMIN);
   //reader->AddVariable("Lc_DOCACHI2MAX:=log(Lc_DOCACHI2MAX)", &Lc_DOCACHI2MAX);
   //reader->AddVariable("Lc_DOCA12:=log(Lc_DOCA12)", &Lc_DOCA12);
   //reader->AddVariable("Lc_DOCA13:=log(Lc_DOCA13)", &Lc_DOCA13);
   //reader->AddVariable("Lc_DOCA23:=log(Lc_DOCA23)", &Lc_DOCA23);
   /*reader->AddVariable("Lc_ENDVERTEX_CHI2", &Lc_ENDVERTEX_CHI2);
   reader->AddVariable("Lc_DIRA_OWNPV", &Lc_DIRA_OWNPV);
   reader->AddVariable("Lc_IPCHI2_OWNPV", &Lc_IPCHI2_OWNPV);
   reader->AddVariable("Lc_FDCHI2_OWNPV", &Lc_FDCHI2_OWNPV);

   reader->AddVariable("p_PT", &p_PT);
   reader->AddVariable("p_IPCHI2_OWNPV", &p_IPCHI2_OWNPV);
   reader->AddVariable("p_ProbNNp", &p_ProbNNp);

   reader->AddVariable("Km_PT", &Km_PT);
   reader->AddVariable("Km_IPCHI2_OWNPV", &Km_IPCHI2_OWNPV);
   reader->AddVariable("Km_ProbNNk", &Km_ProbNNk);

   reader->AddVariable("pip_PT", &pip_PT);
   reader->AddVariable("pip_IPCHI2_OWNPV", &pip_IPCHI2_OWNPV);
   reader->AddVariable("pip_ProbNNpi", &pip_ProbNNpi);*/

   // Spectator variables declared in the training have to be added to the reader, too
   //Float_t spec1,spec2;
   //reader->AddSpectator( "spec1 := var1*2",   &spec1 );
   //reader->AddSpectator( "spec2 := var1*3",   &spec2 );

   //Float_t Category_cat1, Category_cat2, Category_cat3;
   //if (Use["Category"]){
   // Add artificial spectators for distinguishing categories
   //   reader->AddSpectator( "Category_cat1 := var3<=0",             &Category_cat1 );
   //   reader->AddSpectator( "Category_cat2 := (var3>0)&&(var4<0)",  &Category_cat2 );
   //   reader->AddSpectator( "Category_cat3 := (var3>0)&&(var4>=0)", &Category_cat3 );
   //}

   // Book the MVA methods

   TString dir = "dataset/weights/";
   TString prefix = "TMVAClassification";

   // Book method(s)
   for (std::map<std::string, int>::iterator it = Use.begin(); it != Use.end(); it++)
   {
      if (it->second)
      {
         TString methodName = TString(it->first) + TString(" method");
         TString weightfile = dir + prefix + TString("_") + TString(it->first) + TString(".weights.xml");
         reader->BookMVA(methodName, weightfile);
      }
   }

   // Book output histograms
   UInt_t nbin = 100;
   TH1F *histLk(0);
   TH1F *histLkD(0);
   TH1F *histLkPCA(0);
   TH1F *histLkKDE(0);
   TH1F *histLkMIX(0);
   TH1F *histPD(0);
   TH1F *histPDD(0);
   TH1F *histPDPCA(0);
   TH1F *histPDEFoam(0);
   TH1F *histPDEFoamErr(0);
   TH1F *histPDEFoamSig(0);
   TH1F *histKNN(0);
   TH1F *histHm(0);
   TH1F *histFi(0);
   TH1F *histFiG(0);
   TH1F *histFiB(0);
   TH1F *histLD(0);
   TH1F *histNn(0);
   TH1F *histNnbfgs(0);
   TH1F *histNnbnn(0);
   TH1F *histNnC(0);
   TH1F *histNnT(0);
   TH1F *histBdt(0);
   TH1F *histBdtG(0);
   TH1F *histBdtB(0);
   TH1F *histBdtD(0);
   TH1F *histBdtF(0);
   TH1F *histRf(0);
   TH1F *histSVMG(0);
   TH1F *histSVMP(0);
   TH1F *histSVML(0);
   TH1F *histFDAMT(0);
   TH1F *histFDAGA(0);
   TH1F *histCat(0);
   TH1F *histPBdt(0);
   TH1F *histDnnGpu(0);
   TH1F *histDnnCpu(0);

   if (Use["Likelihood"])
      histLk = new TH1F("MVA_Likelihood", "MVA_Likelihood", nbin, -1, 1);
   if (Use["LikelihoodD"])
      histLkD = new TH1F("MVA_LikelihoodD", "MVA_LikelihoodD", nbin, -1, 0.9999);
   if (Use["LikelihoodPCA"])
      histLkPCA = new TH1F("MVA_LikelihoodPCA", "MVA_LikelihoodPCA", nbin, -1, 1);
   if (Use["LikelihoodKDE"])
      histLkKDE = new TH1F("MVA_LikelihoodKDE", "MVA_LikelihoodKDE", nbin, -0.00001, 0.99999);
   if (Use["LikelihoodMIX"])
      histLkMIX = new TH1F("MVA_LikelihoodMIX", "MVA_LikelihoodMIX", nbin, 0, 1);
   if (Use["PDERS"])
      histPD = new TH1F("MVA_PDERS", "MVA_PDERS", nbin, 0, 1);
   if (Use["PDERSD"])
      histPDD = new TH1F("MVA_PDERSD", "MVA_PDERSD", nbin, 0, 1);
   if (Use["PDERSPCA"])
      histPDPCA = new TH1F("MVA_PDERSPCA", "MVA_PDERSPCA", nbin, 0, 1);
   if (Use["KNN"])
      histKNN = new TH1F("MVA_KNN", "MVA_KNN", nbin, 0, 1);
   if (Use["HMatrix"])
      histHm = new TH1F("MVA_HMatrix", "MVA_HMatrix", nbin, -0.95, 1.55);
   if (Use["Fisher"])
      histFi = new TH1F("MVA_Fisher", "MVA_Fisher", nbin, -4, 4);
   if (Use["FisherG"])
      histFiG = new TH1F("MVA_FisherG", "MVA_FisherG", nbin, -1, 1);
   if (Use["BoostedFisher"])
      histFiB = new TH1F("MVA_BoostedFisher", "MVA_BoostedFisher", nbin, -2, 2);
   if (Use["LD"])
      histLD = new TH1F("MVA_LD", "MVA_LD", nbin, -2, 2);
   if (Use["MLP"])
      histNn = new TH1F("MVA_MLP", "MVA_MLP", nbin, -1.25, 1.5);
   if (Use["MLPBFGS"])
      histNnbfgs = new TH1F("MVA_MLPBFGS", "MVA_MLPBFGS", nbin, -1.25, 1.5);
   if (Use["MLPBNN"])
      histNnbnn = new TH1F("MVA_MLPBNN", "MVA_MLPBNN", nbin, -1.25, 1.5);
   if (Use["CFMlpANN"])
      histNnC = new TH1F("MVA_CFMlpANN", "MVA_CFMlpANN", nbin, 0, 1);
   if (Use["TMlpANN"])
      histNnT = new TH1F("MVA_TMlpANN", "MVA_TMlpANN", nbin, -1.3, 1.3);
   if (Use["DNN_GPU"])
      histDnnGpu = new TH1F("MVA_DNN_GPU", "MVA_DNN_GPU", nbin, -0.1, 1.1);
   if (Use["DNN_CPU"])
      histDnnCpu = new TH1F("MVA_DNN_CPU", "MVA_DNN_CPU", nbin, -0.1, 1.1);
   if (Use["BDT"])
      histBdt = new TH1F("MVA_BDT", "MVA_BDT", nbin, -0.8, 0.8);
   if (Use["BDTG"])
      histBdtG = new TH1F("MVA_BDTG", "MVA_BDTG", nbin, -1.0, 1.0);
   if (Use["BDTB"])
      histBdtB = new TH1F("MVA_BDTB", "MVA_BDTB", nbin, -1.0, 1.0);
   if (Use["BDTD"])
      histBdtD = new TH1F("MVA_BDTD", "MVA_BDTD", nbin, -0.8, 0.8);
   if (Use["BDTF"])
      histBdtF = new TH1F("MVA_BDTF", "MVA_BDTF", nbin, -1.0, 1.0);
   if (Use["RuleFit"])
      histRf = new TH1F("MVA_RuleFit", "MVA_RuleFit", nbin, -2.0, 2.0);
   if (Use["SVM_Gauss"])
      histSVMG = new TH1F("MVA_SVM_Gauss", "MVA_SVM_Gauss", nbin, 0.0, 1.0);
   if (Use["SVM_Poly"])
      histSVMP = new TH1F("MVA_SVM_Poly", "MVA_SVM_Poly", nbin, 0.0, 1.0);
   if (Use["SVM_Lin"])
      histSVML = new TH1F("MVA_SVM_Lin", "MVA_SVM_Lin", nbin, 0.0, 1.0);
   if (Use["FDA_MT"])
      histFDAMT = new TH1F("MVA_FDA_MT", "MVA_FDA_MT", nbin, -2.0, 3.0);
   if (Use["FDA_GA"])
      histFDAGA = new TH1F("MVA_FDA_GA", "MVA_FDA_GA", nbin, -2.0, 3.0);
   if (Use["Category"])
      histCat = new TH1F("MVA_Category", "MVA_Category", nbin, -2., 2.);
   if (Use["Plugin"])
      histPBdt = new TH1F("MVA_PBDT", "MVA_BDT", nbin, -0.8, 0.8);

   // PDEFoam also returns per-event error, fill in histogram, and also fill significance
   if (Use["PDEFoam"])
   {
      histPDEFoam = new TH1F("MVA_PDEFoam", "MVA_PDEFoam", nbin, 0, 1);
      histPDEFoamErr = new TH1F("MVA_PDEFoamErr", "MVA_PDEFoam error", nbin, 0, 1);
      histPDEFoamSig = new TH1F("MVA_PDEFoamSig", "MVA_PDEFoam significance", nbin, 0, 10);
   }

   // Book example histogram for probability (the other methods are done similarly)
   TH1F *probHistFi(0), *rarityHistFi(0);
   if (Use["Fisher"])
   {
      probHistFi = new TH1F("MVA_Fisher_Proba", "MVA_Fisher_Proba", nbin, 0, 1);
      rarityHistFi = new TH1F("MVA_Fisher_Rarity", "MVA_Fisher_Rarity", nbin, 0, 1);
   }

   // Prepare input tree (this must be replaced by your data source)
   // in this example, there is a toy tree with signal and one with background events
   // we'll later on use only the "signal" events for the test in this example.
   //
   //TFile *input(0);
   TFile *input = new TFile(filename.c_str());
   /*
   TString fname = "../Tuples/LcK_Turbo_2016_MagDown_small_sweight.root";
 
   if (!gSystem->AccessPathName( fname )) {
      input = TFile::Open( fname ); // check if file in local directory exists
   }
   else {
      TFile::SetCacheFileDir(".");
      input = TFile::Open("http://root.cern.ch/files/tmva_class_example.root", "CACHEREAD"); // if not: download from ROOT server
   }
   if (!input) {
      std::cout << "ERROR: could not open data file" << std::endl;
      exit(1);
   }
   */
   std::cout << "--- TMVAClassificationApp    : Using input file: " << input->GetName() << std::endl;

   // Event loop

   // Prepare the event tree
   // - Here the variable names have to corresponds to your tree
   // - You can use the same variables as above which is slightly faster,
   //   but of course you can use different ones and copy the values inside the event loop
   //
   std::cout << "--- Select signal sample" << std::endl;
   TTree *theTree = (TTree *)input->Get("DecayTree");

   TCut cut = TCut("");
   TFile *output = new TFile(outname.c_str(), "RECREATE");
   TTree *smallTree = theTree->CopyTree(cut);
   TTree *newtree = smallTree->CloneTree(-1);

   std::cout << "Made all the trees" << std::endl;

   float bdt;
   TBranch *b_bdt = newtree->Branch("bdt", &bdt, "bdt/F");
   float mlp;
   TBranch *b_mlp = newtree->Branch("mlp", &mlp, "mlp/F");
   //float bdtd; TBranch*  b_bdtd = newtree->Branch("bdtd", &bdtd,"bdtd/F");
   float bdtg;
   TBranch *b_bdtg = newtree->Branch("bdtg", &bdtg, "bdtg/F");

   std::cout << "Made all the bdt and mlp branches" << std::endl;

   //Double_t Lc_ENDVERTEX_CHI2, Lc_DIRA_OWNPV, Lc_IPCHI2_OWNPV, Lc_FD_OWNPV;
   //Double_t p_PT, p_IPCHI2_OWNPV, p_ProbNNp;
   //Double_t Km_PT, Km_IPCHI2_OWNPV, Km_ProbNNk;
   //Double_t pip_PT, pip_IPCHI2_OWNPV, pip_ProbNNpi;

   //Double_t  LcENDVERTEX_CHI2, LcDIRA_OWNPV, LcIPCHI2_OWNPV, LcFDCHI2_OWNPV, pPT, pIPCHI2_OWNPV, pProbNNp, KmPT, KmIPCHI2_OWNPV, KmProbNNk, pipPT, pipIPCHI2_OWNPV, pipProbNNpi, pMC15TuneV1_ProbNNp, KmMC15TuneV1_ProbNNk, pipMC15TuneV1_ProbNNpi;
   Double_t LcENDVERTEX_CHI2, LcDIRA_OWNPV, LcIPCHI2_OWNPV, LcFDCHI2_OWNPV, pPT, pIPCHI2_OWNPV, pProbNNp, KmPT, KmIPCHI2_OWNPV, KmProbNNk, pipPT, pipIPCHI2_OWNPV, pipProbNNpi;
   //Double_t Lc_M, Lc_PT, Lc_TAU, Lc_ENDVERTEX_CHI2, p_PT, Km_PT, pip_PT;

   theTree->SetBranchAddress("Lc_ENDVERTEX_CHI2", &LcENDVERTEX_CHI2);
   theTree->SetBranchAddress("Lc_DIRA_OWNPV", &LcDIRA_OWNPV);
   theTree->SetBranchAddress("Lc_IPCHI2_OWNPV", &LcIPCHI2_OWNPV);
   theTree->SetBranchAddress("Lc_FDCHI2_OWNPV", &LcFDCHI2_OWNPV);

   theTree->SetBranchAddress("p_PT", &pPT);
   theTree->SetBranchAddress("p_IPCHI2_OWNPV", &pIPCHI2_OWNPV);
   theTree->SetBranchAddress("p_ProbNNp", &pProbNNp);

   theTree->SetBranchAddress("Km_PT", &KmPT);
   theTree->SetBranchAddress("Km_IPCHI2_OWNPV", &KmIPCHI2_OWNPV);
   theTree->SetBranchAddress("Km_ProbNNk", &KmProbNNk);

   theTree->SetBranchAddress("pip_PT", &pipPT);
   theTree->SetBranchAddress("pip_IPCHI2_OWNPV", &pipIPCHI2_OWNPV);
   theTree->SetBranchAddress("pip_ProbNNpi", &pipProbNNpi);

   //  theTree->SetBranchAddress("p_MC15TuneV1_ProbNNp", &pMC15TuneV1_ProbNNp);
   //  theTree->SetBranchAddress("Km_MC15TuneV1_ProbNNk", &KmMC15TuneV1_ProbNNk);
   //  theTree->SetBranchAddress("pip_MC15TuneV1_ProbNNpi", &pipMC15TuneV1_ProbNNpi);

   std::cout << "set all the branch addresses" << std::endl;

   // Efficiency calculator for cut method
   Int_t nSelCutsGA = 0;
   Double_t effS = 1.;

   std::vector<Float_t> vecVar(4); // vector for EvaluateMVA tests

   std::cout << "--- Processing: " << theTree->GetEntries() << " events" << std::endl;
   TStopwatch sw;
   sw.Start();
   for (Long64_t ievt = 0; ievt < theTree->GetEntries(); ievt++)
   {

      if (ievt % 100000 == 0)
         std::cout << "--- ... Processing event: " << ievt << std::endl;

      theTree->GetEntry(ievt);

      Lc_ENDVERTEX_CHI2 = LcENDVERTEX_CHI2;
      Lc_DIRA_OWNPV = LcDIRA_OWNPV;
      Lc_IPCHI2_OWNPV = LcIPCHI2_OWNPV;
      Lc_FDCHI2_OWNPV = LcFDCHI2_OWNPV;

      p_PT = pPT;
      p_IPCHI2_OWNPV = pIPCHI2_OWNPV;
      p_ProbNNp = pProbNNp;

      Km_PT = KmPT;
      Km_IPCHI2_OWNPV = KmIPCHI2_OWNPV;
      Km_ProbNNk = KmProbNNk;

      pip_PT = pipPT;
      pip_IPCHI2_OWNPV = pipIPCHI2_OWNPV;
      pip_ProbNNpi = pipProbNNpi;

      //      p_MC15TuneV1_ProbNNp   = pMC15TuneV1_ProbNNp;
      //      Km_MC15TuneV1_ProbNNk  = KmMC15TuneV1_ProbNNk;
      //      pip_MC15TuneV1_ProbNNpi= pipMC15TuneV1_ProbNNpi;

      if (Use["CutsGA"])
      {
         // Cuts is a special case: give the desired signal efficienciy
         Bool_t passed = reader->EvaluateMVA("CutsGA method", effS);
         if (passed)
            nSelCutsGA++;
      }

      if (Use["Likelihood"])
         histLk->Fill(reader->EvaluateMVA("Likelihood method"));
      if (Use["LikelihoodD"])
         histLkD->Fill(reader->EvaluateMVA("LikelihoodD method"));
      if (Use["LikelihoodPCA"])
         histLkPCA->Fill(reader->EvaluateMVA("LikelihoodPCA method"));
      if (Use["LikelihoodKDE"])
         histLkKDE->Fill(reader->EvaluateMVA("LikelihoodKDE method"));
      if (Use["LikelihoodMIX"])
         histLkMIX->Fill(reader->EvaluateMVA("LikelihoodMIX method"));
      if (Use["PDERS"])
         histPD->Fill(reader->EvaluateMVA("PDERS method"));
      if (Use["PDERSD"])
         histPDD->Fill(reader->EvaluateMVA("PDERSD method"));
      if (Use["PDERSPCA"])
         histPDPCA->Fill(reader->EvaluateMVA("PDERSPCA method"));
      if (Use["KNN"])
         histKNN->Fill(reader->EvaluateMVA("KNN method"));
      if (Use["HMatrix"])
         histHm->Fill(reader->EvaluateMVA("HMatrix method"));
      if (Use["Fisher"])
         histFi->Fill(reader->EvaluateMVA("Fisher method"));
      if (Use["FisherG"])
         histFiG->Fill(reader->EvaluateMVA("FisherG method"));
      if (Use["BoostedFisher"])
         histFiB->Fill(reader->EvaluateMVA("BoostedFisher method"));
      if (Use["LD"])
         histLD->Fill(reader->EvaluateMVA("LD method"));
      if (Use["MLP"])
      {
         histNn->Fill(reader->EvaluateMVA("MLP method"));
         mlp = reader->EvaluateMVA("MLP method");
         b_mlp->Fill();
      }
      if (Use["MLPBFGS"])
         histNnbfgs->Fill(reader->EvaluateMVA("MLPBFGS method"));
      if (Use["MLPBNN"])
         histNnbnn->Fill(reader->EvaluateMVA("MLPBNN method"));
      if (Use["CFMlpANN"])
         histNnC->Fill(reader->EvaluateMVA("CFMlpANN method"));
      if (Use["TMlpANN"])
         histNnT->Fill(reader->EvaluateMVA("TMlpANN method"));
      if (Use["DNN_GPU"])
         histDnnGpu->Fill(reader->EvaluateMVA("DNN_GPU method"));
      if (Use["DNN_CPU"])
         histDnnCpu->Fill(reader->EvaluateMVA("DNN_CPU method"));
      if (Use["BDT"])
      {
         histBdt->Fill(reader->EvaluateMVA("BDT method"));
         bdt = reader->EvaluateMVA("BDT method");
         b_bdt->Fill();
      }
      if (Use["BDTG"])
      {
         histBdtG->Fill(reader->EvaluateMVA("BDTG method"));
         bdtg = reader->EvaluateMVA("BDTG method");
         b_bdtg->Fill();
      }
      if (Use["BDTB"])
         histBdtB->Fill(reader->EvaluateMVA("BDTB method"));
      if (Use["BDTD"])
         histBdtD->Fill(reader->EvaluateMVA("BDTD method"));
      if (Use["BDTF"])
         histBdtF->Fill(reader->EvaluateMVA("BDTF method"));
      if (Use["RuleFit"])
         histRf->Fill(reader->EvaluateMVA("RuleFit method"));
      if (Use["SVM_Gauss"])
         histSVMG->Fill(reader->EvaluateMVA("SVM_Gauss method"));
      if (Use["SVM_Poly"])
         histSVMP->Fill(reader->EvaluateMVA("SVM_Poly method"));
      if (Use["SVM_Lin"])
         histSVML->Fill(reader->EvaluateMVA("SVM_Lin method"));
      if (Use["FDA_MT"])
         histFDAMT->Fill(reader->EvaluateMVA("FDA_MT method"));
      if (Use["FDA_GA"])
         histFDAGA->Fill(reader->EvaluateMVA("FDA_GA method"));
      if (Use["Category"])
         histCat->Fill(reader->EvaluateMVA("Category method"));
      if (Use["Plugin"])
         histPBdt->Fill(reader->EvaluateMVA("P_BDT method"));

      // Retrieve also per-event error
      if (Use["PDEFoam"])
      {
         Double_t val = reader->EvaluateMVA("PDEFoam method");
         Double_t err = reader->GetMVAError();
         histPDEFoam->Fill(val);
         histPDEFoamErr->Fill(err);
         if (err > 1.e-50)
            histPDEFoamSig->Fill(val / err);
      }

      // Retrieve probability instead of MVA output
      if (Use["Fisher"])
      {
         probHistFi->Fill(reader->GetProba("Fisher method"));
         rarityHistFi->Fill(reader->GetRarity("Fisher method"));
      }
   }

   // Get elapsed time
   sw.Stop();
   std::cout << "--- End of event loop: ";
   sw.Print();

   // Get efficiency for cuts classifier
   if (Use["CutsGA"])
      std::cout << "--- Efficiency for CutsGA method: " << double(nSelCutsGA) / theTree->GetEntries()
                << " (for a required signal efficiency of " << effS << ")" << std::endl;

   if (Use["CutsGA"])
   {

      // test: retrieve cuts for particular signal efficiency
      // CINT ignores dynamic_casts so we have to use a cuts-secific Reader function to acces the pointer
      TMVA::MethodCuts *mcuts = reader->FindCutsMVA("CutsGA method");

      if (mcuts)
      {
         std::vector<Double_t> cutsMin;
         std::vector<Double_t> cutsMax;
         mcuts->GetCuts(0.7, cutsMin, cutsMax);
         std::cout << "--- -------------------------------------------------------------" << std::endl;
         std::cout << "--- Retrieve cut values for signal efficiency of 0.7 from Reader" << std::endl;
         for (UInt_t ivar = 0; ivar < cutsMin.size(); ivar++)
         {
            std::cout << "... Cut: "
                      << cutsMin[ivar]
                      << " < \""
                      << mcuts->GetInputVar(ivar)
                      << "\" <= "
                      << cutsMax[ivar] << std::endl;
         }
         std::cout << "--- -------------------------------------------------------------" << std::endl;
      }
   }

   newtree->Write();
   output->Close();

   // Write histograms

   TFile *target = new TFile("TMVApp.root", "RECREATE");
   if (Use["Likelihood"])
      histLk->Write();
   if (Use["LikelihoodD"])
      histLkD->Write();
   if (Use["LikelihoodPCA"])
      histLkPCA->Write();
   if (Use["LikelihoodKDE"])
      histLkKDE->Write();
   if (Use["LikelihoodMIX"])
      histLkMIX->Write();
   if (Use["PDERS"])
      histPD->Write();
   if (Use["PDERSD"])
      histPDD->Write();
   if (Use["PDERSPCA"])
      histPDPCA->Write();
   if (Use["KNN"])
      histKNN->Write();
   if (Use["HMatrix"])
      histHm->Write();
   if (Use["Fisher"])
      histFi->Write();
   if (Use["FisherG"])
      histFiG->Write();
   if (Use["BoostedFisher"])
      histFiB->Write();
   if (Use["LD"])
      histLD->Write();
   if (Use["MLP"])
      histNn->Write();
   if (Use["MLPBFGS"])
      histNnbfgs->Write();
   if (Use["MLPBNN"])
      histNnbnn->Write();
   if (Use["CFMlpANN"])
      histNnC->Write();
   if (Use["TMlpANN"])
      histNnT->Write();
   if (Use["DNN_GPU"])
      histDnnGpu->Write();
   if (Use["DNN_CPU"])
      histDnnCpu->Write();
   if (Use["BDT"])
      histBdt->Write();
   if (Use["BDTG"])
      histBdtG->Write();
   if (Use["BDTB"])
      histBdtB->Write();
   if (Use["BDTD"])
      histBdtD->Write();
   if (Use["BDTF"])
      histBdtF->Write();
   if (Use["RuleFit"])
      histRf->Write();
   if (Use["SVM_Gauss"])
      histSVMG->Write();
   if (Use["SVM_Poly"])
      histSVMP->Write();
   if (Use["SVM_Lin"])
      histSVML->Write();
   if (Use["FDA_MT"])
      histFDAMT->Write();
   if (Use["FDA_GA"])
      histFDAGA->Write();
   if (Use["Category"])
      histCat->Write();
   if (Use["Plugin"])
      histPBdt->Write();

   // Write also error and significance histos
   if (Use["PDEFoam"])
   {
      histPDEFoam->Write();
      histPDEFoamErr->Write();
      histPDEFoamSig->Write();
   }

   // Write also probability hists
   if (Use["Fisher"])
   {
      if (probHistFi != 0)
         probHistFi->Write();
      if (rarityHistFi != 0)
         rarityHistFi->Write();
   }
   target->Close();

   std::cout << "--- Created root file: \"TMVApp.root\" containing the MVA output histograms" << std::endl;

   delete reader;

   std::cout << "==> TMVAClassificationApplication is done!" << std::endl
             << std::endl;
}

int main(int argc, char **argv)
{
   // TString methodList;
   // for (int i=1; i<argc; i++) {
   //    TString regMethod(argv[i]);
   //    if(regMethod=="-b" || regMethod=="--batch") continue;
   //    if (!methodList.IsNull()) methodList += TString(",");
   //    methodList += regMethod;
   // }
   TMVAClassificationApplication();
   return 0;
}