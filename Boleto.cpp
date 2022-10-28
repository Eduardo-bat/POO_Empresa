#include "Boleto.hpp"

Boleto::Boleto(int _vencimento, float _valor){
  vencimento= _vencimento;
  valor= _valor;
}

bool Boleto::boletoVencido(){
  if( this->data.diffData(this->data.dateNow() > vencimento ) //conferir
}