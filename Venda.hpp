#ifndef VENDA_H
#define VENDA_H

#include "Cliente.hpp"
#include "Data.h"
#include "Produto.hpp"

class Venda {
  private: 
Cliente *cliente;
Produto *produto;
int qtd;
Data data;

  public:
Venda(Cliente *_cliente, Produto *_produto, int _qtd, Data _data);

void efetuaVenda(Produto *_produto, int _qtd);
};

#endif