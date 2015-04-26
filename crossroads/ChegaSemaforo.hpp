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
  }

  bool podeCruzar() {
    if (pistaAberta() && !pistaDestinoLotada(pistaDestino)) {
      // Adiciona carro na pista pistaDestino
      // Deleta carro da pista original
    } else {
      // Cria um novo evento Chega Semaforo para this->tempo + TEMPOSEMAFORO
    }
  }

  bool pistaAberta() {
    return pista->getStatus();
  }

  bool pistaDestinoLotada(Pista pista) {
    return pista->lotada();
  }
}