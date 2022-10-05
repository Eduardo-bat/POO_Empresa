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
    Empresa() {};
    static Empresa *instptrEmpresa;
    
  public:
    static Empresa *instEmpresa();
    Funcionario* adicionaFuncionario(TipoPessoa tipo, std::string cadastro, std::string nome,
                              std::string email, std::string endereco, Data nascimento,
                                Departamento* departamento, Cargo *cargo, Data dataContratacao,
                                  float salario);
    Cliente* adicionarCliente(std::string telefone, std::string nome, std::string cadastro,
          std::string email, enum TipoPessoa tipo);
    void adicionarDepartamento(Departamento* departamento);
    bool retirarDepartamento(Departamento* departamento);
    void aplicarDissidio(TipoDissidio tipo, float valor, Data data);
    Departamento* getDeptFuncionario(Funcionario* funcionario);
    bool vende(Cliente *cliente, Produto *produto, int qtd, unsigned ano, unsigned mes, unsigned dia);
};

#endif