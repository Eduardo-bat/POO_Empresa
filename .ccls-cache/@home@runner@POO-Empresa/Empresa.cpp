#include "Empresa.hpp"

void Empresa::adicionarDepartamento(Departamento* departamento) {
  this->departamentos.push_back(departamento);
}

bool Empresa::retirarDepartamento(Departamento* departamento) {
  std::vector<Departamento*>::iterator itr;
  for(itr = this->departamentos.begin(); itr != this->departamentos.end(); ++ itr)
    if(*itr == departamento) {
      this->departamentos.erase(itr);
      return true;
    }
  return false;
}

void Empresa::aplicarDissidio(float valor) {
  std::vector<Departamento*>::iterator itrD;
  std::vector<Funcionario*>::iterator itrF;
  for(itrD = this->departamentos.begin(); itrD != this->departamentos.end(); ++ itrD)
    for(itrF = (*itrD)->pessoal.begin(); itr != this->pessoal.end(); ++ itr)
}