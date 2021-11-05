#ifndef FEATURES_H
#define FEATURES_H
#include <map>

void set_file_names(TString &, TString &, TString &, TString &, TString &);
void set_branch_args(PARTICLE &particle);

namespace main_config
{
    enum type
    {
        MC,
        ws1,
        ws2
    };
    const std::map<main_config::type, bool> use = {
        {MC, true},
        {ws1, true},
        {ws2, false}};
}

#endif // FEATURES_H
