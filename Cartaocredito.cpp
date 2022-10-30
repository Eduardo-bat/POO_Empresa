#include "Cartaocredito.hpp"

Cartaocredito::Cartaocredito(int _numParcelas, float _valorTotal){
 numParcelas= _numParcelas;
 valorTotal= _valorTotal;
 valorParcela= _valorTotal / _numParcelas;
  efetuado= false;
} 

void Cartaocredito::efetuarPagamento(){
  efetuado=true;
  dataPagamento=dataPagamento.dateNow();
}
   
Data Cartaocredito::getDataPagamento(){
 return dataPagamento;    
}

float Cartaocredito::getValorTotal(){
  return valorTotal;
}

float Cartaocredito::getValorParcela(){
 return valorParcela;
}

int Cartaocredito::getNumParcelas(){
  return numParcelas;
}