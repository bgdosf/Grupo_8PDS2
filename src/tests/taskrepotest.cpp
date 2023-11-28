#include "doctest.h"


#include "database.hpp"
#include "model/task.hpp"
#include "repository/taskrepo.hpp"
#include "model/user.hpp"
#include "repository/userrepo.hpp"

TEST_CASE("Testando repositório de tarefas") {
  const char *dbname = "taskrepotest.db";
  setenv("DATABASE", dbname, 1);
  createTables();
  TaskRepo taskRepo;
  UserRepo userRepo;

  SUBCASE("Testando adição de tarefa") {
    User *u = userRepo.createUser("luan", "luan1810");
    Task *t = taskRepo.createTask("Tarefa", "luan", "Teste", "2023-11-26");

    CHECK_EQ(t->description(), "Teste");
  }

  remove(dbname);
}