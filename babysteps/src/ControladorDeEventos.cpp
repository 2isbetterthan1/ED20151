/* Copyright [2015] <LeoSL e marcelinol>
 * ControladorDeEventos.cpp
 */

#ifndef CONTROLADORDEEVENTOS_HPP
#define CONTROLADORDEEVENTOS_HPP

#define TEMPOSEMAFORO 15
#include "Evento.cpp"
#include "Pista.cpp"
#include "CriaCarro.cpp"
#include "GeraSemaforo.cpp"
#include "ChegaSemaforo.cpp"
#include "Pilha.cpp"
#include "Carro.cpp"
#include "ListaEnc.cpp"
#include "Lista.cpp"

class ControladorDeEventos {

private:
  double tempoTotal;
  double tempoSemaforo = TEMPOSEMAFORO;
  int estadoSemaforos = 1;
  int carrosIn = 0;
  int carrosOut = 0;
  Lista<Pista> listaDePistas;
  ListaEnc<Evento> linhaDoTempo;

public:

  /**
  * Construtor. Construtor de um controlador de eventos.
  */
  ControladorDeEventos(tempoTotal) { // herdar listas
    this->tempoTotal = tempoTotal;
    setup();
  }

  /**
  * Função setup. Chama as funções que cria as pistas e os eventos, cria a linha
  * do tempo e manda percorrê-la.
  */
  void setup() {
    linhaDoTempo = new Lista<Evento>();
    inicializaPistas();
    geraSemaforos();
    percorreLinhaDoTempo();
  }


  /**
  * Função carroOut. acrescenta a contagem de carros que saíram do sistema.
  */
  void carroOut() {
    this->carrosOut += 1;
  }

  /**
  * Função carroIn. acrescenta a contagem de carros que entraram no sistema.
  */
  void carroIn() {
    this->carrosIn += 1;
  }

  /**
  * Função percorreLinhaDoTempo. Acessa cada um dos eventos da linha do tempo
  * e executa-o até que acabe o tempo de execução da simulação.
  */
  void percorreLinhaDoTempo() {
    bool ongoing = true;
    Evento currentEvent = linhaDoTempo.retiraDoInicio();
    while(currentEvent.getTime() <= tempoTotal) {
      currentEvent.executa();
      currentEvent = linhaDoTempo.retiraDoInicio();
    }
  }

  /**
  * Função geraSemaforos. Cria e adiciona os eventos de troca de estado dos semáforos
  * na linha do tempo
  */
  void geraSemaforos() {
    double tempoCorrente = 0;
    while(tempoCorrente < tempoTotal) {
      GeraSemaforo semaforo = new GeraSemaforo(tempoCorrente);
      linhaDoTempo.adicionaEmOrdem(semaforo);
      tempoCorrente += tempoSemaforo;
    }
  }

  /**
  * Função getTimeline. Retorna a linha do tempo.
  */
  Lista<Evento> getTimeline() {
    return this->linhaDoTempo();
  }

  /**
  * Função addTimelineEvent. Adiciona um elemento da linha do tempo.
  */
  void addTimelineEvent(Evento evento) {
    linhaDoTempo.adicionaEmOrdem(evento);
  }

  /**
  * Função geraCriaCarro. Cria um evento CriaCarro para cada uma das pistas
  * fonte. A criação dos carros seguintes será feita na execução do próprio
  * evento CriaCarro.
  */
  void geraCriaCarro(Pista pista) {
    int tempo = pista.getFrequenciaEntradaDeCarros();
    CriaCarro criaCarro = new CriaCarro(pista, tempo);
    linhaDoTempo.adicionaEmOrdem(criaCarro);
  }

  /**
  * Função getEstadoSemaforos. Informa em qual cenário está o sistema com
  * relação aos semáforos.
  */
  int getEstadoSemaforos() {
    return this->estadoSemaforos();
  }

  /**
  * Função setEstadoSemaforos. Determina o cenário do sistema com relação aos
  * semáforos.
  */
  void setEstadoSemaforos(int estado) {
    this->estadoSemaforos = estado;
  }

