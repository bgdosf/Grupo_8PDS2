#include "doctest.h"


#include "database.hpp"
#include "model/user.hpp"
#include "repository/userrepo.hpp"
#include "repository/tagrepo.hpp"

TEST_CASE("Testando repositório de usuário") {
    const char *dbname = "tagrepotest.db";
    setenv("DATABASE", dbname, 1);
    createTables();
    UserRepo userRepo;
    User *u = userRepo.createUser("geo", "123456");
    TagRepo tagRepo(*u);

    SUBCASE("Testando adição de uma tag") {
        Tag *t = tagRepo.createTag("tag1");

        CHECK(t->name() == "tag1");
    }

    SUBCASE("Testando obtenção de todas as tags de usuário") {
        Tag *t1 = tagRepo.createTag("tag1");
        Tag *t2 = tagRepo.createTag("tag2");

        std::vector<Tag> response = tagRepo.getAllTags();

        CHECK(response.size() == 2);
    }


    SUBCASE("Testando alteracao de uma tag") {
        Tag *t = tagRepo.createTag("tag1");
        Tag *tNew = tagRepo.updateTag(*t, "tag2");

        CHECK(tNew->name() == "tag2");
        CHECK(tNew->id() == t->id());
    }

    remove(dbname);

}