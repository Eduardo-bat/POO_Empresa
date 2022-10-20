#ifndef LogAcNeg_H
#define LogAcNeg_H

#include "Log.hpp"
#include <list>

template <class Entidade, typename Funcionalidade>
class LogAcessoNegado : public Log<Entidade> {
  private:
    Funcionalidade funcionalidade;
    virtual void metodoAbstrato() {}
  public:
    LogAcessoNegado(Usuario *_usuario, Entidade _entidade, Funcionalidade _funcionalidade)
                     : Log<Entidade>(_usuario, _entidade), funcionalidade(_funcionalidade) {};
    Funcionalidade getFuncionalidade();
};

template <class Entidade, typename Funcionalidade>
Funcionalidade LogAcessoNegado<Entidade, Funcionalidade>::getFuncionalidade() {
  return this->funcionalidade;
}

template <class Entidade, typename Funcionalidade>
std::list<LogAcessoNegado<Entidade, Funcionalidade>> listLogAcessoNegado;

#endif