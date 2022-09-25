#ifndef ALTERACAO_H
#define  ALTERACAO_H
#include <string>

enum Tipo {
    Promocao=1,
    Desligamento,
    Dissidio
    };

class  Alteracao {
 public:
 
 std::string getNome() const;
 
 void setNome(const std::string& Nome);

Alteracao(std::string Nome);

Tipo getTipo() const;
 
 void setTipo(const Tipo& Tipo);


 private:
Tipo Tipo;
 std::string Nome;

};
#endif