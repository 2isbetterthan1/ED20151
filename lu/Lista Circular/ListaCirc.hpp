/* Copyright [2015] <marcelinol>
 * Caboclo.hpp
 */


#include "Elemento.hpp"
#include "ListaEnc.hpp"

template<typename T>

class ListaCirc : public ListaEnc<T> {
 private:
	ListaEnc<T>* lista;
	Elemento<T>* sentinela;

 public:
	ListaCirc(): ListaEnc<T>::ListaEnc() {
		lista = new ListaEnc<T>();
	}
	~ListaCirc() {
		ListaEnc<T>::~ListaEnc();
	}
	void adicionaNoInicio(const T& dado);
	T retiraDoInicio() {
			//  return ListaEnc<T>::retiraDoInicio();
		return retiraDoInicio();
	}
	void eliminaDoInicio() {  //  REESCREVER
		eliminaDoInicio();
	}

	void adicionaNaPosicao(const T& dado, int pos) {
		ListaEnc<T>::adicionaNaPosicao(dado, pos);
	}

	int posicao(const T& dado) const {
		return ListaEnc<T>::posicao(dado);
	}

	T* posicaoMem(const T& dado) const {
		return ListaEnc<T>::posicaoMem(dado);
	}

	bool contem(const T& dado) {
		return ListaEnc<T>::contem(dado);
	}

	T retiraDaPosicao(int pos) {
		return ListaEnc<T>::retiraDaPosicao(pos);
	}

	void adiciona(const T& dado) {  //  REESCREVER
		ListaEnc<T>::adiciona(dado);
	}

	T retira() {  //  REESCREVER
		return ListaEnc<T>::retira();
	}

	T retiraEspecifico(const T& dado) {
		return ListaEnc<T>::retiraEspecifico(dado);
	}

	T mostra(int pos) {  //  ESCREVER
		return;
	}

	void adicionaEmOrdem(const T& dado) {
		ListaEnc<T>::adicionaEmOrdem(dado);
	}

	int verUltimo() {
		return 0;
	}

	bool listaVazia() const {
		return ListaEnc<T>::listaVazia();
	}

	bool igual(T dado1, T dado2) {
		return ListaEnc<T>::igual(dado1, dado2);
	}

	bool maior(T dado1, T dado2) {
		return ListaEnc<T>::maior(dado1, dado2);
	}

	bool menor(T dado1, T dado2) {
		return ListaEnc<T>::menor(dado1, dado2);
	}

	void destroiLista() {
		ListaEnc<T>::destroiLista();
	}
};
