#include <iostream>
#include <SQLiteCpp/SQLiteCpp.h>
#include <string>

#include "statements.h"

int main(int, char **)
{
    std::string db_name = (std::string)getenv("WORKSPACE_DIR") + "/database/searches.db";
    std::cout << db_name << std::endl;
    SQLite::Database db(db_name, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
    std::string stmt;
    try
    {
        bool new_particles = true;
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

        // stmt = "CREATE TRIGGER IF NOT EXISTS UniqueColumnCheckNullInsert "
        // "BEFORE INSERT "
        // "ON Particles "
        // "WHEN NEW.Mass IS NULL "
        // "BEGIN "
        // "SELECT CASE WHEN(( "
        // "    SELECT 1 "
        // "    FROM Particles "
        // "    WHERE Mass IS NULL "
        // "    ) "
        // "    NOTNULL) THEN RAISE(ABORT, 'error row exists') END; "
        // "END; ";
        // db.exec(stmt);
        
        if (new_particles)
            db.exec(statements::insert_particles_stmt);
    }
    catch (SQLite::Exception &e)
    {
        std::cout << "SQLite exception at Particles: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    try
    {
        bool new_features = true;
        if (db.tableExists("Features"))
            new_features = false;
        stmt = "CREATE TABLE IF NOT EXISTS Features ("
               "ID INTEGER PRIMARY KEY, "
               "Name TEXT NOT NULL UNIQUE, "
               "Scope TEXT NOT NULL);";
        db.exec(stmt);
        if (new_features)
            db.exec(statements::insert_features_stmt);
    }
    catch (SQLite::Exception &e)
    {
        std::cout << "SQLite exception at Features: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    try
    {
        stmt = "CREATE VIEW IF NOT EXISTS Particle_features AS "
               "SELECT p.Name || '_' || f.Name as Name, p.ID as Particle_ID, f.ID as Feature_ID "
               "FROM Particles p "
               "CROSS JOIN Features f "
               "WHERE Scope = 'Particle';";
        db.exec(stmt);
    }
    catch (SQLite::Exception &e)
    {
        std::cout << "SQLite exception at Particle_features: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    try
    {
        stmt = "CREATE TABLE IF NOT EXISTS Feature_sets ("
               "set_ID INTEGER PRIMARY KEY AUTOINCREMENT, "
               "Notes TEXT, "
               "Mass REAL, "
               "FOREIGN KEY (Mass) REFERENCES Particle"
               ");";
        db.exec(stmt);
    }
    catch (SQLite::Exception &e)
    {
        std::cout << "SQLite exception at Feature_sets: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    try
    {
        stmt = "CREATE TABLE IF NOT EXISTS Feature_set_rel ("
               "set_ID INTEGER NOT NULL, "
               "feature_ID INTEGER NOT NULL, "
               "particle_ID INTEGER NOT NULL, "
               "FOREIGN KEY (set_ID) REFERENCES Feature_sets ( set_ID ) "
               "ON UPDATE CASCADE "
               "ON DELETE NO ACTION, "
               "FOREIGN KEY (feature_ID) REFERENCES Features ( ID ) "
               "ON UPDATE CASCADE "
               "ON DELETE NO ACTION, "
               "FOREIGN KEY (particle_ID) REFERENCES Particles ( ID ) "
               "ON UPDATE CASCADE "
               "ON DELETE NO ACTION, "
               "UNIQUE ( set_ID, particle_ID, feature_ID) "
               ");";
        db.exec(stmt);
    }
    catch (SQLite::Exception &e)
    {
        std::cout << "SQLite exception at Feature_set_rel: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    try
    {
        stmt = "CREATE TABLE IF NOT EXISTS TMVA_methods ("
               "ID INTEGER PRIMARY KEY, "
               "Name TEXT NOT NULL UNIQUE);";
        db.exec(stmt);
    }
    catch (SQLite::Exception &e)
    {
        std::cout << "SQLite exception: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    try
    {
        stmt = "CREATE TABLE IF NOT EXISTS TMVA_hyperp ("
               "ID INTEGER PRIMARY KEY, "
               "Name TEXT NOT NULL, "
               "Value, "
               "Param_type TEXT, "
               "Method_ID INTEGER NOT NULL, "
               "FOREIGN KEY (Method_ID) REFERENCES TMVA_methods (Name));";
        db.exec(stmt);
    }
    catch (SQLite::Exception &e)
    {
        std::cout << "SQLite exception at TMVA_hyperp: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    try
    {

        stmt = "CREATE TABLE IF NOT EXISTS TMVA_method_sets ("
               "set_ID INTEGER NOT NULL, "
               "Method_ID TEXT NOT NULL, "
               "Hyperparam_ID INTEGER NOT NULL, "
               "FOREIGN KEY (Method_ID) REFERENCES TMVA_methods(ID) "
               "ON DELETE NO ACTION ON UPDATE CASCADE, "
               "FOREIGN KEY (Hyperparam_ID) REFERENCES TMVA_hyperp(ID) "
               "ON DELETE NO ACTION ON UPDATE CASCADE "
               ");";
        db.exec(stmt);
    }
    catch (SQLite::Exception &e)
    {
        std::cout << "SQLite exception at TMVA_method_sets: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    try
    {
        stmt = "CREATE TABLE IF NOT EXISTS TMVA_runs ("
               "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
               "Feature_set INTEGER NOT NULL,"
               "Method_set INTEGER NOT NULL, "
               "ROC_integral REAL, "
               "Punzi_FOM REAL, "
               "Notes TEXT, "
               "FOREIGN KEY (Feature_set) REFERENCES Feature_sets(set_ID) "
               "ON UPDATE CASCADE ON DELETE NO ACTION, "
               "FOREIGN KEY (Method_set) REFERENCES TMVA_method_sets(set_ID) "
               "ON UPDATE CASCADE ON DELETE NO ACTION "
               ");";
        db.exec(stmt);
    }
    catch (SQLite::Exception &e)
    {
        std::cout << "SQLite exception at TMVA_runs: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
