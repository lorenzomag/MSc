#ifndef PCH
#define PCH

#include <cassert>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
// #include <mutex>
#include <set>
// #include <thread>
#include <vector>

#include "TApplication.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TFile.h"
#include "TH1D.h"
#include "THStack.h"
#include "TLatex.h"
#include "TObjString.h"
#include "TRandom.h"
#include "TRint.h"
#include "TROOT.h"
#include "TString.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TTree.h"

#include "ROOT/RDataFrame.hxx"

#include "TMVA/Factory.h"
#include "TMVA/DataLoader.h"
#include "TMVA/Tools.h"
#include "TMVA/OptimizeConfigParameters.h"
#include "TMVA/TMVAGui.h"

#include "BSlogger.hpp"
#include "rang.hpp"
#include <nlohmann/json.hpp>

#endif // PCH
