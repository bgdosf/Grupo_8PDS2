#include "view/abstractview.hpp"

#include <iostream>

int checkStoiFunction(std::string num) {
    int numResult;
    try {
        numResult = stoi(num);
    } catch (const std::invalid_argument &e) {
        return -1;
    }
    return numResult;
}

void View::displayMessage(std::string message) const { std::cout << message; }

std::string View::getInput() const {
  std::string response;
  std::getline(std::cin, response);
  return response;
}

int View::getInputNumber() const{
    std::string id = getInput();
    int idNum;
    do {
      idNum = checkStoiFunction(id);
      if(idNum == -1) displayMessage("Digite um número corretamente\n");
    } while (idNum < 0);

    return idNum;
}