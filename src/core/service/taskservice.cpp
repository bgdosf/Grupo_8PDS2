#include "service/taskservice.hpp"

Service *TaskService::handler() {
  view.userTasks(loggedInUser->username());
  view.printOptions();
  int response = stoi(view.getInput());

    switch (response) {
        case 0:
            return addTask();
        case 1:
            return viewTask();
    }

  return new TaskService(loggedInUser); 
}

Service *TaskService::addTask() {
    std::vector<std::string> result;
    std::string title;
    Task *t;
    view.displayMessage("Digite exit no campo de título caso deseje voltar!\n");
    do {
        result = view.createTaskForm();
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


Service *TaskService::viewTask() {
  std::string title;
  Task *task;
  view.displayMessage("Digite exit no campo abaixo caso deseje voltar!\n");
  do {
        title = view.viewTaskForm();
        if (title == "exit") return new TaskService(loggedInUser);
        task = repo.getTaskByTitle(title);
        if (task == nullptr) {
            view.displayMessage("Tarefa com esse título não existe!\n");
        }
  } while(task == nullptr);

  std::cout << "Título: " << task->title() << std::endl;
  std::cout << "Descrição: " << task->description() << std::endl;
  std::cout << "Data de Entrega: " << task->deliveryDate() << std::endl;
  std::cout << "Tarefa finalidade? " << (task->isFinished() ? "SIM :)" : "Ainda não :/") << std::endl;
  std::cout << "--------------------------" << std::endl;
  std::cout << "\n";

  view.printViewOptions();
  int response = stoi(view.getInput());

  switch (response) {
    case 0:
        return addTask();
    case 1:
        return new TaskService(loggedInUser);
    }

  return new TaskService(loggedInUser);
}