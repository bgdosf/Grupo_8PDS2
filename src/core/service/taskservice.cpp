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
    int taskExist;
    std::vector<std::string> result;
    std::string title;
    view.displayMessage("Digite exit no campo de título caso deseje voltar!\n");
    do {
        title = view.createTitleTaskForm();
        if (title == "exit") return new TaskService(loggedInUser);
        int taskExist = checkTaskExistenceByTitle(title);
        if (!taskExist) {
            view.displayMessage("Tarefa com esse título já existe!\n");
        }
    } while(!taskExist);
    
    result = view.createTaskForm();

    if (createTask(title, loggedInUser->username(), result[0], result[1])) {
        view.displayMessage("Tarefa criada\n");
    } else {
        view.displayMessage("Tarefa não criada! (Erro no sistema :( )\n");
    }
    return new TaskService(loggedInUser);
}

int TaskService::checkTaskExistenceByTitle(std::string title) {
    Task *t = repo.getTaskByTitle(title);
    if (t == nullptr) return 0;
    return 1;
}

int TaskService::createTask(std::string title, std::string username, std::string description, std::string delivery_date) {
    Task *t = repo.createTask(title, username, description, delivery_date);
    if (t == nullptr) return 0;
    return 1;
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
        return editTask();
    case 1:
        return new TaskService(loggedInUser);
    }

  return new TaskService(loggedInUser);
}

Service *TaskService::editTask() {

    return new TaskService(loggedInUser);
}