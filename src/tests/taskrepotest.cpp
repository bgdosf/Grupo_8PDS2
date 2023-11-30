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
    UserRepo userRepo;
    User *u = userRepo.createUser("borges", "borges1810");
    TaskRepo taskRepo(u);

    SUBCASE("Testando criação de tarefa") {
        Task *t = taskRepo.createTask("Tarefa", "Teste", "2023-11-26");

        CHECK_EQ(t->title(), "Tarefa");
    }

    SUBCASE("Testando pegar tarefas do usuário") {
        Task *t1 = taskRepo.createTask("Tarefa1", "Teste1", "2023-11-26");
        Task *t2 = taskRepo.createTask("Tarefa2", "Teste2", "2023-11-26");

        std::vector<Task *> taskVector = taskRepo.getAllTasks();
        CHECK_EQ(taskVector[0]->title(), t1->title());
        CHECK_EQ(taskVector[1]->title(), t2->title());
    }

    SUBCASE("Testando pegar tarefa com id inexistente") {
        Task *t = taskRepo.getTask(1);

        CHECK_EQ(t, nullptr);
    }

    SUBCASE("Testando excluir tarefa") {
        Task *task = taskRepo.createTask("Tarefa1", "Teste1", "2023-11-26");
        taskRepo.deleteTask(task->id());
        Task *taskDeleted = taskRepo.getTask(task->id());

        CHECK_EQ(taskDeleted, nullptr);
    }

    SUBCASE("Testando finalizar tarefa") {
        Task *task = taskRepo.createTask("Tarefa1", "Teste1", "2023-11-26");
        taskRepo.finishTask(task->id());
        Task *taskUpdated = taskRepo.getTask(task->id());

        CHECK(taskUpdated->isFinished());
    }

    remove(dbname);
}