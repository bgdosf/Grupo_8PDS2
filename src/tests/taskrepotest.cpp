#include "database.hpp"
#include "doctest.h"
#include "model/task.hpp"
#include "model/user.hpp"
#include "repository/taskrepo.hpp"
#include "repository/userrepo.hpp"

TEST_CASE("Testando repositório de tarefas") {
  const char *dbname = "taskrepotest.db";
  setenv("DATABASE", dbname, 1);
  createTables();
  TaskRepo taskRepo;
  UserRepo userRepo;

  SUBCASE("Testando criação de tarefa") {
    User *u = userRepo.createUser("borges", "borges1810");
    Task *t = taskRepo.createTask("Tarefa", "borges", "Teste", "2023-11-26");

    CHECK_EQ(t->title(), "Tarefa");
  }

  SUBCASE("Testando pegar tarefas do usuário") {
    User *u = userRepo.createUser("borges", "borges1810");
    Task *t1 = taskRepo.createTask("Tarefa1", "borges", "Teste1", "2023-11-26");
    Task *t2 = taskRepo.createTask("Tarefa2", "borges", "Teste2", "2023-11-26");

    std::vector<Task *> taskVector =
        taskRepo.getAllTasksByUsername(u->username());
    CHECK_EQ(taskVector[0]->title(), t1->title());
    CHECK_EQ(taskVector[1]->title(), t2->title());
  }

  SUBCASE("Testando pegar tarefa com id inexistente") {}

  remove(dbname);
}