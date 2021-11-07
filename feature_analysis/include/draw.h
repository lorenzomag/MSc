#ifndef DRAW_H
#define DRAW_H

void draw_features(Search &, Search &);
void draw_features(Search &, Search &, Search &);

namespace draw_config{

    const std::map<TString, std::pair<double, double>> suggested_hist_ranges = {
        {"ciao", {1.2,3}}
    };
};


#endif // DRAW_H