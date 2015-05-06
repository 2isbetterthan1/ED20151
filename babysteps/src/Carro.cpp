/* Copyright [2015] <LeoSL>
 * Fila.hpp
 */
#ifndef CARRO_HPP
#define CARRO_HPP

#include <iostream>
#include <cstdlib>
#include <time.h>

class Carro {
private:
	double tamanho;
public:

	/**
	* Construtor. Construtor de um carro.
	*/
	Carro() {
		setTamanho();
	}

	/**
  * Função setTamanho. Determina o tamanho ocupado pelo carro. Esse tamanho é
	* determinado por um número aleatório entre 2 e 8, mais 1 metro a frente do
	* carro e 2 metros atrás.
  */
	void setTamanho() {
		srand(time(NULL));
		int tamanhoCarro = 2 + rand() % 8;
		double tamanhoOcupado = (double) (tamanhoCarro + 3);
		this->tamanho = tamanhoOcupado;
	}

	double getSize() {
		return this->tamanho;
	}

	/**
  * Destrutor. Destrutor de um carro.
  */
	~Carro() {
	}
};
#endif
