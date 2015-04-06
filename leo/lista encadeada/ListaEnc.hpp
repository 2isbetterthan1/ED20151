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
  int size = -1;
  Elemento<T>* head;

 public:
/**
* Construtor. Construtor de uma Lista Encadeada.
*/
  ListaEnc() {
    size = 0;
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
    Elemento<T>* cabeca = new Elemento<T>(0, NULL);
    if (cabeca != NULL) {
      head = cabeca;
    } else {
    throw("Não foi possível criar a lista.");
    }
  }
/**
* Função listaVazia. Retorna um valor booleano informando se a lista encadeada está vazia ou não.
*/
  bool listaVazia() const {
    return head->getProximo() == NULL;
  }
/**
* Função excecaoListaVazia. Joga uma exceção e interrompe demais métodos caso a lista esteja vazia.
*/
  void excecaoListaVazia() {
    if (listaVazia()) {
      throw("Lista Vazia!");
    }
  }
/**
* Função adicionaNoInicio. Adiciona elementos no início de uma lista encadeada.
*/
  void adicionaNoInicio(const T& dado) {
    Elemento<T>* antigoPrimeiro = head->getProximo();
    Elemento<T>* elemento = new Elemento<T>(dado, NULL);
    if (elemento != NULL) {
      elemento->setProximo(antigoPrimeiro);
      head = elemento;
      size++;
    } else {
      throw("Não foi possível adicionar o elemento. Memória cheia.")
    }
  }
/**
* Função retiraDoInicio. Retira e retorna elemento do início de uma lista encadeada.
*/
  T retiraDoInicio() {
    Elemento<T>* antigoPrimeiro = head->getProximo();
    head = *antigoPrimeiro->getProximo();
    size--;
    return antigoPrimeiro;
  }
/**
* Função eliminaDoInicio. Chama o destrutor do primeiro elemento de uma lista encadeada.
*/
  void eliminaDoInicio() {
    Elemento<T>* inicio = retiraDoInicio();
    inicio.~Elemento();
  }
/**
* Função adicionaNaPosicao. Adiciona um elemento (argumento) em uma posição específica (argumento) da lista encadeada.
*/
  void adicionaNaPosicao(const T& dado, int pos) {
    Elemento<T>* novoDado = new Elemento<T>(dado, NULL);
    if (novoDado != NULL && (pos > -1 && pos <= size)) {
      Elemento<T>* proximo = new Elemento<T>(dado, NULL);
      proximo = acheElementoNaPos(pos);
      novoDado->setInfo(dado);
      proximo->setProximo(novoDado);
      novoDado->setProximo(proximo->getProximo());
      size++;
    } else {
      throw("Lista Cheia ou Posição Inválida");
    }
  }
/**
* Função acheElementoNaPos. Retorna um elemento na lista por meio de sua posição - passada como argumento.
*/
  Elemento<T> acheElementoNaPos(int pos) {
    excecaoListaVazia();
    Elemento<T>* proximo = head->getProximo();
    int controller = 0;
    while (controller >= 0 && controller < pos) {
      proximo = proximo->getProximo();
      controller++;
    }
    return proximo;
  }
/**
* Função posicao. Retorna a posição de um determinado elemento - passado como argumento à função.
*/
  int posicao(const T& dado) const {
    excecaoListaVazia();
    if (contem(dado)) {
      int position = 0;
      Elemento<T>* proximo = acheElementoNaPos(position);
      while (proximo->getInfo() != dado && position < size) {
        position++;
        proximo = acheElementoNaPos(position);
      }
      return position;
    } else {
      throw("Lista não contém este dado.");
    }
  }
/**
* Função posicaoMem. Retorna a posição de memória de um determinado dado (argumento).
*/
  T* posicaoMem(const T& dado) const {
    excecaoListaVazia();
    if (contem(dado)) {
      int position = 0;
      Elemento<T>* proximo = acheElementoNaPos(position);
      while (proximo->getInfo() != dado && position < size) {
        position++;
        proximo = acheElementoNaPos(position);
      }
      return *proximo;
    } else {
      throw("Dado Inválido");
    }
  }
/**
* Função retiraDaPosicao. Retira e retorna um elemento da lista encadeada de uma posição específica (argumento).
*/
  T retiraDaPosicao(int pos) {
    excecaoListaVazia();
    if (pos == size) {
      return retira();
    }
    Elemento<T>* elementoAretirar = acheElementoNaPos(pos);
    Elemento<T>* anterior = acheElementoNaPos(pos - 1);
    Elemento<T>* seguinte = acheElementoNaPos(pos + 1);
    anterior->setProximo(seguinte);
    return elementoAretirar;
  }
/**
* Função contem. Retorna um valor booleano positivo caso determinado dado (argumento) conste na lista.
*/
  bool contem(const T& dado) {
    excecaoListaVazia();
    int position = -1;
    while (position < size) {
      position++;
      Elemento<T>* proximo = acheElementoNaPos(position);
      if (proximo->getInfo() == dado) {
        return true;
      }
    }
    return false;
  }
/**
* Função adiciona. Adiciona um dado (argumento) no final da lista encadeada.
*/
  void adiciona(const T& dado) {
    Elemento<T>* novoElemento = new Elemento();
    if (novoElemento != NULL) {
      adicionaNaPosicao(dado, size);
    } else {
      throw("Lista cheia!");
    }
  }
/**
* Função retira. Retira e retonar um elemento do final da lista encadeada.
*/
  T retira() {
    Elemento<T>* elementoAretirar = acheElementoNaPos(size);
    Elemento<T>* penultimoElemento = acheElementoNaPos(size - 1);
    Elemento<T>* elementoNulo = NULL;
    penultimoElemento->setProximo(elementoNulo);
    return elementoAretirar;
  }
/**
* Função retiraEspecifico. Retira e retorna um elemento específico (argumento) da lista encadeada.
*/
  T retiraEspecifico(const T& dado) {
    int pos = posicao(dado);
    Elemento<T>* elemento = acheElementoNaPos(pos);
    return retiraDaPosicao(elemento);
  }
/**
* Função adicionaEmOrdem. Adiciona o elemento passado (argumento) em ordem na lista encadeada.
* Percorre e verifica a ordem de grandeza dos elementos encadeados.
*/
  void adicionaEmOrdem(const T& dado) {
    int pos = size;
    Elemento<T>* elementoAcomparar = acheElementoNaPos(pos);

    while (dado < elementoAcomparar->getInfo()) {
      pos--;
      elementoAcomparar = acheElementoNaPos(pos);
    }
    adicionaNaPosicao(dado, pos);
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
    excecaoListaVazia();
    destroiListaEncadeada();
    destroiCabeca();
  }
/*
* Função destroiCabeca. Chama o destrutor da cabeça de uma lista encadeada. 
*/
  void destroiCabeca() {
    head->~Elemento();
  }
/**
* Função destroiListaEncadeada. Percorre a lista encadeada e destroi seus respectivos elementos.
*/
  void destroiListaEncadeada() {
    int controller = size;
    Elemento<T>* proximoElemento = acheElementoNaPos(size);
    while (controller > 0) {
      Elemento<T>* elementoAdestruir = proximoElemento;
      proximoElemento = proximoElemento->getProximo();
      elementoAdestruir->~Elemento();
      controller--;
    }
    size = 0;
  }
};
