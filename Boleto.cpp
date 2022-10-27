#include "Boleto.hpp"

Boleto::Boleto(int _vencimento, float _valor){
  vencimento= _vencimento;
  valor= _valor;
}

Boleto::bool boletoVencido(){
  this->data.diffData(dateNow()); //conferir
}