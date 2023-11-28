#include "view/taskview.hpp"

void TaskView::printOptions() {
    displayMessage("==================================================\n");
    displayMessage("Digite a opção que deseja acessar:\n");
    displayMessage("0 - Criar Tarefa\n");
    displayMessage("1 - Sair do Sistema\n\n");
}

void TaskView::userTasks(std::string username) {
    TaskRepo taskRepo;

    std::vector<Task*> tasks = taskRepo.getAllTasksByUsername(username);

    if (tasks.empty()) {
        std::cout << "Nenhuma tarefa encontrada para o usuário " << username << std::endl;
        return;
    }

    for (Task* task : tasks) {
        std::cout << "Título: " << task->title() << std::endl;
        std::cout << "Usuário: " << task->user().username() << std::endl;
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

std::vector<std::string> TaskView::taskForm() {
    std::vector<std::string> response;

    displayMessage("Título da Tarefa: ");
    std::string title = getInput();
    displayMessage("Descrição: ");
    std::string description = getInput();
    displayMessage("Data de término: ");
    std::string delivery_date = getInput();


    response.push_back(title);
    response.push_back(description);
    response.push_back(delivery_date);

    return response;
}
