#include "service/authservice.hpp"

#include "service/tagservice.hpp"

Service *AuthService::handler() {
  _view.printWelcome();
  int response = stoi(_view.getInput());

  switch (response) {
    case 0:
      return login();
    case 1:
      return registerUser();
  }

  return new AuthService();
}

Service *AuthService::login() {
  std::vector<std::string> data = _view.loginForm();
  if (authenticate(data.at(0), data.at(1)) == 0) {  // login falhou
    _view.displayMessage("Login invalido\n");
    return new AuthService();
  } else {
    User *loggedInUser = _repo.getUserByName(data.at(0));

    return new TaskService(loggedInUser);
  }
}

int AuthService::authenticate(std::string username, std::string password) {
  User *u = _repo.getUserByName(username);
  if (u == nullptr) return 0;
  if (u->password() != password) return 0;
  return 1;
}

Service *AuthService::registerUser() {
  // Pegando usuário e validando
  std::string username;
  User *u;
  _view.displayMessage("Digite exit no campo de usuário caso deseje voltar!\n");
  do {
    username = _view.registerUsernameForm();
    if (username == "exit") return new AuthService();
    u = _repo.getUserByName(username);
    if (u != nullptr) {
      _view.displayMessage("Usuário com esse nome já existe!\n");
    }
  } while (u != nullptr);

  // pegando senha e validando
  std::vector<std::string> passwords;
  _view.displayMessage("Digite exit no campo de senha caso deseje voltar!\n");
  do {
    passwords = _view.registerPasswordForm();
    if (passwords.at(0) == "exit") return new AuthService();
    if (passwords.at(0) != passwords.at(1))
      _view.displayMessage("Senhas não são iguais\n");
  } while (passwords.at(0) != passwords.at(1));

  // Criando usuário
  do {
    if (_repo.createUser(username, passwords[0]) != nullptr) {
      _view.displayMessage("Usuário criado\n");
    } else {
      _view.displayMessage("Usuário não criado! (Erro no sistema :( )\n");
    }
  } while (u != nullptr);

  return new AuthService();
}