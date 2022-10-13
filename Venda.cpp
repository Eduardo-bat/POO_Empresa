#include "Venda.hpp"

Venda::Venda(Cliente *_cliente, Produto *_produto, int _qtd, Data _data) {
  this->cliente = _cliente;
  this->produto = _produto;
  this->qtd = _qtd;
  this->data = _data;
}


void Venda::efetuaVenda() {
  if (this->produto->verificaEstoque(this->qtd)) {
      this->produto->alteraQtd(this->qtd);
  }
}