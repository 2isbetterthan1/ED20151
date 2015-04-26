Pista() : Fila() {
private:
  double frequenciaEntradaDeCarros;
  bool aberta;
  bool sumidouro;
  double tamanho;     //  EM METROS
  double velocidade;  //  EM METROS POR SEGUNDO
  double tempoPercorrimento;
  Pilha aleatorio<Pista>;
public:

  Pista() {

    tempoPercorrimento = tamanho/velocidade;
  }

  bool isSumidouro() {
    return sumidouro;
  }

  double getTempoPercorrimento() {
    tempoPercorrimento;
  }

  bool lotada() {
    double ocupado = size*(TAMANHOCARRO + 3);
    return ocupado > (tamanho - (TAMANHOCARRO + 3)
  }
  
  criaPilhaAleatoria(prob1, prob2, prob3, primeiraOpcao, segundaOpcao, terceiraOpcao) {
    aleatorio = new Pilha<Pista>;
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

  Pista getPistaAleatoria() {
    int indicePistaDestino = random(0..9)
    return aleatorio->encontra(indicePistaDestino);
  }

  void switchStatus() {
    aberta = !aberta;
  }

  bool getStatus() {
    return aberta;
  }

}