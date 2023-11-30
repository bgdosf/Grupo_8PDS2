#pragma once

#include <string>

#include "model/task.hpp"
#include "repository/abstractrepo.hpp"

class TaskRepo : public Repo {
   public:
    TaskRepo(User *u) : _u(*u) {}

    Task *getTask(int id);

    Task *createTask(std::string title, std::string description,
                     std::string deliveryDate);

    std::vector<Task *> getAllTasks();

    Task *getTaskById(int id);

    int deleteTask(int id);

    int finishTask(int id);

    std::vector<Task *> filterTasks(std::string username);

   private:
    User _u;
};