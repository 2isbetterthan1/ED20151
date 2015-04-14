/* Copyright [2015] <marcelinol>
 * ListaEnc.hpp
 */
 
#include "Elemento.hpp"

template<typename T>
class ListaEnc {
 private:
	Elemento<T>* head;
	int size;

 public:
	ListaEnc<T>() {
    criaLista();
  }

	~ListaEnc() {
    destroiLista();
  }

  void criaLista() {
	head = NULL;
    size = -1;
  }

	void adicionaNoInicio(const T& dado) {
		Elemento<T>* novo = new Elemento<T>(dado, head);
    if (novo == NULL) {
      throw "Lista Cheia";
    } else {
			head = novo;
      size++;
    }
  }

	T retiraDoInicio() {
     if (listaVazia()) {
       throw "lista vazia";
     }

     Elemento<T> *saiu = head;

	 T dadoRetirado = saiu->getInfo();

		eliminaDoInicio();
     return dadoRetirado;
  }

	void eliminaDoInicio() {
     if (listaVazia()) {
       throw "lista vazia";
     }

     Elemento<T> *eliminado = head;

	 Elemento<T> *novoInicio = eliminado->getNext();
     head->setNext(novoInicio);

	 size--;

     delete eliminado;
  }

	void adicionaNaPosicao(const T& dado, int pos) {
		if(pos > size + 1) {
      throw "Erro de posição";
    }

		if(pos == 0) {
      adicionaNoInicio(dado);
    } else {
      Elemento<T> *novo = new Elemento<T>(dado, NULL);

			if (novo == NULL) {
        throw "Lista Cheia";
      }

      Elemento<T> *anterior = head;
      for (int i = 0; i < pos - 1; i++) {
				anterior = anterior->getNext();
			}

			Elemento<T> *posterior = anterior->getNext();
			novo->setNext(posterior);

			anterior->setNext(novo);

			size++;
    }
  }

	int posicao(const T& dado) const {
		if (listaVazia()) {
			throw "lista vazia";
		}
		Elemento<T> *current = head;

		int posicao = 0;

		while (posicao < size && current->getInfo() != dado) {
			current = current->getNext();
			posicao++;
		}

		if (current->getInfo() == dado) {
			return posicao;
		} else {
			throw "Elemento não pertence à lista";
		}
  }

	T* posicaoMem(const T& dado) const {
		if (listaVazia()) {
			throw "lista vazia";
		}
		Elemento<T> *current = head;

		int posicao = 0;

		while (posicao < size && current->getInfo() != dado) {
			current = current->getNext();
			posicao++;
		}

		if (current->getInfo() == dado) {
			return current;
		} else {
			throw "Elemento não pertence à lista";
		}
  }

	bool contem(const T& dado) {
		if (listaVazia()) {
			throw "lista vazia";
		}

		Elemento<T> *current = head;

		int pos = 0;

		while (pos < size && current->getInfo() != dado) {
			current = current->getNext();
			pos++;
		}

		if (current->getInfo() == dado) {
			return true;
		} else {
			return false;
		}
  }

	T retiraDaPosicao(int pos) {
    if (pos > size) {
      throw "Erro de posicao";
    }
    if (pos == 0) {
      return retiraDoInicio();
    }
    if (pos == size - 1) {
      return retira();
    }

		Elemento<T> *anterior = head;

		for (int i = 0; i < pos - 1; i++) {
			anterior = anterior->getNext();
		}

		Elemento<T> *retirar = anterior->getNext();
		T dadoRetirado = retirar->getInfo();

		anterior->setNext(retirar->getNext());

		size--;

    delete retirar;
    return dadoRetirado;
  }

	void adiciona(const T& dado) {
		if (listaVazia()) {
			return adicionaNoInicio(dado);
		}

		Elemento<T> *novo = new Elemento<T>(dado, NULL);

		if(novo == NULL) {
			throw "lista cheia";
		}

		Elemento<T> *anterior = head;

		for (int i = 0; i < size; i++) {
			anterior = anterior->getNext();
		}

		anterior->setNext(novo);

		size++;
  }

	T retira() {
		if (listaVazia()) {
			throw "lista vazia";
		}
		Elemento<T> *ultimo = head;

		for (int i = 0; i < size; i++) {
			ultimo = ultimo->getNext();
		}

		T dadoRetirado = ultimo->getInfo();

		delete ultimo;

		return dadoRetirado;
  }

	T retiraEspecifico(const T& dado) {
    if (listaVazia()) {
      throw "lista vazia";
    }

    Elemento<T> *atual = head;
    Elemento<T> *anterior = head;
    int pos = 0;
    while (pos < size && atual->getInfo() != dado) {
      anterior = atual;
      atual = atual->getNext();
      pos++;
    }

    if (pos == size) {
      throw "Elemento inexistente";
    }

    if (pos == size - 1) {
      return retira();
    }

    T dadoRetirado = atual->getInfo();
    anterior->setNext(atual->getNext());
    delete atual;

    return dadoRetirado;
  }

	void adicionaEmOrdem(const T& dado) {
    if (listaVazia()) {
      adicionaNoInicio(dado);
    }

		Elemento<T> *novo = new Elemento<T>(dado, NULL);

		if (novo == NULL) {
			throw "lista cheia";
		}

		Elemento<T> *atual = head;

    int posicao = 0;

    while (posicao < size && maior(dado, atual->getInfo())) {
      atual = atual->getNext();
      posicao++;
    }

    if (maior(dado, atual->getInfo())) {
      adicionaNaPosicao(dado, posicao + 1);
    } else {
      adicionaNaPosicao(dado, posicao);
    }
  }

  T getFirst() {
    if (listaVazia()) {
      throw 'u';
    }
    Elemento<T> *first = head;
    return first->getInfo();
  }

  T getLast() {
    if (listaVazia()) {
      throw 'u';
    } elsif (size == 0) {
      return getFirst();
    }
    Element<T> *last = head;

    for (int i = 0; i < size; i++) {
			last = last->getNext();
		}

		return last->getInfo();
  }

	bool listaVazia() const {
    return size == -1;
  }

	bool igual(T dado1, T dado2) {
    return dado1 == dado2;
  }

	bool maior(T dado1, T dado2) {
    return dado1 > dado2;
  }

	bool menor(T dado1, T dado2) {
    return dado1 < dado2;
  }

	void destroiLista() {
		size = -1;
  }
};

#endif
