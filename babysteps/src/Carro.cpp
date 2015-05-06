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
	float tamanho;
public:
	Carro() {
		this->tamanho = setTamanho();
	}

	float setTamanho() {
		srand(time(NULL));
		int tamanhoCarro = 2 + rand() % 8;
		float tamanhoOcupado = (float) (tamanhoCarro + 3);
		return tamanhoOcupado;
	}

	~Carro() {

	}
};
#endif
