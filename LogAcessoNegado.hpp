#ifndef LogAcNeg_H
#define LogAcNeg_H

#include "Log.hpp"
#include <list>

template <class Entidade, typename Funcionalidade>
class LogAcessoNegado : public Log<Entidade> {
  private:
    Funcionalidade funcionalidade;
  public:
    LogAcessoNegado(Usuario *_usuario, Data _data, Entidade _entidade, Funcionalidade _funcionalidade)
                     : Log<Entidade>(_usuario, _data, _entidade), funcionalidade(_funcionalidade) {};
    Funcionalidade getFuncionalidade();
};

template <class Entidade, typename Funcionalidade>
Funcionalidade LogAcessoNegado<Entidade, Funcionalidade>::getFuncionalidade() {
  return this->funcionalidade;
}

template <class Entidade, typename Funcionalidade>
std::list<LogAcessoNegado<Entidade, Funcionalidade>> listLogAcessoNegado;

#endif