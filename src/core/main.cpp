#include <cstring>
#include <iostream>

#include "database.hpp"
#include "service/abstractservice.hpp"
#include "service/authservice.hpp"

int main(int argc, char *argv[]) {
  setenv("DATABASE", "prod.db", 0);
  if (argc <= 1) {
    std::cout << "Passe uma opção válida para a execução do programa!\n";
    return 0;
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