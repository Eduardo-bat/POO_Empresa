#include "Departamento.hpp"

Departamento::Departamento(std::string _nome) {
  this->nome = _nome;
}

void Departamento::adicionarFuncionario(Funcionario *f) {
  if(Usuario::instUsuario()->verificaPermissao(RH, this, &Departamento::adicionarFuncionario))
    this->pessoal.push_back(f);
}

bool Departamento::retirarFuncionario(const Funcionario *f) {
  std::vector<Funcionario*>::iterator itr;
  if(Usuario::instUsuario()->verificaPermissao(RH, this, &Departamento::retirarFuncionario))
    for(itr = this->pessoal.begin(); itr != this->pessoal.end(); ++ itr)
      if(*itr == f) {
        this->pessoal.erase(itr);
        return true;
      }
  return false;
}

std::vector<Funcionario*> Departamento::getFuncionarios() {
  return this -> pessoal;
}

std::string Departamento::getNome() const {
	if(this != nullptr)
  	return this->nome;
	else
		return "Departamento invalido (nome)";
}

void Departamento::setNome(std::string _nome){
  if(Usuario::instUsuario()->verificaPermissao(administracao, this, &Departamento::setNome))
    this->nome = _nome;
}