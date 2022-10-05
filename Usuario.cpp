#include "Usuario.hpp"

Usuario::Usuario(int _permissao){this->permissao=_permissao;}


bool Usuario::verificaPermissao(int _permissao){
    if (this->permissao >= _permissao){
        return true;
    }
        else{
            return false;
        }
    }
    
int Usuario::getPermissao() { return this->permissao; }

void Usuario::setPermissao( int _permissao){this->permissao=_permissao;}