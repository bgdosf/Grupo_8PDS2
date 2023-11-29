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
  void userTasks(std::string username);
  std::vector<std::string> createTaskForm();
  int viewTaskForm();
};