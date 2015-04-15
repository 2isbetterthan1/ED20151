/* Copyright [2015] <LeoSL>
 * ListaDupla.hpp
 */

#include "Elemento.hpp"

template<typename T>

/**
* Classe ListaEnc. Uma Lista Encadeada é uma lista onde cada elemento está armazenado em um objeto chamado elemento de lista.
*/
class ListaDupla {
 private:
  Elemento<T>* head;
  int size;

 public:
  ListaDupla<T>() {
    criaListaDupla();
  }

  ~ListaDupla() {
    destroiListaDuplo();
  }

  void criaListaDupla() {
    this->head = NULL;
    this->size = -1;
  }

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

  void eliminaDoInicioDuplo() {
    if (listaVazia()) {
      throw 'a';
    }
    Elemento<T>* primeiro = head;
    head = primeiro->getProximo();
    primeiro->~Elemento();
    size--;
  }

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

  int verUltimo() {
    return 0;
  }

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
* Função destroiLista. Serve para destruir a lista encadeada dupla.
*/
  void destroiListaDuplo() {
    size = -1;
  }
};
