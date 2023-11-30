#pragma once

#include "repository/taskrepo.hpp"
#include "service/abstractservice.hpp"
#include "view/taskview.hpp"

class TaskService : public Service {
   public:
    TaskService(User *user) : _loggedInUser(user), _repo(user) {}

    Service *handler() override;

    int checkTaskExistenceById(int id);

    int createTask(std::string title, std::string description,
                   std::string delivery_date);

    Service *deleteTask();

    Service *finishTask();

    Service *addTask();

    Service *editTask();

    Service *viewTask();

   private:
    TaskView _view;
    TaskRepo _repo;
    User *_loggedInUser;
};