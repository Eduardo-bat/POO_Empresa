#include "Cargo.hpp"

Cargo::Cargo(std::string _nome) {
  this->nome = _nome;
}

void Cargo::setNome(const std::string _nome) {
  if(Usuario::instUsuario()->verificaPermissao(administracao, this, Cargo::setNome))
    this->nome = _nome;
}

std::string Cargo::getNome() const {
  if(this != nullptr)
    return this->nome;
  else
    return "Cargo invalido (nome)";
}