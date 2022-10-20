#ifndef ExcAcNeg_H
#define ExcAcNeg_H

#include <exception>
#include <string>
#include "Empresa.hpp"
#include "Usuario.hpp"
#include "Data.h"
#include "LogAcessoNegado.hpp"

class ExcecaoAcessoNegado : public std::exception {
  private:
    std::string mensagem;
  public:
    template <class Entidade, typename Funcionalidade>
    ExcecaoAcessoNegado(Usuario *usuario, Data data, Entidade entidade, Funcionalidade funcionalidade);
    virtual const char* what() const noexcept override;
};

template <class Entidade, typename Funcionalidade>
ExcecaoAcessoNegado::ExcecaoAcessoNegado(Usuario *usuario, Data data, Entidade entidade, Funcionalidade funcionalidade) {
  LogAcessoNegado<Entidade, Funcionalidade> log(usuario, data, entidade, funcionalidade);
  listLogAcessoNegado<Entidade, Funcionalidade>.pushback(log);
}

#endif