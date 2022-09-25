#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Data.hpp"
#include "Cargo.hpp"
#include "Pessoa.hpp"
#include "Alteracao.hpp"
#include "Departamento.hpp"
#include <string>
#include <map>

enum Status { Ativo, desligado};

class Funcionario : public Pessoa {
  private:
    std::string endereco;
    int matricula;
    Data nascimento;
    Departamento departamento;
    Cargo cargo;
    Data dataContratacao;
    float salario;
    Status status;
    std::map<Data, Alteracao> histAlt;
    virtual void metodoAbstrato() {}
    static unsigned int qtd;

public:
  Funcionario(std::string _endereco, int _matricula, Data _nascimento, Departamento _departamento,
              Cargo _cargo, Data _dataContratacao, float _salario, Status _status);
  void aplicaAlteracao();
  std::string getEndereco() const;
  void setEndereco(const std::string _endereco);
  int getMatricula() const;
  Data getNascimento() const;
  void setNascimento(const Data _nascimento);
  std::string getDepartamento() const;
  void setDepartamento(const std::string& _departamento);
  Cargo getCargo() const;
  void setCargo(const Cargo& _cargo);
  Data getContratacao() const;
  float getsalario() const;
  void setSalario(const float _salario);
  Data getDemissao() const;
  Status getstatus() const;
};

#endif