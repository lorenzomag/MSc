#include "pch.h"
#include "classification.hpp"
#include "from_sql.hpp"
#include "BSlogger.hpp"

int classification(std::set<std::string> method_list, const int run, bool save_output, bool use_SQL, TApplication *app = gApplication)
{
   // Enables Multi-threading for ROOT classes that provide it
   ROOT::EnableImplicitMT();
   std::cout << "<INFO>                : Using " << ROOT::GetThreadPoolSize() << " threads\n";

   //---------------------------------------------------------------
   // Loads SQLite database
   auto db = from_sql::open_db();
   std::map<std::string, std::string> feature_map = get_features(db, run);

   //---------------------------------------------------------------
   // This loads the library
   TMVA::Tools::Instance();

   // Default MVA methods to be trained + tested
   std::map<std::string, int> Use;
<<<<<<< HEAD

   // If database has no methods for current run, use default selection of methods
   // Neural Networks (all are feed-forward Multilayer Perceptrons)
   Use["MLP"] = 1; // Recommended ANN
   // Boosted Decision Trees
   Use["BDT"] = 0;  // uses Adaptive Boost
   Use["BDTG"] = 1; // uses Gradient Boost
   Use["BDTB"] = 0; // uses Bagging
   Use["BDTD"] = 0; // decorrelation + Adaptive Boost
   Use["BDTF"] = 0; // allow usage of fisher discriminant for node splitting
=======
   //
   // Neural Networks (all are feed-forward Multilayer Perceptrons)
   Use["MLP"] = 0; // Recommended ANN
>>>>>>> caae89e6fc87ebcbd8eb46fb81a537bc31c159a3
#ifdef R__HAS_TMVAGPU
   Use["DNN_GPU"] = 1; // CUDA-accelerated DNN training.
#else
   Use["DNN_GPU"] = 0;
#endif

#ifdef R__HAS_TMVACPU
   Use["DNN_CPU"] = 1; // Multi-core accelerated DNN.
#else
   Use["DNN_CPU"] = 0;
#endif
<<<<<<< HEAD
=======
   //
   // Boosted Decision Trees
   Use["BDT"] = 0;  // uses Adaptive Boost
   Use["BDTG"] = 0; // uses Gradient Boost
   Use["BDTB"] = 0; // uses Bagging
   Use["BDTD"] = 0; // decorrelation + Adaptive Boost
   Use["BDTF"] = 0; // allow usage of fisher discriminant for node splitting
   //
>>>>>>> caae89e6fc87ebcbd8eb46fb81a537bc31c159a3
   // Friedman's RuleFit method, ie, an optimised series of cuts ("rules")
   Use["RuleFit"] = 0;
   // ---------------------------------------------------------------
   if (!get_methods(db, run, Use))
   {
   }
   std::cout << std::endl;
   std::cout << "==> Start TMVAClassification" << std::endl;
   // Select methods (don't look at this code - not of interest)
   if (!method_list.empty())
   {
      for (auto entry : Use)
         entry.second = 0; // overwrite previous settings if command line args are provided
      for (std::map<std::string, int>::iterator it = Use.begin(); it != Use.end(); it++)
         it->second = 0;

      for (auto regMethod : method_list)
      {
         if (Use.find(regMethod) == Use.end())
         {
            std::cout << "Method \"" << regMethod << "\" not known in TMVA under this name. Choose among the following:" << std::endl;
            for (std::map<std::string, int>::iterator it = Use.begin(); it != Use.end(); it++)
               std::cout << it->first << " ";
            std::cout << std::endl;
            return 1;
         }
         Use[regMethod] = 1;
      }
   }

   // --------------------------------------------------------------------------------------------------

   // Here the preparation phase begins

   // Read training and test data
   // (it is also possible to use ASCII format as input -> see TMVA Users Guide)
   TFile *sigInput(0);
   TFile *bkgInput(0);

<<<<<<< HEAD
   //TString signalFileName = getenv("CURRENT_MC_DATASET");
   //TString bkgFileName = getenv("CURRENT_WS1_DATASET");
=======
   TString signalFileName = getenv("CURRENT_MC_DATASET");
   TString bkgFileName = getenv("CURRENT_WS1_DATASET");
>>>>>>> caae89e6fc87ebcbd8eb46fb81a537bc31c159a3

   TString signalFileName = getenv("SMALL_CURRENT_MC");
   TString bkgFileName = getenv("SMALL_CURRENT_WS1");
   if (!gSystem->AccessPathName(signalFileName))
   {
      sigInput = TFile::Open(signalFileName); // check if file in local directory exists
   }

   if (!sigInput)
   {
      std::cout << "ERROR: could not open data file" << std::endl;
      exit(1);
   }
   std::cout << "--- TMVAClassification       : Using input file: " << sigInput->GetName() << " for signal" << std::endl;

   if (!gSystem->AccessPathName(bkgFileName))
   {
      bkgInput = TFile::Open(bkgFileName); // check if file in local directory exists
   }

   if (!bkgInput)
   {
      std::cout << "ERROR: could not open data file" << std::endl;
      std::cout << bkgFileName << '\n';
      exit(1);
   }
   std::cout << "--- TMVAClassification       : Using input file: " << bkgInput->GetName() << " for background" << std::endl;

   // Register the training and test trees

   TTree *signalTree = (TTree *)sigInput->Get("DecayTree");
   TTree *background = (TTree *)bkgInput->Get("DecayTree");

   // Create a ROOT output file where TMVA will store ntuples, histograms, etc.
   TString outfileName;
   if (save_output)
<<<<<<< HEAD
      outfileName = (TString) "TMVA_run" + run + (TString) ".root";
=======
      outfileName = (TString)"TMVA_run" + run + (TString)".root";
>>>>>>> caae89e6fc87ebcbd8eb46fb81a537bc31c159a3
   else
      outfileName = "TMVA_temp.root";
   TFile *outputFile = TFile::Open(outfileName, "RECREATE");

   // Create the factory object. Later you can choose the methods
   // whose performance you'd like to investigate. The factory is
   // the only TMVA object you have to interact with
   //
   // The first argument is the base of the name of all the
   // weightfiles in the directory weight/
   //
   // The second argument is the output file for the training results
   // All TMVA output can be suppressed by removing the "!" (not) in
   // front of the "Silent" argument in the option string
   TMVA::Factory *factory = new TMVA::Factory("TMVAClassification", outputFile,
                                              "!V:!Silent:Color:DrawProgressBar:AnalysisType=Classification");

   TMVA::DataLoader *dataloader = new TMVA::DataLoader("dataset");

   // Define the input variables that shall be used for the MVA training
   // note that you may also use variable expressions, such as: "3*var1/var2*abs(var3)"
   // [all types of expressions that can also be parsed by TTree::Draw( "expression" )]

<<<<<<< HEAD
   // TMVA variable to use for the training
   size_t n_features = 190;
   for (auto [expr, name] : feature_map)
   {
      if (n_features > 0)
         n_features--;
      else
         break;
=======
   //TMVA variable to use for the training

   for (auto [expr, name] : feature_map)
>>>>>>> caae89e6fc87ebcbd8eb46fb81a537bc31c159a3
      if (name == "")
         dataloader->AddVariable(expr, 'F');
      else
         dataloader->AddVariable(expr, name, "", 'F');
<<<<<<< HEAD
   }
=======

>>>>>>> caae89e6fc87ebcbd8eb46fb81a537bc31c159a3
   // You can add so-called "Spectator variables", which are not used in the MVA training,
   // but will appear in the final "TestTree" produced by TMVA. This TestTree will contain the
   // input variables, the response values of all trained MVAs, and the spectator variables

   dataloader->AddSpectator("Xicst_ID", "Xicst ID", 'F');
   dataloader->AddSpectator("Xicst_M", "Xicst Mass", 'F');

   Double_t signalWeight = 1.0;
   Double_t backgroundWeight = 1.0;

   // You can add an arbitrary number of signal or background trees
   dataloader->AddSignalTree(signalTree, signalWeight);
   dataloader->AddBackgroundTree(background, backgroundWeight);

   // Apply additional cuts on the signal and background samples (can be different)
   TCut mycuts = "";     // for example: TCut mycuts = "abs(var1)<0.5 && abs(var2-0.5)<1";
   TCut mycutb = mycuts; // for example: TCut mycutb = "abs(var1)<0.5";

   // ### Book MVA methods
   //
   // Please lookup the various method configuration options in the corresponding cxx files, eg:
   // src/MethoCuts.cxx, etc, or here: http://tmva.sourceforge.net/optionRef.html
   // it is possible to preset ranges in the option string in which the cut optimisation should be done:
   // "...:CutRangeMin[2]=-1:CutRangeMax[2]=1"...", where [2] is the third input variable

   dataloader->PrepareTrainingAndTestTree(mycuts, mycutb,
                                          "nTrain_Signal=4000:nTrain_Background=4000:nTest_Signal=2000:nTest_Background=2000:SplitMode=Random:NormMode=NumEvents:!V");

   // TMVA ANN: MLP (recommended ANN) -- all ANNs in TMVA are Multilayer Perceptrons
   if (Use["MLP"])
      factory->BookMethod(dataloader, TMVA::Types::kMLP, "MLP", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:!UseRegulator");

   // Multi-architecture DNN implementation.
   if (Use["DNN_CPU"] or Use["DNN_GPU"])
   {
      // General layout.
      TString layoutString("Layout=TANH|128,TANH|128,TANH|128,LINEAR");

      // Training strategies.
      TString training0("LearningRate=1e-1,Momentum=0.9,Repetitions=1,"
                        "ConvergenceSteps=20,BatchSize=256,TestRepetitions=10,"
                        "WeightDecay=1e-4,Regularization=L2,"
                        "DropConfig=0.0+0.5+0.5+0.5, Multithreading=True");
      TString training1("LearningRate=1e-2,Momentum=0.9,Repetitions=1,"
                        "ConvergenceSteps=20,BatchSize=256,TestRepetitions=10,"
                        "WeightDecay=1e-4,Regularization=L2,"
                        "DropConfig=0.0+0.0+0.0+0.0, Multithreading=True");
      TString training2("LearningRate=1e-3,Momentum=0.0,Repetitions=1,"
                        "ConvergenceSteps=20,BatchSize=256,TestRepetitions=10,"
                        "WeightDecay=1e-4,Regularization=L2,"
                        "DropConfig=0.0+0.0+0.0+0.0, Multithreading=True");
      TString trainingStrategyString("TrainingStrategy=");
      trainingStrategyString += training0;// + "|" + training1 + "|" + training2;

      // General Options.
      TString dnnOptions("!H:V:ErrorStrategy=CROSSENTROPY:VarTransform=N:"
                         "WeightInitialization=XAVIERUNIFORM");
      dnnOptions.Append(":");
      dnnOptions.Append(layoutString);
      dnnOptions.Append(":");
      dnnOptions.Append(trainingStrategyString);

      // Cuda implementation.
      if (Use["DNN_GPU"])
      {
         TString gpuOptions = dnnOptions + ":Architecture=GPU";
         factory->BookMethod(dataloader, TMVA::Types::kDL, "DNN_GPU", gpuOptions);
      }
      // Multi-core CPU implementation.
      if (Use["DNN_CPU"])
      {
         TString cpuOptions = dnnOptions + ":Architecture=CPU";
         factory->BookMethod(dataloader, TMVA::Types::kDL, "DNN_CPU", cpuOptions);
      }
   }
<<<<<<< HEAD

=======
   
>>>>>>> caae89e6fc87ebcbd8eb46fb81a537bc31c159a3
   // Boosted Decision Trees

   if (Use["BDT"]) // Adaptive Boost
      factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDT",
                          "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20");

   if (Use["BDTG"]) // Gradient Boost
      factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDTG",
                          "!H:!V:NTrees=1000:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:MaxDepth=2");

   if (Use["BDTB"]) // Bagging
      factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDTB",
                          "!H:!V:NTrees=400:BoostType=Bagging:SeparationType=GiniIndex:nCuts=20");

   if (Use["BDTD"]) // Decorrelation + Adaptive Boost
      factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDTD",
                          "!H:!V:NTrees=400:MinNodeSize=5%:MaxDepth=3:BoostType=AdaBoost:SeparationType=GiniIndex:nCuts=20:VarTransform=Decorrelate");

   if (Use["BDTF"]) // Allow Using Fisher discriminant in node splitting for (strong) linearly correlated variables
      factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDTF",
                          "!H:!V:NTrees=50:MinNodeSize=2.5%:UseFisherCuts:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:SeparationType=GiniIndex:nCuts=20");

   // RuleFit -- TMVA implementation of Friedman's method
   if (Use["RuleFit"])
      factory->BookMethod(dataloader, TMVA::Types::kRuleFit, "RuleFit",
                          "H:!V:RuleFitModule=RFTMVA:Model=ModRuleLinear:MinImp=0.001:RuleMinDist=0.001:NTrees=20:fEventsMin=0.01:fEventsMax=0.5:GDTau=-1.0:GDTauPrec=0.01:GDStep=0.01:GDNSteps=10000:GDErrScale=1.02");

   // For an example of the category classifier usage, see: TMVAClassificationCategory
   //
   // --------------------------------------------------------------------------------------------------
   //  Now you can optimize the setting (configuration) of the MVAs using the set of training events
   //  STILL EXPERIMENTAL and only implemented for BDT's !
   //
   factory->OptimizeAllMethods("ROCIntegral", "FitGA");
   //
   // --------------------------------------------------------------------------------------------------

   // Now you can tell the factory to train, test, and evaluate the MVAs
   //
   // Train MVAs using the set of training events
   factory->TrainAllMethods();

   // Evaluate all MVAs using the set of test events
   factory->TestAllMethods();

   // Evaluate and compare performance of all configured MVAs
   factory->EvaluateAllMethods();

   // --------------------------------------------------------------

   // Save the output
   outputFile->Close();
   for (auto [method, used] : Use)
   {
      if (used)
         std::cout << "ROC Integral for \"" << method << "\" is " << factory->GetROCIntegral(dataloader, method) << std::endl;
   }
   std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
   std::cout << "==> TMVAClassification is done!" << std::endl;

   delete factory;
   delete dataloader;
   // Launch the GUI for the root macros
   if (!gROOT->IsBatch())
      TMVA::TMVAGui(outfileName);

   return 0;
}

