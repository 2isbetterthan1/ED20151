/* Copyright [2015] <marcelinol>
 * PilhaEnc.hpp
 */

#ifndef PILHAENC_HPP
#define PILHAENC_HPP


#include "Elemento.hpp"
#include "ListaEnc.hpp"

template<typename T>
class PilhaEnc: public ListaEnc<T> {
 private:
  ListaEnc<T>* lista;

 public:
     PilhaEnc(): ListaEnc<T>::ListaEnc() {
       lista = new ListaEnc<T>();
     }

    ~PilhaEnc() {
      limparPilha();
    }

    void empilha(const T& dado) {
      lista->adicionaNoInicio(dado);
    }

    T desempilha() {
      return lista->retiraDoInicio();
    }

	T topo() {
    return lista->getFirst();
  }

	void limparPilha() {
      lista->~ListaEnc();
  }

	bool PilhaVazia() {
      return lista->listaVazia();
  }
};

#endif
