/* Copyright [2015] <LeoSL>
 * FilaEnc.hpp
 */
#ifndef PILHAENC_HPP
#define PILHAENC_HPP

#include "Elemento.hpp"
#include "ListaEnc.hpp"

template<typename T>

class FilaEnc: public ListaEnc<T> {
 private:
  ListaEnc<T>* lista;

 public:
  FilaEnc<T>(): ListaEnc<T>::ListaEnc() {
    lista = new ListaEnc<T>();
  }

  ~FilaEnc() {
    limparFila();
  }

  void inclui(const T& dado) {
    lista->adiciona(dado);
  }

  T retira() {
    return lista->retiraDoInicio();
  }

  T ultimo() {
    return lista->ultimoElemento();
  }

  T primeiro() {
    return lista->primeiroElemento();
  }

  bool filaVazia() {
    return lista->listaVazia();
  }

  void limparFila() {
    lista->destroiLista();
  }
};
#endif
