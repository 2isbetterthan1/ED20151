//============================================================================
// Name        : babysteps.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>

#include "Pilha.cpp"
#include "Fila.cpp"
#include "Carro.cpp"
#include "Pista.cpp"

using namespace std;



Fila criaFila() {
	Fila fila = Fila(10);
	return fila;
}

int main() {

	Carro carro = Carro();
	Fila fila = criaFila();
	fila.inclui(carro);
	Carro retirado = fila.retira();

	return 0;
}

