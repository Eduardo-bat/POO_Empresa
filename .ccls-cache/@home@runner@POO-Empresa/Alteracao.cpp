#include "Alteracao.hpp"
#include "Cargo.hpp"

Alteracao::Alteracao(float _novoSalario) {
  this->novoSalario = _novoSalario;
  this->tipo = dissidio;
}

Alteracao::Alteracao(TipoAlteracao _tipo, Cargo _novoCargo, float _novoSalario) {
  this->tipo = _tipo;
  this->novoCargo = _novoCargo;
  this->novoSalario = _novoSalario;
}

TipoAlteracao Alteracao::getTipo() const {
  return tipo;
}

float Alteracao::getNovoSalario() const {
  return novoSalario;
}

Cargo Alteracao::getNovoCargo() const {
  return novoCargo;
}