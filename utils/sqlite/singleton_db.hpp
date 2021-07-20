#ifndef SIGNLETON_DB_H
#define SIGNLETON_DB_H

#include "sqlite3.h"

class sdb
{
public:
    sqlite3 *db;     // Pointer to SQLite database
    char *zErrMsg;   // string for error messages
    int rc;          // rc?
    const char *stmt; // string for SQL statements

    // Delete copy constructor
    sdb(const sdb &) = delete;

    // Get instance of singleton database class
    static sdb &Get();

    void Set_stmt(const char *statement);

    void exec(sqlite3_callback xCallback, void *pArg);

private:
    // Constructor opens the database
    sdb();

    // Destructor closes the database
    ~sdb();

    // The instance of the sdb class to be returned by Get()
    static sdb s_Instance;
};

// Declaration of the instance of sdb Singleton Class
// sdb sdb::s_Instance;

#endif // SIGNLETON_DB_H