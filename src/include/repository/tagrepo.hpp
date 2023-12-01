#pragma once

#include <vector>

#include "model/tag.hpp"
#include "model/user.hpp"
#include "repository/abstractrepo.hpp"

class TagRepo : public Repo {
   public:
    /// @brief Inicia o repositorio
    /// @param u
    TagRepo(User u) : _u(u) {}

    /// @brief pega todas as tags do repositorio
    /// @return um array com todas as tags (elas serao de apenas um user)
    std::vector<Tag> getAllTags();

    /// @brief pega uma tag no banco de dados pelo nome
    /// @param tag
    /// @return a tag buscada (nullptr caso ela não exista)
    Tag *getTagByName(std::string tagname);

    /// @brief Retorna a tag buscada pelo ID
    /// @param id O ID da tag a ser buscada
    /// @return A tag buscada (nullptr caso não exista)
    Tag *getTagById(int id);


    /// @brief cria uma tag com o nome passado
    /// @param tagname
    /// @return a tag criada
    Tag *createTag(std::string tagname);

    /// @brief atualiza uma tag para outro nome
    /// @param tagname
    /// @return a tag alterada
    Tag *updateTag(Tag t, std::string tagname);

   private:
    User _u;
};