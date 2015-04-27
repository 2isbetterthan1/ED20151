/* Copyright [2015] <LeoSL e marcelinol>
 * ControladorDeEventos.hpp
 */
#define TEMPOSEMAFORO 15
ControladorDeEventos() {

private:
  double tempoTotal;
  double tempoSemaforo = TEMPOSEMAFORO;
  int estadoSemaforos = 1;
  Lista<Pista> listaDePistas;
  Lista<Evento> linhaDoTempo;

public:
  ControladorDeEventos(tempoTotal) { // herdar listas
    this->tempoTotal = tempoTotal;
    setup();
  }

  setup() {
    inicializaPistas();
    geraEventosIniciais();
  }

  inicializaPistas() {
    listaDePistas = new Lista<Pista>();
    
    // Via O1leste (1)
    Pista p1 = new Pista<Carro>(..., sumidouro = false);
    geraCriaCarros(p1);

    // Via S1Sul (2)
    Pista p2 = new Pista<Carro>(..., sumidouro = true);
    geraCriaCarros(p2);

    // Via S1norte (3)
    Pista p3 = new Pista<Carro>(..., sumidouro = false);
    geraCriaCarros(p3);

    // Via C1leste (4) << PISTA ESPECIAL, POIS NÃO PODE CHAMAR CRIA CARRO!
    Pista p4 = new Pista<Carro>(..., sumidouro = false);
    geraCriaCarros(p4);

    // Via S2Sul (5)
    Pista p5 = new Pista<Carro>(..., sumidouro = true);
    geraCriaCarros(p5);

    // Via S2Norte (6)
    Pista p6 = new Pista<Carro>(..., sumidouro = false);
    geraCriaCarros(p6);

    // Via L1leste (7)
    Pista p7 = new Pista<Carro>(..., sumidouro = true);
    geraCriaCarros(p7);

    // Via L1oeste (8)
    Pista p8 = new Pista<Carro>(..., sumidouro = false);
    geraCriaCarros(p8);

    // Via N2norte (9)
    Pista p9 = new Pista<Carro>(..., sumidouro = true);
    geraCriaCarros(p9);

    // Via N2sul (10)
    Pista p10 = new Pista<Carro>(..., sumidouro = false);
    geraCriaCarros(p10);

    // Via C1oeste (11) << PISTA ESPECIAL, POIS NÃO PODE CHAMAR CRIA CARRO!
    Pista p11 = new Pista<Carro>(..., sumidouro = false);
    geraCriaCarros(p11);

    // Via N1norte (12)
    Pista p12 = new Pista<Carro>(..., sumidouro = true);
    geraCriaCarros(p13);

    // Via N1sul (13)
    Pista p13 = new Pista<Carro>(..., sumidouro = false);
    geraCriaCarros(p13);

    // Via O1oeste (14)
    Pista p14 = new Pista<Carro>(..., sumidouro = true);
    geraCriaCarros(p14);

    // Cria pilha de possibilidades de conversão para cada pista
    p1->criaPilhaAleatoria(8, 1, 1, p4, p2, p12);
    p3->criaPilhaAleatoria(8, 1, 1, p4, p12, p14);
    p4->criaPilhaAleatoria(4, 3, 3, p7, p9, p5);
    p6->criaPilhaAleatoria(4, 3, 3, p7, p9, p11);
    p8->criaPilhaAleatoria(4, 3, 3, p9, p5, p11);
    p10->criaPilhaAleatoria(4, 3, 3, p7, p11, p5);
    p11->criaPilhaAleatoria(4, 3, 3, p14, p12, p2);
    p13->criaPilhaAleatoria(8, 1, 1, p4, p14, p2);

    // adiciona as pistas prontas na lista de pistas
    listaDePistas->adiciona(p1);
    listaDePistas->adiciona(p2);
    listaDePistas->adiciona(p3);
    listaDePistas->adiciona(p4);
    listaDePistas->adiciona(p5);
    listaDePistas->adiciona(p6);
    listaDePistas->adiciona(p7);
    listaDePistas->adiciona(p8);
    listaDePistas->adiciona(p9);
    listaDePistas->adiciona(p10);
    listaDePistas->adiciona(p11);
    listaDePistas->adiciona(p12);
    listaDePistas->adiciona(p13);
    listaDePistas->adiciona(p14);
  }

  geraEventosIniciais() {
    linhaDoTempo = new Lista<Evento>();
    geraSemaforos();
    geraCriaCarros();
  }

  Lista<Evento> getTimeline() {
    return this->linhaDoTempo();
  }

  void addTimelineEvent(Evento evento) {
    linhaDoTempo->adicionaEmOrdem(evento);
  }

  geraSemaforos() {
    double tempoCorrente = 0;
    while(tempoCorrente < tempoTotal) {
      GeraSemaforo semaforo = new GeraSemaforo(tempoCorrente);
      linhaDoTempo->adicionaEmOrdem(semaforo);
      tempoCorrente += tempoSemaforo;
    }
  }

  geraCriaCarros(Pista pista) {
    int tempo = pista->getFrequenciaEntradaDeCarros();
    CriaCarro criaCarro = new CriaCarro(pista, tempo);
    linhaDoTempo->adicionaEmOrdem(criaCarro);

  }
}
