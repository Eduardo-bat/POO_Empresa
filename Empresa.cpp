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
  try {
    if(Usuario::instUsuario()->getPermissao() == RH)
      if(validaCadastro(func, tipo, cadastro)) {
      Data dataNasc(anoNasc, mesNasc, diaNasc);
      Data dataCria(anoCria, mesCria, diaCria);
      Funcionario* funcionario = new Funcionario(tipo, cadastro, nome, email, endereco, dataNasc, cargo, dataCria, salario); //fazer delete
      departamento->adicionarFuncionario(funcionario);
      return funcionario;
    } else {
      std::cout << "CPF invalido" << std::endl;
      return nullptr;
    }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
  return nullptr;
}

Cliente* Empresa::adicionarCliente(std::string telefone, std::string nome, std::string cadastro,
                                    std::string email, enum TipoPessoa tipo) {
  try {
    if(Usuario::instUsuario()->getPermissao() == vendedor)
      if(validaCadastro(func, tipo, cadastro)) {
        Cliente* cliente = new Cliente(telefone, nome, cadastro, email, tipo); //fazer delete
        return cliente;
      } else {
      std::cout << "CPF invalido" << std::endl;
      return nullptr;
      }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
  return nullptr;
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
  try {
    if(Usuario::instUsuario()->getPermissao() == administracao) 
      this->departamentos.push_back(departamento);
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}

bool Empresa::retirarDepartamento(Departamento* departamento) {
  try {
    if(Usuario::instUsuario()->getPermissao() == administracao) {
      std::vector<Departamento*>::iterator itr;
      for(itr = this->departamentos.begin(); itr != this->departamentos.end(); ++ itr)
        if(*itr == departamento) {
          this->departamentos.erase(itr);
          return true;
        }
    }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
  return false;
}

void Empresa::aplicarDissidio(TipoDissidio tipo, float valor, unsigned ano, unsigned mes, unsigned dia) {
  try {
    if(Usuario::instUsuario()->getPermissao() == administracao) {
      Data data(ano, mes, dia);
      std::vector<Departamento*>::iterator itrD;
      std::vector<Funcionario*>::iterator itrF;
      std::vector<Funcionario*> funcionarios;
      for(itrD = this->departamentos.begin(); itrD != this->departamentos.end(); ++ itrD)
        for(funcionarios = (*itrD)->getFuncionarios(),
              itrF = funcionarios.begin(); itrF != funcionarios.end(); ++ itrF)
          if(tipo == percentual)
            (*itrF)->aplicaDissidio(data, (*itrF)->getSalario() + (*itrF)->getSalario() * valor / 100);
          else
            (*itrF)->aplicaDissidio(data, (*itrF)->getSalario() +  valor);
    }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
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

bool Empresa::criaOrcamento(Cliente* cliente, unsigned ano, unsigned mes, unsigned dia) {
  try {
    if(Usuario::instUsuario()->getPermissao() == vendedor) {
      this->orcamentos.push_back(new Orcamento(cliente, Data(ano, mes, dia)));
      return true;
    }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
  return false;
}

bool Empresa::efetuaPedido(Orcamento* orcamento, unsigned ano, unsigned mes, unsigned dia) {
  try {
    if(Usuario::instUsuario()->getPermissao() == vendedor) {
      for(std::map<Produto*, int>::iterator itr = orcamento->carrinho.begin(); itr != orcamento->carrinho.end(); ++ itr)
        if((itr->first)->ChecaQtd() < (itr->second)) return false;
      this->pedidos.push_back(new Pedido(orcamento, Data(ano, mes, dia)));
      return true;
    }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
  return false;
}

void Empresa::deletaFuncionario(Funcionario* funcionario) {
  try {
    if(Usuario::instUsuario()->getPermissao() == RH) {
      this->getDeptFuncionario(funcionario)->retirarFuncionario(funcionario);
      delete funcionario;
    }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}

void Empresa::deletaCliente(Cliente* cliente) {
  try {
    if(Usuario::instUsuario()->getPermissao() == vendedor) {
      std::vector<Cliente*>::iterator itr;
      for(itr = this->clientes.begin(); itr != this->clientes.end(); ++ itr)
        if(*itr == cliente) {
          this->clientes.erase(itr);
          delete cliente;
        }
    }
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
}

Cargo* Empresa::criaCargo(std::string nome) {
  try {
    if(Usuario::instUsuario()->getPermissao() == administracao)
      return new Cargo(nome);
    else
      throw ExcecaoAcessoNegado(Usuario::instUsuario(), typeid(*this).name(), __FUNCTION__);
  }
  catch(ExcecaoAcessoNegado& e) {
    std::cerr << e.what() << '\n';
  }
  return nullptr;
}