#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H

#include <map>
#include <set>
#include <string>

#include "BSlogger.hpp"
#include "fort.hpp"
#include "rang.hpp"
#include "SQLiteCpp/SQLiteCpp.h"

int classification(std::set<std::string> method_list, const int run, bool save_output, bool use_SQL, TApplication *app);
std::map<std::string, std::string> get_features(SQLite::Database &db, const int run);
bool get_methods(SQLite::Database &db, const int run, std::map<std::string, int> &Use);

#endif // CLASSIFICATION_H