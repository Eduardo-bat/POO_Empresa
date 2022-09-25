#ifndef ALTERACAO_H
#define  ALTERACAO_H

#include "Declaracoes.h"
#include "Cargo.hpp"
#include "Funcionario.hpp"

class  Alteracao {
  private:
    TipoAlteracao tipo = tipoAltNA;
    Status novoStatus = tipoStatusNA;
    Cargo novoCargo;
    float novoSalario = 0.1;
    Alteracao(float _novoSalario); //dissidio
    Alteracao(Cargo _novoCargo, float _novoSalario); //promocao
    Alteracao(Status _novoStatus, Cargo _novoCargo, float _novoSalario); //contratacao
    Alteracao(Status _novoStatus); //demissao
    friend Funcionario;
  
  public:
    TipoAlteracao getTipo() const;
    float getNovoSalario() const;
    Cargo getNovoCargo() const;
};

#endif