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
    
}