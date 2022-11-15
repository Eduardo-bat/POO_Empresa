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
#include "TesteAlemDoDoc.hpp"

int main() {
  // o que tiver que testar além do que os testes do documento cobra, testar dentro da funcao
  // cada um implementa a propria "TesteAlemDoDoc.hpp" com esta funcao e os testes que quiser dentro
  // assim nao vai misturar com os testes do doc
  testeAlemDoDocumento();
  Empresa *empresa = Empresa::instEmpresa();
  Usuario *user = Usuario::instUsuario(permissaoTeste);
  Usuario *user1 = Usuario::instUsuario(permissaoTeste);
  std::cout << "se " << user << " == " << user1 << " o singleton funciona." << std::endl;
  Departamento dep("departamento");
  empresa->adicionarDepartamento(&dep);
  Cargo cargo("cargo");
  Funcionario *func0 = empresa->adicionaFuncionario(pFisica, "12345678910", "nome0", "email0", {1, 1}, 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000);
  Funcionario *func1 = empresa->adicionaFuncionario(pFisica, "98765432101", "nome1", "email1", {-1, -1}, 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000);
  Funcionario *func2 = empresa->adicionaFuncionario(pFisica, "32165498799", "nome2", "email2", {1, -1}, 2000, 10, 10, &dep, &cargo, 2000, 10, 11, 10000);
  Cliente *cliente1 = empresa->adicionarCliente("123456789", "cliente0", "12345678901", "emailcliente0", pFisica);
  Cliente *cliente0 = empresa->adicionarCliente("123456789", "cliente1", "01987654321123", "emailcliente1", pJuridica);
  MateriaPrima madeira("g", 1000), plastico("g", 1000), aluminio("g", 1000), parafuso("unidade", 20);
  Produto mesa("mesa", 10, 0, 10, 20, std::map<MateriaPrima*, unsigned>{{&plastico, 150}, {&aluminio, 100}, {&parafuso, 8}});
  //produzir estoque min
  empresa->deletaFuncionario(func0);
  //cliente deve solicitar etc...
  //cadastrar veiculo etc...
  RegistroLog *regLog = RegistroLog::instRegLog();
  regLog->printLogs(); // cada um coloca os logs nas classses que implementou
}