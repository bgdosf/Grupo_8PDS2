#include "model/tagrepo.hpp"

#include <iostream>

std::vector<Tag> TagRepo::getAllTags() {
    std::vector<Tag> response;
    std::string sql = "SELECT * FROM tag WHERE username='"+_u.username()+"';";
    std::vector<std::map<std::string, std::string>> queryResult = sqlselect(sql);
    
    for (auto t : queryResult) {
        Tag tag(t["name"], stoi(t["id"]), t["username"]);
        response.push_back(tag);
    }

    return response;
}

Tag* TagRepo::getTagByName(std::string tagname) {
    std::string sql = "SELECT * FROM tag WHERE name='"+tagname+"' AND username='"+_u.username()+"';";
    std::vector<std::map<std::string, std::string>> queryResult = sqlselect(sql);
    if (queryResult.size() == 0) { // caso a fila de resultados esteja vazia
        return nullptr;
    }
    Tag *t = new Tag(queryResult[0]["name"], stoi(queryResult[0]["id"]), queryResult[0]["username"]);
    return t;
}

Tag* TagRepo::createTag(std::string tagname) {
    std::string sql = "INSERT INTO tag(name, username) values('"+tagname+"', '"+_u.username()+"');";
    if (execSql(sql) == 0) return nullptr;
    Tag *t = getTagByName(tagname); // buscando a tag criada;
    return t;
}

Tag* TagRepo::updateTag(Tag t, std::string tagname) {
    std::string sql = "UPDATE tag SET name='"+tagname+"' WHERE id="+std::to_string(t.id())+" AND username='"+_u.username()+"';";
    if (execSql(sql) == 0) return nullptr;
    Tag *renamedTag = getTagByName(tagname); // buscando a tag atualizada;
    return renamedTag;
}