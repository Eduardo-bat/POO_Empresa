#ifndef ExcAcNeg_H
#define ExcAcNeg_H

#include <exception>
#include <string>
#include "Data.h"
#include "LogAcessoNegado.hpp"

enum Permissao { vendedor, funcionarioSimples, RH, logista, administracao };

class ExcecaoAcessoNegado : public std::exception {
  private:
    std::string mensagem = "Acesso negado por permissao incompativel";
  public:
    template <class Entidade, typename Funcionalidade>
    ExcecaoAcessoNegado(Usuario *usuario, Entidade entidade, Funcionalidade funcionalidade);
    virtual const char* what() const noexcept override {
      return this->mensagem.c_str(); 
    }
};

template <class Entidade, typename Funcionalidade>
ExcecaoAcessoNegado::ExcecaoAcessoNegado(Usuario *usuario, Entidade entidade, Funcionalidade funcionalidade) {
  LogAcessoNegado<Entidade, Funcionalidade> log(usuario, entidade, funcionalidade);
  listLogAcessoNegado<Entidade, Funcionalidade>.push_back(log);
}

#endif