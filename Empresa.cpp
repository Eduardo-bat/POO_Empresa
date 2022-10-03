#include "Empresa.hpp"
#include <regex>

Funcionario* Empresa::adicionaFuncionario(TipoPessoa _tipo, std::string _cadastro, std::string _nome,
                          std::string _email, std::string _endereco, Data _nascimento,
                            Departamento* _departamento, Cargo _cargo, Data _dataContratacao,
                              float _salario) {
  if(validaCadastro(func, _tipo, _cadastro)) {
    Funcionario* funcionario = new Funcionario(_tipo, _cadastro, _nome, _email, _endereco, _nascimento, _cargo, _dataContratacao, _salario); //fazer delete
    _departamento->adicionarFuncionario(funcionario);
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
  std::regex regularExpr(tipoP == pFisica ? "[0-9]{3}\.?[0-9]{3}\.?[0-9]{3}\-?[0-9]{2}" :
                                              "[0-9]{2}\.?[0-9]{3}\.?[0-9]{3}\/?[0-9]{4}\-?[0-9]{2}");
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

void Empresa::aplicarDissidio(TipoDissidio tipo, float valor, Data data) {
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