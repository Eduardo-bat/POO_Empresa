#ifndef EMPRESA_H
#define EMPRESA_H

#include <vector>
#include "Departamento.hpp"
#include "Cliente.hpp" 

enum TipoDissidio { percentual, absoluto }

class Empresa {
  private:
    std::vector<Departamento*> departamentos;
    std::vector<Cliente*> clientes;
  
  public:
    void adicionarDepartamento(Departamento* departamento);
    bool retirarDepartamento(Departamento* departamento);
    void aplicarDissidio(TipoDissidio tipo, float valor);
};

#endif