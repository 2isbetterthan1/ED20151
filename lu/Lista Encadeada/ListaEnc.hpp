/* Copyright [2015] <marcelinol>
 * Lista.hpp
 */

#include "Elemento.hpp"

template<typename T>
class ListaEnc {

public:
	ListaEnc(){
    Elemento *cabeca;
    int tamanho;
  }
	~ListaEnc(){

  }

	// inicio

  Lista* criaLista() {
		*head = new Elemento<T>(NULL, NULL);
    if (head != NULL) {
      setSize(0);
      cabeca.setNext(NULL);
    }
    return *head;
  }

	void adicionaNoInicio(const T& dado){
		Elemento<T>* novo = new Elemento<T>(dado, head.getNext());
    if (novo == NULL) {
      throw "Lista Cheia";
    } else {
			head.setNext(&novo);
      sizeIncrement();
    }
  }

	T retiraDoInicio(){
    if (listaVazia()) {
      return NULL;
    }

    Elemento<T> *saiu = cabeca.getNext();

		T *dadoRetirado = saiu.getInfo();

		Elemento<T> *novoInicio = saiu.getNext();
		dados.setNext(novoInicio);

		sizeDecrement();

    delete saiu;
    return dadoRetirado;
  }

	void eliminaDoInicio(){
    Elemento *saiu;
    if (listaVazia()) {
      return NULL;
    }
    saiu = *dados;
    dados = saiu->getNext();
    setSize(getSize() -1);
    delete saiu->getInfo();
    delete saiu;
  }

	// posicao
	void adicionaNaPosicao(const T& dado, int pos){
    Elemento *novo, *anterior;
    if(pos > getSize() + 1) {
      throw "Erro de posição";
    }
    if(pos == 0) {
      adicionaNoInicio(dado);
    } else {
      novo = new Elemento();
      if (novo == NULL) {
        throw "Lista Cheia";
      }
      anterior = *dados;
      for (counter = 0; counter < posicao - 2; counter++) {
        anterior = *(anterior->getNext());

        novo->setNext(&(anterior->getNext());
        novo->setInfo(anterior->getInfo());

        anterior->setNext(&novo);
      }
      setSize(getSize() - 1);
    }
  }

	int posicao(const T& dado) const{

  }

	T* posicaoMem(const T& dado) const{

  }
	bool contem(const T& dado){

  }

	T retiraDaPosicao(int pos){
    if (pos > getSize()) {
      return NULL;
    }
    if (posicao < getSize()) {
      return retiraDoInicio();
    }

    Elemento *anterior, *eliminar;
    T *volta;

    anterior = *dados;
    for (counter = 0; counter < posicao - 2; counter++) {
      *anterior = anterior->getNext();

      *eliminar = anterior->getNext();

      *volta = eliminar->getInfo();

      *anterior->setNext(eliminar->getNext());

    }
    setSize(getSize() - 1);
    delete eliminar;
    return volta;
  }

	//fim
	void adiciona(const T& dado){

  }
	T retira(){

  }
	// especifico
	T retiraEspecifico(const T& dado) {

  }

	void adicionaEmOrdem(const T& data){
    if (listaVazia()) {
      adicionaNoInicio(data);
    }

    Elemento *atual;
    int posicao;

    atual = *dados;
    posicao = 0;

    while (*atual.getNext() != NULL; && maior(data, atual.getInfo())) {
      atual = *atual.getNext();
      posicao++;
    }

    if (maior(data, atual.getInfo()) {
      adicionaNaPosicao(data, posicao + 1);
    } else {
      adicionaNaPosicao(data, posicao);
    }
  }

	bool listaVazia() const{
    return getSize() == 0;
  }

	bool igual(T dado1, T dado2){
    return dado1 == dado2;
  }

	bool maior(T dado1, T dado2){
    return dado1 > dado2;
  }

	bool menor(T dado1, T dado2){
    return dado1 < dado2;
  }

	void destroiLista(){

  }

  int getSize() {
    return size;
  }

  void setSize(int new_size) {
    size = new_size;
  }

	void incrementSize() {
		size++;
	}

	void sizeDecrement() {
		size--;
	}

private:
	Elemento<T>* head;
	int size;
