#ifndef MP_H
#define MP_H

#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <limits>
#include "OrcamentoCompra.hpp"
#include "Fornecedor.hpp"

class MateriaPrima {
    std::string unidadeDeMedida;
    std::map<OrcamentoCompra*, std::map<Fornecedor*, bool>> orcamentos;
    std::vector<Fornecedor*> fornecedores;
    unsigned estoqueMin;
    unsigned estoqueAtual;
  public:
    MateriaPrima(std::string _unidadeDeMedida, unsigned _estoqueMin)
                  : unidadeDeMedida(_unidadeDeMedida), estoqueMin(_estoqueMin) {};
    bool inserirFornecedor(Fornecedor*);
    void emiteOrcamentoCompra(unsigned);
    std::map<OrcamentoCompra*, std::map<Fornecedor*, bool>> getOrcamentos();
    Fornecedor* finalizaCompra(OrcamentoCompra*);
    void alteraQtd(int);
    unsigned getQtd();
};

#endif