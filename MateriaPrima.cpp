#include "MateriaPrima.hpp"

bool MateriaPrima::inserirFornecedor(Fornecedor* fornecedor) {
  if(std::find(this->fornecedores.begin(), this->fornecedores.end(), fornecedor) == this->fornecedores.end())
    return false;
  else
    this->fornecedores.push_back(fornecedor);
  return true;
}

void MateriaPrima::emiteOrcamentoCompra(unsigned qtd) {
  std::vector<Fornecedor*>::iterator itrF;
  OrcamentoCompra* orcamento = new OrcamentoCompra(qtd);
  std::map<Fornecedor*, bool> fornecedoresOrcamento;
  for(itrF = this->fornecedores.begin(); itrF != this->fornecedores.end(); ++ itrF) {
    (*itrF)->adicionaOrcamento(orcamento);
    fornecedoresOrcamento.insert({*itrF, false});
  }
  this->orcamentos.insert({orcamento, fornecedoresOrcamento});
}

std::map<OrcamentoCompra*, std::map<Fornecedor*, bool>> MateriaPrima::getOrcamentos() {
  return this->orcamentos;
}

Fornecedor* MateriaPrima::finalizaCompra(OrcamentoCompra* orcamento) {
  if((orcamento->getQtdRespostas() < 1) or orcamento->foiFinalizado()) return nullptr;
  std::map<Fornecedor*, bool> respostasOrcamento = this->orcamentos.at(orcamento);
  std::map<Fornecedor*, bool>::iterator itr;
  Fornecedor* fornecedor;
  float min = std::numeric_limits<float>::max();
  for(itr = respostasOrcamento.begin(); itr != respostasOrcamento.end(); ++ itr)
    if(float resposta = (itr->first)->respostaOrcamento(orcamento); resposta > 0 and resposta < min) {
      fornecedor = itr->first;
      min = resposta;
    }
  respostasOrcamento.at(fornecedor) = true;
  this->alteraQtd(orcamento->getQtdMaterial());
  return fornecedor;
}

void MateriaPrima::alteraQtd(int qtd) {
  this->estoqueAtual += qtd;
}

unsigned MateriaPrima::getQtd() {
  return this->estoqueAtual;
}