#include "view/taskview.hpp"

void TaskView::printOptions() {
    displayMessage("==================================================\n");
    displayMessage("Digite a opção que deseja acessar:\n");
    displayMessage("0 - Criar Tarefa\n");
    displayMessage("1 - Ver Tarefa\n\n");
}

void TaskView::printViewOptions() {
    displayMessage("==================================================\n");
    displayMessage("Digite a opção que deseja acessar:\n");
    displayMessage("0 - Editar essa Tarefa\n");
    displayMessage("1 - Voltar para a Lista de Tarefas\n\n");
}

void TaskView::userTasks(std::string username) {
    std::cout << "\n";
    displayMessage("==================================================\n");
    displayMessage("Todas suas tarefas abaixo:\n\n");

    TaskRepo taskRepo;

    std::vector<Task*> tasks = taskRepo.getAllTasksByUsername(username);

    if (tasks.empty()) {
        std::cout << "Nenhuma tarefa encontrada para o usuário " << username << std::endl;
        return;
    }

    for (Task* task : tasks) {
        std::cout << "Título: " << task->title() << std::endl;
        std::cout << "Descrição: " << task->description() << std::endl;
        std::cout << "Data de Entrega: " << task->deliveryDate() << std::endl;
        std::cout << "Tarefa finalidade? " << (task->isFinished() ? "SIM :)" : "Ainda não :/") << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cout << "\n";
    }

    // Liberar a memória alocada para as tasks
    for (Task* task : tasks) {
        delete task;
    }
}

std::vector<std::string> TaskView::createTaskForm() {
    std::vector<std::string> response;

    displayMessage("Descrição: ");
    std::string description = getInput();
        displayMessage("Número de dias a partir de hoje para data de término: ");
    std::string days_from_now_string = getInput();

    int days_from_now = stoi(days_from_now_string);
    

    // Obter data atual
    std::time_t current_time = std::time(nullptr);
    std::tm* current_date = std::localtime(&current_time);

    // Adicionar dias à data atual
    current_date->tm_mday += days_from_now;
    std::mktime(current_date);

    // Formatar a data para o formato "DD/MM/AAAA"
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%d/%m/%Y", current_date);
    std::string delivery_date = buffer;


    response.push_back(description);
    response.push_back(delivery_date);

    return response;
}

std::string TaskView::viewTaskForm() {
  displayMessage("Qual o título da tarefa que deseja ver? ");
  std::string title = getInput();

  return title;
}

std::string TaskView::createTitleTaskForm() {
    displayMessage("Título da tarefa: ");
    std::string title = getInput();

    return title;
}
