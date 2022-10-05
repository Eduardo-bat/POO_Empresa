#include "Funcionario.hpp"

unsigned int Funcionario::qtd = 0;

Funcionario::Funcionario(TipoPessoa _tipo, std::string _cadastro, std::string _nome, std::string _email,
                          std::string _endereco, Data _nascimento, Cargo *cargo, Data dataCriacao, float salario) {
  this->tipo = _tipo;
  this->cadastro = _cadastro;
  this->nome = _nome;
  this->email = _email;
  this->endereco = _endereco;
  this->matricula = Funcionario::qtd;
  this->nascimento = _nascimento;
  this->contratar(dataCriacao, cargo, salario);
  this->status = ativo;
  Funcionario::qtd++;
}

void Funcionario::aplicaDissidio(Data data, float novoSalario) {
  this->histAlt.insert({data, Alteracao(novoSalario)});
  this->salario = novoSalario;
}

void Funcionario::promover(unsigned ano, unsigned mes, unsigned dia, Cargo *novoCargo, float novoSalario) {
  Data data(ano, mes, dia);
  this->histAlt.insert({data, Alteracao(novoCargo, novoSalario)});
  this->cargo = novoCargo;
  this->salario = novoSalario;
}

void Funcionario::promover(Data data, Cargo *novoCargo, float novoSalario) {
  this->histAlt.insert({data, Alteracao(novoCargo, novoSalario)});
  this->cargo = novoCargo;
  this->salario = novoSalario;
}

void Funcionario::contratar(unsigned ano, unsigned mes, unsigned dia, Cargo *novoCargo, float novoSalario) {
  Data data(ano, mes, dia);
  this->histAlt.insert({data, Alteracao(ativo, novoCargo, novoSalario)});
  this->cargo = novoCargo;
  this->salario = novoSalario;
}

void Funcionario::contratar(Data data, Cargo *novoCargo, float novoSalario) {
  this->histAlt.insert({data, Alteracao(ativo, novoCargo, novoSalario)});
  this->cargo = novoCargo;
  this->salario = novoSalario;
}

void Funcionario::demitir(unsigned ano, unsigned mes, unsigned dia) {
  Data data(ano, mes, dia);
  this->histAlt.insert({data, Alteracao(desligado)});
  this->status = desligado;
}

void Funcionario::demitir(Data data) {
  this->histAlt.insert({data, Alteracao(desligado)});
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

Cargo *Funcionario::getCargo() const {
  return this->cargo;
}

float Funcionario::getSalario() const {
  return this->salario;
}

Status Funcionario::getStatus() const {
  return this->status;
}