#include "pch.h"

#include "CLI/CLI.hpp"
#include "fort.hpp"
#include "rang.hpp"
#include "SQLiteCpp/SQLiteCpp.h"

#include "GetPunzi.hpp"
#include "DatabaseExpo.hpp"
#include "classification.hpp"
#include "from_sql.hpp"
#include "from_toml.hpp"

void exploreOutput(const unsigned int run = 1);

int main(int argc, char **argv)
{
    // Command Line Args parser
    CLI::App parser{"TMVA "};
    parser.set_config("", "../train.toml", "Use this flag to set a config file", true);
    parser.require_subcommand(1);
    parser.allow_extras();

    int run, feature_set, method_set, hyperp_set;
    std::set<std::string> method_names;
    std::set<std::string> default_method_names = {"BDT", "BDTG", "MLP"};
    std::map<std::string, std::string> method_dirs;

    auto used_MVAs = from_sql::get_used_MVAs();
    std::set<std::string> known_MVA_methods = from_sql::get_known_MVAs();
    std::set<std::string> known_feature_sets = from_sql::get_known_feature_sets();
    auto get_method_dirs = [&]()
    {
        // Converst strings to uppercase and checks methods in current run
        std::set<std::string> _temp;
        TString _temp_str;
        for (std::string method : method_names)
        {
            auto _temp_str = (TString)method;
            _temp_str.ToUpper();
            method = (std::string)_temp_str;
            if (used_MVAs[run].count(method))
                _temp.insert(method);
        }
        method_names = _temp;
        if (method_names.empty())
        {
            std::cerr << rang::fg::yellow << "None of the selected methods is present in the current run." << rang::fg::reset << std::endl;
            exit(4);
        }

        // Sets method_dir for current methods
        for (auto method : method_names)
        {
            if (method == "BDT" || method == "BDTG")
                method_dirs[method] = "Method_BDT";
            else if (method == "MLP" || method == "MLPBNN")
                method_dirs[method] = "Method_MLP";
            else if (method == "DNN_CPU" || method == "DNN_GPU")
                method_dirs[method] = "Method_DL";
            else if (method == "RuleFit")
                method_dirs[method] = "Method_RuleFit";
            else if (method == "Likelihood" || method == "LikelihoodPCA")
                method_dirs[method] = "Method_Likelihood";
            else
            {
                std::cerr << rang::fg::red << "Method " << rang::style::italic
                          << method << rang::style::reset << " has not yet been trained";
                exit(2);
            }
        }
    };

    //--------------- OPTIONS FOR DATABASE EXPLORATION
    CLI::App *db_exp = parser.add_subcommand("db", "Describes features and methods sets for selected runs [default: all runs]")->fallthrough();
    db_exp->add_option("-r,--run", run, "TMVA run to display [default: 1]")
        ->default_val(1)
        ->check(CLI::IsMember(used_MVAs));

    db_exp->add_option("-m,--method", method_names, "TMVA method(s) to evaluate [default: BDT,BDTG,MLP]")
        ->default_val(default_method_names)
        ->check(CLI::IsMember(known_MVA_methods, CLI::ignore_case));

    db_exp->parse_complete_callback(get_method_dirs);

    //--------------- OPTIONS FOR TMVA TRAINING
    bool use_SQL{false}, save_output{false};
    CLI::App *train = parser.add_subcommand("train", "Trains the tmva")->fallthrough();
    train->add_flag("--db", use_SQL, "Use this flag to record TMVA training in SQLite database.\n"
                                     "A training with different methods/features will constitute a new run.\n"
                                     "In this case, the --run option will not be considered.");

    train->add_flag("-s,--save", save_output, "Saves the output to a file called TMVA_run{i}.root\n"
                                              "i stands for the run number.\n"
                                              "[Default: saves to TMVA_temp.root]");

    train->add_option("-r,--run", run, "TMVA run ID to train/retrain");
    // ->required();

    train->add_option("-m,--method", method_names, "TMVA method(s) to analyse [default: BDT,BDTG,MLP]")
        ->default_val(default_method_names)
        ->check(CLI::IsMember(known_MVA_methods, CLI::ignore_case));

    train->add_option("--feature-set", feature_set, "TMVA feature set to use for training.");
    //--------------- OPTIONS FOR TMVA APPLICATION
    // CLI::App *apply = parser.add_subcommand("apply", "Applies the tmva")
    //                       ->fallthrough();
    // apply->add_option("-r,--run", run, "TMVA run ID to consider for application")
    //     ->required();

    // apply->add_option("-m,--method", method_names, "TMVA method(s) to apply [default: BDT,BDTG,MLP]")
    //     ->default_val(default_method_names)
    //     ->check(CLI::IsMember(known_MVA_methods, CLI::ignore_case));

    // apply->add_flag("--db", use_SQL, "Use this flag to record TMVA training in SQLite database.\n"
    //                                  "A training with different methods/features will constitute a new run.\n"
    //                                  "In this case, the --run option will not be considered.");

    //--------------- OPTIONS FOR TMVA EVALUATION
    // CLI::App *eval = parser.add_subcommand("eval", "Evaluates TMVA models for specified run and methods");

    // eval->add_option("-r,--run", run, "TMVA run to analyse [default: 1]")
    //     ->default_val(1)
    //     ->check(CLI::IsMember(used_MVAs));

    // eval->add_option("-m,--method", method_names, "TMVA method(s) to evaluate [default: BDT,BDTG,MLP]")
    //     ->default_val(default_method_names)
    //     ->check(CLI::IsMember(known_MVA_methods, CLI::ignore_case));

    // eval->parse_complete_callback(get_method_dirs);
    // eval->add_flag("--db", use_SQL, "Use this flag to record TMVA evaluation in SQLite database.\n"
    //                                 "A training with different methods/features will constitute a new run.\n"
    //                                 "In this case, the --run option will not be considered.");

    //-------------- Parse options (with a touch of colour for help and errors)
    parser.set_help_all_flag("-a,--help-all", "Show help for subcommands as well");
    std::atexit([]()
                { std::cout << rang::style::reset; });
    try
    {
        parser.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        std::cout << (e.get_exit_code() == 0 ? rang::fgB::cyan : rang::fgB::red);

        // For ROOT CLI parser
        if (e.get_exit_code() == 0)
        {
            int root_argc(2);
            char arg1[5] = "tmva";
            char arg2[3] = "-h";
            char *root_argv[2] = {arg1, arg2};
            parser.exit(e);
            std::cout << rang::fg::reset
                      << rang::style::dim
                      << "Command line arguments for underlying ROOT application" << std::endl;
            TApplication app("Help message", &root_argc, root_argv);
            app.Run();
        }
        else
            return parser.exit(e);
    }

    // ROOT parser for remaining args
    TRint app("Root app", &argc, argv);

    //------------- Go through selected methods
    if (parser.got_subcommand("db"))
    {
        if (db_exp->get_option("--run")->count())
            DatabaseExpo(run);
        else
            DatabaseExpo();
    }

    if (parser.got_subcommand("train"))
        classification(method_names, run, save_output, use_SQL, &app);

    // if (parser.got_subcommand("eval"))
    // {
    //     for (auto method : method_names)
    //     {
    //         std::cout << "\nMeasuring punzi values for method " << method << " during run " << run << std::endl;
    //         GetPunzi(run, method, method_dirs[method], use_SQL, &app);
    //         std::cout << rang::bg::cyan << rang::fg::black << method << rang::bg::reset << rang::fg::reset;
    //         std::cout << "\t ---> " << method_dirs[method] << std::endl;
    //     }
    //     // exploreOutput(run);
    // }

    std::ofstream out_file("/home/loren/MSc/TMVA_phase/output/run1/config.toml");
    std::cout << parser.config_to_str(false, true);
    app.Run();
}