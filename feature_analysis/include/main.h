#ifndef FEATURES_H
#define FEATURES_H

void set_file_names(TString &, TString &, TString &, TString &);
void set_branch_args(PARTICLE &particle);

namespace set
{
    enum type
    {
        signal,
        ws1,
        ws2
    };
    const std::map<set::type, bool> use = {
        {set::type::signal, true},
        {set::type::ws1, true},
        {set::type::ws2, false}};
}

#endif // FEATURES