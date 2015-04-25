/* Copyright [2015] <LeoSL>
 * ListaEnc.hpp
 */
#include "Elemento.hpp"

template<typename T>

/**
* Classe ListaEnc. Uma Lista Encadeada é uma lista onde cada elemento está armazenado em um objeto chamado elemento de lista.
*/
class ListaEnc {
 private:
  Elemento<T>* head;
  int size;

 public:
/**
* Construtor. Construtor de uma Lista Encadeada.
*/
  ListaEnc<T>() {
    criaLista();
  }
/**
* Destrutor. Destrutor de uma Lista Encadeda.
*/
  ~ListaEnc() {
    destroiLista();
  }
/**
* Função criaLista. Serve para fazer a configuração inicial de uma lista encadeada.
*/
  void criaLista() {
    head = NULL;
    size = -1;
  }

  void setHead(Elemento<T>* cab) {
    this->head = cab;
  }

  void getHead(Elemento<T>* cab) {
    return this->head;
  }

  void setSize(int tam) {
    this->size = tam;
  }
/**
* Função listaVazia. Retorna um valor booleano informando se a lista encadeada está vazia ou não.
*/
  bool listaVazia() const {
    if (size == -1) {
      return true;
    } else {
      return false;
    }
  }
/**
* Função adicionaNoInicio. Adiciona elementos no início de uma lista encadeada.
*/
  void adicionaNoInicio(const T& dado) {
    Elemento<T>* elemento = new Elemento<T>(dado, head);
    if (elemento != NULL) {
     head = elemento;
     size++;
    } else {
     throw 'a';
    }
  }
/**
* Função retiraDoInicio. Retira e retorna elemento do início de uma lista encadeada.
*/
  T retiraDoInicio() {
    if (listaVazia()) {
      throw 'a';
    }
    Elemento<T>* antigoPrimeiro = head;
    head = antigoPrimeiro->getProximo();
    T data = antigoPrimeiro->getInfo();
    antigoPrimeiro->~Elemento();
    size--;
    return data;
  }
/**
* Função primeiroElemento. Retorna elemento do início de uma lista encadeada.
*/
  T primeiroElemento() {
    if (listaVazia()) {
      throw 'a';
    }
    Elemento<T>* primeiro = head;
    return primeiro->getInfo();
  }
/**
* Função ultimoElemento. Retorna o elemento do final da lista encadeada.
*/
  Elemento<T>* ultimoElemento() {
    Elemento<T>* ultimo = head;
    if ( listaVazia() ) {
      return ultimo->getInfo();
    } else {
      for (int i = 0; i < size; i++) {
        ultimo = ultimo->getProximo();
      }
      return ultimo;
    }
  }
/**
* Função eliminaDoInicio. Chama o destrutor do primeiro elemento de uma lista encadeada.
*/
  void eliminaDoInicio() {
    Elemento<T>* antigoPrimeiro = head;
    head = antigoPrimeiro->getProximo();
    T data = antigoPrimeiro->getInfo();
    antigoPrimeiro->~Elemento();
    delete data;
  }
/**
* Função adicionaNaPosicao. Adiciona um elemento (argumento) em uma posição específica (argumento) da lista encadeada.
*/
  void adicionaNaPosicao(const T& dado, int pos) {
    if (pos > size + 1) {
      throw 'a';
    }
    if ( pos == 0 ) {
      adicionaNoInicio(dado);
    } else {
      Elemento<T>* novoDado = new Elemento<T>(dado, NULL);
      if (novoDado == NULL) {
        throw 'a';
      }
      Elemento<T>* elementoApercorrer = head;
      for (int i = 0; i < pos - 1; i++) {
        elementoApercorrer = elementoApercorrer->getProximo();
      }
      Elemento<T>* elementoPosterior = elementoApercorrer->getProximo();
      novoDado->setProximo(elementoPosterior);
      elementoApercorrer->setProximo(novoDado);
      size++;
    }
  }
/**
* Função posicao. Retorna a posição de um determinado elemento - passado como argumento à função.
*/
  int posicao(const T& dado) const {
    if (listaVazia()) {
      throw 'a';
    }
    int position = 0;
    Elemento<T>* atual = head;
    while (atual->getInfo() != dado && position < size) {
      atual = atual->getProximo();
      position++;
    }
    if (atual->getInfo() == dado) {
      return position;
    } else {
      throw 'a';
    }
  }
/**
* Função posicaoMem. Retorna a posição de memória de um determinado dado (argumento).
*/
  T* posicaoMem(const T& dado) const {
    if (listaVazia()) {
      throw 'a';
    }
    int position = 0;
    Elemento<T>* atual = head;
    while (atual->getInfo() != dado && position < size) {
      atual = atual->getProximo();
      position++;
    }
    if (atual->getInfo() == dado) {
      return &atual;
    } else {
      throw 'a';
    }
  }
/**
* Função retiraDaPosicao. Retira e retorna um elemento da lista encadeada de uma posição específica (argumento).
*/
  T retiraDaPosicao(int pos) {
    if (pos > size) {
      throw 'a';
    }
    if (pos == (size - 1)) {
      return retira();
    }
    if (pos == 0) {
      return retiraDoInicio();
    }
    Elemento<T>* anterior = head;
    int controller = 0;
    while (controller < pos - 1) {
      anterior = anterior->getProximo();
      controller++;
    }
    Elemento<T>* elementoAretirar = anterior->getProximo();
    T dadoRemovido = elementoAretirar->getInfo();
    anterior->setProximo(elementoAretirar->getProximo());
    size--;
    elementoAretirar->~Elemento();
    return dadoRemovido;
  }
/**
* Função contem. Retorna um valor booleano positivo caso determinado dado (argumento) conste na lista.
*/
  bool contem(const T& dado) {
    if (listaVazia()) {
      throw 'a';
    }
    int pos = 0;
    Elemento<T>* atual = head;
    while (pos < size && atual->getInfo() != dado) {
      atual = atual->getProximo();
      pos++;
    }
    if (atual->getInfo() == dado) {
      return true;
    } else {
      return false;
    }
  }
/**
* Função adiciona. Adiciona um dado (argumento) no final da lista encadeada.
*/
  Elemento<T>* adiciona(const T& dado) {
    if ( listaVazia() ) {
      adicionaNoInicio(dado);
    } else {
      Elemento<T>* novoDado = new Elemento<T>(dado, NULL);
      if (novoDado == NULL) {
        throw 'a';
      }
      Elemento<T>* anterior = head;
      for (int i = 0; i < size; i++) {
        anterior = anterior->getProximo();
      }
      anterior->setProximo(novoDado);
      size++;
    }
    return anterior->getProximo();
  }
/**
* Função retira. Retira e retonar um elemento do final da lista encadeada.
*/
  T retira() {
    if (listaVazia()) {
      throw 'a';
    }
    Elemento<T> *ultimoElemento = head;
    for (int i = 0; i < size; i++) {
      ultimoElemento = ultimoElemento->getProximo();
    }
    T dadoRemovido = ultimoElemento->getInfo();
    ultimoElemento->~Elemento();
    return dadoRemovido;
  }
/**
* Função retiraEspecifico. Retira e retorna um elemento específico (argumento) da lista encadeada.
*/
  T retiraEspecifico(const T& dado) {
    if (listaVazia()) {
      throw 'a';
    }
    int pos = posicao(dado);
    return retiraDaPosicao(pos);
  }
/**
* Função adicionaEmOrdem. Adiciona o elemento passado (argumento) em ordem na lista encadeada.
* Percorre e verifica a ordem de grandeza dos elementos encadeados.
*/
  void adicionaEmOrdem(const T& dado) {
    if (listaVazia()) {
      adicionaNoInicio(dado);
    }
    Elemento<T>* novoDado = new Elemento<T>(dado, NULL);
    if (novoDado == NULL) {
      throw 'a';
    }
    Elemento<T>* atual = head;
    int posicao = 0;
    while (posicao < size && maior(dado, atual->getInfo())) {
      atual = atual->getProximo();
      posicao++;
    }
    if (maior(dado, atual->getInfo())) {
      adicionaNaPosicao(dado, size + 1);
    } else {
      adicionaNaPosicao(dado, posicao);
    }
  }
/**
* Função igual. Retorna um valor booleano verdadeiro caso dois dados comparados sejam iguais.
*/
  bool igual(T dado1, T dado2) {
    return dado1 == dado2;
  }
/**
* Função maior. Retorna um valor booleano verdadeiro caso o primeiro elemento (argumento) seja maior que o segundo (argumento).
*/
  bool maior(T dado1, T dado2) {
    return dado1 > dado2;
  }
/**
* Função menor. Retorna um valor booleano verdadeiro caso o primeiro elemento (argumento) seja menor que o segundo (argumento).
*/
  bool menor(T dado1, T dado2) {
    return dado1 < dado2;
  }
/**
* Função destroiLista. Chama duas funções específicas para destruir a lista encadeada e sua cabeça.
*/
  void destroiLista() {
    if (!listaVazia()) {
     int controller = 0;
     while (controller < size) {
       Elemento<T>* atual = head;
       Elemento<T>* proximo = atual->getProximo();
       head = proximo;
       atual->~Elemento();
       controller++;
     }
    }
    size = -1;
  }
};
