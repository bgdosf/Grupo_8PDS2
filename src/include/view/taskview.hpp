#pragma once

#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include "model/tag.hpp"
#include "model/task.hpp"
#include "repository/tagrepo.hpp"
#include "repository/taskrepo.hpp"
#include "view/abstractview.hpp"

class TaskView : public View {
   public:
    /// @brief Imprime as opções disponíveis no menu
    void printOptions();

    /// @brief Mostra os detalhes de uma única tarefa para o usuário
    /// @param task A tarefa a ser exibida
    void userTask(Task task);

    /// @brief Mostra as tarefas associadas a um usuário
    /// @param tasks Um vetor de ponteiros para tarefas
    /// @param username O nome de usuário associado às tarefas
    void userTasks(std::vector<Task *>, std::string username);

    /// @brief Renderiza um formulário para deletar uma tarefa
    /// @return O ID da tarefa a ser deletada
    int deleteTaskForm();

    /// @brief Renderiza um formulário para marcar uma tarefa como concluída
    /// @return O ID da tarefa a ser marcada como concluída
    int finishTaskForm();

    /// @brief Renderiza um formulário para adicionar uma tag a uma tarefa
    /// @return O ID da tarefa à qual a tag será adicionada
    int addTagForm();

    /// @brief Renderiza um formulário para obter o nome de uma nova tag
    /// @return O nome da nova tag
    std::string tagNameForm();

    /// @brief Renderiza um formulário para criar uma nova tarefa
    /// @return Um vetor contendo os detalhes da nova tarefa (título, descrição, data de entrega)
    std::vector<std::string> createTaskForm();

    /// @brief Renderiza um formulário para visualizar uma tarefa
    /// @return O ID da tarefa a ser visualizada
    int viewTaskForm();
};