#define TEMPOSEMAFORO 15

controladorDeEventos() {

private:
  int tempoTotal;
  int tempoSemaforo = TEMPOSEMAFORO;

public:
  controladorDeEventos(tempoTotal) {
    this->tempoTotal = tempoTotal;
  }


  CriaLinhaDoTempo() {
    ListaEnc linhaDoTempo = new ListaEnc<Evento>();
  }

  InicializaPista() {
    Fila p1 = new Fila<Carro>(...);
    p1.criaPilhaAleatoria(8, 1, 1, p2, p3, p4);
    (p2,p3,p4...)
  }

  GeraEventosIniciais() {
    geraSemaforos();
    geraCarros();
  }

  geraSemaforos() {
    int tempoCorrente = 0;
    while(tempoCorrente < tempoTotal) {
      GeraSemaforo semaforo = new GeraSemaforo(tempoCorrente);
      linhaDoTempo->adicionaEmOrdem(semaforo);
      tempoCorrente += tempoSemaforo;
    }
  }

  geraCarros() {
    // int ordemCronologica = 0;
    // while(ordemCronologica < 15) {
    //   GeraCarro carro1 = new geraCarro(p1, ordemCronologica);
    //   linhaDoTempo->adicionaEmOrdem(carro1);
    //   ordemCronologica += 5;
    // }

    GeraCarro carro1 = new geraCarro(p1, 0);
    linhaDoTempo->adicionaEmOrdem(carro1)

    GeraCarro carro2 = new geraCarro(p2, 0);
    linhaDoTempo->adicionaEmOrdem(carro2);
    (p3, p4, ...)
  }




}

abstract Evento() {
  Evento() { }
}

GeraCarro() : Evento() {

private:
  int tempo;
  Pista pista;
public:
  GeraCarro(pista, tempo) {
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
      GeraCarro novoCarro = new GeraCarro(pista, proximoTempo);
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
