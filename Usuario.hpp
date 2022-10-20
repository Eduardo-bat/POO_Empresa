#ifndef USUARIO_H
#define USUARIO_H

#include "ExcecaoAcessoNegado.hpp"

class Usuario {
 private:

 int permissao;
  Usuario(int _permissao);
  static Usuario *instptrUsuario;
  

 public:
Usuario(){};
static Usuario *instUsuario(int _permissao);
static Usuario *instUsuario();
template <class Entidade, typename Funcionalidade>
 bool verificaPermissao(int _permissao, Entidade entidade, Funcionalidade funcionalidade);
 int getPermissao();
    };

template <class Entidade, typename Funcionalidade>
bool Usuario::verificaPermissao(int permissao, Entidade entidade, Funcionalidade funcionalidade) {
  bool resultado = false;
  try {
    if(this->permissao == permissao) resultado = true;
    else throw ExcecaoAcessoNegado(this, entidade, funcionalidade);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
  return resultado;
}

#endif