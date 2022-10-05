#include <iostream>
#include "Empresa.hpp"
#include "Funcionario.hpp"


int main() {
    Empresa* empresa = Empresa::instEmpresa();
    Departamento dep("departamento");
    empresa->adicionarDepartamento(&dep);
    Data dataN(2000, 10, 10);
    Cargo cargo("cargo");
    Data dataC(2000, 10, 11);
    Funcionario* funcionario = empresa->adicionaFuncionario(pFisica, "12345678910", "func", "email", "end", dataN, &dep, &cargo, dataC, 10000);
    std::cout << funcionario->getCadastro() << std::endl;
    if(empresa->adicionaFuncionario(pFisica, "123", "func", "email", "end", dataN, &dep, &cargo, dataC, 10000) == nullptr)
        std::cout << "verifica 1 funciona\n";
    if(empresa->adicionaFuncionario(pFisica, "1234567891011", "func", "email", "end", dataN, &dep, &cargo, dataC, 10000) == nullptr)
        std::cout << "verifica 2 funciona\n";
    if(empresa->adicionaFuncionario(pFisica, "12345678910", "func", "email", "end", dataN, &dep, &cargo, dataC, 10000) == nullptr)
        std::cout << "verifica 3 funciona\n";
}