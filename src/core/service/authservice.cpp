#include "service/authservice.hpp"

Service *AuthService::handler() {
  view.printWelcome();
  int response = stoi(view.getInput());

  switch (response) {
    case 0:
      return login();
    case 1:
      return registerUser();
  }

  return new AuthService();
}

Service *AuthService::login() {
  std::vector<std::string> data = view.loginForm();
  if (authenticate(data.at(0), data.at(1)) == 0) {  // login falhou
    view.displayMessage("Login invalido\n");
    return new AuthService();
  } else {
    User *loggedInUser = repo.getUserByName(data.at(0));

    return new TaskService(loggedInUser);
  }
}

int AuthService::authenticate(std::string username, std::string password) {
  User *u = repo.getUserByName(username);
  if (u == nullptr) return 0;
  if (u->password() != password) return 0;
  return 1;
}

Service *AuthService::registerUser() {
  // Pegando usuário e validando
  std::string username;
  User *u;
  view.displayMessage("Digite exit no campo de usuário caso deseje voltar!\n");
  do {
    username = view.registerUsernameForm();
    if (username == "exit") return new AuthService();
    u = repo.getUserByName(username);
    if (u != nullptr) {
      view.displayMessage("Usuário com esse nome já existe!\n");
    }
  } while (u != nullptr);

  // pegando senha e validando
  std::vector<std::string> passwords;
  view.displayMessage("Digite exit no campo de senha caso deseje voltar!\n");
  do {
    passwords = view.registerPasswordForm();
    if (passwords.at(0) == "exit") return new AuthService();
    if (passwords.at(0) != passwords.at(1))
      view.displayMessage("Senhas não são iguais\n");
  } while (passwords.at(0) != passwords.at(1));

  // Criando usuário
  if (repo.createUser(username, passwords[0]) != nullptr) {
    view.displayMessage("Usuário criado\n");
  } else {
    view.displayMessage("Usuário não criado! (Erro no sistema :( )\n");
  }
  return new AuthService();
}