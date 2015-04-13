/* Copyright [2015] <marcelinol>
 * PilhaEnc.hpp
 */

#ifndef PILHAENC_HPP
#define PILHAENC_HPP

#include "Elemento.hpp"
#include "ListaEnc.hpp"

template<typename T>
class PilhaEnc: private ListaEnc<T> {
 public:
    PilhaEnc(): ListaEnc() {}
    ~PilhaEnc() {
      limparPilha();
    }
    void empilha(const T& dado): adicionaNoInicio(const T& dado) {}
    T desempilha(): retiraDoInicio() {}
	T topo() {
    return;  // implementar
  }
	void limparPilha(): ~ListaEnc() {}
	bool PilhaVazia(): listaVazia() {}
};

#endif
