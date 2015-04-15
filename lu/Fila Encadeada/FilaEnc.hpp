/* Copyright [2015] <marcelinol>
 * FilaEnc.hpp
 */

#include "Elemento.hpp"
#include "ListaEnc.hpp"

template<typename T>

class FilaEnc: public ListaEnc<T> {
 private:
  ListaEnc<T>* lista;

 public:
	FilaEnc<T>(): ListaEnc<T>::ListaEnc() {
    lista = new ListaEnc<T>();
  }

	~FilaEnc() {
    limparFila();
  }

	void inclui(const T& dado) {
    lista->adiciona(dado);
  }

	T retira() {
    return lista->retiraDoInicio();
  }

	T ultimo() {
    return lista->getLast();
  }

	T primeiro() {
    return lista->getFirst();
  }

	bool filaVazia() {
    return lista->listaVazia();
  }

	void limparFila() {
    lista->~ListaEnc();
  }
};
