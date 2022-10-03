#ifndef EMPRESA_H
#define EMPRESA_H

#include <list>
#include <vector>
#include "Funcionario.hpp"
#include "Cliente.hpp"
#include "Departamento.hpp"
#include "Venda.hpp"

enum TipoDissidio { percentual, absoluto };
enum TipoCadastro { func, cliente};

class Empresa {
  private:
    std::vector<Departamento*> departamentos;
    std::vector<Cliente*> clientes;
    std::list<Venda> vendas;
    bool validaCadastro(TipoCadastro tipoC, TipoPessoa tipo, std::string cadastro);
    
  public:
    Funcionario* adicionaFuncionario(TipoPessoa _tipo, std::string _cadastro, std::string _nome,
                              std::string _email, std::string _endereco, Data _nascimento,
                                Departamento* _departamento, Cargo _cargo, Data _dataContratacao,
                                  float _salario);
    Cliente* adicionarCliente(std::string telefone, std::string nome, std::string cadastro,
          std::string email, enum TipoPessoa tipo);
    void adicionarDepartamento(Departamento* departamento);
    bool retirarDepartamento(Departamento* departamento);
    void aplicarDissidio(TipoDissidio tipo, float valor, Data data);
    Departamento* getDeptFuncionario(Funcionario* funcionario);
};

#endif