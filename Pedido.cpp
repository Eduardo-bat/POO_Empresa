#include "Pedido.hpp"

Pedido::Pedido(Orcamento *orcamento, Data data) {
    this->orcamento = orcamento;
    this->data = data;
    this->valor_total = orcamento->calculatotal();
    vende();
}

void Pedido::vende() {
    for (auto it = orcamento->carrinho.begin(); it != orcamento->carrinho.end(); it++) {
        Venda* venda = new Venda(orcamento->cliente, it->first, it->second, this->data);
        listaVendas.push_back(venda);
    }
}

std::list<Venda*> Pedido::getVendas() {
    return listaVendas;
}

