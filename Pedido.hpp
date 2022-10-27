#ifndef PEDIDO_H
#define PEDIDO_H

#include "Orcamento.hpp"
#include "Venda.hpp"


class Pedido {
    public:
        Pedido(Orcamento *orcamento, Data data);
        void vende();
        float calculaNovoTotal();
    

    private:
        Orcamento *orcamento;
        Data data;
        float valor_total;
        std::list<Venda*> listaVendas;



};

#endif
