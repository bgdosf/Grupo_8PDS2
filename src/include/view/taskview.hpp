#pragma once

#include "view/abstractview.hpp"
#include "repository/taskrepo.hpp"
#include "model/task.hpp"

#include <ctime>
#include <iostream>
#include <vector>
#include <string>

class TaskView: public View {
public:

    void printOptions();
    void printViewOptions();
    void userTasks(std::string username);
    std::vector<std::string> createTaskForm();
    std::string viewTaskForm();
    std::string createTitleTaskForm();
};