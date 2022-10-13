#ifndef ORDEMDEPROD_H
#define ORDEMDEPROD_H
#include "Data.h"
#include "Producao.hpp"

class OrdemDeProd{

private:
 Data data;

public:
 OrdemDeProd(unsigned _ano, unsigned _mes, unsigned _dia);
 Producao produz(int qtd, int lote, Produto *prod);

};



#endif