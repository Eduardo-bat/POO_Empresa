#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <string>
#include <vector>
#include "Declaracoes.h"
#include "Empresa.hpp"

class Departamento {
private:
  std::string nome;
  std::vector<Funcionario*> pessoal;
  friend Empresa;

public:
  Departamento(std::string Nome);
  void adicionarFuncionario(Funcionario *f);
  bool retirarFuncionario(const Funcionario *f);
  std::string getNome() const;
  void setNome(const std::string _nome);
};

#endif