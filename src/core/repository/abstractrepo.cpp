#include "repository/abstractrepo.hpp"
#include <iostream>


Repo::Repo() {
    sqlite3_open(getenv("DATABASE"), &db);
}

Repo::~Repo() {
    sqlite3_close(db);
}

int Repo::execSql(std::string command) const {
    char *err = 0;
    int rc = sqlite3_exec(db, command.c_str(), nullptr, nullptr, &err);
    return (rc == SQLITE_OK);
}

std::vector<std::map<std::string, std::string>> Repo::sqlselect(std::string command) const {
    sqlite3_stmt *statement;
    std::vector<std::map<std::string, std::string>> result;

    // Consulta
    if (sqlite3_prepare_v2(db, command.c_str(), -1, &statement, nullptr) != SQLITE_OK) {
        // Retornando previamente por erro, no caso, a consulta retorna como vazia
        return result;
    }

    // percorrendo o resultado da busca
    while (sqlite3_step(statement) == SQLITE_ROW) {
        int col = sqlite3_column_count(statement);
        std::map<std::string, std::string> line;

        // adicionando a coluna e seus valores no mapa
        for (int i = 0; i < col; ++i) {
            const char *name = sqlite3_column_name(statement, i);
            const char *value = reinterpret_cast<const char *>(sqlite3_column_text(statement, i));

            line[name] = value;
        }

        result.push_back(line);
    }

    sqlite3_finalize(statement);
    return result;
}



