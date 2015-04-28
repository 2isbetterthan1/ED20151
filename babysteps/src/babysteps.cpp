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

using namespace std;


Pilha criaPilha() {
	Pilha pilha = Pilha(10);
	return pilha;
}

Fila criaFila() {
	Fila fila = Fila(10);
	return fila;
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Pilha p = criaPilha();
	p.empilha(1);
	int primeiro = p.desempilha();

	Carro carro = Carro();
	Fila fila = criaFila();
	fila.inclui(carro);
	Carro retirado = fila.retira();

	cout << primeiro << endl; // prints !!!Hello World!!!
	return 0;
}

