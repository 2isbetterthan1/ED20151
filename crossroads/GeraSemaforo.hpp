GeraSemaforo(double tempo) : Evento() {
private:
  double tempo;

public:
  GeraSemaforo(tempo) {
    this->tempo = tempo;
  }

  double getTime() {
    return this->tempo;
  }

  void executa() {
    trocaStatusPistas();
  }

  trocaStatusPistas() {
    int estado = controladorDeEventos->getEstadoSemaforos();

    switch(estado) {
      case 1:
        estadoA();
        break;
      case 2:
        estadoB();
        break;
      case 3:
        estadoC();
        break;
      case 4:
        estadoD();
        break;
      default:
        break;
      }

  }

  estadoA() {
    trocaEstadoPista(1);
    trocaEstadoPista(3);
    trocaEstadoPista(4);
    trocaEstadoPista(6);
    controladorDeEventos->setEstadoSemaforos(2);
  }
  
  estadoB() {
    trocaEstadoPista(8);
    trocaEstadoPista(3);
    trocaEstadoPista(4);
    trocaEstadoPista(11);
    controladorDeEventos->setEstadoSemaforos(3);
  }

  estadoC() {
    trocaEstadoPista(11);
    trocaEstadoPista(10);
    trocaEstadoPista(13);
    trocaEstadoPista(8);
    controladorDeEventos->setEstadoSemaforos(4);
  }

  estadoD() {
    trocaEstadoPista(1);
    trocaEstadoPista(10);
    trocaEstadoPista(13);
    trocaEstadoPista(4);
    controladorDeEventos->setEstadoSemaforos(1);
  }

  trocaEstadoPista(int indice) {
    Pista pista = listaDePistas->encontraNaPosicao(indice);
    pista->switchStatus();
  }
}