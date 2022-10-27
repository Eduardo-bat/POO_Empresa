#ifndef LogLeitura_H
#define LogLeitura_H

#include "Data.h"
#include "Log.hpp"
#include <list>

template <class Entidade ,typename Informacao>
class LogLeitura: public Log<Entidade>{

private:

  Informacao informacao;
virtual void metodoAbstrato() {}

public:
  LogLeitura(Usuario *_usuario, Entidade _entidade, Informacao _informacao)
                 : Log<Entidade>(_usuario, _entidade), Informacao(_informacao) {};


  Informacao getInformacao();
};

template <class Entidade, typename Informacao>
Informacao LogLeitura<Entidade, Informacao>::getInformacao() {
  return this->informacao;
}

template <class Entidade, typename Informacao>
std::list<LogLeitura<Entidade, Informacao>> listLogLeitura;

#endif

