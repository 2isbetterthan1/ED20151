/* Copyright [2015] <LeoSL e marcelinol>
 * ControladorDeEventos.hpp
 */
#define TEMPOSEMAFORO 15

class ControladorDeEventos() {

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

  void setup() {
    linhaDoTempo = new Lista<Evento>();
    inicializaPistas();
    geraSemaforos();
    percorreLinhaDoTempo();
  }

  void percorreLinhaDoTempo() {
    bool ongoing = true
    Evento currentEvent = linhaDoTempo->getFirst();
    while(currentEvent->getTime() <= tempoTotal) {
      currentEvent.executa();
      currentEvent = linhaDoTempo.encontraNaPosicao(2);
      linhaDoTempo.retiraDoInicio();
    }
  }

  void geraSemaforos() {
    double tempoCorrente = 0;
    while(tempoCorrente < tempoTotal) {
      GeraSemaforo semaforo = new GeraSemaforo(tempoCorrente);
      linhaDoTempo->adicionaEmOrdem(semaforo);
      tempoCorrente += tempoSemaforo;
    }
  }

  Lista<Evento> getTimeline() {
    return this->linhaDoTempo();
  }

  void addTimelineEvent(Evento evento) {
    linhaDoTempo->adicionaEmOrdem(evento);
  }

  void geraCriaCarro(Pista pista) {
    int tempo = pista->getFrequenciaEntradaDeCarros();
    CriaCarro criaCarro = new CriaCarro(pista, tempo);
    linhaDoTempo->adicionaEmOrdem(criaCarro);
  }

  int getEstadoSemaforos() {
    return this->estadoSemaforos();
  }

  void setEstadoSemaforos(int estado) {
    this->estadoSemaforos = estado;
  }

  void inicializaPistas() { // INICIA com semaforos no estado = 1
    listaDePistas = new Lista<Pista>();
    bool aberta, sumidouro;
    double freq, tamanho, velocidade;


    // Via O1leste (1)
    aberta = true;
    sumidouro = false;
    freq = 8~12 (s);
    tamanho = 2000;
    velocidade = 80/3.6;

    Pista p1 = new Pista<Carro>(aberta, sumidouro, freq, tamanho, velocidade);
    geraCriaCarro(p1);

    // Via S1Sul (2)
    aberta = true;
    sumidouro = true;
    freq = NULL;
    tamanho = 500;
    velocidade = 60/3.6;

    Pista p2 = new Pista<Carro>(aberta, sumidouro, freq, tamanho, velocidade);

    // Via S1norte (3)
    aberta = false;
    sumidouro = false;
    freq = 23~37 (s);
    tamanho = 500;
    velocidade = 60/3.6;

    Pista p3 = new Pista<Carro>(aberta, sumidouro, freq, tamanho, velocidade);
    geraCriaCarro(p3);

    // Via C1leste (4) << PISTA ESPECIAL, POIS NÃO PODE CHAMAR CRIA CARRO!
    aberta = true;
    sumidouro = false;
    freq = NULL;
    tamanho = 300;
    velocidade = 60/3.6;

    Pista p4 = new Pista<Carro>(aberta, sumidouro, freq, tamanho, velocidade);

    // Via S2Sul (5)
    aberta = true;
    sumidouro = true;
    freq = NULL;
    tamanho = 500;
    velocidade = 40/3.6;

    Pista p5 = new Pista<Carro>(aberta, sumidouro, freq, tamanho, velocidade);

    // Via S2Norte (6)
    aberta = false;
    sumidouro = false;
    freq = 45~75 (s);
    tamanho = 500;
    velocidade = 40/3.6;

    Pista p6 = new Pista<Carro>(aberta, sumidouro, freq, tamanho, velocidade);
    geraCriaCarro(p6);

    // Via L1leste (7)
    aberta = true;
    sumidouro = true;
    freq = NULL;
    tamanho = 400;
    velocidade = 30/3.6;

    Pista p7 = new Pista<Carro>(aberta, sumidouro, freq, tamanho, velocidade);

    // Via L1oeste (8)
    aberta = false;
    sumidouro = false;
    freq = 8~12 (s);
    tamanho = 400;
    velocidade = 30/3.6;

    Pista p8 = new Pista<Carro>(aberta, sumidouro, freq, tamanho, velocidade);
    geraCriaCarro(p8);

    // Via N2norte (9)
    aberta = true;
    sumidouro = true;
    freq = NULL;
    tamanho = 500;
    velocidade = 40/3.6;

    Pista p9 = new Pista<Carro>(aberta, sumidouro, freq, tamanho, velocidade);

    // Via N2sul (10)
    aberta = false;
    sumidouro = false;
    freq = 15~25 (s);
    tamanho = 500;
    velocidade = 40/3.6;

    Pista p10 = new Pista<Carro>(aberta, sumidouro, freq, tamanho, velocidade);
    geraCriaCarro(p10);

    // Via C1oeste (11) << PISTA ESPECIAL, POIS NÃO PODE CHAMAR CRIA CARRO!
    aberta = false;
    sumidouro = false;
    freq = NULL;
    tamanho = 300;
    velocidade = 60/3.6;

    Pista p11 = new Pista<Carro>(aberta, sumidouro, freq, tamanho, velocidade);

    // Via N1norte (12)
    aberta = true;
    sumidouro = true;
    freq = NULL;
    tamanho = 500;
    velocidade = 60/3.6;

    Pista p12 = new Pista<Carro>(aberta, sumidouro, freq, tamanho, velocidade);

    // Via N1sul (13)
    aberta = false;
    sumidouro = false;
    freq = 15~25 (s);
    tamanho = 500;
    velocidade = 60/3.6;

    Pista p13 = new Pista<Carro>(aberta, sumidouro, freq, tamanho, velocidade);
    geraCriaCarro(p13);

    // Via O1oeste (14)
    aberta = true;
    sumidouro = true;
    freq = NULL;
    tamanho = 2000;
    velocidade = 80/3.6;

    Pista p14 = new Pista<Carro>(aberta, sumidouro, freq, tamanho, velocidade);

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
}
