/* Copyright [2015] <LeoSL>
 * ListaDupla.hpp
 */

#include "Elemento.hpp"

template<typename T>

/**
* Classe ListaDupla. Uma Lista Duplamente Encadeada é uma lista linear.
* Na lista duplamente encadeada, cada elemento está armazenado em um objeto chamado elemento de lista.
* Cada elemento possui referências para o seu elemento posterior e anterior.
*/
class ListaDupla {
 private:
  Elemento<T>* head;
  int size;

 public:
/**
* Construtor. Construtor de uma Lista Duplamente Encadeada.
*/
  ListaDupla<T>() {
    criaListaDupla();
  }
/**
* Destrutor. Destrutor de uma Lista Duplamente Encadeada.
*/
  ~ListaDupla() {
    destroiListaDuplo();
  }
/**
* Função criaListaDupla. Serve para fazer a configuração inicial de uma lista duplamente encadeada.
*/
  void criaListaDupla() {
    this->head = NULL;
    this->size = -1;
  }
/**
* Função adicionaNoInicioDuplo. Adiciona elementos no início de uma lista duplamente encadeada.
*/
  void adicionaNoInicioDuplo(const T& dado) {
    Elemento<T>* novoElemento = new Elemento<T>(dado, NULL);
    if (novoElemento != NULL) {
      head = novoElemento;
      novoElemento->setProximo(NULL);
      size++;
    } else {
     throw 'a';
    }
  }
/**
* Função retiraDoInicioDuplo. Retira e retorna elemento do início de uma lista duplamente encadeada.
*/
  T retiraDoInicioDuplo() {
    if (listaVazia()) {
      throw 'a';
    }
    Elemento<T>* primeiro = head;
    head = primeiro->getProximo();
    T primeiroElemento = primeiro->getInfo();
    primeiro->~Elemento();
    size--;
    return primeiroElemento;
  }
/**
* Função eliminaDoInicioDuplo. Chama o destrutor do primeiro elemento de uma lista duplamente encadeada.
*/
  void eliminaDoInicioDuplo() {
    if (listaVazia()) {
      throw 'a';
    }
    Elemento<T>* primeiro = head;
    head = primeiro->getProximo();
    primeiro->~Elemento();
    size--;
  }
/**
* Função adicionaNaPosicaoDuplo. Adiciona um elemento (argumento) em uma posição específica (argumento) da lista duplamente encadeada.
*/
  void adicionaNaPosicaoDuplo(const T& dado, int pos) {
    if (listaVazia()) {
      adicionaNoInicioDuplo(dado);
    } else {
      if (pos == 0) {
        Elemento<T>* novoElemento = new Elemento<T>(dado, NULL);
        if (novoElemento != NULL) {
          Elemento<T>* antigoPrimeiro = head;
          head = novoElemento;
          novoElemento->setProximo(antigoPrimeiro);
          antigoPrimeiro->setAnterior(novoElemento);
          size++;
        } else {
         throw 'a';
        }
      } else {
        if (pos == size + 1) {
          adicionaDuplo(dado);
        } else {
          if (pos > size + 1) {
            throw 'a';
          }
          Elemento<T>* novoElemento = new Elemento<T>(dado, NULL);
          if (novoElemento != NULL) {
            Elemento<T>* elementoApercorrer = head;
            int controller = 0;
            while (controller != pos && controller < size) {
              elementoApercorrer = elementoApercorrer->getProximo();
              controller++;
            }
            Elemento<T>* anterior = elementoApercorrer->getBack();
            novoElemento->setProximo(elementoApercorrer);
            novoElemento->setAnterior(anterior);
            elementoApercorrer->setAnterior(novoElemento);
            anterior->setProximo(novoElemento);
            size++;
          } else {
            throw 'a';
          }
        }
      }
    }
  }
/**
* Função adicionaDuplo. Adiciona um dado (argumento) no final da lista duplamente encadeada.
*/
  void adicionaDuplo(const T& dado) {
    if (listaVazia()) {
      adicionaNoInicioDuplo(dado);
    } else {
      Elemento<T>* novoElemento = new Elemento<T>(dado, NULL);
      if (novoElemento != NULL) {
        Elemento<T>* elemento = head;
        int controller = 0;
        while (controller < size) {
          elemento = elemento->getProximo();
          controller++;
        }
        elemento->setProximo(novoElemento);
        novoElemento->setAnterior(elemento);
        novoElemento->setProximo(NULL);
        size++;
      } else {
        throw 'a';
      }
    }
  }
/**
* Função adicionaEmOrdem. Adiciona o elemento passado (argumento) em ordem na lista duplamente encadeada.
* Percorre e verifica a ordem de grandeza dos elementos encadeados.
*/
  void adicionaEmOrdem(const T& data) {
    if (listaVazia()) {
      adicionaNoInicioDuplo(data);
    } else {
      Elemento<T>* elementoApercorrer = head;
      int controller = 0;
      while (controller < size && maior(data, elementoApercorrer->getInfo())) {
        elementoApercorrer = elementoApercorrer->getProximo();
        controller++;
      }
      if (maior(data, elementoApercorrer->getInfo())) {
        adicionaNaPosicaoDuplo(data, size + 1);
      } else {
        adicionaNaPosicaoDuplo(data, controller);
      }
    }
  }
/**
* Função posicaoDuplo. Retorna a posição de um determinado elemento - passado como argumento à função.
*/
  int posicaoDuplo(const T& dado) const {
    if (listaVazia()) {
      throw 'a';
    }
    Elemento<T>* elementoApercorrer = head;
    int controller = 0;
    T infoElemento = elementoApercorrer->getInfo();
    while (infoElemento != dado && controller < size) {
      elementoApercorrer = elementoApercorrer->getProximo();
      infoElemento = elementoApercorrer->getInfo();
      controller++;
    }
    if (infoElemento == dado) {
      return controller;
    } else {
      throw 'a';
    }
  }
/**
* Função posicaoMemDuplo. Retorna a posição de memória de um determinado dado (argumento).
*/
  T* posicaoMemDuplo(const T& dado) const {
    if (listaVazia()) {
      throw 'a';
    }
    Elemento<T>* elementoApercorrer = head;
    int pos = 0;
    T infoElemento = elementoApercorrer->getInfo();
    while (infoElemento != dado && pos < size) {
      elementoApercorrer = elementoApercorrer->getProximo();
      infoElemento = elementoApercorrer->getInfo();
      pos++;
    }
    if (infoElemento == dado) {
      return &elementoApercorrer;
    } else {
      throw 'a';
    }
  }
/**
* Função contemDuplo. Retorna um valor booleano positivo caso determinado dado (argumento) conste na lista.
*/
  bool contemDuplo(const T& dado) {
    if (listaVazia()) {
      throw 'a';
    }
    Elemento<T>* elementoApercorrer = head;
    int controller = 0;
    T infoElemento = elementoApercorrer->getInfo();
    while (infoElemento != dado && controller < size) {
      elementoApercorrer = elementoApercorrer->getProximo();
      infoElemento = elementoApercorrer->getInfo();
      controller++;
    }
    if (infoElemento == dado) {
      return true;
    } else {
      return false;
    }
  }
/**
* Função retiraDaPosicaoDuplo. Retira e retorna um elemento da lista duplamente encadeada de uma posição específica (argumento).
*/
  T retiraDaPosicaoDuplo(int pos) {
    if (listaVazia() || pos > size) {
      throw 'a';
    }
    Elemento<T>* elementoApercorrer = head;
    int controller = 0;
    while (controller < pos) {
      elementoApercorrer = elementoApercorrer->getProximo();
      controller++;
    }
    T infoElemento = elementoApercorrer->getInfo();
    Elemento<T>* proximo = elementoApercorrer->getProximo();
    Elemento<T>* anterior = elementoApercorrer->getBack();
    anterior->setProximo(proximo);
    proximo->setAnterior(anterior);
    size--;
    return infoElemento;
  }
/**
* Função retiraDuplo. Retira e retonar um elemento do final da lista duplamente encadeada.
*/
  T retiraDuplo() {
    if (listaVazia()) {
      throw 'a';
    }
    Elemento<T>* elementoApercorrer = head;
    int controller = 0;
    while (controller < size) {
      elementoApercorrer = elementoApercorrer->getProximo();
      controller++;
    }
    T infoElemento = elementoApercorrer->getInfo();
    Elemento<T>* anterior = elementoApercorrer->getBack();
    anterior->setProximo(NULL);
    size--;
    return infoElemento;
  }
/**
* Função retiraEspecificoDuplo. Retira e retorna um elemento específico (argumento) da lista duplamente encadeada.
*/
  T retiraEspecificoDuplo(const T& dado) {
    if (listaVazia()) {
      throw 'a';
    }
    Elemento<T>* elementoApercorrer = head;
    int controller = 0;
    T infoElemento = elementoApercorrer->getInfo();
    while (infoElemento != dado && controller < size) {
      elementoApercorrer = elementoApercorrer->getProximo();
      infoElemento = elementoApercorrer->getInfo();
      controller++;
    }
    if (infoElemento == dado) {
      return retiraDaPosicaoDuplo(controller);
    } else {
      throw 'a';
    }
  }
/**
* Função mostra. Mostra a informação de um elemento em uma posição (argumento) específica da lista duplamente encadeada.
*/
  T mostra(int pos) {
    if (listaVazia() || pos > size) {
      throw 'a';
    }
    Elemento<T>* elementoApercorrer = head;
    int controller = 0;
    T infoElemento = elementoApercorrer->getInfo();
    while (controller < pos) {
      elementoApercorrer = elementoApercorrer->getProximo();
      infoElemento = elementoApercorrer->getInfo();
      controller++;
    }
    return infoElemento;
  }
/**
* Função verUltimo. Vê o último.
*/
  int verUltimo() {
    return 0;
  }
/**
* Função listaVazia. Retorna um valor booleano informando se a lista duplamente encadeada está vazia ou não.
*/
  bool listaVazia() const {
    if (size == -1) {
      return true;
    } else {
      return false;
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
* Função destroiLista. Serve para destruir a lista duplamente encadeada dupla.
*/
  void destroiListaDuplo() {
    size = -1;
  }
};
