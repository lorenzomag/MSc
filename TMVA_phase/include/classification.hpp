#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H

#include <map>
#include <set>
#include <string>

#include "BSlogger.hpp"
#include "fort.hpp"
#include "rang.hpp"
#include "SQLiteCpp/SQLiteCpp.h"


int classification(std::set<std::string> method_list, const int run, bool save_output, TApplication *app);
std::map<std::string, std::string> get_features(SQLite::Database &db, const int run);

#endif // CLASSIFICATION_H