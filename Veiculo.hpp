#pragma once
#include "Data.h"
#include "Funcionario.hpp"
#include "Empresa.hpp"
#include "Turno.hpp"
#include <string>
#include <map>

class Veiculo {

private:
std::map<Funcionario*,Data> rota;
int capacidade;
Turno turno;
public:
Veiculo(int _capacidade, Turno _t);
void adicionafuncionario(Funcionario* funcionario);
void removefuncionario(Funcionario* funcionario);
float calculaDistancia (float x1, float y1, float x2, float y2);
void print_rota();
void setCapacidade(int _c);
void setTurno(Turno _t);
int getCapacidade();
std::string getTurno();


};
