#ifndef USUARIO_H
#define USUARIO_H

#include <string>
class Usuario {
 private:

 int permissao;
  Usuario(std::string _nome, int _permissao);
  static Usuario *instptrUsuario;
  std::string nome;

 public:

static Usuario *instUsuario(std::string nome, int _permissao);
 bool verificaPermissao(int _permissao);
 int getPermissao();
 void setPermissao(int _permissao);
std::string getNome();
    };
#endif