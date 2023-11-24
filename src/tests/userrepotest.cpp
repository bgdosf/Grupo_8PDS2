#include "doctest.h"


#include "database.hpp"
#include "model/user.hpp"
#include "model/userrepo.hpp"

TEST_CASE("Testando repositório de usuário") {
    const char *dbname = "userrepotest.db";
    setenv("DATABASE", dbname, 1);
    createTables();
    UserRepo repo;

    SUBCASE("Testando adição de um usuário") {
        User *u = repo.createUser("luan", "luan1810");
        CHECK(u->username() == "luan");
    }

    remove(dbname);

}