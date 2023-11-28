#include "repository/taskrepo.hpp"
#include "repository/userrepo.hpp"

#include <iostream>
#include <vector>
#include <map>

Task* TaskRepo::getTaskByTitle(std::string title) {
  std::string sql = "SELECT * FROM task WHERE title = '" + title + "';"; 
  std::vector<std::map<std::string, std::string>> queryResult = sqlselect(sql);
  std::cout<< sql << std::endl;
  if (queryResult.size() == 0) { // caso a fila de resultados esteja vazia
      return nullptr;
  }
  Task *t = new Task(queryResult[0]["title"], queryResult[0]["username"], queryResult[0]["description"], queryResult[0]["delivery_date"], stoi(queryResult[0]["is_finished"]));
  return t;
}

Task* TaskRepo::createTask(std::string title, std::string username, std::string description, std::string deliveryDate) {
    UserRepo userRepo;
    User *u = userRepo.getUserByName(username);
    if(!u) return nullptr;
    std::string sql = "INSERT INTO task (title, username, description, delivery_date) "
                    "VALUES ('"+title+"', '"+username+"', '"+description+"', '"+deliveryDate+"');";            
    if (execSql(sql) == 0) return nullptr;
    Task *t = getTaskByTitle(title);
    return t;
}

std::vector<Task*> TaskRepo::getAllTasksByUsername(std::string username) {
  std::vector<Task*> taskVector;
  std::string sql = "SELECT * FROM task WHERE username = '" + username + "' ORDER BY is_finished DESC;";
  std::vector<std::map<std::string, std::string>> queryResult = sqlselect(sql);
    for (auto taskData : queryResult) {
      Task *t = new Task(taskData["title"], taskData["username"], taskData["description"], taskData["delivery_date"], stoi(taskData["is_finished"]));
      taskVector.push_back(t);
  }

  return taskVector;
}