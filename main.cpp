#include <iostream>
#include "Empresa.hpp"
#include "Funcionario.hpp"


int main() {
    Empresa* empresa = Empresa::instEmpresa();
    Departamento dep("departamento");
    empresa->adicionarDepartamento(&dep);
    Cargo cargo("cargo");
    Funcionario* funcionario = empresa->adicionaFuncionario(pFisica, "12345678910", "func", "email", "end", 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000);
    std::cout << funcionario->getCadastro() << std::endl;
    std::cout << ((funcionario->gettHistAlt()).begin())->second.getNovoCargo()->getNome() << std::endl;
    std::cout << ((funcionario->gettHistAlt()).begin())->first.getData() << std::endl;
    if(empresa->adicionaFuncionario(pFisica, "123", "func", "email", "end", 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000) == nullptr)
        std::cout << "verifica 1 funciona\n";
    if(empresa->adicionaFuncionario(pFisica, "1234567891011", "func", "email", "end", 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000) == nullptr)
        std::cout << "verifica 2 funciona\n";
    if(empresa->adicionaFuncionario(pFisica, "12345678910", "func", "email", "end", 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000) == nullptr)
        std::cout << "verifica 3 funciona\n";
}