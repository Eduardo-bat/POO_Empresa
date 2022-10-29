#include "Boleto.hpp"

Boleto::Boleto(vencimentoBoleto _vencimento, float _valor){
  efetuado= false;
  vencimento= _vencimento;
  valor= _valor;
  dataAbertura= dataAbertura.dateNow();
}

bool Boleto::boletoVencido(){
  
  Data x= dataAbertura.dateNow();
  if(vencimento==noventaDias){
     if( x.diffData(dataAbertura) > 90 ){
     return true;
   }else{
     return false;
   }
  }else if(vencimento==sessentaDias){
    if( x.diffData(dataAbertura) > 60 ){
     return true;
   }else{
     return false;
   }
  }else if(vencimento==trintaDias){
    if(x.diffData(dataAbertura) > 30 ){
     return true;
   }else{
     return false;
   }
  }
  
}

void Boleto::pagarBoleto(){
  if(this->boletoVencido()==false){
    efetuado=true;
    dataPagamento=dataAbertura.dateNow();
    std::cout<<endl<<"Pagamento efetuado com sucesso!";
  }else{
    std::cout<<endl<<"Este boleto esta vencido!";  
  }
}