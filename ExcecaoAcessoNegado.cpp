#include "ExcecaoAcessoNegado.hpp"
#include "RegistroLog.hpp"

ExcecaoAcessoNegado::ExcecaoAcessoNegado(Usuario *usuario, std::string entidade, std::string funcionalidade) {
  RegistroLog::instRegLog()->vecLogAcNeg.push_back(LogAcessoNegado(usuario, entidade, funcionalidade));
}