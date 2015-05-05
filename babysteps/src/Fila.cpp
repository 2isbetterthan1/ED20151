/* Copyright [2015] <LeoSL>
 * Fila.hpp
 */

#ifndef FILA_HPP
#define FILA_HPP


#include "Carro.cpp"

/**
* Classe Fila.
*
* Fila é uma estrutura de dados que gerencia dados e processos por ordem cronológica seguindo a lógica FIFO (First In, First Out), ou seja, o primeiro a entrar no controle da fila é o primeiro a sair.
*/
class Fila {
 private:
  int end;
  int max;
  Carro dados[];

 public:
/**
* Construtor. Construtor de uma fila.
*/
  Fila() {
    max = 10;
    end = -1;
  }

/**
* Construtor. Construtor de uma fila cujo tamanho é definido através da instanciação de classe.
*/
  Fila(int tam) {
    max = tam;
    end = -1;
  }

/**
* InicializaFila. Inicializa uma fila por meio da variável de controle @end, que indica o final da fila.
*/
  void inicializaFila() {
    end = -1;
  }

/**
* Inclui. Insere elementos no final da fila.
*/
  void inclui(Carro dado) {
    if (filaCheia()) {
      throw "Fila Cheia!";
    }
    end += 1;
    dados[end] = dado;
  }

/**
* Retira. Retira os elementos pela ordem de chegada, ou seja, o primeiro que entrou na fila será o primeiro a sair.
*
* O método também percorre a fila alterando a posição dos elementos para que o lugar vago seja ocupado pelo seu subsequente e assim por diante.
*/
  Carro retira() {
    Carro first = dados[0];
    if (filaVazia()) {
      throw "Fila Vazia!";
    }
    for ( int i = 0 ; i < end ; i++ ) {
      dados[i] = dados[i+1];
    }
    end -= 1;
    return first;
  }

/**
* Ultimo. O método retorna o elemento que está na última posição da fila
*/
  Carro ultimo() {
    if (filaVazia()) {
      throw "Fila Vazia!";
    }
    return dados[end];
  }

/**
* GetUltimo. O método retorna a posição do elemento que está na última posição da fila
*/
  int getUltimo() {
    if (filaVazia()) {
      throw "Fila Vazia!";
    }
    return end;
  }

/**
* FilaCheia. Retorna um valor booleano TRUE caso a variável de controle @end seja igual à capacidade máxima da pilha -1 e FALSE se a variável de controle seja qualquer outro valor.
*/
  bool filaCheia() {
    return end == (max -1);
  }

/**
* FilaVazia. Retorna um valor booleano TRUE caso a variável de controle @end seja igual -1 e FALSE se a variável de controle seja qualquer outro valor.
*/
  bool filaVazia() {
    return end == -1;
  }
};
#endif
