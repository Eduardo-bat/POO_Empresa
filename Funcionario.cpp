#include "Funcionario.hpp"

unsigned int Funcionario::qtd = 0;

Funcionario::Funcionario(TipoPessoa _tipo, std::string _cadastro, std::string _nome, std::string _email,
                          std::string _endereco, Data _nascimento, Cargo *cargo, Data dataCriacao, float salario) {
  this->tipo = _tipo;
  this->cadastro = _cadastro;
  this->nome = _nome;
  this->email = _email;
  this->endereco = _endereco;
  this->matricula = (++ Funcionario::qtd);
  this->nascimento = _nascimento;
  this->contratar(dataCriacao, cargo, salario);
  this->status = ativo;
}

void Funcionario::aplicaDissidio(Data data, float novoSalario) {
  this->histAlt.insert({data, Alteracao(novoSalario)});
  this->salario = novoSalario;
}

void Funcionario::promover(unsigned ano, unsigned mes, unsigned dia, Cargo *novoCargo, float novoSalario) {
  if(Usuario::instUsuario()->verificaPermissao(RH, this,
                              static_cast<void (Funcionario::*)(unsigned, unsigned, unsigned, Cargo*, float)> (&Funcionario::promover))) {
    Data data(ano, mes, dia);
    this->histAlt.insert({data, Alteracao(novoCargo, novoSalario)});
    this->cargo = novoCargo;
    this->salario = novoSalario;
  }
}

void Funcionario::promover(Data data, Cargo *novoCargo, float novoSalario) {
  if(Usuario::instUsuario()->verificaPermissao(RH, this,
                              static_cast<void (Funcionario::*)(Data, Cargo*, float)> (&Funcionario::promover))) {
    this->histAlt.insert({data, Alteracao(novoCargo, novoSalario)});
    this->cargo = novoCargo;
    this->salario = novoSalario;
  }
}

void Funcionario::contratar(unsigned ano, unsigned mes, unsigned dia, Cargo *novoCargo, float novoSalario) {
  if(Usuario::instUsuario()->verificaPermissao(RH, this,
                              static_cast<void (Funcionario::*)(unsigned, unsigned, unsigned, Cargo*, float)> (&Funcionario::contratar))) {
    Data data(ano, mes, dia);
    this->histAlt.insert({data, Alteracao(ativo, novoCargo, novoSalario)});
    this->cargo = novoCargo;
    this->salario = novoSalario;
  }
}

void Funcionario::contratar(Data data, Cargo *novoCargo, float novoSalario) {
  if(Usuario::instUsuario()->verificaPermissao(RH, this,
                              static_cast<void (Funcionario::*)(Data, Cargo*, float)> (&Funcionario::contratar))) {
    this->histAlt.insert({data, Alteracao(ativo, novoCargo, novoSalario)});
    this->cargo = novoCargo;
    this->salario = novoSalario;
  }
}

void Funcionario::demitir(unsigned ano, unsigned mes, unsigned dia) {
  if(Usuario::instUsuario()->verificaPermissao(RH, this,
                              static_cast<void (Funcionario::*)(unsigned, unsigned, unsigned)> (&Funcionario::demitir))) {
    Data data(ano, mes, dia);
    this->histAlt.insert({data, Alteracao(desligado)});
    this->status = desligado;
  }
}

void Funcionario::demitir(Data data) {
  if(Usuario::instUsuario()->verificaPermissao(RH, this,
                              static_cast<void (Funcionario::*)(Data)> (&Funcionario::demitir))) {
  this->histAlt.insert({data, Alteracao(desligado)});
  this->status = desligado;
  }
}

std::map<Data, Alteracao> Funcionario::getHistAlt() {
  if(this != nullptr)
    return this->histAlt;
  else {
    std::map<Data, Alteracao> mapErro;
    mapErro.insert({Data(0, 0, 0), Alteracao()});
    return mapErro;
  }
}

std::string Funcionario::getEndereco() const {
  if(this != nullptr)
    return this -> endereco;
  else
    return nullptr;
}

void Funcionario::setEndereco(const std::string _endereco) {
  if(Usuario::instUsuario()->verificaPermissao(RH, this, &Funcionario::setEndereco))
    this->endereco = _endereco;
}

int Funcionario::getMatricula() const {
  if(this != nullptr)
    return this -> matricula;
  else
    return 0;
}

Data Funcionario::getNascimento() const {
  if(this != nullptr)
    return this -> nascimento;
  else
    return Data(0, 0, 0);
}

void Funcionario::setNascimento(const Data _nascimento) {
  if(Usuario::instUsuario()->verificaPermissao(RH, this, &Funcionario::setNascimento))
    this->nascimento = _nascimento;
}

Cargo *Funcionario::getCargo() const {
  if(this != nullptr)
    return this -> cargo;
  else
    return nullptr;
}

float Funcionario::getSalario() const {
  if(this != nullptr)
    return this -> salario;
  else
    return 0;
}

Status Funcionario::getStatus() const {
  if(this != nullptr)
    return this -> status;
  else
    return statusInvalido;
}