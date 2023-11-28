#include "service/taskservice.hpp"

Service *TaskService::handler() {
  view.userTasks(loggedInUser->username());
  view.printOptions();
  int response = stoi(view.getInput());

    switch (response) {
        case 0:
            return addTask();
        case 1:
            return nullptr;
    }

  return nullptr; 
}

Service *TaskService::addTask() {
    std::vector<std::string> result;
    std::string title;
    Task *t;
    view.displayMessage("Digite exit no campo de título caso deseje voltar!\n");
    do {
        result = view.taskForm();
        title = result[0];
        if (title == "exit") return new TaskService(loggedInUser);
        t = repo.getTaskByTitle(title);
        if (t != nullptr) {
            view.displayMessage("Tarefa com esse título já existe!\n");
        }
    } while(t != nullptr);

    if (repo.createTask(title, loggedInUser->username(), result[1], result[2]) != nullptr) {
        view.displayMessage("Tarefa criada\n");
    } else {
        view.displayMessage("Tarefa não criada! (Erro no sistema :( )\n");
    }
    return new TaskService(loggedInUser);
}
