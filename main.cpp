#include <iostream>
#include "Empresa.hpp"
#include "Funcionario.hpp"
#include "Produto.hpp"
#include "Estoque.hpp"

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
    produto->alteraQtd(60);
    produto->setValorvenda(1920,2000, 10, 11);
    estoque->print();
    produto->print_hist();
    estoque->removeProduto(produto);
    estoque->print();

  Produto* cerveja=new Produto("Cerveja",4.50,1, 100, 200);
  cerveja->print();
  OrdemDeProd ordem=OrdemDeProd(2020, 10, 13); 
  ordem.produz(20, 0, cerveja);
  cerveja->print();
  estoque->adicionaProduto(cerveja);
  estoque->print();
  

}
