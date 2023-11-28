#include "view/loginview.hpp"


void LoginView::printWelcome() {
    displayMessage("==================================================\n");
    displayMessage("Bem Vindo ao Gerenciador de Tarefas\n");
    displayMessage("Digite a opção que deseja acessar:\n");
    displayMessage("0 - Login\n");
    displayMessage("1 - Registrar\n\n");
}

std::vector<std::string> LoginView::loginForm() {
    std::vector<std::string> response;

    displayMessage("Usuário: ");
    std::string username = getInput();
    displayMessage("Senha: ");
    std::string password = getInput();


    response.push_back(username);
    response.push_back(password);

    return response;
}

std::string LoginView::registerUsernameForm() {
    
    displayMessage("Usuário: ");
    std::string username = getInput();

    return username;
}

std::vector<std::string> LoginView::registerPasswordForm() {
    std::vector<std::string> response;
    displayMessage("Senha: ");
    std::string password = getInput();
    displayMessage("Repetir senha: ");
    std::string passwordConfirm = getInput();


    response.push_back(password);
    response.push_back(passwordConfirm);

    return response;
}