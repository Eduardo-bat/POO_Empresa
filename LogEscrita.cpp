#include "LogEscrita.hpp"

std::string LogEscrita::getAtributoAntes() {
    return this->atributoAntes;
}

std::string LogEscrita::getAtributoDepois() {
    return this->atributoDepois;
}

void LogEscrita::print() {
  std::cout << typeid(*this).name() << "; permissao: " << usuario->getPermissao() << "; data: "
                << data.getData() << "; entidade: " << entidade << "; atributo antes: " << atributoAntes
                    << "; atributo depois: " << atributoDepois;
}