#include "database.hpp"
#include "doctest.h"
#include "model/user.hpp"
#include "repository/userrepo.hpp"

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