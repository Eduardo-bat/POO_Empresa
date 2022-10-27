#ifndef BOLETO_H
#define BOLETO_H
#include "Pagamento.hpp"
#include "Data.h"

class Boleto : public Pagamento{

 private:
  virtual void metodoAbstrato() {}
  int vencimento; //30, 60 ou 90 dias
  float valor;

 public:
  Boleto(int _vencimento, float _valor);
  bool boletoVencido();

 
};

#endif