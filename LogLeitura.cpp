#include "LogLeitura.hpp"

std::string LogLeitura::getInformacao() {
  return this->informacao;
}

void LogLeitura::print() {
  std::cout << "LogLeitura" << "; permissao: " << usuario->getPermissao() << "; data: "
              << data.getData() << "; entidade: " << entidade << "; informacao: " << informacao << std::endl;
}