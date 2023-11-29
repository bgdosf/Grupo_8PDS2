#pragma once

#include "repository/abstractrepo.hpp"
#include "model/task.hpp"

#include <string>

class TaskRepo: public Repo {
public:

    Task* getTaskByTitle(std::string title);

    Task* createTask(std::string title, std::string username, std::string description, std::string deliveryDate);

    Task* updateTask(std::string title, std::string username, std::string description, std::string deliveryDate);

    std::vector<Task*> getAllTasksByUsername(std::string username);
};