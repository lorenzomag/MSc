#include <iostream>
#include <boost/program_options.hpp>
#include <fstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

namespace po = boost::program_options;
using json = nlohmann::json;

namespace settings_selection
{

    int features_ID;
    int methods_ID;
    int version;

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

        if (vm.count("help"))
        {
            std::cout << "Usage:" << std::endl
                      << "./<program_name> [input_file_name] [[options]]" << std::endl;
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

        std::cout << std::endl
                  << std::endl;

        // create byte vector
        std::vector<uint8_t>
            v = {0x82, 0xa7, 0x63, 0x6f, 0x6d, 0x70, 0x61, 0x63,
                 0x74, 0xc3, 0xa6, 0x73, 0x63, 0x68, 0x65, 0x6d,
                 0x61, 0x00};

        // deserialize it with MessagePack
        json j = json::from_msgpack(v);

        json::to_msgpack(j);

        // print the deserialized JSON value
        std::cout << std::setw(2) << j << std::endl;

        return 0;
    }
}
