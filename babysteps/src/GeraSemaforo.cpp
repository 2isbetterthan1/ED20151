/* Copyright [2015] <LeoSL e marcelinol>
 * ControladorDeEventos.hpp
 */

#ifndef GERASEMAFORO_HPP
#define GERASEMAFORO_HPP

#include "Pista.cpp"
#include "Evento.cpp"
//#include "ControladorDeEventos.hpp"

class GeraSemaforo : public Evento {
private:
  double tempo;

public:
  GeraSemaforo(double time) {
    this->tempo = tempo;
  }

  double getTime() {
    return this->tempo;
  }

  void executa() {
    trocaStatusPistas();
  }

  void trocaStatusPistas() {
	int estado = 1;
    //  int estado = controladorDeEventos->getEstadoSemaforos();

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

  void estadoA() {
  //   trocaEstadoPista(1);
  //   trocaEstadoPista(3);
  //   trocaEstadoPista(4);
  //   trocaEstadoPista(6);
  //   controladorDeEventos->setEstadoSemaforos(2);
  }
  //
  void estadoB() {
  //   trocaEstadoPista(8);
  //   trocaEstadoPista(3);
  //   trocaEstadoPista(4);
  //   trocaEstadoPista(11);
  //   controladorDeEventos->setEstadoSemaforos(3);
  }
  //
  void estadoC() {
  //   trocaEstadoPista(11);
  //   trocaEstadoPista(10);
  //   trocaEstadoPista(13);
  //   trocaEstadoPista(8);
  //   controladorDeEventos->setEstadoSemaforos(4);
  }
  //
  void estadoD() {
  //   trocaEstadoPista(1);
  //   trocaEstadoPista(10);
  //   trocaEstadoPista(13);
  //   trocaEstadoPista(4);
  //   controladorDeEventos->setEstadoSemaforos(1);
  }
  //
  void trocaEstadoPista(int indice) {
  //   Pista pista = listaDePistas->encontraNaPosicao(indice);
  //   pista->switchStatus();
  }
};
#endif
