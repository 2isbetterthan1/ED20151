#define TEMPOSEMAFORO 15

controladorDeEventos() {

private:
  int tempoTotal;
  int tempoSemaforo = TEMPOSEMAFORO;

public:
  controladorDeEventos(tempoTotal) {
    this->tempoTotal = tempoTotal;
    setup();
  }

  setup() {
    criaLinhaDoTempo();
    inicializaPistas();
    geraEventosIniciais();
  }


  criaLinhaDoTempo() {
    ListaEnc linhaDoTempo = new ListaEnc<Evento>();
  }

  inicializaPistas() {
    Pista p1 = new Pista<Carro>(...);
    p1->criaPilhaAleatoria(8, 1, 1, p2, p3, p4);
    geraCriaCarros(p1);
    (p2,p3,p4...)
  }

  geraEventosIniciais() {
    geraSemaforos();
    geraCriaCarros();
  }

  geraSemaforos() {
    int tempoCorrente = 0;
    while(tempoCorrente < tempoTotal) {
      GeraSemaforo semaforo = new GeraSemaforo(tempoCorrente);
      linhaDoTempo->adicionaEmOrdem(semaforo);
      tempoCorrente += tempoSemaforo;
    }
  }

  geraCriaCarros(Pista pista) {
    CriaCarro carro1 = new CriaCarro(p1, 0);
    linhaDoTempo->adicionaEmOrdem(carro1)

    // CriaCarro carro2 = new CriaCarro(p2, 0);
    // linhaDoTempo->adicionaEmOrdem(carro2);
    // (p3, p4, ...)
  }




}

abstract Evento() {
  Evento() { }
}

CriaCarro() : Evento() {

private:
  int tempo;
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
    int proximoTempo = tempo + pista->getFrequenciaAddCarro();

    if(proximoTempo < tempoTotal) { //  VERIFICAR SE TEMOS ACESSO AO TEMPO TOTAL.
      CriaCarro novoCarro = new CriaCarro(pista, proximoTempo);
    }
  }

}

GeraSemaforo(int tempo) : Evento() {
private:
  int tempo;

public:
  GeraSemaforo(tempo) {
    this->tempo = tempo;
  }


}

ChegaSemaforo() : Evento() {

}

Cruza() : Evento() {

}



Pista() {

  int frequenciaEntradaDeCarros;

  criaPilhaAleatoriaX(prob1, prob2, prob3, primeiraOpcao, segundaOpcao, terceiraOpcao) {
    Pilha aleatorio = new Pilha;
    for(prob1) {
      aleatorio.empilha(primeiraOpcao);
    }
    for(prob2) {
      aleatorio.empilha(segundaOpcao);
    }
    for(prob3) {
      aleatorio.empilha(terceiraOpcao);
    }
    return aleatorio
  }

}

Carro() {}
