/* Copyright [2015] <marcelinol>
 * ListaDupla.hpp
 */

#include "ElementoDuplo.hpp"

template<typename T>

class ListaDupla {
 private:
	 ElementoDuplo<T>* head;
	 int size;

 public:
	ListaDupla<T>() {
		criaLista();
	}

	~ListaDupla() {
		criaLista();
	}

	void criaLista() {
		head = NULL;
		size = -1;
	}

	void adicionaNoInicioDuplo(const T& dado) {
		ElementoDuplo<T>* novo = new ElementoDuplo<T>(dado, NULL, head);
		if (novo == NULL) {
			throw "Lista Cheia";
		} else {
			if (!listaVazia()) {
				head->setPrevious(novo);
			}
			head = novo;
			size++;
			}
	}

	T retiraDoInicioDuplo() {
		if (listaVazia()) {
			throw 'u';
		} else {
			ElementoDuplo<T> *saiu = head;
			T dadoRetirado = saiu->getInfo();
			head = saiu->getNext();
			head->setPrevious(NULL);
			delete saiu;
			return dadoRetirado;
		}
	}

	void eliminaDoInicioDuplo() {
		if (listaVazia()) {
			throw 'u';
		} else {
			ElementoDuplo<T>* eliminado = head;
			head = head->getNext();
			head->setPrevious(NULL);
			delete eliminado;
		}
	}

	void adicionaNaPosicaoDuplo(const T& dado, int pos) {
		if (pos > size + 1 || pos < 0) {
			throw 'x';
		}
		if (listaVazia()) {
			adicionaNoInicioDuplo(dado);
		} else {
			if (pos == size + 1) {
				adicionaDuplo(dado);
			} else {
				ElementoDuplo<T>* novo = new ElementoDuplo<T>(dado, NULL, NULL);
				if (novo == NULL) {
					throw "Lista Cheia";
				}
				ElementoDuplo<T>* anterior = head;
				for (int i = 0; i < pos - 1; i++) {
					anterior = anterior->getNext();
				}
				novo->setPrevious(anterior);
				novo->setNext(anterior->getNext());

				(anterior->getNext())->setPrevious(novo);
				anterior->setNext(novo);
				size++;
			}
		}
	}

	T retiraDaPosicaoDuplo(int pos) {
		if (pos > size + 1 || pos < 0) {
			throw 'x';
		}
		if (listaVazia()) {
			throw 'u';
		}
		if (pos == 0) {
			return retiraDoInicioDuplo();
		}
		if (pos == size) {
			return retiraDuplo();
		}

		ElementoDuplo<T>* atual = head;
		for (int i = 0; i < pos; i++) {
			atual = atual->getNext();
		}
		T dadoRetirado = atual->getInfo();
		(atual->getPrevious())->setNext(atual->getNext());
		(atual->getNext())->setPrevious(atual->getPrevious());

		size--;
		delete atual;
		return dadoRetirado;
	}

	void adicionaEmOrdem(const T& dado) {
		if (listaVazia()) {
			adicionaNoInicioDuplo(dado);
		} else {
			ElementoDuplo<T>* atual = head;
			int posicao = 0;
			while (posicao < size && maior(dado, atual->getInfo())) {
				atual = atual->getNext();
				posicao++;
			}
			if (posicao == size) {
				adicionaDuplo(dado);
			} else {
				adicionaNaPosicaoDuplo(dado, posicao);
			}
		}
	}

	int posicaoDuplo(const T& dado) const {
		if (listaVazia()) {
			throw 'u';
		}

		ElementoDuplo<T> *current = head;
		int posicao = 0;
		while (posicao < size && current->getInfo() != dado) {
			current = current->getNext();
			posicao++;
		}

		if (current->getInfo() == dado) {
			return posicao;
		} else {
			throw "z";
		}
	}

	T* posicaoMemDuplo(const T& dado) const {
		if (listaVazia()) {
			throw "u";
		}

		ElementoDuplo<T> *current = head;
		int posicao = 0;
		while (posicao < size && current->getInfo() != dado) {
			current = current->getNext();
			posicao++;
		}

		if (current->getInfo() == dado) {
			return current;
		} else {
			throw "z";
		}
	}

	bool contemDuplo(const T& dado) {
		if (listaVazia()) {
			throw "lista vazia";
		}

		ElementoDuplo<T> *current = head;
		int posicao = 0;

		while (posicao < size && current->getInfo() != dado) {
			current = current->getNext();
			posicao++;
		}

		if (current->getInfo() == dado) {
			return true;
		} else {
			return false;
		}
	}

	void adicionaDuplo(const T& dado) {
		if (listaVazia()) {
			return adicionaNoInicioDuplo(dado);
		}
		ElementoDuplo<T> *novo = new ElementoDuplo<T>(dado, NULL, NULL);
		if(novo == NULL) {
			throw "x";
		}

		ElementoDuplo<T> *anterior = head;
		for (int i = 0; i < size; i++) {
			anterior = anterior->getNext();
		}

		anterior->setNext(novo);
		novo->setPrevious(anterior);

		size++;
	}

	T retiraDuplo() {
		if (listaVazia()) {
			throw "u";
		}
		ElementoDuplo<T> *ultimo = head;

		for (int i = 0; i < size; i++) {
			ultimo = ultimo->getNext();
		}

		T dadoRetirado = ultimo->getInfo();
		(ultimo->getPrevious())->setNext(NULL);

		size--;
		delete ultimo;
		return dadoRetirado;
	}

	T retiraEspecificoDuplo(const T& dado) {
		if (listaVazia()) {
			throw "lista vazia";
		}

		ElementoDuplo<T> *atual = head;
		int posicao = 0;
		while (posicao < size && atual->getInfo() != dado) {
			atual = atual->getNext();
			posicao++;
		}

		if (atual->getInfo() != dado) {
			throw 'y';
			}
			return retiraDaPosicaoDuplo(posicao);
	}

	T mostra(int pos) {
		if (pos > size + 1 || pos < 0) {
			throw 'x';
		}
		if (listaVazia()) {
			throw 'u';
		}
		ElementoDuplo<T>* atual = head;
		for (int i = 0; i < pos - 1; i++) {  //  VAI DAR MERDA ESSE pos -1
			atual = atual->getNext();
		}
		return atual->getInfo();
	}

	int verUltimo() {
		return size;
	}

	bool listaVazia() const {
		return size == -1;
	}

	void destroiListaDuplo() {
		criaLista();
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
};
