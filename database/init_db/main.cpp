#include <iostream>
#include <SQLiteCpp/SQLiteCpp.h>
#include <string>

#include "statements.h"

int main(int, char **)
{
    try
    {

        std::string db_name = (std::string)getenv("WORKSPACE_DIR") + "/database/searches.db";
        std::cout << db_name << std::endl;
        SQLite::Database db(db_name, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
        bool new_particles = true;
        bool new_features = true;
        std::string stmt;
        if (db.tableExists("Particles"))
            new_particles = false;
        stmt = "CREATE TABLE IF NOT EXISTS Particles ("
               "ID INTEGER PRIMARY KEY, "
               "Name TEXT NOT NULL, "
               "Mass REAL, "
               "Width REAL, "
               "PID INT, "
               "UNIQUE(Name, Mass));";
        db.exec(stmt);
        if (new_particles)
            db.exec(statements::insert_particles_stmt);

        if (db.tableExists("Features"))
            new_features = false;
        stmt = "CREATE TABLE IF NOT EXISTS Features ("
               "ID INTEGER PRIMARY KEY, "
               "Name TEXT NOT NULL UNIQUE, "
               "Scope TEXT NOT NULL);";
        db.exec(stmt);
        if (new_features)
            db.exec(statements::insert_features_stmt);

        stmt = "CREATE VIEW IF NOT EXISTS Particle_features AS "
               "SELECT p.Name || '_' || f.Name as Name, p.ID as Particle_ID, f.ID as Feature_ID "
               "FROM Particles p "
               "CROSS JOIN Features f "
               "WHERE Scope = 'Particle';";
        db.exec(stmt);

        SQLite::Statement query(db, "SELECT * from Particle_features;");
        std::cout << "SQLite statement '" << query.getQuery().c_str() << "' compiled (" << query.getColumnCount() << " columns in the result)\n";

        while (query.executeStep())
        {
            auto name = query.getColumn("Name");
            auto feat = query.getColumn("Feature_ID");
            auto part = query.getColumn("Particle_ID");

            std::cout << name << " for particle " << part << " and feature " << feat << std::endl;
        }
    }
    catch (SQLite::Exception &e)
    {
        std::cout << "SQLite exception: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}