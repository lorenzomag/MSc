#include <iostream>
#include <boost/program_options.hpp>

#include "settings_selection.hpp"

namespace po = boost::program_options;

namespace settings_selection
{
    int select_options(int ac, char **av)
    {
        // Declare the supported options.
        features_ID = -999;
        methods_ID = -999;
        version = -999;
        po::options_description desc("Allowed options");
        desc.add_options()("help,h", "Produce help message")("features,f", po::value<int>(&features_ID)->default_value(1), "Set of features ID (see json)")("methods,m", po::value<int>(&methods_ID)->default_value(1), "Set of methods ID (see json)")("version,v", po::value<int>(&version)->default_value(1), "Params for TMVA")("batch,b", "BatchMode on");

        po::positional_options_description p;
        p.add("input-file", -1);

        po::variables_map vm;
        po::store(po::command_line_parser(ac, av).options(desc).positional(p).run(), vm);
        po::notify(vm);

        if (vm.count("help")){
            std::cout << desc << std::endl;
            exit(0);
            }

        if (vm.count("methods"))
        {
            std::cout << "Include paths are: "
                 << vm["methods"].as<int>() << "\n";
        }

        if (vm.count("features"))
        {
            std::cout << "Input files are: "
                 << vm["features"].as<int>() << "\n";
        }

        if (vm.count("batch"))
            std::cout << "BATCH!!!" << std::endl;

        std::cout << "Optimization level is " << version << "\n";
        return 0;
    }
}
