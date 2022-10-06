#include "Estoque.hpp"

Estoque::Estoque() {}
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
bool Estoque::verificaEstoque(Produto *_produto, int _qtd, Data _data) {
  if (_produto->verificaEstoque(_qtd) == 1) {
    return true;
  } else {
    emiteOrdem(_data);
    return false;
  }
}

bool Estoque::verificaEstoquemin(Produto *_produto, Data _data) {
  if (_produto->verificaEstoquemin() == 1) {
    return true;
  } else {
    emiteOrdem(_data);
    return false;
  }
}

OrdemDeProd Estoque::emiteOrdem(Data _data) {
  OrdemDeProd *op = new OrdemDeProd(_data);
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
