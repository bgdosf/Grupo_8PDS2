#include <cstring>
#include <fstream>
#include <iostream>

#include "database.hpp"
#include "service/abstractservice.hpp"
#include "service/authservice.hpp"

bool doesDatabaseExist(const char *filename) {
    std::ifstream file(filename);
    return file.good();
}

int main(int argc, char *argv[]) {
    setenv("DATABASE", "prod.db", 0);
    if (argc <= 1) {
        std::cout << "Passe uma opção válida para a execução do programa!\n";
        return 0;
    }

    const char *databaseName = "prod.db";

    if (!doesDatabaseExist(databaseName)) {
        std::cout << "Banco de dados não encontrado. Criando..." << std::endl;
        createTables();
    }

    if (strcmp(argv[1], "createdb") == 0) {
        createTables();
    } else if (strcmp(argv[1], "run") == 0) {
        Service *s = new AuthService();
        while (s != nullptr) {
            Service *old_service = s;
            s = s->handler();

            delete old_service;
        }
    }
}