#ifndef CLIENTE_H
#define  CLIENTE_H
#include <string>
#include "Pessoa.hpp"
class  Cliente : public Pessoa {
 public:
    
    std::string getTelefone() const;
 
 void setTelefone(const std::string& Telefone);
    
    Cliente(std::string Telefone,
          std::string Nome,
          std::string Cpf_Cnpj,
          std::string Email,
          enum Tipo Tipo);
    
virtual ~Cliente();

private:
    
    std::string Telefone;

};
#endif