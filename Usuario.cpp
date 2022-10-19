#include "Usuario.hpp"

Usuario *Usuario::instptrUsuario = 0;

Usuario *Usuario::instUsuario(std::string nome, int _permissao) {
  if(instptrUsuario == 0)
    instptrUsuario = new Usuario(nome, _permissao);
  return instptrUsuario;
}

Usuario::Usuario(std::string _nome, int _permissao){this->nome=_nome;this->permissao=_permissao;}


bool Usuario::verificaPermissao(int _permissao){
    if (this->permissao == _permissao){
        return true;
    }
        else{
            return false;
        }
    }
    
int Usuario::getPermissao() { return this->permissao; }

void Usuario::setPermissao( int _permissao){this->permissao=_permissao;}

std::string Usuario::getNome() {return this->nome;}