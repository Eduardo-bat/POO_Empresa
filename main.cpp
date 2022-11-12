#include <iostream>
#include "Empresa.hpp"
#include "Funcionario.hpp"
#include "Produto.hpp"
#include "Estoque.hpp"
#include "Usuario.hpp"
#include "ExcecaoAcessoNegado.hpp"
#include "Orcamento.hpp"
#include "Pedido.hpp"
#include "Turno.hpp"
#include "MateriaPrima.hpp"

int main() {
  Usuario *user = Usuario::instUsuario(administracao);
  Empresa *empresa = Empresa::instEmpresa();
  Departamento dep("departamento");
  empresa->adicionarDepartamento(&dep);
  Cargo cargo("cargo");
  Funcionario *funcionario = empresa->adicionaFuncionario(pFisica, "12345678910", "func", "email", "end", 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000);
  Cliente *cliente = empresa->adicionarCliente("34372373", "Cliente", "123456789", "email", pFisica);
  std::cout << funcionario->getCadastro() << std::endl;
  std::cout << ((funcionario->getHistAlt()).begin())->second.getNovoCargo()->getNome() << std::endl;
  std::cout << ((funcionario->getHistAlt()).begin())->first.getData() << std::endl;
  if (empresa->adicionaFuncionario(pFisica, "123", "func", "email", "end", 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000) == nullptr)
    std::cout << "verifica 1 funciona\n";
  if (empresa->adicionaFuncionario(pFisica, "1234567891011", "func", "email", "end", 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000) == nullptr)
    std::cout << "verifica 2 funciona\n";
  if (empresa->adicionaFuncionario(pFisica, "12345678910", "func", "email", "end", 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000) == nullptr)
    std::cout << "verifica 3 funciona\n";
  empresa->aplicarDissidio(absoluto, 100, 2000, 10, 12);
  std::cout << funcionario->getCargo()->getNome() << std::endl;
  std::cout << (--(funcionario->getHistAlt()).end())->second.getNovoCargo()->getNome() << std::endl;
  Estoque *estoque = Estoque::instEstoque();
  MateriaPrima *ferro = new MateriaPrima("kg", 45);
  MateriaPrima *silicio = new MateriaPrima("kg", 15);
  MateriaPrima *plastico = new MateriaPrima("kg", 100);
  MateriaPrima *C_I = new MateriaPrima("Unidades", 1000);
  std::map<MateriaPrima *, unsigned> materiaprima;
  materiaprima.emplace(ferro, 35);
  materiaprima.emplace(silicio, 8);
  materiaprima.emplace(plastico, 50);
  materiaprima.emplace(C_I, 500);
  Produto *produto = new Produto("Carro", 17750, 10, 45, 13, &materiaprima);
  produto->insereLotes(50);
  estoque->adicionaProduto(produto);
  std::cout << "\n";
  estoque->print();
  std::cout << "\n";

  produto->insereLotes(65);
  produto->alteraQtd(30);
  estoque->verificaEstoquemin(produto, 2022, 13, 10);
  produto->setValorvenda(1920, 2000, 10, 11);
  estoque->print();
  produto->print_hist();
  estoque->removeProduto(produto);
  estoque->print();
  estoque->print();
  estoque->print_op();

  Data data(2022, 10, 27);

  Orcamento *orcamento = new Orcamento(cliente, data);
  orcamento->insereProduto(produto, 25);
  orcamento->print();

  Pedido *pedido = new Pedido(orcamento, data);
  MateriaPrima mp("kg", 5);
  Fornecedor fornecedor;
  mp.inserirFornecedor(&fornecedor);
  mp.emiteOrcamentoCompra(10);
  // OrcamentoCompra* oc = mp.getOrcamentos().begin().first;
  // fornecedor.calculaOrcamento(oc, 1000.0);
  // std::cout << (mp.finalizaCompra(oc))->respostaOrcamento(oc);
  estoque->print();
}