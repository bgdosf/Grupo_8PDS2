# Task Manager

## Visão Geral
Projeto de um Task Manager desenvolvido ao longo da disciplina de PDS2, possui funcionalidades de adição de tasks, datas, tags para organização de tasks, entre outras. \
A principal funcionalidade do Task Manager é permitir aos usuários gerenciarem e acompanharem sua lista de afazeres, vendo tarefas que pertencem a um mesmo grupo, tarefas já finalizadas e a data limite de tarefas ainda não finalizadas.\
O sistema de login e registro é implementado de forma a garantir a segurança das informações dos usuários, utilizando práticas recomendadas de autenticação e armazenamento de dados. As tags agregam um elemento de personalização, permitindo que os usuários classifiquem suas tarefas de acordo com suas preferências individuais ou necessidades específicas.

## Funcionalidades
- Login e registro de usuários
- Persistência dos dados em memória
- Criação de tarefas para melhor gerenciamento de afazeres
- Criação de tags para melhor subdivisão de tarefas
- Data limite de tarefas para organização de prioridades
- Finalização de tarefas já concluidas

## Dependências 
sqlite3, libsqlite3-dev


## Como utilizar
make run #executa o codigo \
make test #executar testes \
make clean #limpa o diretorio de bin

