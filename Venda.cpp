#include "Venda.hpp"

Venda::Venda(Cliente *_cliente, Produto *_produto, int _qtd, Data _data) {
  this->cliente = _cliente;
  this->produto = _produto;
  this->qtd = _qtd;
  this->data = _data;
}


// void Venda::efetuaVenda(Produto *_produto, int _qtd) {
//   if (_produto->verificaEstoque(_qtd)) {
//       _produto->alteraQtd(_qtd);
//   }
// }