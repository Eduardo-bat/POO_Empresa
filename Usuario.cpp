#include "Usuario.hpp"
#include <iostream>

Usuario *Usuario::instptrUsuario = 0;

Usuario *Usuario::instUsuario(int _permissao) {
  if (instptrUsuario == 0)
    instptrUsuario = new Usuario(_permissao);
  return instptrUsuario;
}

Usuario *Usuario::instUsuario() {
  if (instptrUsuario == 0)
    instptrUsuario = new Usuario;
  return instptrUsuario;
}

Usuario::Usuario(int _permissao) { this->permissao = _permissao; }

int Usuario::getPermissao() { return this->permissao; }