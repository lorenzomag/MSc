#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/codata_constants.hpp>

using namespace boost::units;

auto speedOfLight = si::constants::codata::c;

void print_usage();

quantity<si::length> time_to_length(quantity<si::time>);
quantity<si::time> length_to_time(quantity<si::length>);
