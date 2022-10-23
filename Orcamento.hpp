#pragma once
#include "Data.h"
#include "Cliente.hpp"
#include "Produto.hpp"
#include <map>

class Orcamento{
    
    public:
Orcamento(Cliente* _cliente);
void insereProduto(Produto* _produto, int qtd);
void removeProduto(Produto* _produto);
float calculatotal();
void print();

    private:
std::map<Produto*,int>carrinho;
Data data;
Cliente* cliente;
float valor_total;
};
