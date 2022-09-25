#ifndef DECLARACOES
#define DECLARACOES

enum TipoPessoa { pFisica, pJuridica };
class Pessoa;
enum TipoAlteracao {admissao, demissao, promocao, dissidio, tipoAltNA};
class Alteracao;
class Cargo;
class Departamento;
enum TipoDissidio { percentual, absoluto };
class Empresa;
class Cliente;
enum Status { ativo, desligado, tipoStatusNA };
class Funcionario;
enum TipoCadastro { func, cliente};
class Data;

#endif