/* Copyright [2015] <LeoSL>
 * Pilha.hpp
 */

template<typename T>

#ifndef PILHA_HPP
#define PILHA_HPP


class Pilha {
 private:
  int top;
  int max;
  int dados[];

 public:
  Pilha() {
    max = 10;
    top = -1;
  }

  Pilha<T> (int t) {
    max = t;
    top = -1;
  }

  int getMax() {
	  return this->max;
  }

  int encontra(int pos) {
    if(PilhaVazia()) {
      throw "a";
    }
    return dados[pos];
  }

  void empilha(T dado) {
    if (PilhaCheia()) {
      throw "Pilha Cheia!";
    }
    top += 1;
    dados[top] = dado;
  }

  T desempilha() {
    if (PilhaVazia()) {
      throw "Pilha Vazia!";
    }
    top -= 1;
    return dados[top+1];
  }

  T topo() {
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
