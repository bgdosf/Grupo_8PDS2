#include "model/task.hpp"

int Task::id() { return _id; }

std::string Task::title() { return _title; }

User Task::user() {
    UserRepo userRepo;
    User u = *userRepo.getUserByName(_username);
    return u;
}

std::string Task::description() { return _description; }

std::string Task::deliveryDate() { return _deliveryDate; }

bool Task::isFinished() { return _isFinished; }

std::vector<Tag *> Task::tags() {
    TagRepo tagRepo(user());
    TaskTagRepo taskTagRepo;
    std::vector<Tag *> tags;
    std::vector<int> tagIds = taskTagRepo.getAllTagsByTaskId(id());
    if (tagIds.size() != 0) {
        for (auto tagId : tagIds) {
            tags.push_back(tagRepo.getTagById(tagId));
        }
    }
    return tags;
}