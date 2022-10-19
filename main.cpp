#include <iostream>
#include "Empresa.hpp"
#include "Funcionario.hpp"
#include "Produto.hpp"
#include "Estoque.hpp"
#include "Usuario.hpp"

int main() {
    int _p;
    std::cout<<"Insira permissão do usuário: ";
    scanf("%d",&_p);
    Usuario* user = Usuario::instUsuario(_p);
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
    empresa->aplicarDissidio(absoluto, 100, 2000, 10, 12);
    std::cout << funcionario->getCargo()->getNome() << std::endl;
    std::cout << (-- (funcionario->gettHistAlt()).end())->second.getNovoCargo()->getNome() << std::endl;
   Estoque* estoque = Estoque::instEstoque();
    Produto* produto = new  Produto("Carro",17750,10,45,13);
    Produto* produto_1 = new  Produto("Computador",1500,6,35,22);
    produto->insereLotes(50);
    produto->insereLotes(65);
    estoque->adicionaProduto(produto);
    estoque->adicionaProduto(produto_1);
    estoque->print();
    produto->insereLotes(65);
    produto->alteraQtd(30);
    estoque->verificaEstoquemin(produto,2022,13,10);
    produto->setValorvenda(1920,2000, 10, 11);
    estoque->print();
    produto->print_hist();
    estoque->removeProduto(produto);
    estoque->print();
    estoque->verificaEstoquemin(produto_1,2022,13,10);
    estoque->print();
    estoque->print_op();
    

}
