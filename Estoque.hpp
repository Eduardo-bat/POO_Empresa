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
    OrdemDeProd emiteOrdem(unsigned _ano, unsigned _mes, unsigned _dia, int _qtd, Produto *_produto);
    bool verificaEstoquemin(Produto *_produto, unsigned _ano, unsigned _mes, unsigned _dia);
    static Estoque *instEstoque();
    void print();

};
#endif