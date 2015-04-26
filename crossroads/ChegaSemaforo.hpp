#define TEMPOSEMAFORO 15
ChegaSemaforo() : Evento() {
private:
  Carro carro;
  double tempo;
  Pista pista;
  Pista pistaDestino;
public:

  ChegaSemaforo(Carro carro, double tempo, Pista pista) {
    this->carro = carro;
    this->tempo = tempo;
    this->pista = pista;
    pistaDestino = pista->getPistaAleatoria();
    podeCruzar(pistaDestino);
  }

  void podeCruzar(Pista pistaDestino) {
    if (pistaAberta() && !pistaDestinoLotada(pistaDestino)) {
      pistaDestino->adiciona(carro); // Adiciona carro na pista pistaDestino
      pistaDestino->retira(carro); // Retira carro da pista original
    } else {
      double tempo = this->tempo + TEMPOSEMAFORO;
      ChegaSemaforo novoChegaSemaforo = new ChegaSemaforo(carro, tempo, this->pista); // Cria um novo evento Chega Semaforo para this->tempo + TEMPOSEMAFORO
    }
  }

  bool pistaAberta() {
    return this->pista->getStatus();
  }

  bool pistaDestinoLotada(Pista pistaDestino) {
    return pistaDestino->lotada();
  }
}