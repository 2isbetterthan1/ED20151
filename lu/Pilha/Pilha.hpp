/* Copyright [2015] <marcelinol>
*  Pilha.hpp
*/

template<typename T>

/**
* Classe Pilha. Uma pilha é uma lista linear na qual o primeiro elemento a entrar é o último elemento a sair.
* Ela possui apenas uma entrada onde os dados entram e de onde eles saem.
*/
class Pilha {
 private:
  int topoDaPilha;
  int maximoDeElementos;
  T* dados = new T[maximoDeElementos];

 public:
/**
* Construtor. Construtor de uma Pilha
*/
  Pilha() {
    maximoDeElementos = 10;
    limparPilha();
  }

  Pilha<T> (int t) {
	  maximoDeElementos = t;
	  limparPilha();
  }

/**
* Função empilha. Insere um elemento no topo da pilha se ela não estiver cheia.
* @param dado Elemento a ser inserido na pilha.
*/
  void empilha(T dado) {
	if (PilhaCheia()) {
	 throw "Pilha Cheia";
	}
	topoDaPilha += 1;
    dados[topoDaPilha] = dado;
  }

/**
* Função desempilha. Retira um elemento do topo da pilha se ela não estiver vazia.
* @return elemento retirado do topo da pilha
*/
  T desempilha() {
	if (PilhaVazia()) {
	 throw "Pilha Vazia";
	}
	topoDaPilha -= 1;
	return dados[topoDaPilha +1];
  }

/**
* Função topo. Lê o valor que está no topo da pilha se ela não estiver vazia.
* @return valor que está no dopo da pilha.
*/
  T topo() {
    if (PilhaVazia()) {
	 throw "Pilha Vazia";
    }
    return dados[topoDaPilha];
  }

/**
* Função getPosTopo. Vê qual é o índice do topo da pilha.
* @return valor de elementos na pilha - 1.
*/
  int getPosTopo() {
    if (PilhaVazia()) {
     throw "Pilha Vazia";
    }
    return topoDaPilha;
  }

/**
* Função limparPilha. Deixa a pilha vazia.
*/
  void limparPilha() {
	topoDaPilha = -1;
  }

/**
* Função PilhaVazia. Verifica se a pilha está vazia.
* @return verdadeiro se a pilha estiver vazia, falso se não estiver vazia.
*/
  bool PilhaVazia() {
    return topoDaPilha == -1;
  }

/**
* Função PilhaCheia. Verifica se a pilha está cheia.
* @return verdadeiro se a pilha estiver cheia, falso se não estiver cheia.
*/
  bool PilhaCheia() {
    return topoDaPilha == maximoDeElementos -1;
  }
};