std::map<std::string, std::string> get_features(SQLite::Database &db, const int run)
{
   std::map<std::string, std::string> map;

   std::string script_dir = getenv("SQL_SCRIPTS");
   std::string script = "Get_Features.sql";
   std::ifstream file(script_dir + "/" + script);
   if (!file)
   {
      std::cerr << rang::fg::red << "File " << script << " not found\n";
      exit(6);
   }
<<<<<<< HEAD

   std::string str, stmt;
   while (getline(file, str))
   {
      stmt.append(str + "\n");
   }
   SQLite::Statement query(db, stmt);
   query.bind(1, run);
   while (query.executeStep())
   {
      static bool first_line = true;
      int set_ID = query.getColumn("Feature Set ID");
      std::string feature_expr = query.getColumn("Feature");
      std::string feature_name = query.getColumn("Base Feature");
      map[feature_expr] = feature_name;
      if (first_line)
      {
         std::cout << std::endl
                   << rang::fg::blue
                   << std::left << std::setw(15) << "Run:" << std::setw(5) << run << std::endl
                   << std::left << std::setw(15) << "Feature set:" << std::setw(5) << set_ID
                   << rang::fg::reset << std::endl;
         first_line = false;
      }
      std::cout << "Feature:   " << std::left << std::setw(30) << feature_expr
                << " from " << feature_name << std::endl;
   }
   if (map.empty())
   {
      std::cout << rang::fg::yellow << "Run " << rang::style::bold << run << rang::style::reset
                << rang::fg::yellow << " does not have a filled entry in the SQLite database or doesn't exist yet.\n";
      exit(7);
   }
   return map;
}

