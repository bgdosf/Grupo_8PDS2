#pragma once

#include <string>
#include "model/user.hpp"
#include "repository/userrepo.hpp"

class Task {
public:
    Task(std::string title, std::string username, std::string description, std::string deliveryDate, bool isFinished): 
    _title(title), _username(username), _description(description), _deliveryDate(deliveryDate), _isFinished(isFinished) {};

    std::string title();
    User user();
    std::string description();
    std::string deliveryDate();
    bool isFinished();

private:
    std::string _title;
    std::string _username;
    std::string _description;
    std::string _deliveryDate;
    bool _isFinished;
};