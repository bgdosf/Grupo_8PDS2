#pragma once

#include "repository/userrepo.hpp"
#include "service/abstractservice.hpp"
#include "service/taskservice.hpp"
#include "view/loginview.hpp"

class AuthService : public Service {
 public:
  Service *handler() override;

  /// @brief lida com logica de login, utilizando repo e view
  /// @return a proxima tela
  Service *login();

  /// @brief lida com logica de registro, utilizando repo e view
  /// @return a proxima tela
  Service *registerUser();

  /// @brief autentica um usuário
  /// @param username
  /// @param password
  /// @return 1 caso as credencias sejam válidas e 0 caso não sejam
  int authenticate(std::string username, std::string password);

 private:
  LoginView _view;
  UserRepo _repo;
};