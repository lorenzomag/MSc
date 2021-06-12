#ifndef USE_HEADER
#define USE_HEADER

#include <map>
#include <string>

std::map<std::string, int> Use;

std::map<std::string, int> get_use()
{
    // Default MVA methods to be trained + tested

    // Cut optimisation
    Use["Cuts"] = 1;
    Use["CutsD"] = 1;
    Use["CutsPCA"] = 0;
    Use["CutsGA"] = 0;
    Use["CutsSA"] = 0;
    //
    // 1-dimensional likelihood ("naive Bayes estimator")
    Use["Likelihood"] = 1;
    Use["LikelihoodD"] = 0;   // the "D" extension indicates decorrelated input variables (see option strings)
    Use["LikelihoodPCA"] = 1; // the "PCA" extension indicates PCA-transformed input variables (see option strings)
    Use["LikelihoodKDE"] = 0;
    Use["LikelihoodMIX"] = 0;
    //
    // Mutidimensional likelihood and Nearest-Neighbour methods
    Use["PDERS"] = 1;
    Use["PDERSD"] = 0;
    Use["PDERSPCA"] = 0;
    Use["PDEFoam"] = 1;
    Use["PDEFoamBoost"] = 0; // uses generalised MVA method boosting
    Use["KNN"] = 1;          // k-nearest neighbour method
    //
    // Linear Discriminant Analysis
    Use["LD"] = 1; // Linear Discriminant identical to Fisher
    Use["Fisher"] = 0;
    Use["FisherG"] = 0;
    Use["BoostedFisher"] = 0; // uses generalised MVA method boosting
    Use["HMatrix"] = 0;
    //
    // Function Discriminant analysis
    Use["FDA_GA"] = 1; // minimisation of user-defined function using Genetics Algorithm
    Use["FDA_SA"] = 0;
    Use["FDA_MC"] = 0;
    Use["FDA_MT"] = 0;
    Use["FDA_GAMT"] = 0;
    Use["FDA_MCMT"] = 0;
    //
    // Neural Networks (all are feed-forward Multilayer Perceptrons)
    Use["MLP"] = 0;      // Recommended ANN
    Use["MLPBFGS"] = 0;  // Recommended ANN with optional training method
    Use["MLPBNN"] = 1;   // Recommended ANN with BFGS training method and bayesian regulator
    Use["CFMlpANN"] = 0; // Depreciated ANN from ALEPH
    Use["TMlpANN"] = 0;  // ROOT's own ANN
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
    //
    // Support Vector Machine
    Use["SVM"] = 1;
    //
    // Boosted Decision Trees
    Use["BDT"] = 1;  // uses Adaptive Boost
    Use["BDTG"] = 0; // uses Gradient Boost
    Use["BDTB"] = 0; // uses Bagging
    Use["BDTD"] = 0; // decorrelation + Adaptive Boost
    Use["BDTF"] = 0; // allow usage of fisher discriminant for node splitting
    //
    // Friedman's RuleFit method, ie, an optimised series of cuts ("rules")
    Use["RuleFit"] = 1;
    // ---------------------------------------------------------------

    return Use;
}

void select_methods(TString myMethodList)
{
    // Select methods (don't look at this code - not of interest)
    if (myMethodList != "")
    {
        for (std::map<std::string, int>::iterator it = Use.begin(); it != Use.end(); it++)
            it->second = 0;

        std::vector<TString> mlist = TMVA::gTools().SplitString(myMethodList, ',');
        for (UInt_t i = 0; i < mlist.size(); i++)
        {
            std::string regMethod(mlist[i]);

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
}
#endif // USE_HEADER
