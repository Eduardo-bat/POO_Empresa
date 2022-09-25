#ifndef PESSOA_H
#define PESSOA_H

#include <string>

enum TipoPessoa { pFisica, pJuridica };

class Pessoa {
  protected:
    TipoPessoa tipo;
    std::string cadastro, nome, email;
    virtual void metodoAbstrato() = 0;
    bool validaCadastro();

  public:
    TipoPessoa getTipo() const;
    std::string getCadastro() const;
    std::string getNome() const;
    std::string getEmail() const;
    void setTipo(TipoPessoa tipo);
    void setCadastro(const std::string cadastro);
    void setNome(const std::string nome);
    void setEmail(const std::string email);
    bool operator=(const Pessoa& other);//Verificar
};

#endif