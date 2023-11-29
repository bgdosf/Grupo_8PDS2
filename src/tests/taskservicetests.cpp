#include "database.hpp"
#include "doctest.h"
#include "model/task.hpp"
#include "model/user.hpp"
#include "repository/taskrepo.hpp"
#include "repository/userrepo.hpp"
#include "service/taskservice.hpp"

TEST_CASE("Testando service de tarefas") {
  const char *dbname = "taskrepotest.db";
  setenv("DATABASE", dbname, 1);
  createTables();
  TaskRepo taskRepo;
  UserRepo userRepo;
  User *u = userRepo.createUser("cae", "cae222");
  TaskService taskService(u);

  SUBCASE("Testando criação de tarefa válida") {
    int r = taskService.createTask("tarefa", "cae", "teste", "11/28/2023");
    CHECK(r == 1);
  }

  remove(dbname);
}