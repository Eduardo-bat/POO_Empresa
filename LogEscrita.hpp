#ifndef LOGESCRITA_H
#define LOGESCRITA_H

#include "Log.hpp"
#include <list>

template <class Entidade, typename AtrtibutoAntes, typename AtributoDepois>
class LogEscrita : public Log<Entidade> {

    private:
        AtributoAntes atributo;
        AtributoDepois atributo;
        virtual void metodoAbstrato() {}
    
    public:
        LogEscrita(Usuario *_usuario, Entidade _entidade, Data _data, AtributoAntes _atributo, AtributoDepois _atributo)
                     : Log<Entidade>(_usuario, _entidade, _data), AtributoAntes(_atributo), AtributoDepois(_atributo) {};


        AtrtibutoAntes getAtributo();
        AtributoDepois getAtributo();
    };

template <class Entidade, typename AtrtibutoAntes, typename AtributoDepois>
AtrtibutoAntes LogEscrita<Entidade, AtrtibutoAntes, AtributoDepois>::getAtributo() {
    return this->atributo;
}

template <class Entidade, typename AtrtibutoAntes, typename AtributoDepois>
std::list<LogEscrita<Entidade, AtrtibutoAntes, AtributoDepois>> listLogEscrita;

#endif