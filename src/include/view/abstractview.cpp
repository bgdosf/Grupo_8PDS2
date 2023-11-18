#include "model/abstractview.hpp"

#include <iostream>

void View::displayMessage(std::string message) const {
    std::cout << message << std::endl;
}

std::string View::getInput() const {
    std::string response;
    std::cin >> response;
    return response;
}