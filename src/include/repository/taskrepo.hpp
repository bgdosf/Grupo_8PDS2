#pragma once

#include <string>

#include "model/task.hpp"
#include "repository/abstractrepo.hpp"

class TaskRepo : public Repo {
   public:
    TaskRepo(User *u) : _u(*u) {}

    /// @brief Retorna a tarefa com o ID especificado
    /// @param id O ID da tarefa a ser buscada
    /// @return A tarefa buscada (nullptr caso não exista)
    Task *getTask(int id);

    /// @brief Cria uma nova tarefa com o título, descrição e data de entrega especificados
    /// @param title O título da tarefa
    /// @param description A descrição da tarefa
    /// @param deliveryDate A data de entrega da tarefa
    /// @return A tarefa criada
    Task *createTask(std::string title, std::string description,
                     std::string deliveryDate);

    /// @brief Retorna um vetor contendo todas as tarefas associadas a um usuário
    /// @return Um vetor de tarefas
    std::vector<Task *> getAllTasks();

    /// @brief Retorna a tarefa com o ID especificado
    /// @param id O ID da tarefa a ser buscada
    /// @return A tarefa buscada (nullptr caso não exista)
    Task *getTaskById(int id);

    /// @brief Deleta a tarefa com o ID especificado
    /// @param id O ID da tarefa a ser deletada
    /// @return 0 se a exclusão for bem-sucedida, caso contrário um código de erro
    int deleteTask(int id);

    /// @brief Marca a tarefa com o ID especificado como concluída
    /// @param id O ID da tarefa a ser marcada como concluída
    /// @return 0 se a marcação for bem-sucedida, caso contrário um código de erro
    int finishTask(int id);


   private:
    User _u;
};