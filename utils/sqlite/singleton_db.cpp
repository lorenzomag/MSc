#include "singleton_db.hpp"
#include <string>

// Get instance of singleton database class
sdb &sdb::Get()
{
    return s_Instance;
}

// Constructor opens the database
sdb::sdb()
{
    /* Open database */
    std::string workspace_dir = getenv("WORKSPACE_DIR");
    std::string db_file_name = workspace_dir + "/search_parameters.db";
    rc = sqlite3_open(db_file_name.c_str(), &db);

    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(1);
    }
    else
    {
        fprintf(stdout, "Opened database successfully\n");
    }
};

// Destructor closes the database
sdb::~sdb()
{
    sqlite3_close(db);
}

void sdb::Set_stmt(const char *statement)
{
    stmt = statement;
}

void sdb::exec(sqlite3_callback xCallback, void *pArg)
{
    rc = sqlite3_exec(db, stmt, xCallback, pArg, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
};

sdb sdb::s_Instance;