#pragma once
#include "pch.h"

using json = nlohmann::json;


enum feat_source
{
    from_file,
    default_values
};

json select_features(feat_source);
