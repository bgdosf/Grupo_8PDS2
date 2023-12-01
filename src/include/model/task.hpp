#pragma once

#include <string>

#include "model/tag.hpp"
#include "model/user.hpp"
#include "repository/tagrepo.hpp"
#include "repository/tasktagrepo.hpp"
#include "repository/userrepo.hpp"

class Task {
   public:
    Task(int id, std::string title, std::string username,
         std::string description, std::string deliveryDate, bool isFinished)
        : _id(id),
          _title(title),
          _username(username),
          _description(description),
          _deliveryDate(deliveryDate),
          _isFinished(isFinished){};

    int id();
    std::string title();
    User user();
    std::string description();
    std::string deliveryDate();
    bool isFinished();
    std::vector<Tag*> tags();

   private:
    int _id;
    std::string _title;
    std::string _username;
    std::string _description;
    std::string _deliveryDate;
    bool _isFinished;
};