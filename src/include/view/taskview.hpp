#pragma once

#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include "model/task.hpp"
#include "repository/taskrepo.hpp"
#include "view/abstractview.hpp"

class TaskView : public View {
   public:
    void printOptions();
    void printViewOptions();
    void userTask(Task task);
    void userTasks(std::vector<Task *>, std::string username);
    int deleteTaskForm();
    int finishTaskForm();
    std::vector<std::string> createTaskForm();
    int viewTaskForm();
};