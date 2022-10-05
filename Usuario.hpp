#ifndef USUARIO_H
#define USUARIO_H


class Usuario {
 private:
 
 int permissao;

 public:

 Usuario(int _permissao);
 bool verificaPermissao(int permissao);

    };
#endif