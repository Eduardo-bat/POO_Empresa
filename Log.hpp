/*
#pragma once
#include "Data.h"
#include "Usuario.hpp"

template<class t>
class Log{

protected:

Data data;
Usuario usuario;
 t *entidade;

public:
Log(){};
 Usuario getUsuario();
 Data getData();
 ~Log();
 void setEntity(t *_entity);
t getEntity();
};


template <class t>
 Usuario Log<t>::getUsuario(){return this->usuario;}

template <class t>
Data Log<t>::getData(){return this->data;}

template <class t>
void Log<t>:: setEntity(t *_entity){this->entidade=(_entity);}

template <class t>
t Log<t>::getEntity(){return this->*entidade;}

*/