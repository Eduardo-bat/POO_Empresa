#include "Funcionario.hpp"

unsigned int Funcionario::qtd = 1;

Funcionario(std::string _endereco, int _matricula, Data _nascimento, Departamento _departamento,
              Cargo _cargo, Data _dataContratacao, float _salario, Status _status) {
  this->endereco = _endereco;
  this->matricula = _matricula;
  this->nascimento = _nascimento;
  this->departamento = _departamento;
  this->cargo = _cargo;
  this->dataContratacao = _dataContratacao;
  this->salario = _salario;
  this->status = _status;
  Funcionario::qtd++;
}

std::string Funcionario::getEndereco() const {
  return this->endereco;
}

void Funcionario::setEndereco(const std::string _endereco) {
  this->endereco = _endereco;
}

int Funcionario::getMatricula() const {
  return this->matricula;
}

Data Funcionario::getNascimento() const {
  return this->nascimento;
}

void Funcionario::setNascimento(const Data _nascimento) {
  this->nascimento = _nascimento;
}

std::string Funcionario::getDepartamento() const {
  return this->departamento;
}

void Funcionario::setDepartamento(const Departamento& _departamento) {
  this->departamento = _departamento;
}

Cargo Funcionario::getCargo() const {
  return this->cargo;
}

void Funcionario::setCargo(const Cargo& _cargo) {
  this->cargo = _cargo;
}

Data Funcionario::getContratacao() const {
  return this->datacontratacao;
}

float Funcionario::getsalario() const {
  return this->salario;
}

void Funcionario::setSalario(const float _salario) {
  this->salario = _salario;
}

Data Funcionario::getDemissao() const {
  std::vector<Alteracao*>::iterator itr;
  for(itr = this->departamentos.begin(); itr != this->departamentos.end(); ++ itr)
}

Status Funcionario::getstatus() const {
  return this->status;
}

void Funcionario::setStatus(const Status &status) {
  this->status = status;
}