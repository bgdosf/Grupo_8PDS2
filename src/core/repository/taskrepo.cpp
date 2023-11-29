#include "repository/taskrepo.hpp"

#include <iostream>
#include <map>
#include <vector>

#include "repository/userrepo.hpp"

Task *TaskRepo::getTaskById(int id) {
  std::string sql = "SELECT * FROM task WHERE id = " + std::to_string(id) + ";";
  std::vector<std::map<std::string, std::string>> queryResult = sqlselect(sql);
  std::cout << sql << std::endl;
  if (queryResult.size() == 0) {  // caso a fila de resultados esteja vazia
    return nullptr;
  }
  Task *t = new Task(stoi(queryResult[0]["id"]), queryResult[0]["title"],
                     queryResult[0]["username"], queryResult[0]["description"],
                     queryResult[0]["delivery_date"],
                     stoi(queryResult[0]["is_finished"]));
  return t;
}

Task *TaskRepo::createTask(std::string title, std::string username,
                           std::string description, std::string deliveryDate) {
  UserRepo userRepo;
  User *u = userRepo.getUserByName(username);
  if (!u) return nullptr;
  std::string sql =
      "INSERT INTO task (title, username, description, delivery_date) "
      "VALUES ('" +
      title + "', '" + username + "', '" + description + "', '" + deliveryDate +
      "');";
  int r = execSql(sql);
  if (r) return getTaskById(r);
  return nullptr;
}

std::vector<Task *> TaskRepo::getAllTasksByUsername(std::string username) {
  std::vector<Task *> taskVector;
  std::string sql = "SELECT * FROM task WHERE username = '" + username +
                    "' ORDER BY is_finished DESC;";
  std::vector<std::map<std::string, std::string>> queryResult = sqlselect(sql);
  for (auto taskData : queryResult) {
    Task *t =
        new Task(stoi(taskData["id"]), taskData["title"], taskData["username"],
                 taskData["description"], taskData["delivery_date"],
                 stoi(taskData["is_finished"]));
    taskVector.push_back(t);
  }

  return taskVector;
}

Task *TaskRepo::getTaskByIdAndUsername(int id, std::string username) {
  std::string sql = "SELECT * FROM task WHERE id = " + std::to_string(id) +
                    " AND username = '" + username + "';";
  std::vector<std::map<std::string, std::string>> queryResult = sqlselect(sql);
  std::cout << sql << std::endl;
  if (queryResult.size() == 0) {  // caso a fila de resultados esteja vazia
    return nullptr;
  }
  Task *t = new Task(stoi(queryResult[0]["id"]), queryResult[0]["title"],
                     queryResult[0]["username"], queryResult[0]["description"],
                     queryResult[0]["delivery_date"],
                     stoi(queryResult[0]["is_finished"]));
  return t;
}