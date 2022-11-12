#include "LogLeitura.hpp"

std::string LogLeitura::getInformacao() {
  return this->informacao;
}

void LogLeitura::print() {
  std::cout << typeid(*this).name() << "; permissao: " << usuario->getPermissao() << "; data: "
              << data.getData() << "; entidade: " << entidade << "; informacao: " << informacao;
}