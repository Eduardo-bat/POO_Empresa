#include "Cliente.hpp"

Cliente::Cliente(std::string _cadastro, std::string _nome, std::string _email,  
                  std::string _telefone, enum TipoPessoa _tipo) {                    
  this->cadastro = _cadastro;
  this->telefone = _telefone;
  this->nome = _nome;
  this->email = _email;
  this->tipo = _tipo;
}

std::string Cliente::getTelefone() {
  if(this != nullptr)
    return this -> telefone;
  else
    return "";
}
 
void Cliente::setTelefone(const std::string _telefone){
  if(Usuario::instUsuario()->verificaPermissao(vendedor, this, Cliente::setTelefone))
    this->telefone = _telefone;
}