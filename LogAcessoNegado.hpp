#ifndef LogAcNeg_H
#define LogAcNeg_H

#include "Log.hpp"
#include <list>

enum Permissao { vendedor, funcionarioSimples, RH, logista, administracao };

class LogAcessoNegado : public Log {
  private:
    std::string funcionalidade;
    virtual void metodoAbstrato() {};
  public:
    LogAcessoNegado(Usuario *_usuario, std::string _entidade, std::string _funcionalidade)
                     : Log(_usuario, _entidade), funcionalidade(_funcionalidade) {};
    std::string getFuncionalidade();
    void print() override;
};

#endif