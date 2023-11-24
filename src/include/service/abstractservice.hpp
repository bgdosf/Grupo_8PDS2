#pragma once

class Service {
public:
    /// @brief Lida com logica de ligacao entre modelo e view
    /// @return O proximo handler ao qual o usuario sera redirecionado
    virtual Service *handler() = 0;
};