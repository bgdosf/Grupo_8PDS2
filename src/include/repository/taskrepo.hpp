#pragma once

#include <string>

#include "model/task.hpp"
#include "repository/abstractrepo.hpp"

class TaskRepo : public Repo {
 public:
  Task* getTaskById(int id);

  Task* createTask(std::string title, std::string username,
                   std::string description, std::string deliveryDate);

  Task* updateTask(std::string title, std::string username,
                   std::string description, std::string deliveryDate);

  std::vector<Task*> getAllTasksByUsername(std::string username);

  Task* getTaskByIdAndUsername(int id, std::string username);
};