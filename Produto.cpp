#include "Produto.hpp"

Produto::Produto(std::string nome,float valorvenda, int codigo, int lotemin, int estoquemin){
    this->nome=nome;
    this->valorvenda=valorvenda;
    this->lotemin=lotemin;
    this->estoquemin=estoquemin;
    this->codigo=codigo;
}

int Produto::ChecaQtd(){
    int outp=0;
    for(auto it=lotes.begin();it!=lotes.end();it++){
        outp+=(**it);
    }
    return outp;
}

void Produto::alteraQtd(int qtd){
     for(auto it=lotes.begin();it!=lotes.end();it++){
      if(qtd>=0 && (**it) <= qtd){
       qtd -=(**it);
        (**it)=0;
        }
       else{
         (**it)-=qtd;
       }
}
  }

bool Produto::verificaEstoque(int _qtd){
if (this->ChecaQtd() >= _qtd) {
    return true;
  } else {
    return false;
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

void Produto::setValorvenda(const float valorvenda){this->valorvenda=valorvenda;}

void Produto::insereLotes(int qtd){
    lotes.push_back(&qtd);
}

