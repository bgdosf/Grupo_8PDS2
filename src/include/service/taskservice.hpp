#pragma once

#include "repository/tagrepo.hpp"
#include "repository/taskrepo.hpp"
#include "repository/tasktagrepo.hpp"
#include "service/abstractservice.hpp"
#include "service/tagservice.hpp"
#include "view/taskview.hpp"

class TaskService : public Service {
   public:
    TaskService(User *user) : _loggedInUser(user), _taskRepo(user), _tagRepo(*user) {}

    Service *handler() override;

    /// @brief Exibe todas as tarefas
    /// @return O próximo serviço
    Service *viewAllTasks();

    /// @brief Verifica se uma tarefa com o ID especificado existe
    /// @param id O ID da tarefa a ser verificada
    /// @return O ID da tarefa se a tarefa existir, caso contrário 0
    int checkTaskExistenceById(int id);

    /// @brief Cria uma nova tarefa com o título, descrição e data de entrega especificados
    /// @param title O título da tarefa
    /// @param description A descrição da tarefa
    /// @param delivery_date A data de entrega da tarefa
    /// @return O ID da tarefa  se a criação for bem-sucedida, caso contrário 0
    int createTask(std::string title, std::string description,
                   std::string delivery_date);

    /// @brief Deleta uma tarefa
    /// @return o próximo serviço
    Service *deleteTask();

    /// @brief Marca uma tarefa como concluída
    /// @return o próximo serviço
    Service *finishTask();

    /// @brief Adiciona uma tarefa
    /// @return o próximo serviço
    Service *addTask();

    /// @brief Exibe uma tarefa em específico
    /// @return o próximo serviço
    Service *viewTask();

    /// @brief Adiciona uma tag a uma tarefa
    /// @return o próximo serviço
    Service *addTag();

   private:
    TaskView _view;
    TaskRepo _taskRepo;
    TagRepo _tagRepo;
    TaskTagRepo _taskTagRepo;
    User *_loggedInUser;
};