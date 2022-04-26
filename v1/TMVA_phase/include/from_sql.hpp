#ifndef TMVA_H
#define TMVA_H

#include "SQLiteCpp/SQLiteCpp.h"

namespace from_sql
{
    SQLite::Database open_db();
    void set_method_dirs(int run, std::set<std::string> &method_names, std::map<std::string, std::string> &method_dirs, std::map<int, std::set<std::string>> get_used_MVAs);
    std::map<int, std::set<std::string>> get_used_MVAs();
    std::set<std::string> get_known_MVAs();

    std::set<std::string> get_known_feature_sets();
};

#endif // TMVA_H