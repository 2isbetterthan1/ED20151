/* Copyright [2015] <LeoSL>
 * PilhaEnc.hpp
 */
#ifndef PILHAENC_HPP
#define PILHAENC_HPP

#include "Elemento.hpp"
#include "ListaEnc.hpp"

template<typename T>

/**
* Classe PilhaEnc. Uma Pilha Encadeada é uma estrutura linear.
* A pilha obedece à lógica Last In, First Out.
* Herdamos a estrutura lista encadeada.
*/
class PilhaEnc: public ListaEnc<T> {
 private:
  ListaEnc<T>* lista;

 public:
/**
* Construtor. Construtor de uma pilha encadeada.
*/
  PilhaEnc(): ListaEnc<T>::ListaEnc() {
    lista = new ListaEnc<T>();
  }
/**
* Destruturor. Destruturor de uma pilha encadeada.
*/
  ~PilhaEnc() {
    limparPilha();
  }
/**
* Função PilhaVazia. Retorna um valor booleano informando se a pilha encadeada está vazia ou não.
*/
  bool PilhaVazia() {
    return lista->listaVazia();
  }
/**
* Função empilha. Adiciona ao topo da pilha encadeada através do método adicionaNoInicio da classe mãe.
*/
  void empilha(const T& dado) {
    lista->adicionaNoInicio(dado);
  }
/**
* Função desempilha. Retira do topo da pilha encadeda um elemento através do método retiraDoInicio da classe mãe.
*/
  T desempilha() {
    return lista->retiraDoInicio();
  }
/**
* Função topo. Retorna o primeiro elemeneto da pilha encadeada através do método primeiroElemento da classe mãe.
*/
  T topo() {
    return lista->primeiroElemento();
  }
/**
* Função limparPilha. Executa a limpeza da pilha encadeada através do método destroiLista da classe mãe.
*/
  void limparPilha() {
    lista->destroiLista();
  }
};
#endif
