#ifndef PEDIDO_H
#define PEDIDO_H

#include "Orcamento.hpp"
#include "Venda.hpp"


class Pedido {
    public:
        Pedido(Orcamento *orcamento, Data data);
        void vende();
        void calculaNovoTotal();
        std::list<Venda*> getVendas();
    

    private:
        Orcamento *orcamento;
        Data data;
        std::list<Venda*> listaVendas;

};

#endif
