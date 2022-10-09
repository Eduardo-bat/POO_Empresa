#ifndef ESTOQUE_H
#define ESTOQUE_H
#include <list>
#include <vector>
#include"Data.h"
#include"Ordemdeprod.hpp"
#include"Produto.hpp"
#include <iostream>



class Estoque {
  private:
    std::list<OrdemDeProd> ordemdeprod;
    std::vector<Produto*> produtos_estoque;
     Estoque(){};
    static Estoque *instptrEstoque;

  public:
    void adicionaProduto(Produto* p);
    void removeProduto(Produto *p);
     void adicionaOrdem(OrdemDeProd* op);
    OrdemDeProd emiteOrdem(Data data);
    bool verificaEstoque(Produto *_produto, int _qtd, Data _data);
    bool verificaEstoquemin(Produto *_produto, Data _data);
    static Estoque *instEstoque();
    void print();

};
#endif