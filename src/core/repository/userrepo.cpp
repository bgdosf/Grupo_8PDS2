#include "repository/userrepo.hpp"

#include <iostream>
#include <map>
#include <vector>

User* UserRepo::getUserByName(std::string username) {
  std::string sql = "SELECT * FROM user WHERE username='" + username + "';";
  std::vector<std::map<std::string, std::string>> queryResult = sqlselect(sql);
  if (queryResult.size() == 0) {  // caso a fila de resultados esteja vazia
    return nullptr;
  }
  User* u = new User(queryResult[0]["username"], queryResult[0]["password"]);
  return u;
}

User* UserRepo::createUser(std::string username, std::string password) {
  std::string sql = "INSERT INTO user (username, password) VALUES ('" +
                    username + "','" + password + "');";
  if (execSql(sql) == 0) return nullptr;
  User* u = getUserByName(username);  // buscando o usuário criado para retorno
  return u;
}