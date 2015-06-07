/* Copyright [2015] <LeoSL>
 * Pilha.hpp
 */

#ifndef PILHA_HPP
#define PILHA_HPP

//ESPECIALIZAR PILHA COMO PILHADEPISTAS
//PilhaDePistas : pulic Pilha<Pista>

template<typename T>

/**
* Classe Pilha. Uma pilha é uma lista linear na qual o primeiro elemento a entrar é o último elemento a sair.
* Ela possui apenas uma entrada onde os dados entram e de onde eles saem.
*/
class Pilha {
 private:
  int top;
  int max;
  T* dados;

 public:

   /**
   * Construtor. Construtor de uma Pilha
   */
  Pilha<T> (int t) {
    max = t;
    top = -1;
    dados = new T[max];
  }

  /**
  * Função getMax. Informa o valor máximo de elementos que a pilha aceita.
  */
  int getMax() {
	  return this->max;
  }
  /**
  * Função encontra. Encontra um elemento na pilha pela sua posição.
  */
  T encontra(int pos) {
    if(PilhaVazia()) {
      throw "a";
    }
    return dados[pos];
  }

  /**
  * Função empilha. Insere um elemento no topo da pilha se ela não estiver cheia.
  * @param dado Elemento a ser inserido na pilha.
  */
  void empilha(T dado) {
    if (PilhaCheia()) {
      throw "Pilha Cheia!";
    }
    top += 1;
    dados[top] = dado;
  }


  /**
  * Função desempilha. Retira um elemento do topo da pilha se ela não estiver vazia.
  * @return elemento retirado do topo da pilha
  */
  T desempilha() {
    if (PilhaVazia()) {
      throw "Pilha Vazia!";
    }
    top -= 1;
    return dados[top+1];
  }

  /**
  * Função topo. Lê o valor que está no topo da pilha se ela não estiver vazia.
  * @return valor que está no dopo da pilha.
  */
  T topo() {
    if (PilhaVazia()) {
      throw "Pilha Vazia!";
    }
    return dados[top];
  }

  /**
  * Função getPosTopo. Vê qual é o índice do topo da pilha.
  * @return valor de elementos na pilha - 1.
  */
  int getPosTopo() {
    if (PilhaVazia()) {
      throw "Pilha Vazia!";
    }
    return top;
  }

  /**
  * Função limparPilha. Deixa a pilha vazia.
  */
  void limparPilha() {
    top = -1;
  }

  /**
  * Função PilhaVazia. Verifica se a pilha está vazia.
  * @return verdadeiro se a pilha estiver vazia, falso se não estiver vazia.
  */
  bool PilhaVazia() {
    return top == -1;
  }

  /**
  * Função PilhaCheia. Verifica se a pilha está cheia.
  * @return verdadeiro se a pilha estiver cheia, falso se não estiver cheia.
  */
  bool PilhaCheia() {
    return top == (max - 1);
  }
};
#endif
