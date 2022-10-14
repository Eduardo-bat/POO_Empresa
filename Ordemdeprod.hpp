#ifndef ORDEMDEPROD_H
#define ORDEMDEPROD_H
#include "Data.h"
#include "Producao.hpp"

class OrdemDeProd{

private:
 Data data;
 int qtd;

public:
 OrdemDeProd(unsigned _ano, unsigned _mes, unsigned _dia, int _qtd, Produto *_prod);
 Producao produz(Produto *prod);

};



#endif
