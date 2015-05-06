/* Copyright [2015] <LeoSL e marcelinol>
 * ControladorDeEventos.hpp
 */

#ifndef CHEGASEMAFORO_HPP
#define CHEGASEMAFORO_HPP

#ifndef NULL
#define NULL   ((void *) 0)
#endif

#include "Evento.cpp"
#include "Pista.cpp"
#include "GeraSemaforo.cpp"
#include "CriaCarro.cpp"
#include "Pilha.cpp"
#include "Carro.cpp"
#include "ControladorDeEventos.cpp"
//  #include "Lista.cpp"

#define TEMPOSEMAFORO 15

class ChegaSemaforo : public Evento {
private:
  Carro carro;
  double tempo;
  Pista pista;
  Pista pistaDestino;
public:

  ChegaSemaforo(Carro carro, double tempo, Pista pista, Pista pistaDestino) {
    this->carro = carro;
    this->tempo = tempo;
    this->pista = pista;
    setPistaDestino(pistaDestino);
  }

  double getTime() {
    return this->tempo;
  }

  void executa() {
    tentaCruzar();
  }

  void setPistaDestino(Pista pistaDestino) {
    if (pistaDestino == NULL) {
      this->pistaDestino = this->pista.getPistaAleatoria();
    }

    this->pistaDestino = pistaDestino;
  }

  void tentaCruzar() {
    if (pistaAberta() && !pistaDestinoLotada(pistaDestino)) {
      criaCarroNaPistaDestino(carro);
      pista.retira();  //  FILA NAO PODE TER retiraEspecifico
    } else {
      double tempo = this->tempo + TEMPOSEMAFORO;
      ChegaSemaforo* novoChegaSemaforo = new ChegaSemaforo(carro, tempo, this->pista, this->pistaDestino); // Cria um novo evento Chega Semaforo para this->tempo + TEMPOSEMAFORO
      controladorDeEventos->addTimelineEvent(novoChegaSemaforo);  //  CRIAR A TIMELINE NO MAIN E ADICIONAR DIRETAMENTE NELA? - esse controlador de eventos nao é conhecido aqui
    }
  }

  void criaCarroNaPistaDestino(Carro carro) {
    pistaDestino.inclui(carro);
    if(pistaDestino.isSumidouro()) {
      pistaDestino.retira();
      //  controladorDeEventos->carroOut();
    } else {
      //  criaEventoChegaSemaforo(carro, pistaDestino);
    }
  }

  void criaEventoChegaSemaforo(Pista pista) {
    double tempoDePercorrimento = pista.getTempoPercorrimento();
    double tempoChegada = this->tempo + tempoDePercorrimento;
    //  Evento chegaSemaforo = new ChegaSemaforo(carro, tempoChegada, pista, NULL);
    //  controladorDeEventos->addTimelineEvent(chegaSemaforo);
  }

  bool pistaAberta() {
    return this->pista.getStatus();
  }

  bool pistaDestinoLotada(Pista pistaDestino) {
    return pistaDestino.lotada();
  }
};
#endif
