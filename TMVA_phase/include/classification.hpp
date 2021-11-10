#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H

#include <map>
#include <set>
#include <string>

#include "BSlogger.hpp"
#include "fort.hpp"
#include "rang.hpp"
#include "SQLiteCpp/SQLiteCpp.h"

void classification(std::set<std::string> method_list, bool save_output, bool use_SQL, TApplication *app, const int run);
std::map<std::string, std::string> get_features(SQLite::Database &db, const int run);
bool get_methods(SQLite::Database &db, std::map<std::string, int> &Use, const int run);
std::string get_hyperparameters(SQLite::Database &db, const std::string &method_name, const int run);

#endif // CLASSIFICATION_H