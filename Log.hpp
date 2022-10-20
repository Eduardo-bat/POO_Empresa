#pragma once
#include "Data.h"
#include "Usuario.hpp"

template <class Entidade>
class Log {
  protected:
    Data data;
    Usuario *usuario;
    Entidade entidade;
    virtual void metodoAbstrato() = 0;
  public:
    Usuario* getUsuario();
    Data getData();
    Entidade getEntity();
};

template <class Entidade>
Usuario* Log<Entidade>::getUsuario(){return this->usuario;}

template <class t>
Data Log<t>::getData(){return this->data;}

template <class t>
t Log<t>::getEntity(){return this->*entidade;}