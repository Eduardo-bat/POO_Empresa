#ifndef USUARIO_H
#define USUARIO_H

#include <string>
class Usuario {
 private:

 int permissao;
  Usuario(int _permissao);
  static Usuario *instptrUsuario;
  std::string nome;

 public:
Usuario(){};
static Usuario *instUsuario(int _permissao);
static Usuario *instUsuario();
 bool verificaPermissao(int _permissao);
 int getPermissao();
    };
#endif