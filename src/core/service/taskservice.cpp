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
  view.displayMessage("Digite exit no campo de título caso deseje voltar!\n");
  result = view.createTaskForm();
  std::cout << result[0] << result[1] << result[2] << std::endl;

  if (createTask(result[0], loggedInUser->username(), result[1], result[2])) {
    view.displayMessage("Tarefa criada\n");
  } else {
    view.displayMessage("Tarefa não criada! (Erro no sistema :( )\n");
  }
  return new TaskService(loggedInUser);
}

int TaskService::createTask(std::string title, std::string username,
                            std::string description,
                            std::string delivery_date) {
  Task *t = repo.createTask(title, username, description, delivery_date);
  if (t == nullptr) return 0;
  return 1;
}

Service *TaskService::viewTask() {
  int id;
  Task *task;
  do {
    view.displayMessage("Digite exit no campo abaixo caso deseje voltar!\n");
    id = view.viewTaskForm();
    if (id == -1) return new TaskService(loggedInUser);
    if (id == 0) {
      view.displayMessage("Digite um número corretamente\n");
    } else {
      task = repo.getTaskByIdAndUsername(id, loggedInUser->username());
      if (task == nullptr)
        view.displayMessage("Não existe tarefa sua com esse id :/\n");
    }
  } while (task == nullptr);

  std::cout << "ID: " << task->id() << std::endl;
  std::cout << "Título: " << task->title() << std::endl;
  if (task->description() != "")
    std::cout << "Descrição: " << task->description() << std::endl;
  if (task->deliveryDate() != "")
    std::cout << "Data de Entrega: " << task->deliveryDate() << std::endl;
  std::cout << "Tarefa finalidade? "
            << (task->isFinished() ? "SIM :)" : "Ainda não :/") << std::endl;
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

Service *TaskService::editTask() { return new TaskService(loggedInUser); }