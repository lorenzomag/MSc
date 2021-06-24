#ifndef SELECT_FEATS
#define SELECT_FEATS

using json = nlohmann::json;


enum feat_source
{
    from_file,
    default_values
};

json select_features(feat_source);

#endif // SELECT_FEATS