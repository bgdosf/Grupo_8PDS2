#pragma once

#include "service/abstractservice.hpp"
#include "view/taskview.hpp"
#include "repository/taskrepo.hpp"

class TaskService: public Service {
public:
    TaskService(User* user) : loggedInUser(user) {}

    Service *handler() override;

    Service *createTask();

    Service *addTask();

private:
    TaskView view;
    TaskRepo repo;
    User* loggedInUser;
};