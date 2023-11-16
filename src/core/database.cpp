#include "database.hpp"

#include <sqlite3.h>
#include <string>
#include <cstring>
#include <iostream>

void createTables() {
    sqlite3 *db;
    sqlite3_open(getenv("DATABASE"), &db);

    char *err = 0;
    std::string sql_user = "CREATE TABLE user (" 
                      "username VARCHAR(100) PRIMARY KEY,"
                      "password VARCHAR(100) NOT NULL);";
    
    int rc = sqlite3_exec(db, sql_user.c_str(), nullptr, nullptr, &err);
    if( rc != SQLITE_OK ){
        std::cout << "SQL error: " << err << std::endl;
        sqlite3_free(err);
    } else {
        std::cout << "SUCESS!";
    }

}