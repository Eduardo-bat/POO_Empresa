#include "Alteracao.hpp"

  Alteracao::Alteracao(float _novoSalario) {
    this->tipo = dissidio;
    this->novoSalario = _novoSalario;
    Cargo cargo;
    this->novoCargo = cargo;
  }

  Alteracao::Alteracao(Cargo _novoCargo, float _novoSalario) {
    this->tipo = promocao;
    this->novoCargo = _novoCargo;
    this->novoSalario = _novoSalario;
  }

  Alteracao::Alteracao(Status _novoStatus, Cargo _novoCargo, float _novoSalario) {
    this->tipo = admissao;
    this->novoStatus = _novoStatus;
    this->novoCargo = _novoCargo;
    this->novoSalario = _novoSalario;
  }

  Alteracao::Alteracao(Status _novoStatus) {
    this->tipo = demissao;
    this->novoStatus = _novoStatus;
    Cargo cargo;
    this->novoCargo = cargo;
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