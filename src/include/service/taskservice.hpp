#pragma once

#include "repository/taskrepo.hpp"
#include "service/abstractservice.hpp"
#include "view/taskview.hpp"

class TaskService : public Service {
 public:
  TaskService(User *user) : loggedInUser(user) {}

  Service *handler() override;

  int checkTaskExistenceById(int id);

  int createTask(std::string title, std::string username,
                 std::string description, std::string delivery_date);

  Service *addTask();

  Service *editTask();

  Service *viewTask();

 private:
  TaskView view;
  TaskRepo repo;
  User *loggedInUser;
};