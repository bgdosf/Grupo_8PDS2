#include "doctest.h"

#include "database.hpp"
#include "model/user.hpp"
#include "repository/userrepo.hpp"
#include "service/authservice.hpp"

TEST_CASE("Testando servico de autenticação") {
    const char *dbname = "userservicetest.db";
    setenv("DATABASE", dbname, 1);
    createTables();
    UserRepo repo;
    AuthService service;

    SUBCASE("Testando login válido de usuário") {
        User *u = repo.createUser("borges", "borges1810");
        int r = service.authenticate("borges", "borges1810");
        CHECK(r == 1);
    }

    SUBCASE("Testando login inválido de usuário (senha errada)") {
        User *u = repo.createUser("borges", "borges1810");
        int r = service.authenticate("borges", "testesenha");
        CHECK(r == 0);
    }

    SUBCASE("Testando login inválido de usuário (usuario errado)") {
        User *u = repo.createUser("borges", "borges1810");
        int r = service.authenticate("borgesb", "borges1810");
        CHECK(r == 0);
    }

    remove(dbname);

}