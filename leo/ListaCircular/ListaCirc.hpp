/* Copyright [2015] <LeoSL>
 * ListaCirc.hpp
 */
#ifndef LISTACIRC_HPP
#define LISTACIRC_HPP

#include "Elemento.hpp"
#include "ListaEnc.hpp"

class ListaCirc {
 private:
  ListaEnc<T>* lista;
  Elemento<T>* sentinela;

 public:
  ListaCirc() ListaEnc<T>::ListaEnc() {
    sentinela = new Elemento<T>(NULL, NULL);
    ListaEnc<T>::setHead(sentinela);
    int tam = -2;
    ListaEnc<T>::setSize(tam);
  }

  ~ListaCirc() {
    ListaEnc<T>::~ListaEnc();
  }

  void adicionaNoInicio(const T& dado) {
    if (listaVazia()) {
      adiciona();
    }
    ListaEnc<T>::adicionaNoInicio(dado);
    Elemento<T>* primeiro = ListaEnc<T>::primeiroElemento();
    sentinela->setProximo(primeiro);
  }

  void adicionaNaPosicao(const T& dado, int pos) {
    if(listaVazia()) {
      throw 'a';
    }
    if (pos == 0) {
      adicionaNoInicio(dado);
    } else {
      ListaEnc<T>::adicionaNaPosicao(dado, pos);
    }
  }

  void adiciona(const T& dado) {
    Elemento<T>* ultimo = ListaEnc<T>::adiciona(dado);
    ultimo->setProximo(sentinela);
  }

  T retiraDoInicio() {
    ListaEnc<T>::retiraDoInicio();
    sentinela = ListaEnc<T>::getHead();
  }

  void eliminaDoInicio() {
    ListaEnc<T>::eliminaDoInicio();
    sentinela = ListaEnc<T>::getHead();
  }

  int posicao(const T& dado) const {
    ListaEnc<T>::posicao(dado);
  }

  T* posicaoMem(const T& dado) const {
    ListaEnc<T>::posicaoMem(dado);
  }

  bool contem(const T& dado) {
    ListaEnc<T>::contem(dado);
  }

  T retiraDaPosicao(int pos) {
    if (pos == 0) {
      retiraDoInicio();
    } else {
      if (pos == size) {
        retira();
      } else {
        ListaEnc<T>::retiraDaPosicao(pos);
      }
    }
  }

  T retira() {
    ListaEnc<T>::retira();
    Elemento<T>* ultimo = ListaEnc<T>::ultimoElemento();
    ultimo->setProximo(sentinela);
  }

  T retiraEspecifico(const T& dado) {
    Elemento<T>* primeiro = sentinela->getProximo();
    if (primeiro->getInfo() == dado) {
      retiraDoInicio();
    } else {
      ListaEnc<T>::retiraEspecifico(dado);
    }
  }

  T mostra(int pos) {
    ListaEnc<T>::mostra(pos);
  }

  void adicionaEmOrdem(const T& data) {
    ListaEnc<T>::adicionaEmOrdem();
    if (posicao(data) == size + 1) {
      Elemento<T>* ultimo = ultimoElemento();
      ultimo->setProximo(sentinela);
    }
  }

  int verUltimo() {
    ListaEnc<T>::verUltimo();
  }

  bool listaVazia() const {
    return ListaEnc<T>::listaVazia();
  }

  bool igual(T dado1, T dado2) {
    return ListaEnc<T>::igual(dado1, dado2);
  }

  bool maior(T dado1, T dado2) {
    return ListaEnc<T>::maior(dado1, dado2);
  }

  bool menor(T dado1, T dado2) {
    return ListaEnc<T>::menor(dado1, dado2);
  }

  void destroiLista() {
    return ListaEnc<T>::destroiLista();
  }

};
