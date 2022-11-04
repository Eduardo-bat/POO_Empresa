#include <iostream>
#include "Empresa.hpp"
#include "Funcionario.hpp"
#include "Produto.hpp"
#include "Estoque.hpp"
#include "Usuario.hpp"
#include "ExcecaoAcessoNegado.hpp"
#include "Orcamento.hpp"
#include "Pedido.hpp"

int main() {
  Usuario* user = Usuario::instUsuario(administracao);
  Empresa* empresa = Empresa::instEmpresa();
  Departamento dep("departamento");
  empresa->adicionarDepartamento(&dep);
  Cargo cargo("cargo");
  Funcionario* funcionario = empresa->adicionaFuncionario(pFisica, "12345678910", "func", "email", "end", 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000);
  Cliente* cliente = empresa->adicionarCliente("34372373", "Cliente", "123456789", "email", pFisica);
  std::cout << funcionario->getCadastro() << std::endl;
  std::cout << ((funcionario->getHistAlt()).begin())->second.getNovoCargo()->getNome() << std::endl;
  std::cout << ((funcionario->getHistAlt()).begin())->first.getData() << std::endl;
  if(empresa->adicionaFuncionario(pFisica, "123", "func", "email", "end", 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000) == nullptr)
      std::cout << "verifica 1 funciona\n";
  if(empresa->adicionaFuncionario(pFisica, "1234567891011", "func", "email", "end", 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000) == nullptr)
      std::cout << "verifica 2 funciona\n";
  if(empresa->adicionaFuncionario(pFisica, "12345678910", "func", "email", "end", 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000) == nullptr)
      std::cout << "verifica 3 funciona\n";
  empresa->aplicarDissidio(absoluto, 100, 2000, 10, 12);
  std::cout << funcionario->getCargo()->getNome() << std::endl;
  std::cout << (-- (funcionario->getHistAlt()).end())->second.getNovoCargo()->getNome() << std::endl;
  Estoque* estoque = Estoque::instEstoque();
  Produto* produto = new  Produto("Carro",17750,10,45,13);
  Produto* produto_1 = new  Produto("Computador",1500,6,35,22);
  produto->insereLotes(50);
  produto_1->insereLotes(65);
  estoque->adicionaProduto(produto);
  estoque->adicionaProduto(produto_1);
  std::cout << "\n";
  estoque->print();
  std::cout << "\n";
  
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

  Data data(2022, 10, 27);

  Orcamento* orcamento = new Orcamento(cliente, data);
  orcamento->insereProduto(produto, 25);
  orcamento->insereProduto(produto_1, 25);
  orcamento->print();

  Pedido* pedido = new Pedido(orcamento, data);

  //Venda* venda = new Venda(cliente, produto, 25, data);

 estoque->print();
  
}