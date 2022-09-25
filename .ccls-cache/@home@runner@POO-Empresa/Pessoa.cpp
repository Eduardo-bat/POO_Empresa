#include "Pessoa.hpp"
#include <string>

    TipoPessoa Pessoa::getTipo() const { return this-> tipo; }
    std::string Pessoa::getCadastro() const { return this-> cadastro; }
    std::string Pessoa::getNome() const { return this-> nome; }
    std::string Pessoa::getEmail() const { return this-> email; }
    void Pessoa::setTipo(TipoPessoa _tipo) { this-> tipo = _tipo; }
    void Pessoa::setCadastro(const std::string _cadastro) { this-> cadastro = _cadastro; }
    void Pessoa::setNome(const std::string _nome) { this-> nome = _nome; }
    void Pessoa::setEmail(const std::string _email) { this-> email = _email; }
    bool Pessoa::operator=(const Pessoa &other) {
      if (this->cadastro == other.getCadastro()) {
        return true;
          } else {
          return false;
            }
                }