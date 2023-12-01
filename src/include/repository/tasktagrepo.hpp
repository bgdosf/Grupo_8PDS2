#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "repository/abstractrepo.hpp"

class TaskTagRepo : public Repo {
   public:
    /// @brief Obtém todas as tags associadas a um determinado ID de tarefa
    /// @param taskId O ID da tarefa para a qual as tags estão sendo buscadas
    /// @return Um vetor contendo os IDs das tags associadas à tarefa
    std::vector<int> getAllTagsByTaskId(int taskId);

    /// @brief Adiciona uma tag a uma tarefa especificada
    /// @param taskId O ID da tarefa à qual a tag será adicionada
    /// @param tagId O ID da tag a ser adicionada à tarefa
    /// @return o ID do da task_tag adicionada se for bem-sucedida, caso contrário 0
    int addTagToTask(int taskId, int tagId);

};