#include "model/task.hpp"

std::string Task::title() {
    return _title;
}

User Task::user() {
    UserRepo userRepo;
    User u = *userRepo.getUserByName(_username);
    return u;
}

std::string Task::description() {
  return _description;
}

std::string Task::deliveryDate() {
  return _deliveryDate;
}

bool Task::isFinished() {
  return _isFinished;
}