#ifndef VENDA_H
#define VENDA_H

#include "Cliente.hpp"
#include "Data.h"
#include "Produto.hpp"
#include "Estoque.hpp"

class Venda {
  private: 
Cliente *cliente;
Produto *produto;
int qtd;
Data data;
Estoque *estoque;

  public:
Venda(Cliente *_cliente, Produto *_produto, int _qtd, Data data, Estoque *_estoque);

bool verificaEstoque(int _qtd);

void efetuaVenda(Data data);
};

#endif