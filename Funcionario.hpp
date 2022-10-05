#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include <map>
#include "Pessoa.hpp"
#include "Data.h"
#include "Cargo.hpp"
#include "Alteracao.hpp"

class Funcionario : public Pessoa {
  private:
    std::string endereco;
    unsigned int matricula;
    Data nascimento;
    Cargo *cargo;
    Data dataCriacao;
    float salario;
    Status status;
    std::map<Data, Alteracao> histAlt;
    virtual void metodoAbstrato() {}
    static unsigned int qtd;

public:
  Funcionario(TipoPessoa _tipo, std::string _cadastro, std::string _nome, std::string _email,
                std::string _endereco, Data _nascimento,
                  Cargo *_cargo, Data _dataContratacao, float _salario);
  void aplicaDissidio(Data _data, float _novoSalario);
  void promover(Data _data, Cargo *_novoCargo, float _novoSalario);
  void contratar(Data _data, Cargo *_novoCargo, float _novoSalario);
  void demitir(Data _data);
  std::map<Data, Alteracao> gettHistAlt();
  std::string getEndereco() const;
  void setEndereco(const std::string _endereco);
  int getMatricula() const;
  Data getNascimento() const;
  void setNascimento(const Data _nascimento);
  Cargo *getCargo() const;
  float getSalario() const;
  Status getStatus() const;
};

#endif