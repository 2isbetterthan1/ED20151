CriaCarro() : public Evento() {

private:
  double tempo;
  Pista pista;
public:
  CriaCarro(pista, tempo) {
    this->tempo = tempo;
    this->pista = pista;
  }

  void insereCarro() {
    Carro carro = new Carro();
    pista->adiciona(carro);
  }

  void geraProximoCarro() {
    double proximoTempo = tempo + pista->getFrequenciaEntradaDeCarros();

    if(proximoTempo < controladorDeEventos->tempoTotal) { //  VERIFICAR SE TEMOS ACESSO AO TEMPO TOTAL.
      CriaCarro novoCarro = new CriaCarro(pista, proximoTempo);
    }
  }

  void criaEventoChegaSemaforo() {
    double tempoDePercorrimento = pista->getTempoPercorrimento();
    double tempoChegada = this->tempo + tempoDePercorrimento;
    Evento chegaSemaforo = new ChegaSemaforo(Carro carro, double tempoChegada, Pista pista, NULL);
    controladorDeEventos->addTimelineEvent(chegaSemaforo);
  }

}