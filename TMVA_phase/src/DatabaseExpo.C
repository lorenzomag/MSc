#include "fort.hpp"

#include "pch.h"

#include "from_sql.hpp"
#include "DatabaseExpo.hpp"

void DatabaseExpo(int called_run)
{
    std::string db_name = getenv("DATABASE");
    std::cout << "Details on SQLite database for the current project:\n"
              << rang::style::italic << rang::fg::blue << db_name << rang::style::reset
              << "\n/ ------------------------------------\n "
              << std::endl;

    auto db = from_sql::open_db();

    run_script(db, "ExploreRunFeatures.sql", called_run);
    run_script(db, "ExploreRunMethods.sql", called_run);
}

void run_script(SQLite::Database &db, std::string script, int called_run)
{
    std::string scripts = getenv("SQL_SCRIPTS");
    std::ifstream file(scripts + "/" + script);
    if (!file)
    {
        std::cerr << rang::fg::red << "File " << script << " not found\n";
        exit(6);
    }

    std::string str, stmt;
    while (getline(file, str))
    {
        stmt.append(str + "\n");
    }
    SQLite::Statement query(db, stmt);
    fort::char_table table;

    const int n_cols = query.getColumnCount();

    /* Change border style */
    table.set_border_style(FT_SOLID_ROUND_STYLE);
    // table.set_border_style(FT_DOUBLE2_STYLE);
    table << fort::header;
    for (int i = 0; i < n_cols; i++)
    {
        table << query.getColumnName(i);
    }
    table << fort::endr;

    while (query.executeStep())
    {
        int run = query.getColumn(0);
        static int control = run;
        if (control != run)
        {
            table << fort::separator;
            control = run;
        }
        if (called_run == 0 || (run == called_run))
        {
            table << run;
            for (int i = 1; i < n_cols; i++)
            {
                table << (std::string)query.getColumn(i);
            }
            table << fort::endr;
        }
    }
    std::cout << table.to_string() << std::endl;
}