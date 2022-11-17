#include "Produto.hpp"

Produto::Produto(std::string nome,float valorvenda, int codigo, int lotemin, int estoquemin,std::map<MateriaPrima*,unsigned> materias_prima){
    this->nome=nome;
    this->valorvenda=valorvenda;
    this->lotemin=lotemin;
    this->estoquemin=estoquemin;
    this->codigo=codigo;
    this->materiasprimas=materias_prima;
}

int Produto::ChecaQtd(){
    int outp=0;
    for(auto it=lotes.begin();it!=lotes.end();it++){
        outp+=(*it);
    }
    return outp;
}

void Produto::alteraQtd(int qtd){
     for(auto it=lotes.begin();it!=lotes.end();it++){
      if(qtd>0 && (*it) <= qtd){
       qtd -=(*it);
        (*it)=0;
        }
       else{
         (*it)-=qtd;
         break;
       }
}
  }


bool Produto::verificaEstoquemin(){
  if (this->ChecaQtd() >= this->getEstoquemin() ) {
    return true;
  } else {
    return false;
  }
}

std::string Produto::getNome() const{ return this->nome;}

void Produto::setNome(const std::string _nome){this->nome=_nome;}

int Produto::getCodigo() const{ return this->codigo; }

void Produto::setCodigo(const int codigo){this->codigo=codigo;}

int Produto::getLotemin() const{return this->lotemin;}

void Produto::setLotemin(const int lotemin){this->lotemin=lotemin;}

int Produto::getEstoquemin() const{return this->estoquemin;}

void Produto::setEstoquemin(const int estoquemin){this->estoquemin=estoquemin;}

float Produto::getValorvenda() const{return this->valorvenda;}

void Produto::setValorvenda(const float valorvenda, unsigned ano, unsigned mes, unsigned dia){
  this->valorvenda=valorvenda;
  Data data(ano, mes, dia);
  hist_valor.emplace(data,valorvenda);
  }

void Produto::insereLotes(int qtd){
  for(auto it=materiasprimas.begin();it!=materiasprimas.end();it++){
   it->first->alteraQtd( -(it->second) );
  }
  lotes.push_back(qtd);  
}

void Produto::print(){
  int aux=1;
  std::cout<<"nome: ";
  std::cout<<this->getNome();
  std::cout<<"\n";
  std::cout<<"Valor Venda: ";
  std::cout<<this->getValorvenda();
  std::cout<<"\n";
  std::cout<<"Lote Mínimo: ";
  std::cout<<this->getLotemin();
  std::cout<<"\n";
  std::cout<<"Estoque Mínimo: ";
  std::cout<<this->getEstoquemin();
  std::cout<<"\n";
  std::cout<<"Código: ";
  std::cout<<this->getCodigo();
  std::cout<<"\n";
  std::cout<<"Quantidade: ";
  std::cout<<this->ChecaQtd();
  std::cout<<"\n";
  for(auto it=lotes.begin();it!=lotes.end();it++){
    std::cout<<"Lote: ";
    std::cout<<aux;
    std::cout<<"\n";
    std::cout<<"Quantidade: ";
    std::cout<<(*it);
    std::cout<<"\n";
    aux++;
  }
  for(auto it=materiasprimas.begin();it!=materiasprimas.end();it++){
  std::cout<<"\n";
  std::cout<<"Matérias primas: ";
  std::cout<<it->second<<it->first->getUnidadeDeMedida();
  }


}

void Produto::print_hist(){
  std::cout<<"\n";
  std::cout<<"Histórico Valor de Venda: ";
  std::cout<<"\n";
  for(auto it=hist_valor.begin();it!=hist_valor.end();it++){
    std::cout<<it->first.getData();
    std::cout<<": R$ ";
    std::cout<<it->second;
    std::cout<<"\n";
  }
   std::cout<<"\n";
}

