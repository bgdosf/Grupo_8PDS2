#include "repository/tasktagrepo.hpp"


std::vector<int> TaskTagRepo::getAllTagsByTaskId(int taskId) {
    std::vector<int> intVec;
    std::string sql = "SELECT tag_id FROM task_tag WHERE task_id = " +
                      std::to_string(taskId) + ";";
    std::vector<std::map<std::string, std::string>> queryResult =
        sqlselect(sql);
    for (auto queryData : queryResult) {
        intVec.push_back(stoi(queryData["tag_id"]));
    }

    return intVec;
}

int TaskTagRepo::addTagToTask(int taskId, int tagId) {
    std::string sql = "INSERT INTO task_tag (task_id, tag_id) VALUES (" +
     std::to_string(taskId) + ", " + std::to_string(tagId) + ");";
    return execSql(sql);
}