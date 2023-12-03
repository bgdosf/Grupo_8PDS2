#include "view/taskview.hpp"

int checkStoiFunctionInput(std::string num) {
    int numResult;
    try {
        numResult = stoi(num);
    } catch (const std::invalid_argument &e) {
        return -1;
    }
    return numResult;
}

void TaskView::printOptions() {
    displayMessage("==================================================\n");
    displayMessage("Digite a opção que deseja acessar:\n");
    displayMessage("0 - Listar Tarefas\n");
    displayMessage("1 - Criar Tarefa\n");
    displayMessage("2 - Ver Tarefa\n");
    displayMessage("3 - Excluir Tarefa\n");
    displayMessage("4 - Finalizar Tarefa\n");
    displayMessage("5 - Adicionar Tag a uma Tarefa\n");
    displayMessage("6 - Entrar na tela de Tags\n\n");
}

void TaskView::userTasks(std::vector<Task *> tasks, std::string username) {
    std::cout << "\n";
    displayMessage("==================================================\n");
    displayMessage("Todas suas tarefas abaixo:\n\n");

    if (tasks.empty()) {
        std::cout << "Nenhuma tarefa encontrada para o usuário " << username
                  << std::endl;
        return;
    }

    for (Task *task : tasks) {
        userTask(*task);
    }

    // Liberar a memória alocada para as tasks
    for (Task *task : tasks) {
        delete task;
    }
}

void TaskView::userTask(Task task) {
    std::vector<Tag *> tags = task.tags();
    std::cout << "ID: " << task.id() << std::endl;
    std::cout << "Título: " << task.title() << std::endl;
    if (task.description() != "")
        std::cout << "Descrição: " << task.description() << std::endl;
    if (task.deliveryDate() != "")
        std::cout << "Data de Entrega: " << task.deliveryDate() << std::endl;
    std::cout << "Tarefa finalizada? "
              << (task.isFinished() ? "SIM :)" : "Ainda não :/") << std::endl;
    if (tags.size() != 0) {
        std::string tagsString = "Tags: ";
        for (auto tag : tags) {
            tagsString += tag->name() + " ";
        }
        std::cout << tagsString << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
    std::cout << "\n";
}

std::vector<std::string> TaskView::createTaskForm() {
    std::vector<std::string> response;

    displayMessage("Título da tarefa: ");
    std::string title = getInput();
    displayMessage("Descrição: ");
    std::string description = getInput();
    int days_from_now;
    do {
        displayMessage(
            "Número de dias a partir de hoje para data de término: \n");
        std::string days_from_now_string = getInput();
        if(days_from_now_string == "")  {
            days_from_now = 0;
            continue;
        }
        days_from_now = checkStoiFunctionInput(days_from_now_string);
        if (days_from_now == -1) {
            displayMessage("Isso não é um número válido! Tente novamente...\n");
        }
    } while (days_from_now == -1);

    std::string delivery_date;
    if (days_from_now) {
        std::cout << std::to_string(days_from_now) << std::endl;

        // Obter data atual
        std::time_t current_time = std::time(nullptr);
        std::tm *current_date = std::localtime(&current_time);

        // Adicionar dias à data atual
        current_date->tm_mday += days_from_now;

        // Usar mktime para normalizar a data após a adição dos dias
        std::mktime(current_date);

        // Formatar a data para o formato "YYYY-MM-DD"
        char buffer[20];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", current_date);
        delivery_date = buffer;
    }

    response.push_back(title);
    response.push_back(description);
    response.push_back(delivery_date);

    return response;
}

int TaskView::viewTaskForm() {
    displayMessage("Qual o id da tarefa que deseja ver? ");
    std::string id = getInput();
    if (id == "exit") return -1;
    int idNum = checkStoiFunctionInput(id);

    return idNum;
}

int TaskView::deleteTaskForm() {
    displayMessage("Qual o id da tarefa que deseja excluir?\n");
    std::string id = getInput();
    if (id == "exit") return -1;
    int idNum = checkStoiFunctionInput(id);

    return idNum;
}

int TaskView::finishTaskForm() {
    displayMessage("Qual o id da tarefa que deseja finalizar?\n");
    std::string id = getInput();
    if (id == "exit") return -1;
    int idNum = checkStoiFunctionInput(id);

    return idNum;
}

int TaskView::addTagForm() {
    displayMessage("Qual o id da tarefa que deseja adicionar uma tag?\n");
    std::string id = getInput();
    if (id == "exit") return -1;
    int idNum = checkStoiFunctionInput(id);

    return idNum;
}

std::string TaskView::tagNameForm() {
    displayMessage("Qual o nome da tag que você quer adicionar?\n");
    std::string tagName = getInput();

    return tagName;
}