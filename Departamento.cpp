#include "Departamento.hpp"

Departamento::Departamento(std::string _nome){
  this->nome = _nome;
}

void Departamento::adicionarFuncionario(Funcionario *f) {
  this->pessoal.push_back(f);
}

bool Departamento::retirarFuncionario(const Funcionario *f) {
  std::vector<Funcionario*>::iterator itr;
  for(itr = this->pessoal.begin(); itr != this->pessoal.end(); ++ itr)
    if(*itr == f) {
      this->pessoal.erase(itr);
      return true;
    }
  return false;
}

std::string Departamento:: getNome() const {
  return this->nome;
}

void Departamento::setNome(std::string _nome){
  this->nome = _nome;
}