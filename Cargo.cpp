#include "Cargo.hpp"
#include "ExcecaoAcessoNegado.hpp"

Cargo::Cargo(std::string _nome) {
  this->nome = _nome;
}

void Cargo::setNome(const std::string _nome) {
  try {
    if(Usuario::instUsuario()->getPermissao() == administracao)
      this->nome = _nome;
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}

std::string Cargo::getNome() const {
  if(this != nullptr)
    return this->nome;
  else
    return "Cargo invalido (nome)";
}