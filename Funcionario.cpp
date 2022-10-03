#include "Funcionario.hpp"

unsigned int Funcionario::qtd = 0;

Funcionario::Funcionario(TipoPessoa _tipo, std::string _cadastro, std::string _nome, std::string _email,
                          std::string _endereco, Data _nascimento, Cargo _cargo, Data _dataCriacao, float _salario) {
  this->tipo = _tipo;
  this->cadastro = _cadastro;
  this->nome = _nome;
  this->email = _email;
  this->endereco = _endereco;
  this->matricula = Funcionario::qtd;
  this->nascimento = _nascimento;
  this->cargo = _cargo;
  this->dataCriacao = _dataCriacao;
  this->salario = _salario;
  this->status = ativo;
  Funcionario::qtd++;
}

void Funcionario::aplicaDissidio(Data _data, float _novoSalario) {
  this->histAlt.insert({_data, Alteracao(_novoSalario)});
  this->salario = _novoSalario;
}

void Funcionario::promover(Data _data, Cargo _novoCargo, float _novoSalario) {
  this->histAlt.insert({_data, Alteracao(_novoCargo, _novoSalario)});
  this->cargo = _novoCargo;
  this->salario = _novoSalario;
}

void Funcionario::contratar(Data _data, Cargo _novoCargo, float _novoSalario) {
  this->histAlt.insert({_data, Alteracao(ativo, _novoCargo, _novoSalario)});
  this->cargo = _novoCargo;
  this->salario = _novoSalario;
}

void Funcionario::demitir(Data _data) {
  this->histAlt.insert({_data, Alteracao(desligado)});
  this->status = desligado;
}

std::map<Data, Alteracao> Funcionario::gettHistAlt() {
  return this->histAlt;
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

Cargo Funcionario::getCargo() const {
  return this->cargo;
}

float Funcionario::getSalario() const {
  return this->salario;
}

Status Funcionario::getStatus() const {
  return this->status;
}