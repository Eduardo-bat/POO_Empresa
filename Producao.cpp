#include "Producao.hpp"

Producao::Producao(Data _data, int quantidade, int Lote, Produto *prod){
 data= _data;
 qtd= quantidade;
 produto= prod;
produto->insereLotes(qtd);
}

/*void Producao::atualizaEstoque(){

  produto->insereLotes(qtd);

}*/