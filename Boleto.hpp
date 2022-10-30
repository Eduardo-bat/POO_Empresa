#ifndef BOLETO_H
#define BOLETO_H
#include "Pagamento.hpp"
#include "Data.h"
#include <iostream>

enum vencimentoBoleto {trintaDias, sessentaDias, noventaDias};

class Boleto : public Pagamento{

 private:
  virtual void metodoAbstrato() {}
  vencimentoBoleto vencimento; //30, 60 ou 90 dias
  Data dataAbertura, dataPagamento;
  float valor;

 public:
  Boleto(vencimentoBoleto _vencimento, float _valor);
  bool boletoVencido();
  void pagarBoleto();
  bool getEfetuado();
  Data getDataAbertura();
  Data getDataPagamento();
  vencimentoBoleto getVencimento();
  float getValor();
};

#endif