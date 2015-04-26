CriaCarro() : Evento() {

private:
  double tempo;
  Pista pista;
public:
  CriaCarro(pista, tempo) {
    this->tempo = tempo;
    this->pista = pista;
  }

  insereCarro() {
    Carro carro = new Carro();
    pista->adiciona(carro);
  }

  geraProximoCarro() {
    double proximoTempo = tempo + pista->getFrequenciaAddCarro();

    if(proximoTempo < controladorDeEventos->tempoTotal) { //  VERIFICAR SE TEMOS ACESSO AO TEMPO TOTAL.
      CriaCarro novoCarro = new CriaCarro(pista, proximoTempo);
    }
  }

  criaEventoChegaSemaforo() {
    double tempoDePercorrimento = pista->getTempoPercorrimento();
    double tempoChegada = this->tempo + tempoDePercorrimento;
    Evento chegaSemaforo = new ChegaSemaforo(Carro carro, double tempoChegada, Pista pista);
    controladorDeEventos->addTimelineEvent(chegaSemaforo);
  }

}