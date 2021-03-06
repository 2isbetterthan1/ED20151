/* Copyright [2015] <LeoSL e marcelinol>
 * ControladorDeEventos.hpp
 */

#ifndef CRIACARRO_HPP
#define CRIACARRO_HPP

#ifndef NULL
#define NULL   ((void *) 0)
#endif

#include "Evento.cpp"
#include "Pista.cpp"
#include "GeraSemaforo.cpp"
#include "Pilha.cpp"
#include "Carro.cpp"
#include "ControladorDeEventos.cpp"
#include "ChegaSemaforo.cpp"

class CriaCarro : public Evento {
private:
  double tempo;
  Pista pista;
  Carro carro;

public:

  /**
  * Construtor. Construtor de um evento CriaCarro.
  */
  CriaCarro(Pista pista, double tempo) {
    this->tempo = tempo;
    this->pista = pista;
  }

  double getTime() {
    return this->tempo;
  }

  void executa() {
	carro = Carro();
    if(!pistaDestinoLotada(this->pista)) {
      insereCarro();
      criaEventoChegaSemaforo();
    }
    geraProximoCarro();
  }

  /**
  * Função pistaDestinoLotada. Retorna true se a pista de destino não tiver
  * espaço para o carro, false se tiver espaço.
  */
  bool pistaDestinoLotada(Pista pistaDestino) {
    return pistaDestino.lotada(carro.getSize());
  }

  /**
  * Função insereCarro. Cria um novo carro e adiciona ele na pista.
  */
  void insereCarro() {
    pista.inclui(carro);
    controladorDeEventos->carroIn();
  }

  /**
  * Função geraProximoCarro. Cria um novo evento de criação de carro e insere-o
  * na linha do tempo.
  */
  void geraProximoCarro() {
    double proximoTempo = tempo + pista.getFrequenciaEntradaDeCarros();

    if(proximoTempo < controladorDeEventos->tempoTotal) {
      CriaCarro novoCriaCarro = CriaCarro(pista, proximoTempo);
      controladorDeEventos->addTimelineEvent(novoCriaCarro);
    }
  }

  /**
  * Função criaEventoChegaSemaforo. Cria um evento de chegada do carro no
  * semáforo e insere-o na linha do tempo.
  */
  void criaEventoChegaSemaforo() {
    double tempoDePercorrimento = pista.getTempoPercorrimento();
    double tempoChegada = this->tempo + tempoDePercorrimento;
    Pista pistaDestino = pista.getPistaAleatoria();

    ChegaSemaforo chegaSemaforo = ChegaSemaforo(carro, tempoChegada, pista, pistaDestino);

    controladorDeEventos->addTimelineEvent(chegaSemaforo);
  }
};
#endif
