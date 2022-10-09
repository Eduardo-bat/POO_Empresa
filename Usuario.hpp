#ifndef USUARIO_H
#define USUARIO_H


class Usuario {
 private:

 int permissao;
  Usuario(int _permissao);
  static Usuario *instptrUsuario;

 public:

static Usuario *instUsuario(int _permissao);
 bool verificaPermissao(int _permissao);
 int getPermissao();
 void setPermissao(int _permissao);

    };
#endif