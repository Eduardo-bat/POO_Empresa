#pragma once
#include "Data.h"
#include <typeinfo>
#include <iostream>
#include <list>
#include "Usuario.hpp"

class Log {
  protected:
    Usuario *usuario;
    Data data;
    std::string entidade;
    virtual void metodoAbstrato() = 0;
  public:
    Log(Usuario *_usuario, std::string _entidade)
        : usuario(_usuario), entidade(_entidade), data(Data::dateNow()) {};
    Usuario* getUsuario();
    Data getData();
    std::string getEntity();
    virtual void print();
};