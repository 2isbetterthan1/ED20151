/* Copyright [2015] <marcelinol>
 * Lista.hpp
 */

#include "Elemento.hpp"

template<typename T>
class ListaEnc {

public:
	ListaEnc(){
    Elemento *head;
    int tamanho;
  }
	~ListaEnc(){

  }

	// inicio

  Lista* criaLista() {
		*head = new Elemento<T>(NULL, NULL);
    if (head != NULL) {
      setSize(0);
      head.setNext(NULL);
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

    Elemento<T> *saiu = head.getNext();

		T *dadoRetirado = saiu.getInfo();

		eliminaDoInicio();
		// Elemento<T> *novoInicio = saiu.getNext();
		// head.setNext(novoInicio);
		//
		// sizeDecrement();
		//
    // delete saiu;
    return dadoRetirado;
  }

	void eliminaDoInicio(){
    if (listaVazia()) {
      return NULL;
    }

    Elemento *eliminado = head.getNext();

		Elemento<T> *novoInicio = eliminado.getNext();
    head.setNext(novoInicio);

		sizeDecrement();

    delete eliminado.getInfo();
    delete eliminado;
  }

	// posicao
	void adicionaNaPosicao(const T& dado, int pos){
		if(pos > getSize() + 1) {
      throw "Erro de posição";
    }

		if(pos == 0) {
      adicionaNoInicio(dado);
    } else {
      Elemento<T> *novo = new Elemento<T>(dado, NULL);

			if (novo == NULL) {
        throw "Lista Cheia";
      }

      Elemento<T> *anterior = head.getNext();
      for (int i = 0; i < pos - 1; i++) {
				*anterior = anterior.getNext();
			}

			Elemento<T> *posterior = anterior.getNext();
			novo.setNext(posterior);

			anterior.setNext(novo);

			sizeIncrement();
    }
  }

	int posicao(const T& dado) const{
		if (listaVazia()) {
			throw "lista vazia";
		}
		Elemento<T> *current = head.getNext();

		int posicao = 0;

		while (posicao < getSize() && current.getInfo() != dado) {
			*current = current.getNext();
			i++;
		}

		if (current.getInfo() == dado) {
			return posicao;
		} else {
			throw "Elemento não pertence à lista";
		}

  }

	T* posicaoMem(const T& dado) const{
		if (listaVazia()) {
			throw "lista vazia";
		}
		Elemento<T> *current = head.getNext();

		int posicao = 0;

		while (posicao < getSize() && current.getInfo() != dado) {
			*current = current.getNext();
			i++;
		}

		if (current.getInfo() == dado) {
			return &current;
		} else {
			throw "Elemento não pertence à lista";
		}
  }

	bool contem(const T& dado){
		if (listaVazia()) {
			throw "lista vazia";
		}

		Elemento<T> *current = head.getNext();

		int posicao = 0;

		while (posicao < getSize() && current.getInfo() != dado) {
			*current = current.getNext();
			i++;
		}

		if (current.getInfo() == dado) {
			return true;
		} else {
			return false;
		}
  }

	T retiraDaPosicao(int pos){
    if (pos > getSize()) {
      throw "Erro de posicao";
    }
    if (posicao == 0) {
      return retiraDoInicio();
    }

		Elemento *anterior = head.getNext();

		for (int i = 0; i < pos - 1; i++) {
			*anterior = anterior.getNext();
		}

		Elemento *retirar = anterior.getNext();
		T dadoRetirado = retirar.getInfo();

		anterior.setNext(retirar.getNext());

		sizeDecrement();

    delete retirar;
    return dadoRetirado;
  }

	//fim
	void adiciona(const T& dado){
		if (listaVazia()) {
			adicionaNoInicio(dado);
		}

		Elemento<T> *novo = new Elemento<T>(dado, NULL);

		if(novo == NULL) {
			throw "lista cheia";
		}

		Elemento *anterior = head.getNext();

		for (int i = 0; i < getSize(); i++) {
			*anterior = anterior.getNext();
		}

		anterior.setNext(novo);

		sizeIncrement();
  }

	T retira(){
		if (listaVazia()) {
			throw "lista vazia";
		}
		Elemento *ultimo = head.getNext();

		for (int i = 0; i < getSize(); i++) {
			*ultimo = ultimo.getNext();
		}

		T dadoRetirado = ultimo.getInfo();

		delete ultimo.getInfo();
		delete ultimo;

		return dadoRetirado();
  }

	T retiraEspecifico(const T& dado) {
		Elemento<T> *elemento = posicaoMem(dado);
		return elemento.getInfo();
  }

	void adicionaEmOrdem(const T& dado){
    if (listaVazia()) {
      adicionaNoInicio(data);
    }

		Elemento<T> *novo = new Elemento<T>(dado, NULL);

		if (novo == NULL) {
			throw "lista cheia";
		}

		Elemento *atual = head.getNext();

    int posicao = 0;

    while (posicao < getSize() && maior(dado, atual.getInfo())) {
      *atual = atual.getNext();
      posicao++;
    }

    if (maior(dado, atual.getInfo()) {
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
		setSize(-1);
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
