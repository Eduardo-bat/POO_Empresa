#include "ExcecaoAcessoNegado.hpp"

ExcecaoAcessoNegado::ExcecaoAcessoNegado(Usuario *usuario, std::string entidade, std::string funcionalidade) {
  Log::getListLog().push_back(LogAcessoNegado(usuario, entidade, funcionalidade));
}