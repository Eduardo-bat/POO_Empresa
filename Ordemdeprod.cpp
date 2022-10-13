#include "Ordemdeprod.hpp"

OrdemDeProd::OrdemDeProd(unsigned _ano, unsigned _mes, unsigned _dia){
  this->data= Data(_ano, _mes, _dia) ;
}

Producao OrdemDeProd::produz(int qtd, int lote, Produto *prod) {
  Producao p=Producao(this->data, qtd, lote, prod);
  return p;
}



