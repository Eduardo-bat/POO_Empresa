#ifndef CARTAOCREDITO_H
#define CARTAOCREDITO_H
#include "Pagamento.hpp"

class Cartaocredito: public Pagamento{
  private:
   void metodoAbstrato() {}
   Data dataPagamento;
   int numParcelas;
   float valorTotal;
   float valorParcela;

  public:
   Cartaocredito(int _numParcelas, float _valorTotal);
   void efetuarPagamento();
   bool getEfetuado();
   Data getDataPagamento();
   float getValorTotal();
   float getValorParcela();
   int getNumParcelas();
    
 };

#endif