#ifndef LOGESCRITA_H
#define LOGESCRITA_H

#include "Log.hpp"
#include <list>

class LogEscrita : public Log {

  private:
    std::string atributoAntes;
    std::string atributoDepois;
    virtual void metodoAbstrato() {};
  
  public:
    LogEscrita(Usuario *_usuario, std::string _entidade, Data _data, 
                  std::string _atributoAntes, std::string _atributoDepois)
                    : Log(_usuario, _entidade), atributoAntes(_atributoAntes), atributoDepois(_atributoDepois) {};
    std::string getAtributoAntes();
    std::string getAtributoDepois();
    void print() override;
  };

#endif