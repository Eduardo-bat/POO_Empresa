#ifndef EMPRESA_H
#define EMPRESA_H

#include <list>
#include <vector>
#include "Funcionario.hpp"
#include "Cliente.hpp"
#include "Departamento.hpp"
#include "Venda.hpp"
#include "Usuario.hpp"
#include "Cargo.hpp"
#include "Pedido.hpp"
#include "Veiculo.hpp"
#include "LogEscrita.hpp"
#include "LogLeitura.hpp"

enum TipoDissidio { percentual, absoluto };
enum TipoCadastro { func, cliente};

class Empresa {
  private:
    std::vector<Departamento*> departamentos;
    std::vector<Cliente*> clientes;
		std::vector<Orcamento*> orcamentos;
		std::vector<Pedido*> pedidos;
    bool validaCadastro(TipoCadastro tipoC, TipoPessoa tipo, std::string cadastro);
    std::vector<Veiculo*> frota;
    std::pair<int, int> endereco = {0, 0};
    Empresa() {};
    static Empresa *instptrEmpresa;
    
  public:
    static Empresa *instEmpresa();
    Funcionario* adicionaFuncionario(TipoPessoa tipo, std::string cadastro, std::string nome,
                              std::string email, std::pair<float, float> endereco, unsigned anoNasc, unsigned mesNasc, unsigned diaNasc,
                                Departamento* departamento, Cargo *cargo, unsigned anoCria, unsigned mesCria, unsigned diaCria, float salario);
    Cliente* adicionarCliente(std::string telefone, std::string nome, std::string cadastro,
          std::string email, enum TipoPessoa tipo);
    void adicionarDepartamento(Departamento* departamento);
    bool retirarDepartamento(Departamento* departamento);
    void aplicarDissidio(TipoDissidio tipo, float valor, unsigned ano, unsigned mes, unsigned dia);
    Departamento* getDeptFuncionario(Funcionario* funcionario);
		bool criaOrcamento(Cliente* cliente, unsigned ano, unsigned mes, unsigned dia);
		std::vector<Orcamento*> getOrcamentos();
		bool efetuaPedido(Orcamento* orcamento, unsigned ano, unsigned mes, unsigned dia);
    void deletaFuncionario(Funcionario* funcionario);
    void deletaCliente(Cliente* cliente);
    Cargo* criaCargo(std::string nome);
    void adicionaVeiculo(Veiculo* veiculo);
    void setEndereco(std::pair<int, int>);
    std::pair<int, int> getEndereco();
};

#endif