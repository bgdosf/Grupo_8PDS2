#include "service/taskservice.hpp"

Service *TaskService::handler() {
    _view.printOptions();
    int response = _view.getInputNumber();

    switch (response) {
        case 0: 
            return viewAllTasks();
        case 1:
            return addTask();
        case 2:
            return viewTask();
        case 3:
            return deleteTask();
        case 4:
            return finishTask();
        case 5:
            return addTag();
        case 6:
            return new TagService(*_loggedInUser);
    }

    return new TaskService(_loggedInUser);
}

Service *TaskService::viewAllTasks() {
    std::vector<Task *> tasks = _taskRepo.getAllTasks();

    _view.userTasks(tasks, _loggedInUser->username());
    
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
    Task *t = _taskRepo.createTask(title, description, delivery_date);
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
            task = _taskRepo.getTaskById(id);
            if (task == nullptr) {
                _view.displayMessage(
                    "\nNão existe tarefa sua com esse id :/\n\n");
            }
            _taskRepo.deleteTask(id);
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
            task = _taskRepo.getTaskById(id);
            if (task == nullptr) {
                _view.displayMessage(
                    "\nNão existe tarefa sua com esse id :/\n\n");
            }
            result = _taskRepo.finishTask(id);
            if (result == -1) {
                _view.displayMessage("\nA tarefa já está como concluída\n\n");
                task = nullptr;
            }
        }
    } while (task == nullptr);
    return new TaskService(_loggedInUser);
}

Service *TaskService::addTag() {
    int taskId;
    Task *task;
    Tag *tag;
    do {
        _view.displayMessage(
            "Digite exit no campo abaixo caso deseje voltar!\n");
        taskId = _view.addTagForm();
        if (taskId == -1) return new TaskService(_loggedInUser);
        if (taskId == 0) {
            _view.displayMessage("Digite um número corretamente\n");
        } else {
            task = _taskRepo.getTaskById(taskId);
            if (task == nullptr)
                _view.displayMessage("Não existe tarefa sua com esse id :/\n");
        }
    } while (task == nullptr);
    do {
        std::string tagName;
        _view.displayMessage(
            "Digite exit no campo abaixo caso deseje voltar!\n");
        tagName = _view.tagNameForm();
        if (tagName == "exit") return new TaskService(_loggedInUser);
        tag = _tagRepo.getTagByName(tagName);
        if (tag == nullptr)
            _view.displayMessage("Não existe tarefa sua com esse id :/\n");
    } while (tag == nullptr);
    _taskTagRepo.addTagToTask(taskId, tag->id());
    
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
            task = _taskRepo.getTaskById(id);
            if (task == nullptr)
                _view.displayMessage("Não existe tarefa sua com esse id :/\n");
        }
    } while (task == nullptr);

    _view.userTask(*task);

    return new TaskService(_loggedInUser);
}