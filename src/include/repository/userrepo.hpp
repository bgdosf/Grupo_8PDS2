#pragma once

#include <string>

#include "model/user.hpp"
#include "repository/abstractrepo.hpp"

class UserRepo : public Repo {
 public:
  /// @brief pega um usuário pelo nome (que é chave única)
  /// @param username
  /// @return o usuário buscado (nullptr caso ele não exista)
  User* getUserByName(std::string username);

  /// @brief cria um usuário no banco de dados
  /// @param username
  /// @param password
  /// @return o usuário criado (nullptr caso ele não tenha sido adicionado)
  User* createUser(std::string username, std::string password);
};