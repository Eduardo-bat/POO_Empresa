#ifndef ExcAcNeg_H
#define ExcAcNeg_H

#include <exception>
#include <string>
#include "Usuario.hpp"
#include "Data.h"

class ExcecaoAcessoNegado : public std::exception {
  private:
    std::string mensagem;
  public:
    ExcecaoAcessoNegado(Usuario usuario, Data data, std::string entidade, std::string funcionalidade);
    virtual const char* what() const noexcept override;
};


#endif