#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Data.h"
#include "Cargo.hpp"
#include "Pessoa.hpp"
#include "Alteracao.hpp"
#include <iostream>
#include <string>
#include <map>
enum Status {
    Ativo=1,
    desligado
};

class Funcionario : public Pessoa {
 public:
  
  Funcionario(std::string Endereco,
          std::string Nome,
          std::string Cpf_Cnpj,
          std::string Email,
          enum Tipo Tipo,
          int Matricula,
          Data Nascimento,
          std::string departamento,
          Cargo cargo,
          Data Datacontratacao,
          float Salario);


 
  bool operator=(const Funcionario& other);//Verificar

   void Alterarstatus();// Verificar

   //virtual ~Funcionario();

   std::string getEndereco() const;
 
 void setEndereco(const std::string& Endereco);
  
  int getMatricula() const;
 
 void setMatricula(const int& Matricula);
 
  Data getNascimento() const;
 
 void setNascimento(const Data& Data);
  
  std::string getDepartamento() const;
 
 void setDepartamento(const std::string& Departamento);
 
  Cargo getCargo() const;
 
 void setCargo(const Cargo& Cargo);
  
  Data getContratacao() const;
 
 void setContratacao(const Data& Data);

  float getsalario() const;
 
 void setSalario(const Data& Data);
  
  Data getDemissao() const;
 
 void setDemissao(const Data& Data);
    
    Status getstatus() const;
 
 void setStatus(const Status& status);


 private:
 std::string Endereco;
          int Matricula;
          Data Nascimento;
          std::string departamento;//Verificar
          Cargo cargo;
          Data DataContratacao;
          float Salario;
          Data DataDemissao;
          int aux_qtd;
          Status status;
          std::map<Data, Alteracao> Hist_Alt;
  
 static int Qtd;
};

#endif