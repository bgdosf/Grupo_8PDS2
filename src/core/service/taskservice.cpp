#include "service/taskservice.hpp"

Service *TaskService::handler() {
  _view.userTasks(_loggedInUser->username());
  _view.printOptions();
  int response = stoi(_view.getInput());

  switch (response) {
    case 0:
      return addTask();
    case 1:
      return viewTask();
  }

  return new TaskService(_loggedInUser);
}

Service *TaskService::addTask() {
  int taskExist;
  std::vector<std::string> result;
  _view.displayMessage("Digite exit no campo de título caso deseje voltar!\n");
  result = _view.createTaskForm();
  std::cout << result[0] << result[1] << result[2] << std::endl;

  if (createTask(result[0], _loggedInUser->username(), result[1], result[2])) {
    _view.displayMessage("Tarefa criada\n");
  } else {
    _view.displayMessage("Tarefa não criada! (Erro no sistema :( )\n");
  }
  return new TaskService(_loggedInUser);
}

int TaskService::createTask(std::string title, std::string username,
                            std::string description,
                            std::string delivery_date) {
  Task *t = _repo.createTask(title, username, description, delivery_date);
  if (t == nullptr) return 0;
  return 1;
}

Service *TaskService::viewTask() {
  int id;
  Task *task;
  do {
    _view.displayMessage("Digite exit no campo abaixo caso deseje voltar!\n");
    id = _view.viewTaskForm();
    if (id == -1) return new TaskService(_loggedInUser);
    if (id == 0) {
      _view.displayMessage("Digite um número corretamente\n");
    } else {
      task = _repo.getTaskByIdAndUsername(id, _loggedInUser->username());
      if (task == nullptr)
        _view.displayMessage("Não existe tarefa sua com esse id :/\n");
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

  _view.printViewOptions();
  int response = stoi(_view.getInput());

  switch (response) {
    case 0:
      return editTask();
    case 1:
      return new TaskService(_loggedInUser);
  }

  return new TaskService(_loggedInUser);
}

Service *TaskService::editTask() { return new TaskService(_loggedInUser); }