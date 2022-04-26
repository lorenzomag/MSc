#include "pch.h"

#include "from_sql.hpp"
#include "SQLiteCpp/SQLiteCpp.h"

namespace from_sql
{

    SQLite::Database open_db()
    {
        std::string db_name = getenv("DATABASE");
        SQLite::Database db(db_name);
        db.exec("PRAGMA foreign_keys=ON;");
        return db;
    }

    std::map<int, std::set<std::string>> get_used_MVAs()
    {
        std::string database = getenv("DATABASE");
        SQLite::Database db(database);
        db.exec("PRAGMA foreign_keys=ON;");
        std::string scripts = getenv("SQL_SCRIPTS");
        std::ifstream in_statement(scripts + "/Get_Used_Methods.sql");
        std::string stmt, _str;
        while (getline(in_statement, _str))
        {
            stmt.append(_str + "\n");
        }
        SQLite::Statement query(db, stmt);

        std::map<int, std::set<std::string>> used_MVAs;
        while (query.executeStep())
        {
            int id = query.getColumn("ID");
            std::string name = query.getColumn("Name");
            used_MVAs[id].insert(name);
        }

        return used_MVAs;
    }

    std::set<std::string> get_known_MVAs()
    {
        std::string database = getenv("DATABASE");
        SQLite::Database db(database);
        db.exec("PRAGMA foreign_keys=ON;");
        std::string scripts = getenv("SQL_SCRIPTS");
        std::ifstream in_statement(scripts + "/Get_Known_Methods.sql");
        std::string stmt, _str;
        while (getline(in_statement, _str))
        {
            stmt.append(_str + "\n");
        }
        SQLite::Statement query(db, stmt);

        std::set<std::string> used_MVAs;
        while (query.executeStep())
        {
            std::string name = query.getColumn("Name");
            used_MVAs.insert(name);
        }
        return used_MVAs;
    }
    std::set<std::string> get_known_feature_sets()
    {
        std::string database = getenv("DATABASE");
        SQLite::Database db(database);
        db.exec("PRAGMA foreign_keys=ON;");
        std::string scripts = getenv("SQL_SCRIPTS");
        std::ifstream in_statement(scripts + "/Get_Known_Feature_Sets.sql");
        std::string stmt, _str;
        while (getline(in_statement, _str))
        {
            stmt.append(_str + "\n");
        }
        SQLite::Statement query(db, stmt);

        std::set<std::string> used_MVAs;
        while (query.executeStep())
        {
            std::string name = query.getColumn("Name");
            used_MVAs.insert(name);
        }
        return used_MVAs;
    }

};