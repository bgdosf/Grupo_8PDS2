#pragma once

#include <string>
#include <vector>

#include "view/abstractview.hpp"

class LoginView : public View {
 public:
  /// @brief printa a tela inicial
  void printWelcome();

  /// @brief printa o login de formulario e obtem inputs
  /// @return um vetor contendo usuario e senha
  std::vector<std::string> loginForm();

  /// @brief printa pedindo por username e obtem input
  /// @return username que foi passado
  std::string registerUsernameForm();

  /// @brief printa pedindo por senha e confirmacao e obtem inputs
  /// @return um vetor contendo a senha e confirmacao de senha
  std::vector<std::string> registerPasswordForm();
};