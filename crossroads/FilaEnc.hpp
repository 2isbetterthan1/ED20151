/* Copyright [2015] <LeoSL>
 * FilaEnc.hpp
 */
#ifndef FilaENC_HPP
#define FilaENC_HPP

#include "Elemento.hpp"
#include "ListaEnc.hpp"

template<typename T>

/**
* Classe FilaEnc. Uma Fila Encadeada é uma estrutura linear.
* A Fila obedece à lógica First In, First Out.
* Herdamos a estrutura lista encadeada.
*/
class FilaEnc: public ListaEnc<T> {
 private:
  ListaEnc<T>* lista;

 public:
/**
* Construtor. Construtor de uma Fila encadeada.
*/
  FilaEnc<T>(): ListaEnc<T>::ListaEnc() {
    lista = new ListaEnc<T>();
  }
/**
* Destruturor. Destruturor de uma Fila encadeada.
*/
  ~FilaEnc() {
    limparFila();
  }
/**
* Função emFila. Adiciona ao final da Fila encadeada através do método adiciona da classe mãe.
*/
  void inclui(const T& dado) {
    lista->adiciona(dado);
  }

  int getSize() {
    lista->getSize();
  }
/**
* Função retira. Retira do início da Fila encadeda um elemento através do método retiraDoInicio da classe mãe.
*/
  T retira() {
    return lista->retiraDoInicio();
  }
/**
* Função ultimo. Retorna o último elemento da Fila encadeada através do método ultimoElemento da classe mãe.
*/
  T ultimo() {
    return lista->ultimoElemento();
  }
/**
* Função primeiro. Retorna o primeiro elemento da Fila encadeada através do método primeiroElemento da classe mãe.
*/
  T primeiro() {
    return lista->primeiroElemento();
  }
/**
* Função FilaVazia. Retorna um valor booleano informando se a Fila encadeada está vazia ou não.
*/
  bool filaVazia() {
    return lista->listaVazia();
  }
/**
* Função limparFila. Executa a limpeza da Fila encadeada através do método destroiLista da classe mãe.
*/
  void limparFila() {
    lista->destroiLista();
  }
};
#endif
