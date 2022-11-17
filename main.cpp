#include <iostream>
#include "Empresa.hpp"
#include "Funcionario.hpp"
#include "Produto.hpp"
#include "Estoque.hpp"
#include "Usuario.hpp"
#include "ExcecaoAcessoNegado.hpp"
#include "RegistroLog.hpp"
#include "Orcamento.hpp"
#include "Pedido.hpp"
#include "Turno.hpp"
#include "MateriaPrima.hpp"
//#include "TesteAlemDoDoc.hpp"

int main() {
  // o que tiver que testar além do que os testes do documento cobra, testar dentro da funcao
  // cada um implementa a propria "TesteAlemDoDoc.hpp" com esta funcao e os testes que quiser dentro
  // assim nao vai misturar com os testes do doc
  //testeAlemDoDocumento();
  Usuario::instUsuario()->reset();
  Estoque *estoque = Estoque::instEstoque();
  Empresa *empresa = Empresa::instEmpresa();
  Usuario *user = Usuario::instUsuario("usuario1", permissaoTeste);
  Usuario *user1 = Usuario::instUsuario();
  std::cout << "se " << user << " == " << user1 << " o singleton funciona." << std::endl;
  Departamento dep("dep");
  empresa->adicionarDepartamento(&dep);
  Cargo cargo("cargo");
  Funcionario *func0 = empresa->adicionaFuncionario(pFisica, "12345678910", "nome0", "email0", {1., 1.}, 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000);
  Funcionario *func1 = empresa->adicionaFuncionario(pFisica, "98765432101", "nome1", "email1", {-1., -1.}, 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000);
  Funcionario *func2 = empresa->adicionaFuncionario(pFisica, "32165498799", "nome2", "email2", {1., -1.}, 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000);
  Cliente *cliente1 = empresa->adicionarCliente("123456789", "cliente0", "12345678901", "emailcliente0", pFisica);
  Cliente *cliente0 = empresa->adicionarCliente("123456789", "cliente1", "01987654321123", "emailcliente1", pJuridica);
  MateriaPrima madeira("madeira", "g", 1000), plastico("plastico", "g", 1000), aluminio("aluminio", "g", 1000), parafuso("parafuso", "unidade", 20);
  Produto mesa("mesa", 10, 0, 10, 20, std::map<MateriaPrima*, unsigned>{{&plastico, 150}, {&aluminio, 100}, {&parafuso, 8}});
	Estoque *estoque = Estoque::instEstoque();
	estoque->adicionaProduto(&mesa);
  //produzir estoque min
  empresa->deletaFuncionario(func0);
  estoque->adicionaProduto(&mesa);
  estoque->emiteOrdem(2022, 11, 17, mesa.getEstoquemin(), &mesa);
  mesa.print();
  empresa->criaOrcamento(cliente0, 2022, 11, 17);
  (*empresa->getOrcamentos().begin())->insereProduto(&mesa, 10);
  mesa.setValorvenda(10.5, 2022, 11, 22);
  empresa->efetuaPedido(*empresa->getOrcamentos().begin(), 2022, 11, 17);
  std::cout << "\n";
  mesa.print();
  std::cout << "\n";
  (*empresa->getOrcamentos().begin())->print();
  
  //cliente deve solicitar etc...
  //cadastrar veiculo etc...
  RegistroLog::instRegLog()->printLogs(); // cada um coloca os logs nos métodos das classes que implementou
}