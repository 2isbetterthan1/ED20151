/* Copyright [2015] <LeoSL>
 * Pilha.hpp
 */

#ifndef PILHA_HPP
#define PILHA_HPP

#include "Pista.cpp"

template<typename Pista>


class Pilha {
 private:
  int top;
  int max;
  Pista* dados;

 public:

  Pilha<Pista> (int t) {
    max = t;
    top = -1;
    dados = new Pista[max];
  }

  int getMax() {
	  return this->max;
  }

  Pista encontra(int pos) {
    if(PilhaVazia()) {
      throw "a";
    }
    return dados[pos];
  }

  void empilha(Pista dado) {
    if (PilhaCheia()) {
      throw "Pilha Cheia!";
    }
    top += 1;
    dados[top] = dado;
  }

  Pista desempilha() {
    if (PilhaVazia()) {
      throw "Pilha Vazia!";
    }
    top -= 1;
    return dados[top+1];
  }

  Pista topo() {
    if (PilhaVazia()) {
      throw "Pilha Vazia!";
    }
    return dados[top];
  }

  int getPosTopo() {
    if (PilhaVazia()) {
      throw "Pilha Vazia!";
    }
    return top;
  }

  void limparPilha() {
    top = -1;
  }

  bool PilhaVazia() {
    return top == -1;
  }

  bool PilhaCheia() {
    return top == (max - 1);
  }
};
#endif
