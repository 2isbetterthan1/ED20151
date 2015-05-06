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

#define TEMPOSEMAFORO 15

class ChegaSemaforo : public Evento {
private:
  Carro carro;
  double tempo;
  Pista pista;
  Pista* pistaDestino;
public:
  /**
  * Construtor. Construtor de um ChegaSemaforo.
  */
  ChegaSemaforo(Carro carro, double tempo, Pista pista, Pista* pistaDestino) {
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

  /**
  * Função setPistaDestino. Determina, aleatoriamente, a pista para o qual
  * o carro vai virar. Se a pista atual for um sumidouro, não faz nada.
  */
  void setPistaDestino(Pista pistaDestino) {
    if (pistaDestino != NULL) {
      this->pistaDestino = this->pista.getPistaAleatoria();
    }
    this->pistaDestino = pistaDestino;
  }

  /**
  * Função tentaCruzar. Verifica se a pista atual está com o semáforo aberto
  * e se a pista de destino tem espaço para o carro. Caso seja possível,
  * retira o carro da pista atual e insere-o na pista de destino.
  */
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

  /**
  * Função criaCarroNaPistaDestino. Insere o carro na pista de destino.
  * Se a pista de destino for sumidouro, já exclui o carro e acrescenta na
  * contagem de carros retirados.
  */
  void criaCarroNaPistaDestino(Carro carro) {
    pistaDestino.inclui(carro);
    if(pistaDestino.isSumidouro()) {
      pistaDestino.retira();
      controladorDeEventos->carroOut();
    } else {
      criaEventoChegaSemaforo(carro, pistaDestino);
    }
  }

  /**
  * Função criaEventoChegaSemaforo. Cria um novo evento de chegaSemaforo.
  * Utilizado quando não for possível cruzar. (Reagenda o cruzamento)
  */
  void criaEventoChegaSemaforo(Pista pista) {
    double tempoDePercorrimento = pista.getTempoPercorrimento();
    double tempoChegada = this->tempo + tempoDePercorrimento;
    Evento chegaSemaforo = new ChegaSemaforo(carro, tempoChegada, pista, NULL);
    controladorDeEventos->addTimelineEvent(chegaSemaforo);
  }

  /**
  * Função pistaAberta. Informa se a pista que o carro está inserido está
  * com o semáforo aberto.
  */
  bool pistaAberta() {
    return this->pista.getStatus();
  }

  /**
  * Função pistaDestinoLotada. Verifica se há espaço para o carro na pista de
  * destino.
  */
  bool pistaDestinoLotada(Pista pistaDestino) {
    float tamanhoCarro = carro.getSize();
    return pistaDestino.lotada(tamanhoCarro);
  }
};
#endif
