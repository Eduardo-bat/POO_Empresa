#include "Pedido.hpp"

Pedido::Pedido(Orcamento *orcamento, Data data) {
    this->orcamento = orcamento;
    this->data = data;
    this->valor_total = 0;

}

float Pedido::calculaNovoTotal() {
    return this->orcamento->calculatotal();
}

void Pedido::vende() {
    for (auto it = orcamento->carrinho.begin(); it != orcamento->carrinho.end(); it++) {
        Venda venda(orcamento->cliente, it->first, it->second, this->data);
    }
    
    //Venda venda(orcamento->cliente, Produto *_produto, int _qtd, Data _data)
}