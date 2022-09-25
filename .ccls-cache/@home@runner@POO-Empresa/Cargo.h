#ifndef CARGO_H
#define CARGO_H
#include <string>

class Cargo {
 public:

Cargo(std::string Nome);
Cargo();

std::string getNome() const;
 
 void setNome(const std::string& Nome);


 private:

 std::string Nome;

};
#endif