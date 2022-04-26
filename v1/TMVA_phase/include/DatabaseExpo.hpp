#ifndef DB_H
#define DB_H

#include "SQLiteCpp/SQLiteCpp.h"

void DatabaseExpo(int called_run = 0);
void run_script(SQLite::Database &db, std::string script, int called_run);

#endif // DB_H