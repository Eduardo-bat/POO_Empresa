#ifndef PAGAMENTO_H
#define PAGAMENTO_H
#include "Data.h"

class Pagamento{

protected:
 Data data; // to em duvida dessa data ainda...
 bool efetuado;
 virtual void metodoAbstrato() = 0;

public:
  bool pagamentoEfetuado(); //porque o pedido so eh efetivado quando o pagamento eh efetuado
 
};


#endif