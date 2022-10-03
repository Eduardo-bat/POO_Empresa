#ifndef CARGO_H
#define CARGO_H

#include <string>

class Cargo {
  private:
    std::string nome;
   
  public:
    Cargo(std::string _nome = "cargoNA");
    std::string getNome() const;
    void setNome(const std::string _nome);

};
#endif