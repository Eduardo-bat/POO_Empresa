#include "Empresa.hpp"
#include <regex>

Empresa *Empresa::instptrEmpresa = 0;

Empresa *Empresa::instEmpresa() {
  if(instptrEmpresa == 0)
    instptrEmpresa = new Empresa;
  return instptrEmpresa;
}

Funcionario* Empresa::adicionaFuncionario(TipoPessoa tipo, std::string cadastro, std::string nome,
                          std::string email, std::string endereco, unsigned anoNasc, unsigned mesNasc, unsigned diaNasc,
                            Departamento* departamento, Cargo *cargo, unsigned anoCria, unsigned mesCria, unsigned diaCria, float salario) {
  if(validaCadastro(func, tipo, cadastro)
      and Usuario::instUsuario()->verificaPermissao(RH, this, &Empresa::adicionaFuncionario)) {
    Data dataNasc(anoNasc, mesNasc, diaNasc);
    Data dataCria(anoCria, mesCria, diaCria);
    Funcionario* funcionario = new Funcionario(tipo, cadastro, nome, email, endereco, dataNasc, cargo, dataCria, salario); //fazer delete
    departamento->adicionarFuncionario(funcionario);
    return funcionario;
  } else {
    return nullptr;
  }
}

Cliente* Empresa::adicionarCliente(std::string telefone, std::string nome, std::string cadastro,
                                    std::string email, enum TipoPessoa tipo) {
  if(validaCadastro(cliente, tipo, cadastro)
      and Usuario::instUsuario()->verificaPermissao(vendedor, this, &Empresa::adicionarCliente)) {
    Cliente* cliente = new Cliente(telefone, nome, cadastro, email, tipo); //fazer delete
    return cliente;
  } else {
    return nullptr;
  }          
}

bool Empresa::validaCadastro(TipoCadastro tipoC, TipoPessoa tipoP, std::string cadastro) {
  std::regex regularExpr(tipoP == pFisica ? "[0-9]{3}[0-9]{3}[0-9]{3}[0-9]{2}" :
                                              "[0-9]{2}[0-9]{3}[0-9]{3}[0-9]{4}[0-9]{2}");
  if(!std::regex_match(cadastro, regularExpr)) return false;
  if(tipoC == func) {
    std::vector<Departamento*>::iterator itrD;
    std::vector<Funcionario*>::iterator itrF;
    std::vector<Funcionario*> funcionarios;
    for(itrD = this->departamentos.begin(); itrD != this->departamentos.end(); ++ itrD)
      for(funcionarios = (*itrD)->getFuncionarios(),
            itrF = funcionarios.begin(); itrF != funcionarios.end(); ++ itrF)
        if((*itrF)->getCadastro() == cadastro)
          return false;
  } else {
    std::vector<Cliente*>::iterator itr;
    for(itr = this->clientes.begin(); itr != this->clientes.end(); ++ itr)
      if((*itr)->getCadastro() == cadastro)
        return false;
  }
  return true;
}

void Empresa::adicionarDepartamento(Departamento* departamento) {
  if(Usuario::instUsuario()->verificaPermissao(administracao, this, &Empresa::adicionarDepartamento))
    this->departamentos.push_back(departamento);
}

bool Empresa::retirarDepartamento(Departamento* departamento) {
  std::vector<Departamento*>::iterator itr;
  if(Usuario::instUsuario()->verificaPermissao(administracao, this, &Empresa::retirarDepartamento))
    for(itr = this->departamentos.begin(); itr != this->departamentos.end(); ++ itr)
      if(*itr == departamento) {
        this->departamentos.erase(itr);
        return true;
      }
  return false;
}

void Empresa::aplicarDissidio(TipoDissidio tipo, float valor, unsigned ano, unsigned mes, unsigned dia) {
  Data data(ano, mes, dia);
  std::vector<Departamento*>::iterator itrD;
  std::vector<Funcionario*>::iterator itrF;
  std::vector<Funcionario*> funcionarios;
  if(Usuario::instUsuario()->verificaPermissao(administracao, this, &Empresa::aplicarDissidio)) {
    for(itrD = this->departamentos.begin(); itrD != this->departamentos.end(); ++ itrD)
      for(funcionarios = (*itrD)->getFuncionarios(),
            itrF = funcionarios.begin(); itrF != funcionarios.end(); ++ itrF)
        if(tipo == percentual)
          (*itrF)->aplicaDissidio(data, (*itrF)->getSalario() + (*itrF)->getSalario() * valor / 100);
        else
          (*itrF)->aplicaDissidio(data, (*itrF)->getSalario() +  valor);
  }
}

Departamento* Empresa::getDeptFuncionario(Funcionario* funcionario) {
  std::vector<Departamento*>::iterator itrD;
  std::vector<Funcionario*>::iterator itrF;
  for(itrD = this->departamentos.begin(); itrD != this->departamentos.end(); ++ itrD) {
    std::vector<Funcionario*> funcionarios = (*itrD)->getFuncionarios();
    for(funcionarios = (*itrD)->getFuncionarios(),
					itrF = funcionarios.begin(); itrF != funcionarios.end(); ++ itrF)
      if((*itrF) == funcionario)
        return (*itrD);
  }
  return nullptr;
}

bool Empresa::vende(Cliente *cliente, Produto *produto, int qtd, unsigned ano, unsigned mes, unsigned dia) {
  if(produto->ChecaQtd() >= qtd
      and Usuario::instUsuario()->verificaPermissao(vendedor, this, &Empresa::vende)) {
    Data data(ano, mes, dia);
    Venda venda(cliente, produto, qtd, data);
    this->vendas.push_back(venda);
    return true;
  } else return false;
}

void Empresa::deletaFuncionario(Funcionario* funcionario) {
  if(Usuario::instUsuario()->verificaPermissao(administracao, this, &Empresa::deletaFuncionario)) {
    this->getDeptFuncionario(funcionario)->retirarFuncionario(funcionario);
    delete funcionario;
  }
}

void Empresa::deletaCliente(Cliente* cliente) {
  std::vector<Cliente*>::iterator itr;
  if(Usuario::instUsuario()->verificaPermissao(administracao, this, &Empresa::deletaFuncionario))
    for(itr = this->clientes.begin(); itr != this->clientes.end(); ++ itr)
      if(*itr == cliente) {
        this->clientes.erase(itr);
        delete cliente;
      }
}

Cargo* Empresa::criaCargo(std::string nome) {
  if(Usuario::instUsuario()->verificaPermissao(administracao, this, &Empresa::criaCargo)) {
    Cargo *cargo = new Cargo(nome);
    return cargo;
  } else return nullptr;
}