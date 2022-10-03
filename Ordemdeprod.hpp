#ifndef ORDEMDEPROD_H
#define ORDEMDEPROD_H
#include "Data.h"
#include "Producao.hpp"

class OrdemDeProd{

private:
 Data data;

public:
 OrdemDeProd(Data _data);
 Producao produz(Data _data, int qtd, int lote, Produto *prod);

};

#endif