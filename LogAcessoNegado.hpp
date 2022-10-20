#ifndef LogAcNeg_H
#define LogAcNeg_H

#include "Log.hpp"
#include <list>

template <class Entidade, typename Funcionalidade>
class LogAcessoNegado : public Log<Entidade> {
  private:
    Funcionalidade funcionalidade;
  public:
    template <class TEntidade, typename TFuncionalidade>
    LogAcessoNegado(Usuario *_usuario, Data _data, Entidade _entidade, Funcionalidade _funcionalidade)
                     : usuario(_usuario), data(_data), entidade(_entidade), funcionalidade(_funcionalidade);
    Funcionalidade getFuncionalidade();
};

template <class TEntidade, typename TFuncionalidade>
TFuncionalidade LogAcessoNegado<TEntidade, TFuncionalidade>::getFuncionalidade() {
  return this->funcionalidade;
}

template <class TEntidadeL, typename TFuncionalidadeL>
std::list<LogAcessoNegado<TEntidadeL, TFuncionalidadeL>> listLogAcessoNegado;

#endif