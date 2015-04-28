#define TEMPOSEMAFORO 15
class ChegaSemaforo() : public Evento() {
private:
  Carro carro;
  double tempo;
  Pista pista;
  Pista pistaDestino;
public:

// se ele receber a pista aleatoria, nao pegar uma nova.
// Quando o evento for reagendado ele deve usar a mesma pista do evento original
  ChegaSemaforo(Carro carro, double tempo, Pista pista, Pista pistaDestino) {
    this->carro = carro;
    this->tempo = tempo;
    this->pista = pista;
    setPistaDestino(pistaDestino);

    podeCruzar(pistaDestino);
  }

  double getTime() {
    return this->tempo;
  }

  void setPistaDestino(Pista pistaDestino) {
    if (pistaDestino == NULL) {
      this->pistaDestino = this->pista->getPistaAleatoria();
    }

    this->pistaDestino = pistaDestino;
  }

  void podeCruzar(Pista pistaDestino) {
    if (pistaAberta() && !pistaDestinoLotada(pistaDestino)) {
      pistaDestino->adiciona(carro); // Adiciona carro na pista pistaDestino
      pistaDestino->elimina(carro); // Retira carro da pista original ---- temos função elimina?
    } else {
      double tempo = this->tempo + TEMPOSEMAFORO;
      ChegaSemaforo novoChegaSemaforo = new ChegaSemaforo(carro, tempo, this->pista, this->pistaDestino); // Cria um novo evento Chega Semaforo para this->tempo + TEMPOSEMAFORO
    }
  }

  bool pistaAberta() {
    return this->pista->getStatus();
  }

  bool pistaDestinoLotada(Pista pistaDestino) {
    return pistaDestino->lotada();
  }
}