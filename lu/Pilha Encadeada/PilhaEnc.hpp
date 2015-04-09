/* Copyright [2015] <marcelinol>
 * PilhaEnc.hpp
 */


#ifndef PILHAENC_HPP
#define PILHAENC_HPP

#include "Elemento.hpp"
// #include "ListaEnc.hpp"
class ListaEnc;
template<typename T>
class PilhaEnc: private ListaEnc {
 public:
    PilhaEnc() : ListaEnc() {}
    ~PilhaEnc() {
      limparPilha();
    }
    void empilha(const T& dado): adicionaNoInicio(const T& dado) {}
    T desempilha(): retiraDoInicio() {}
	T topo() {
    // implementar
  }
	void limparPilha(): ~ListaEnc() {}
	bool PilhaVazia(): listaVazia() {}
};

#endif
