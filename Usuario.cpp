#include "Usuario.hpp"
#include <iostream>

Usuario *Usuario::instptrUsuario = 0;

Usuario *Usuario::instUsuario( int _permissao) {
  if(instptrUsuario == 0)
    instptrUsuario = new Usuario( _permissao);
  return instptrUsuario;
}

Usuario *Usuario::instUsuario() {
  if(instptrUsuario == 0)
    instptrUsuario = new Usuario;
  return instptrUsuario;
}

Usuario::Usuario( int _permissao){this->permissao=_permissao;}


bool Usuario::verificaPermissao(int _permissao){
   try{
    if ((this->permissao == _permissao)){
         return true;
    }
   
        else{
           
            throw(permissao);//revisar 
            
        }
   }
   catch(int _p){
    std::cout<<"Permissão "<<_p<<" não compatível";
    std::cout<<"\n";
    return false;
   }
    }
    
int Usuario::getPermissao() { return this->permissao; }