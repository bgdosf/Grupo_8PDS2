#pragma once

#include <string>

class Tag {
public:
    Tag(std::string name, int id, std::string username): _id(id), _name(name), _username(username) {}
    std::string name();
    int id();
    std::string username();
private:
    int _id; 
    std::string _name;
    std::string _username;
};