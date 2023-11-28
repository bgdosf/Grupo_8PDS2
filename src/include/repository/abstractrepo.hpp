#pragma once

#include <sqlite3.h>
#include <string>
#include <vector>
#include <map>

class Repo {
    public:
        /// @brief Construtor
        Repo();

        /// @brief Destrutor
        ~Repo();

        /// @brief executa um comando generico, onde nenhum resultado é obtido
        /// @param command 
        /// @return codigo de sucesso ou falha
        virtual int execSql(std::string command) const;

        /// @brief executa um select, onde um resultado é obtido
        /// @param command 
        /// @return vetor de mapa representando cada atributo e o valor correspondente
        virtual std::vector<std::map<std::string, std::string>> sqlselect(std::string command) const;
    protected:
        sqlite3 *db;
};