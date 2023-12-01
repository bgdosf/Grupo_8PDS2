#pragma once

#include "service/abstractservice.hpp"
#include "repository/tagrepo.hpp"
#include "view/tagview.hpp"
#include "model/user.hpp"


class TagService: public Service {
public:
    TagService(User u): _tagRepo(u), _user(u) {}

    Service *handler() override;

    /// @brief lista as tags do usuario
    /// @return o proximo service
    Service *listTags();

    /// @brief adiciona uma tag
    /// @return o proximo service
    Service *addTag();

    /// @brief atualiza uma tag
    /// @return o proximo service
    Service *updateTag();


private:
    User _user;
    TagRepo _tagRepo;
    TagView _tagView;
};