bool get_methods(SQLite::Database &db, const int run, std::map<std::string, int> &Use)
{
   std::string script_dir = getenv("SQL_SCRIPTS");
   std::string script = "Get_Methods.sql";
   std::ifstream file(script_dir + "/" + script);
   if (!file)
   {
      std::cerr << rang::fg::red << "File " << script << " not found\n";
      exit(6);
   }

=======

>>>>>>> caae89e6fc87ebcbd8eb46fb81a537bc31c159a3
   std::string str, stmt;
   while (getline(file, str))
   {
      stmt.append(str + "\n");
   }
   SQLite::Statement query(db, stmt);
   query.bind(1, run);
<<<<<<< HEAD
   bool first_line = true;
   while (query.executeStep())
   {
      int set_ID = query.getColumn("Method Set ID");
      std::string method = query.getColumn("Method");
      if (first_line)
      {
         std::cout << std::endl
                   << rang::fg::blue
                   << std::left << std::setw(15) << "Run:" << std::setw(5) << run << std::endl
                   << std::left << std::setw(15) << "Method set:" << std::setw(5) << set_ID
                   << rang::fg::reset << std::endl;
         first_line = false;
      }
      std::cout << "Method:   " << std::left << std::setw(13) << method << std::endl;
      if (method == "DNN_GPU" || method == "DNN_CPU")
      {
#ifdef R__HAS_TMVAGPU
         Use["DNN_GPU"] = 1; // CUDA-accelerated DNN training.
#else
         Use["DNN_GPU"] = 0;
#endif

#ifdef R__HAS_TMVACPU
         Use["DNN_CPU"] = 0; // Multi-core accelerated DNN.
#else
         Use["DNN_CPU"] = 0;
#endif
      }
      Use[method] = 1;
   }

   if (first_line)
      return false; // no methods in specified run
   else
      return true; // methods were collected from run
=======
   while (query.executeStep())
   {
      static bool first_line = true;
      int set_ID = query.getColumn("Feature Set ID");
      std::string feature_expr = query.getColumn("Feature");
      std::string feature_name = query.getColumn("Base Feature");
      map[feature_expr] = feature_name;
      if (first_line)
      {
         std::cout << std::endl
                   << rang::fg::blue
                   << std::left << std::setw(15) << "Run:" << std::setw(5) << run << std::endl
                   << std::left << std::setw(15) << "Feature set:" << std::setw(5) << set_ID
                   << rang::fg::reset << std::endl;
         first_line = false;
      }
      std::cout << "Feature:   " << std::left << std::setw(30) << feature_expr
                << " from " << feature_name << std::endl;
   }
   if (map.empty())
   {
      std::cout << rang::fg::yellow << "Run " << rang::style::bold << run << rang::style::reset
                << rang::fg::yellow << " does not have a filled entry in the SQLite database or doesn't exist yet.\n";
      exit(7);
   }
   return map;
>>>>>>> caae89e6fc87ebcbd8eb46fb81a537bc31c159a3
}
