#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

class Usuario {
private:
  int permissao;
  Usuario(int _permissao);
  static Usuario *instptrUsuario;

public:
  Usuario() {};
  static Usuario *instUsuario(int _permissao);
  static Usuario *instUsuario();
  int getPermissao();
};

#endif