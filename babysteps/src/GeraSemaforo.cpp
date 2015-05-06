/* Copyright [2015] <LeoSL e marcelinol>
 * ControladorDeEventos.hpp
 */

#ifndef GERASEMAFORO_HPP
#define GERASEMAFORO_HPP

#include "Pista.cpp"
#include "Evento.cpp"
#include "ControladorDeEventos.cpp"

class GeraSemaforo : public Evento {
private:
  double tempo;

public:

  /**
  * Construtor. Construtor de um evento GeraSemaforo.
  */
  GeraSemaforo(double time) {
    this->tempo = tempo;
  }

  double getTime() {
    return this->tempo;
  }

  void executa() {
    trocaStatusPistas();
  }

  /**
  * Função trocaStatusPistas. Passa de um cenário para o próximo (cenário da
  * simulação com relação aos semáforos).
  */
  void trocaStatusPistas() {
	int estado = controladorDeEventos->getEstadoSemaforos();

    switch(estado) {
      case 1:
        estadoA();
        break;
      case 2:
        estadoB();
        break;
      case 3:
        estadoC();
        break;
      case 4:
        estadoD();
        break;
      default:
        break;
      }

  }

  /**
  * Função estadoA.
  * Abre os semáforos das pistas 4 e 6.
  * Fecha os semáforos das pistas 1 e 3.
  */
  void estadoA() {
    trocaEstadoPista(1);
    trocaEstadoPista(3);
    trocaEstadoPista(4);
    trocaEstadoPista(6);
    controladorDeEventos->setEstadoSemaforos(2);
  }

  /**
  * Função estadoB.
  * Abre os semáforos das pistas 8 e 11.
  * Fecha os semáforos das pistas 4 e 6.
  */
  void estadoB() {
    trocaEstadoPista(8);
    trocaEstadoPista(3);
    trocaEstadoPista(4);
    trocaEstadoPista(11);
    controladorDeEventos->setEstadoSemaforos(3);
  }

  /**
  * Função estadoC.
  * Abre os semáforos das pistas 10 e 13.
  * Fecha os semáforos das pistas 8 e 11.
  */
  void estadoC() {
    trocaEstadoPista(11);
    trocaEstadoPista(10);
    trocaEstadoPista(13);
    trocaEstadoPista(8);
    controladorDeEventos->setEstadoSemaforos(4);
  }

  /**
  * Função estadoD.
  * Abre os semáforos das pistas 1 e 3.
  * Fecha os semáforos das pistas 10 e 13.
  */
  void estadoD() {
    trocaEstadoPista(1);
    trocaEstadoPista(10);
    trocaEstadoPista(13);
    trocaEstadoPista(4);
    controladorDeEventos->setEstadoSemaforos(1);
  }

  /**
  * Função trocaEstadoPista. Fecha uma pista se ela estiver aberta, abre se ela
  * estiver fechada.
  */
  void trocaEstadoPista(int indice) {
    Pista pista = listaDePistas->encontraNaPosicao(indice);
    pista->switchStatus();
  }
};
#endif
