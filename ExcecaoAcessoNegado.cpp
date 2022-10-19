#include "ExcecaoAcessoNegado.hpp"

ExcecaoAcessoNegado::ExcecaoAcessoNegado(Usuario usuario, Data data, std::string entidade, std::string funcionalidade) {
  this -> mensagem = "Acesso de " + usuario.getNome() + " na data " + data.getData() + " à funcionalidae " +
                        funcionalidade + " da entidade " + entidade + " negado.";
}

const char* ExcecaoAcessoNegado::what() const noexcept {
  return this -> mensagem.c_str();
}