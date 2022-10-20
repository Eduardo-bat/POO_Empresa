#include "Pessoa.hpp"

#include <string>

TipoPessoa Pessoa::getTipo() const {
  if(this != nullptr)
    return this -> tipo;
  else
    return tpInvalido;
}

std::string Pessoa::getCadastro() const {
  if(this != nullptr)
    return this -> cadastro;
  else
    return "";
}

std::string Pessoa::getNome() const {
  if(this != nullptr)
    return this -> nome;
  else
    return "";
}

std::string Pessoa::getEmail() const {
  if(this != nullptr)
    return this -> email;
  else
    return "";
}

void Pessoa::setNome(const std::string _nome) {
  if(Usuario::instUsuario()->verificaPermissao(RH, this, Pessoa::setNome))
    this -> nome = _nome;
}

void Pessoa::setEmail(const std::string _email) {
  if(Usuario::instUsuario()->verificaPermissao(RH, this, Pessoa::setNome))
    this -> email = _email;
}