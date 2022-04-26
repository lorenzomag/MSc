#ifndef DRAW_H
#define DRAW_H

void draw_features(Search &, Search &);
void draw_features(Search &, Search &, Search &);

namespace draw_config
{

    const std::map<TString, std::pair<double, double>> suggested_hist_ranges = {
        {"Kbach_PT", {0, 10000.}},
        {"Kbach_ProbNNk", {0, 1.}},
        {"Lc_PT", {0, 35000.}},
        {"pibach_PT",{0, 4000.}},
        {"pibach_ProbNNpi", {0, 1.}},
        {"Xicst_IPCHI2_OWNPV", {0, 30.}},
        {"Lc_IPCHI2_OWNPV", {0, 10.}},
        {"Xicst_FDCHI2_OWNPV", {0, 40.}},
        {"Xicst_ENDVERTEX_CHI2", {0, 50.}},
        {"pibach_IPCHI2_OWNPV", {0, 10.}},
        {"Kbach_IPCHI2_OWNPV", {0, 10.}}};
};

#endif // DRAW_H