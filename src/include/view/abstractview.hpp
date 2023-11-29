#pragma once

#include <string>

class View {
 public:
  /// @brief mostra a mensagem ao usuario
  /// @param message
  virtual void displayMessage(std::string message) const;

  /// @brief obtem input do usuario
  /// @return input obtido
  virtual std::string getInput() const;
};