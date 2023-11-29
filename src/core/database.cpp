#include "database.hpp"

#include <sqlite3.h>

#include <cstring>
#include <iostream>
#include <string>

void createTables() {
    sqlite3 *db;
    sqlite3_open(getenv("DATABASE"), &db);

    char *err = 0;
    std::string sql_tables =
        "CREATE TABLE user ("
        "username VARCHAR(100) PRIMARY KEY,"
        "password VARCHAR(100) NOT NULL); ";
    sql_tables +=
        "CREATE TABLE task ("
        "title VARCHAR(100) PRIMARY KEY, "
        "username VARCHAR(100) NOT NULL, "
        "description VARCHAR(500), "
        "delivery_date VARCHAR(50), "
        "is_finished BOOLEAN NOT NULL DEFAULT(false), "
        "FOREIGN KEY(username) REFERENCES user(username));";

    sql_tables +=
        "CREATE TABLE tag ("
        "id INTEGER NOT NULL PRIMARY KEY,"
        "name VARCHAR(100) NOT NULL UNIQUE,"
        "username VARCHAR(100) NOT NULL, "
        "FOREIGN KEY (username) REFERENCES user(username));";
    int rc = sqlite3_exec(db, sql_tables.c_str(), nullptr, nullptr, &err);

    if (rc != SQLITE_OK) {
        std::cout << "SQL error: " << err << std::endl;
        sqlite3_free(err);
    } else {
        std::cout << "SUCESS!\n";
    }
    sqlite3_close(db);
}