#include <iostream>
#include <type_traits>

#include <boost/units/cmath.hpp>
#include <boost/units/io.hpp>
#include <boost/units/pow.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/codata_constants.hpp>
#include <boost/units/systems/si/prefixes.hpp>

using namespace boost::units;
using namespace boost::units::si;

namespace decay_tl_converter
{

    template <class in, class out>
    void print_output(std::string case_type, in input, out output);

    int converter(int argc, char **argv);

    void print_usage();

    quantity<length> time_to_length(quantity<si::time> t);

    quantity<si::time> length_to_time(quantity<length> l);

}