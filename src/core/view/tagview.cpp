#include "view/tagview.hpp"

void TagView::printMenu() {
    displayMessage("Bem vindo ao menu de tags, o que deseja fazer? \n");
    displayMessage("0 - Listar tags\n");
    displayMessage("1 - Adicionar tag\n");
    displayMessage("2 - Atualizar tag\n");
}

void TagView::printTags(std::vector<Tag> tags) {
    for (auto t : tags) {
        printTag(t);
    }
}

void TagView::printTag(Tag t) {
    displayMessage("============================\n");
    displayMessage("Id: " + std::to_string(t.id()) + "\n");
    displayMessage("Nome: " + t.name() + "\n");
    displayMessage("============================\n");
}

std::vector<std::string> TagView::renderUpdateForm() {
    std::vector<std::string> response;

    displayMessage("Digite o antigo nome da tag: ");
    std::string id = getInput();
    displayMessage("Digite o novo nome: ");
    std::string newName = getInput();

    response.push_back(id);
    response.push_back(newName);

    return response;
}