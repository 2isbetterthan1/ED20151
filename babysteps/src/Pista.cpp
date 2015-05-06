/* Copyright [2015] <LeoSL and marcelinol>
 * Pista.hpp
 */


#ifndef PISTA_HPP
#define PISTA_HPP
#define TAMANHOCARRO 7

#include "Fila.cpp"
#include "Pilha.cpp"
#include "PilhaEnc.cpp"
#include <iostream>
#include <cstdlib>
#include <time.h>


class Pista : public Fila {
private:
  bool aberta;
  bool sumidouro;
  double frequenciaEntradaDeCarros;
  double tamanho;     //  EM METROS
  double velocidade;  //  EM METROS POR SEGUNDO
  double tempoPercorrimento;
  Pilha<Pista>* aleatorio;
public:

  Pista(bool aberta, bool sumidouro, double frequenciaEntradaDeCarros, double tamanho, double velocidade) {
      this->aberta = aberta;
      this->sumidouro = sumidouro;
      this->frequenciaEntradaDeCarros = frequenciaEntradaDeCarros;
      this->tamanho = tamanho;
      this->velocidade = velocidade;
      setTempoPercorrimento();
      Pilha<Pista>* aleatorio = new Pilha<Pista>(14);
    }

  void setTempoPercorrimento() {
    this->tempoPercorrimento = (this->tamanho)/(this->velocidade);
  }

  double getFrequenciaEntradaDeCarros () {
    return this->frequenciaEntradaDeCarros;
  }

  bool isSumidouro() {
    return this->sumidouro;
  }

  double getTempoPercorrimento() {
    return this->tempoPercorrimento;
  }

  bool getStatus() {
    return this->aberta;
  }

  bool lotada() {
    int tamanhoDaFila = this->getUltimo();
    double ocupado = tamanhoDaFila*(TAMANHOCARRO + 3);
    return ocupado > (tamanho - (TAMANHOCARRO + 3));
  }


  void criaPilhaAleatoria(int prob1, int prob2, int prob3, Pista primeiraOpcao, Pista segundaOpcao, Pista terceiraOpcao) {

    for (int i = 0; i < prob1; i++) {
      aleatorio->empilha(primeiraOpcao);
    }

    for (int i = 0; i < prob2; i++) {
      aleatorio->empilha(segundaOpcao);
    }

    for (int i = 0; i < prob2; i++) {
      aleatorio->empilha(terceiraOpcao);
    }
  }

  Pista getPistaAleatoria() {
	srand(time(NULL));
    int indicePistaDestino = rand() % 10;
    return aleatorio->encontra(indicePistaDestino);
  }

  void switchStatus() {
    this->aberta = !getStatus();
  }



};
#endif
