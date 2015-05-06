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
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;



Fila criaFila() {
	Fila fila = Fila(10);
	return fila;
}

int main() {
	srand(time(NULL));

	return 0;
}

