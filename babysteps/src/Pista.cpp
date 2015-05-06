/* Copyright [2015] <LeoSL and marcelinol>
 * Pista.hpp
 */


#ifndef PISTA_HPP
#define PISTA_HPP
#define TAMANHOMAXIMOCARRO 11

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

  /**
  * Construtor. Construtor de uma pista.
  */
  Pista(bool aberta, bool sumidouro, double frequenciaEntradaDeCarros, double tamanho, double velocidade) {
    this->aberta = aberta;
    this->sumidouro = sumidouro;
    this->frequenciaEntradaDeCarros = frequenciaEntradaDeCarros;
    this->tamanho = tamanho;
    this->velocidade = velocidade;
    setTempoPercorrimento();
    Pilha<Pista>* aleatorio = new Pilha<Pista>(14);
  }

  /**
  * Função setTempoPercorrimento. Determina o tempo que um carro levará
  * para percorrer a pista.
  */
  void setTempoPercorrimento() {
    this->tempoPercorrimento = (this->tamanho)/(this->velocidade);
  }

  /**
  * Função getFrequenciaEntradaDeCarros. Informa a frequência com que os carros
  * devem ser criados. (Usada somente para pistas fontes)
  */
  double getFrequenciaEntradaDeCarros () {
    return this->frequenciaEntradaDeCarros;
  }

  /**
  * Função isSumidouro. Informa se a pista é do tipo sumidouro.
  */
  bool isSumidouro() {
    return this->sumidouro;
  }

  /**
  * Função getTempoPercorrimento. Informa o tempo que um carro leva para
  * percorrer a pista.
  */
  double getTempoPercorrimento() {
    return this->tempoPercorrimento;
  }

  /**
  * Função getStatus. Informa se o semáforo da pista está aberto.
  */
  bool getStatus() {
    return this->aberta;
  }

  /**
  * Função lotada. Informa se há espaço para determinado tamanho de carro
  * na pista.
  */
  bool lotada(float tamanhoCarro) {
    double ocupado = ocuppied();
    return tamanhoCarro > (tamanho - ocupado);
  }

  /**
  * Função ocuppied. Informa o total de espaço ocupado na pista.
  */
  float ocuppied() {
    float sizes = 0;
    Carro currentCar;
    for (int i = 0; i < this->getUltimo(); i++) {
      currentCar = this.encontra(i);
      sizes += currentCar.getSize();
    }
    return sizes;
  }

  /**
  * Função criaPilhaAleatoria. Cria uma pilha com as possíveis pistas de destino
  * Para cada 10% de chance de a pista destino ser escolhida, há um elemento na
  * pilha.
  */
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

  /**
  * Função getPistaAleatoria. Retorna uma pista de destino "aleatoria" com base
  * nas porcentagens definidas.
  */
  Pista getPistaAleatoria() {
	srand(time(NULL));
    int indicePistaDestino = rand() % 10;
    return aleatorio->encontra(indicePistaDestino);
  }

  /**
  * Função switchStatus. Troca o estado do semáforo da pista(fechado <-> aberto)
  */
  void switchStatus() {
    this->aberta = !getStatus();
  }
};
#endif
