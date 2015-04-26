GeraSemaforo(double tempo) : Evento() {
private:
  double tempo;

public:
  GeraSemaforo(tempo) {
    this->tempo = tempo;
  }

  trocaStatusPistas() {

    switchCase(estado) { // TÁ ERRADO!

    case 1:
      estadoA();
    case 2:
      estadoB();
    case 3:
      estadoC();
    case 4:
      estadoD();
    }

  }

  estadoA() {
    trocaEstadoPista(1);
    trocaEstadoPista(3);
    trocaEstadoPista(4);
    trocaEstadoPista(6);
    controladorDeEventos->setEstado(2);
  }
  
  estadoB() {
    trocaEstadoPista(8);
    trocaEstadoPista(3);
    trocaEstadoPista(4);
    trocaEstadoPista(11);
    controladorDeEventos->setEstado(3);
  }

  estadoC() {
    trocaEstadoPista(11);
    trocaEstadoPista(10);
    trocaEstadoPista(13);
    trocaEstadoPista(8);
    controladorDeEventos->setEstado(4);
  }

  estadoD() {
    trocaEstadoPista(1);
    trocaEstadoPista(10);
    trocaEstadoPista(13);
    trocaEstadoPista(4);
    controladorDeEventos->setEstado(1);
  }

  trocaEstadoPista(int indice) {
    Pista pista = listaDePistas->encontraNaPosicao(indice);
    pista->switchStatus();
  }
}