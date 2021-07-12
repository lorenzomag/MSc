#include "converter.hpp"

using namespace boost::units;
using namespace boost::units::si;

namespace decay_tl_converter
{
    quantity<si::velocity> speedOfLight = 299792458 * si::meter_per_second;
    template <class in, class out>
    void print_output(std::string case_type, in input, out output)
    {

        std::string input_type, output_type;

        if (case_type.compare("-t") == 0)
        {
            input_type = "time";
            output_type = "length";
        }
        else
        {
            input_type = "length";
            output_type = "time";
        }

        std::cout << "Converting decay " << input_type << " to decay " << output_type << std::endl
                  << "============================" << std::endl
                  << "Decay " << input_type << ": " << engineering_prefix << input << std::endl
                  << "Decay " << output_type << ": " << engineering_prefix << output << std::endl;
    }

    int converter(int argc, char **argv)
    {

        if (argc < 2 || argc > 4)
        {
            print_usage();
            return 1;
        }

        double power = (argc > 3) ? std::stod(argv[3]) : 0;

        std::string input_type = argv[1];

        if (std::string("-t").compare(input_type) == 0)
        {
            quantity<si::time> input = (argc > 2) ? std::stod(argv[2]) * pow(10, power) * seconds : 1 * seconds;
            quantity<length> output = time_to_length(input);
            print_output(input_type, input, output);
        }
        else if (std::string("-l").compare(input_type) == 0)
        {
            quantity<length> input = (argc > 2) ? std::stod(argv[2]) * pow(10, power) * meter : 1 * meters;
            quantity<si::time> output = length_to_time(input);
            print_output(input_type, input, output);
        }
        else
        {
            print_usage();
            return 2;
        }

        return 0;
    }

    void print_usage()
    {
        std::cout << "Usage: ./converter CASE [VALUE] [ORDER]" << std::endl
                  << std::endl
                  << "CASE: \"-t\" if you want to convert decay time into decay length; \"-l\" in the opposite case; " << std::endl
                  << "VALUE: value of input decay time/length in SI units (second for time, meter for length) /defaults to 1/;" << std::endl
                  << "ORDER: order of magnitude of value (e.g. 3 for VALUE * 10 ^ 3, -2 for VALUE * 10 ^ {-2}) /defaults to 0/" << std::endl;
    }

    quantity<length> time_to_length(quantity<si::time> t)
    {
        return t * speedOfLight;
    }

    quantity<si::time> length_to_time(quantity<length> l)
    {
        return l / speedOfLight;
    }
}