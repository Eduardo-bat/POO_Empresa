#include "Veiculo.hpp"
#include <cmath>
#define Vm 18
#include <vector>
#include <algorithm>
#include <map>


Veiculo::Veiculo(int _capacidade, Turno *_t,std::pair<float,float>*end_empresa){
this->capacidade=_capacidade;
this->turno=_t;
this->end_empresa=end_empresa;
}
float Veiculo::calculaDistancia_e (float x1, float y1){
return 110.57 * sqrt( pow(this->end_empresa->first-x1,2) + pow(this->end_empresa->second-y1, 2) );
}

float Veiculo::calculaDistancia (float x1, float y1, float x2, float y2){
return 110.57 * sqrt( pow(x2-x1,2) + pow(y2-y1, 2) );
}

void Veiculo::sethorario(){
  float outp=0;
  float t=0;
  Data* _d= new Data();
  _d->setHora(this->getTurno().gethorario_entrada()-1);
  _d->setMin(50);
  for(auto it=rota.begin();it!=rota.end();it++){
    std::pair<float,float>aux=it->getEndereco();
    if(it==rota.begin()){
      outp=calculaDistancia_e(aux.first,aux.second);
      t=outp/Vm;
      int d=t;
        int m=(t-d)*60;
        Data _data=Data();
        _data.setHora(d);
        _data.setMin(m);
        *_d=*_d-_data;
       quadro_horarios.insert(make_pair(it->getNome(),*_d));
      }
    else{
      outp=calculaDistancia((it-1)->getEndereco().first,(it-1)->getEndereco().second,aux.first,aux.second);
      t=outp/Vm;
      int d=t;
        int m=(t-d)*60;
         _d->setHora(_d->getHora()+d);
         _d->setMin(_d->getMin()+m);
        quadro_horarios.insert(make_pair(it->getNome(),*_d));
    }
    }
}



void Veiculo::adicionafuncionario(Funcionario _f){
 std::vector<Funcionario>::iterator itf;
  itf=rota.begin();
  std::pair<float,float>auxf=_f.getEndereco();
  //if(this->getTurno()==_f.getTurno()){
  if(rota.empty()==1){
    rota.push_back(_f);
    }
    else{
    std::pair<float,float>auxi=itf->getEndereco();
  if(calculaDistancia_e(auxf.first,auxf.second) >= calculaDistancia_e(auxi.first,auxi.second)){
    rota.insert(itf,_f);
    }
    
    else if(rota.size()>1){
      for( auto it=rota.begin();it!=rota.end();it++){
        std::pair<float,float>auxi=it->getEndereco();
      std::pair<float,float>auxa=(it+1)->getEndereco();
        if (calculaDistancia(auxf.first,auxf.second,auxi.first,auxi.second) <= calculaDistancia(auxa.first,auxa.second,auxi.first,auxi.second)){
        rota.insert(it+1,_f);
          break;
        }
        }
    }
    
      
  else{
   rota.push_back(_f);
}
    }
    sethorario();
}
//}


void Veiculo::removefuncionario(Funcionario funcionario){
for(auto it=rota.begin();it!=rota.end();it++){
if (it->getNome()==funcionario.getNome())
rota.erase(it);
}
}

void Veiculo::print_rota(){
   std::cout<<"Rota:"<<"\n";
    for( auto it=rota.begin();it!=rota.end();it++){
        std::cout<<it->getNome()<<"\n";
}
}

Turno Veiculo::getTurno(){
return *this->turno;
}
void Veiculo::print_qh(){
  std::vector<std::pair<std::string,Data> > arr;
  for(auto itf=quadro_horarios.begin();itf!=quadro_horarios.end();itf++){
    arr.push_back(make_pair(itf->first,itf->second));
  }
  
  std::sort(arr.begin(), arr.end(),
              [] (const auto &x, const auto &y) {return x.second < y.second;});
    std::cout<<"Quadro de Horários:"<<"\n";
  for(auto it=arr.begin();it!=arr.end();it++){
    std::cout<<it->first<<" ";
    std::cout<<it->second.getHora()<<":"<<it->second.getMin()<<"\n";
    
  }
 
}