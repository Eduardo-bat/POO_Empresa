#include "Cargo.hpp"

Cargo::Cargo(std::string _nome) {
  this->nome = _nome;
}

void Cargo::setNome(const std::string _nome) {
  this->nome = _nome;
}

std::string Cargo::getNome() const {
  return this->nome;
}