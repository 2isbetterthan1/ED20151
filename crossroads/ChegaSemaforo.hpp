/* Copyright [2015] <LeoSL e marcelinol>
 * ControladorDeEventos.hpp
 */

 #include "ControladorDeEventos.hpp"
 #include "Evento.hpp"
 #include "Pista.hpp"
 #include "GeraSemaforo.hpp"
 #include "CriaCarro.hpp"
 #include "Pilha.hpp"
 #include "Carro.hpp"
 #include "FilaEnc.hpp"
 #include "ListaEnc.hpp"
 #include "Lista.hpp"

#define TEMPOSEMAFORO 15

class ChegaSemaforo : public Evento() {
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
      this->pistaDestino = this->pista->getPistaAleatoria();
    }

    this->pistaDestino = pistaDestino;
  }

  void tentaCruzar() {
    if (pistaAberta() && !pistaDestinoLotada(pistaDestino)) {
      criaCarroNaPistaDestino(carro);
      pista->retiraEspecifico(carro);
    } else {
      double tempo = this->tempo + TEMPOSEMAFORO;
      ChegaSemaforo novoChegaSemaforo = new ChegaSemaforo(carro, tempo, this->pista, this->pistaDestino); // Cria um novo evento Chega Semaforo para this->tempo + TEMPOSEMAFORO
    }
  }

  void criaCarroNaPistaDestino(Carro carro) {
    pistaDestino->adiciona(carro);å
    if(pistaDestino->isSumidouro()) {
      pistaDestino->retiraEspecifico(carro);
      controladorDeEventos->carroOut();
    } else {
      criaEventoChegaSemaforo(carro, pistaDestino);
    }
  }

  void criaEventoChegaSemaforo(Pista pista) {
    double tempoDePercorrimento = pista->getTempoPercorrimento();
    double tempoChegada = this->tempo + tempoDePercorrimento;
    Evento chegaSemaforo = new ChegaSemaforo(carro, tempoChegada, pista, NULL);
    controladorDeEventos->addTimelineEvent(chegaSemaforo);
  }

  bool pistaAberta() {
    return this->pista->getStatus();
  }

  bool pistaDestinoLotada(Pista pistaDestino) {
    return pistaDestino->lotada();
  }
}
