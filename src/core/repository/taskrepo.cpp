#include "repository/taskrepo.hpp"

#include <iostream>
#include <map>
#include <vector>

#include "repository/userrepo.hpp"

Task *TaskRepo::getTask(int id) {
    std::string sql =
        "SELECT * FROM task WHERE id = " + std::to_string(id) + ";";
    std::vector<std::map<std::string, std::string>> queryResult =
        sqlselect(sql);
    if (queryResult.size() == 0) {  // caso a fila de resultados esteja vazia
        return nullptr;
    }
    Task *t = new Task(
        stoi(queryResult[0]["id"]), queryResult[0]["title"],
        queryResult[0]["username"], queryResult[0]["description"],
        queryResult[0]["delivery_date"], stoi(queryResult[0]["is_finished"]));
    return t;
}

Task *TaskRepo::createTask(std::string title, std::string description,
                           std::string deliveryDate) {
    std::string sql =
        "INSERT INTO task (title, username, description, delivery_date) "
        "VALUES ('" +
        title + "', '" + _u.username() + "', '" + description + "', '" +
        deliveryDate + "');";
    int r = execSql(sql);
    if (r) return getTask(r);
    return nullptr;
}

std::vector<Task *> TaskRepo::getAllTasks() {
    std::vector<Task *> taskVector;
    std::string sql = "SELECT * FROM task WHERE username = '" + _u.username() +
                      "' ORDER BY is_finished;";
    std::vector<std::map<std::string, std::string>> queryResult =
        sqlselect(sql);
    for (auto taskData : queryResult) {
        Task *t =
            new Task(stoi(taskData["id"]), taskData["title"],
                     taskData["username"], taskData["description"],
                     taskData["delivery_date"], stoi(taskData["is_finished"]));
        taskVector.push_back(t);
    }

    return taskVector;
}

Task *TaskRepo::getTaskById(int id) {
    std::string sql = "SELECT * FROM task WHERE id = " + std::to_string(id) +
                      " AND username = '" + _u.username() + "';";
    std::vector<std::map<std::string, std::string>> queryResult =
        sqlselect(sql);
    if (queryResult.size() == 0) {  // caso a fila de resultados esteja vazia
        return nullptr;
    }
    Task *t = new Task(
        stoi(queryResult[0]["id"]), queryResult[0]["title"],
        queryResult[0]["username"], queryResult[0]["description"],
        queryResult[0]["delivery_date"], stoi(queryResult[0]["is_finished"]));
    return t;
}

int TaskRepo::deleteTask(int id) {
    std::string sql = "DELETE FROM task WHERE id = " + std::to_string(id) +
                      " AND username = '" + _u.username() + "';";
    return execSql(sql);
}

int TaskRepo::finishTask(int id) {
    Task *t = getTask(id);
    if (t->isFinished()) return -1;
    std::string sql =
        "UPDATE task SET is_finished = true WHERE id = " + std::to_string(id) +
        " AND username = '" + _u.username() + "';";
    return execSql(sql);
}