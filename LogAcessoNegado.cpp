#include "LogAcessoNegado.hpp"

std::string LogAcessoNegado::getFuncionalidade() {
  return this->funcionalidade;
}

void LogAcessoNegado::print() {
  std::cout << "LogAcessoNegado" << "; permissao: " << usuario->getPermissao() << "; data: "
                << data.getData() << "; entidade: " << entidade << "; funcionalidade: " << funcionalidade << std::endl;
}