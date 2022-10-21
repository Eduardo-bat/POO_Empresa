#pragma once
#include "Data.h"

class Usuario;
template <class Entidade>
class Log {
  protected:
    Usuario *usuario;
    Data data;
    Entidade entidade;
    virtual void metodoAbstrato() = 0;
  public:
    Log(Usuario *_usuario, Entidade _entidade) : usuario(_usuario), entidade(_entidade) {
      Data _data = Data::dateNow();
      this->data = _data;
    };
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