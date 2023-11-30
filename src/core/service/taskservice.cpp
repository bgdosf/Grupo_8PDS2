#include "service/taskservice.hpp"

Service *TaskService::handler() {
    std::vector<Task *> tasks = _repo.getAllTasks();

    _view.userTasks(tasks, _loggedInUser->username());
    _view.printOptions();
    int response = stoi(_view.getInput());

    switch (response) {
        case 0:
            return addTask();
        case 1:
            return viewTask();
        case 2:
            return deleteTask();
        case 3:
            return finishTask();
    }

    return new TaskService(_loggedInUser);
}

Service *TaskService::addTask() {
    int taskExist;
    std::vector<std::string> result;
    result = _view.createTaskForm();
    if (createTask(result[0], result[1], result[2])) {
        _view.displayMessage("Tarefa criada\n");
    } else {
        _view.displayMessage("Tarefa não criada! (Erro no sistema :( )\n");
    }
    return new TaskService(_loggedInUser);
}

int TaskService::createTask(std::string title, std::string description,
                            std::string delivery_date) {
    Task *t = _repo.createTask(title, description, delivery_date);
    if (t == nullptr) return 0;
    return 1;
}

Service *TaskService::deleteTask() {
    int id;
    Task *task;
    do {
        _view.displayMessage(
            "Digite exit no campo abaixo caso deseje voltar!\n");
        id = _view.deleteTaskForm();
        if (id == -1) return new TaskService(_loggedInUser);
        if (id == 0) {
            _view.displayMessage("Digite um número corretamente\n");
        } else {
            task = _repo.getTaskById(id);
            if (task == nullptr) {
                _view.displayMessage(
                    "\nNão existe tarefa sua com esse id :/\n\n");
            }
            _repo.deleteTask(id);
        }
    } while (task == nullptr);
    return new TaskService(_loggedInUser);
}

Service *TaskService::finishTask() {
    int id;
    int result;
    Task *task;
    do {
        _view.displayMessage(
            "Digite exit no campo abaixo caso deseje voltar!\n");
        id = _view.finishTaskForm();
        if (id == -1) return new TaskService(_loggedInUser);
        if (id == 0) {
            _view.displayMessage("Digite um número corretamente\n");
        } else {
            task = _repo.getTaskById(id);
            if (task == nullptr) {
                _view.displayMessage(
                    "\nNão existe tarefa sua com esse id :/\n\n");
            }
            result = _repo.finishTask(id);
            if (result == -1) {
                _view.displayMessage("\nA tarefa já está como concluída\n\n");
                task = nullptr;
            }
        }
    } while (task == nullptr);
    return new TaskService(_loggedInUser);
}

Service *TaskService::viewTask() {
    int id;
    Task *task;
    do {
        _view.displayMessage(
            "Digite exit no campo abaixo caso deseje voltar!\n");
        id = _view.viewTaskForm();
        if (id == -1) return new TaskService(_loggedInUser);
        if (id == 0) {
            _view.displayMessage("Digite um número corretamente\n");
        } else {
            task = _repo.getTaskById(id);
            if (task == nullptr)
                _view.displayMessage("Não existe tarefa sua com esse id :/\n");
        }
    } while (task == nullptr);

    _view.userTask(*task);

    _view.printViewOptions();
    return new TaskService(_loggedInUser);
}