  /**
  * Função inicializaPistas. Cria todas as pistas e adiciona elas na lista
  * de pistas.
  */
  void inicializaPistas() {
    listaDePistas = new Lista<Pista>();
    bool aberta, sumidouro;
    double freqMin, freqMax, tamanho, velocidade;

    // Via O1leste (1)
    aberta = true;
    sumidouro = false;
    freqMin = 8;
    freqMax = 12;
    tamanho = 2000;
    velocidade = 80/3.6;

    Pista p1 = new Pista<Carro>(aberta, sumidouro, freqMin, freqMax, tamanho, velocidade);
    geraCriaCarro(p1);

    // Via S1Sul (2)
    aberta = true;
    sumidouro = true;
    freq = NULL;
    tamanho = 500;
    velocidade = 60/3.6;

    Pista p2 = new Pista<Carro>(aberta, sumidouro, freqMin, freqMax, tamanho, velocidade);

    // Via S1norte (3)
    aberta = false;
    sumidouro = false;
    freqMin = 23;
    freqMax = 37;
    tamanho = 500;
    velocidade = 60/3.6;

    Pista p3 = new Pista<Carro>(aberta, sumidouro, freqMin, freqMax, tamanho, velocidade);
    geraCriaCarro(p3);

    // Via C1leste (4) << PISTA ESPECIAL, POIS NÃO PODE CHAMAR CRIA CARRO!
    aberta = true;
    sumidouro = false;
    freq = NULL;
    tamanho = 300;
    velocidade = 60/3.6;

    Pista p4 = new Pista<Carro>(aberta, sumidouro, freqMin, freqMax, tamanho, velocidade);

    // Via S2Sul (5)
    aberta = true;
    sumidouro = true;
    freq = NULL;
    tamanho = 500;
    velocidade = 40/3.6;

    Pista p5 = new Pista<Carro>(aberta, sumidouro, freqMin, freqMax, tamanho, velocidade);

    // Via S2Norte (6)
    aberta = false;
    sumidouro = false;
    freqMin = 45;
    freqMax = 75;
    tamanho = 500;
    velocidade = 40/3.6;

    Pista p6 = new Pista<Carro>(aberta, sumidouro, freqMin, freqMax, tamanho, velocidade);
    geraCriaCarro(p6);

    // Via L1leste (7)
    aberta = true;
    sumidouro = true;
    freq = NULL;
    tamanho = 400;
    velocidade = 30/3.6;

    Pista p7 = new Pista<Carro>(aberta, sumidouro, freqMin, freqMax, tamanho, velocidade);

    // Via L1oeste (8)
    aberta = false;
    sumidouro = false;
    freqMin = 8;
    freqMax = 12;
    tamanho = 400;
    velocidade = 30/3.6;

    Pista p8 = new Pista<Carro>(aberta, sumidouro, freqMin, freqMax, tamanho, velocidade);
    geraCriaCarro(p8);

    // Via N2norte (9)
    aberta = true;
    sumidouro = true;
    freq = NULL;
    tamanho = 500;
    velocidade = 40/3.6;

    Pista p9 = new Pista<Carro>(aberta, sumidouro, freqMin, freqMax, tamanho, velocidade);

    // Via N2sul (10)
    aberta = false;
    sumidouro = false;
    freqMin = 15;
    freqMax = 25;
    tamanho = 500;
    velocidade = 40/3.6;

    Pista p10 = new Pista<Carro>(aberta, sumidouro, freqMin, freqMax, tamanho, velocidade);
    geraCriaCarro(p10);

    // Via C1oeste (11) << PISTA ESPECIAL, POIS NÃO PODE CHAMAR CRIA CARRO!
    aberta = false;
    sumidouro = false;
    freq = NULL;
    tamanho = 300;
    velocidade = 60/3.6;

    Pista p11 = new Pista<Carro>(aberta, sumidouro, freqMin, freqMax, tamanho, velocidade);

    // Via N1norte (12)
    aberta = true;
    sumidouro = true;
    freq = NULL;
    tamanho = 500;
    velocidade = 60/3.6;

    Pista p12 = new Pista<Carro>(aberta, sumidouro, freqMin, freqMax, tamanho, velocidade);

    // Via N1sul (13)
    aberta = false;
    sumidouro = false;
    freqMin = 15;
    freqMax = 25;
    tamanho = 500;
    velocidade = 60/3.6;

    Pista p13 = new Pista<Carro>(aberta, sumidouro, freqMin, freqMax, tamanho, velocidade);
    geraCriaCarro(p13);

    // Via O1oeste (14)
    aberta = true;
    sumidouro = true;
    freq = NULL;
    tamanho = 2000;
    velocidade = 80/3.6;

    Pista p14 = new Pista<Carro>(aberta, sumidouro, freqMin, freqMax, tamanho, velocidade);

    // Cria pilha de possibilidades de conversão para cada pista
    p1.criaPilhaAleatoria(8, 1, 1, p4, p2, p12);
    p3.criaPilhaAleatoria(8, 1, 1, p4, p12, p14);
    p4.criaPilhaAleatoria(4, 3, 3, p7, p9, p5);
    p6.criaPilhaAleatoria(4, 3, 3, p7, p9, p11);
    p8.criaPilhaAleatoria(4, 3, 3, p9, p5, p11);
    p10.criaPilhaAleatoria(4, 3, 3, p7, p11, p5);
    p11.criaPilhaAleatoria(4, 3, 3, p14, p12, p2);
    p13.criaPilhaAleatoria(8, 1, 1, p4, p14, p2);

    // adiciona as pistas prontas na lista de pistas
    listaDePistas.adiciona(p1);
    listaDePistas.adiciona(p2);
    listaDePistas.adiciona(p3);
    listaDePistas.adiciona(p4);
    listaDePistas.adiciona(p5);
    listaDePistas.adiciona(p6);
    listaDePistas.adiciona(p7);
    listaDePistas.adiciona(p8);
    listaDePistas.adiciona(p9);
    listaDePistas.adiciona(p10);
    listaDePistas.adiciona(p11);
    listaDePistas.adiciona(p12);
    listaDePistas.adiciona(p13);
    listaDePistas.adiciona(p14);
  }
};
#endif
