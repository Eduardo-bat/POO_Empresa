#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa {
  enum tipo { pFisica, pJuridica };
  tipo Tipo;
  std::string cadastro, nome, email;
  virtual void metodoAbstrato() = 0;
};

#endif