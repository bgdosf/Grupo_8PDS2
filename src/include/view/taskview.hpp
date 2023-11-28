#pragma once

#include "view/abstractview.hpp"
#include "repository/taskrepo.hpp"
#include "model/task.hpp"

#include <iostream>
#include <vector>
#include <string>

class TaskView: public View {
public:

    void printOptions();
    void userTasks(std::string username);
    std::vector<std::string> taskForm();
};