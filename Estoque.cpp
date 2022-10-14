#include "Estoque.hpp"


Estoque *Estoque::instptrEstoque = 0;

Estoque *Estoque::instEstoque() {
  if(instptrEstoque == 0)
    instptrEstoque = new Estoque;
  return instptrEstoque;
}

void Estoque::adicionaProduto(Produto *p) { produtos_estoque.push_back(p); }

void Estoque::adicionaOrdem(OrdemDeProd *op) { ordemdeprod.push_back(*op); }

void Estoque::removeProduto(Produto *p) {
  std::vector<Produto *>::iterator it;
  for (it = produtos_estoque.begin(); it != produtos_estoque.end(); it++) {
    if ((*it)->getNome() == (p->getNome())) {
      produtos_estoque.erase(it);
      break;
    }
  }
}


bool Estoque::verificaEstoquemin(Produto *_produto, unsigned _ano, unsigned _mes, unsigned _dia) {
  if (_produto->verificaEstoquemin() == 1) {
    return true;
  } else {
    int aux=_produto->getEstoquemin()-_produto->ChecaQtd();
    emiteOrdem( _ano, _mes, _dia,aux,_produto);
    return false;
  }
}

OrdemDeProd Estoque::emiteOrdem(unsigned _ano, unsigned _mes, unsigned _dia, int _qtd,Produto *_produto) {
  OrdemDeProd *op = new OrdemDeProd(_ano, _mes, _dia,_qtd,_produto);
  adicionaOrdem(op);
  return *op;
}

void Estoque::print(){
 std::vector<Produto *>::iterator it;
 std::cout<<"Produtos em Estoque:";
 std::cout<<"\n";
  for (it = produtos_estoque.begin(); it != produtos_estoque.end(); it++) {
  (*it)->print();
  std::cout<<"\n";
}
 std::cout<<"\n";
}