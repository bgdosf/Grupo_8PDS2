#pragma once

#include <string>

class User {
   public:
    User(std::string username, std::string password)
        : _username(username), _password(password){};
    std::string username();
    std::string password();

   private:
    std::string _username;
    std::string _password;
};