#include "Ordemdeprod.hpp"

OrdemDeProd::OrdemDeProd(Data _data){
  data= _data;
}

Producao OrdemDeProd::produz(Data _data, int qtd, int lote, Produto *prod) {
  Producao p=Producao(_data, qtd, lote, prod);
  return p;
}