#ifndef ALTERACAO_H
#define  ALTERACAO_H

#include "Cargo.hpp"

enum TipoAlteracao {admissao, demissao, promocao, dissidio};

class  Alteracao {
  private:
    TipoAlteracao tipo;
    Cargo novoCargo;
    float novoSalario;
  
  public:
    Alteracao(float _novoSalario);
    Alteracao(TipoAlteracao _tipo, Cargo _novoCargo, float _novoSalario);
    TipoAlteracao Alteracao::getTipo() const;
    float Alteracao::getNovoSalario() const;
    Cargo Alteracao::getNovoCargo() const;
};

#endif