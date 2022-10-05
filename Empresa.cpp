#include "Empresa.hpp"
#include <regex>

Empresa *Empresa::instptrEmpresa = 0;

Empresa *Empresa::instEmpresa() {
  if(instptrEmpresa == 0)
    instptrEmpresa = new Empresa;
  return instptrEmpresa;
}

Funcionario* Empresa::adicionaFuncionario(TipoPessoa tipo, std::string cadastro, std::string nome,
                          std::string email, std::string endereco, unsigned anoNasc, unsigned mesNasc, unsigned diaNasc,
                            Departamento* departamento, Cargo *cargo, unsigned anoCria, unsigned mesCria, unsigned diaCria, float salario) {
  if(validaCadastro(func, tipo, cadastro)) {
    Data dataNasc(anoNasc, mesNasc, diaNasc);
    Data dataCria(anoCria, mesCria, diaCria);
    Funcionario* funcionario = new Funcionario(tipo, cadastro, nome, email, endereco, dataNasc, cargo, dataCria, salario); //fazer delete
    departamento->adicionarFuncionario(funcionario);
    return funcionario;
  } else {
    return nullptr;
  }
}

Cliente* Empresa::adicionarCliente(std::string telefone, std::string nome, std::string cadastro,
                                    std::string email, enum TipoPessoa tipo) {
  if(validaCadastro(cliente, tipo, cadastro)) {
    Cliente* cliente = new Cliente(telefone, nome, cadastro, email, tipo);
    return cliente;
  } else {
    return nullptr;
  }          
}

bool Empresa::validaCadastro(TipoCadastro tipoC, TipoPessoa tipoP, std::string cadastro) {
  std::regex regularExpr(tipoP == pFisica ? "[0-9]{3}[0-9]{3}[0-9]{3}[0-9]{2}" :
                                              "[0-9]{2}[0-9]{3}[0-9]{3}[0-9]{4}[0-9]{2}");
  if(!std::regex_match(cadastro, regularExpr)) return false;
  if(tipoC == func) {
    std::vector<Departamento*>::iterator itrD;
    std::vector<Funcionario*>::iterator itrF;
    for(itrD = this->departamentos.begin(); itrD != this->departamentos.end(); ++ itrD)
      for(itrF = (*itrD)->getFuncionarios().begin(); itrF != (*itrD)->getFuncionarios().end(); ++ itrF)
        if((*itrF)->getCadastro() == cadastro)
          return false;
  } else {
    std::vector<Cliente*>::iterator itr;
    for(itr = this->clientes.begin(); itr != this->clientes.end(); ++ itr)
      if((*itr)->getCadastro() == cadastro)
        return false;
  }
  return true;
}

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

void Empresa::aplicarDissidio(TipoDissidio tipo, float valor, unsigned ano, unsigned mes, unsigned dia) {
  Data data(ano, mes, dia);
  std::vector<Departamento*>::iterator itrD;
  std::vector<Funcionario*>::iterator itrF;
  for(itrD = this->departamentos.begin(); itrD != this->departamentos.end(); ++ itrD)
    for(itrF = (*itrD)->getFuncionarios().begin(); itrF != (*itrD)->getFuncionarios().end(); ++ itrF)
      if(tipo == percentual)
        (*itrF)->aplicaDissidio(data, (*itrF)->getSalario() + (*itrF)->getSalario() * valor / 100);
      else
        (*itrF)->aplicaDissidio(data, (*itrF)->getSalario() +  valor);
}

Departamento* Empresa::getDeptFuncionario(Funcionario* funcionario) {
  std::vector<Departamento*>::iterator itrD;
  std::vector<Funcionario*>::iterator itrF;
  for(itrD = this->departamentos.begin(); itrD != this->departamentos.end(); ++ itrD) {
    std::vector<Funcionario*> funcionarios = (*itrD)->getFuncionarios();
    for(itrF = (*itrD)->getFuncionarios().begin(); itrF != (*itrD)->getFuncionarios().end(); ++ itrF)
      if((*itrF) == funcionario)
        return (*itrD);
  }
  return nullptr;
}

bool Empresa::vende(Cliente *cliente, Produto *produto, int qtd, unsigned ano, unsigned mes, unsigned dia) {
  if(produto->ChecaQtd() >= qtd) {
    Data data(ano, mes, dia);
    Venda venda(cliente, produto, qtd, data);
    this->vendas.push_back(venda);
    return true;
  } else return false;
}