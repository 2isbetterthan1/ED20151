#define TAMANHOCARRO 7
Pista() : FilaEnc() {
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

  void adiciona(Carro carro){
    Fila<Carro>::adiciona(carro);
  }

  int getSize() {
    Fila<Carro>::getSize();
  }

  void retira() {
    Fila<Carro>::retira();
  }

  bool isSumidouro() {
    return sumidouro;
  }

  double getTempoPercorrimento() {
    tempoPercorrimento;
  }

  bool lotada() {
    int tamanhoDaFila = getSize();
    double ocupado = tamanhoDaFila*(TAMANHOCARRO + 3);
    return ocupado > (tamanho - (TAMANHOCARRO + 3)
  }
  
  void criaPilhaAleatoria(prob1, prob2, prob3, primeiraOpcao, segundaOpcao, terceiraOpcao) {
    aleatorio = new Pilha<Pista>;
   
    for (int i = 0; i <= prob1; i++) {
      aleatorio.empilha(primeiraOpcao);
    }
   
    for (int i = 0; i <= prob2; i++) {
      aleatorio.empilha(segundaOpcao);
    }

    for (int i = 0; i <= prob2; i++) {
      aleatorio.empilha(terceiraOpcao);
    }
  }

  Pista getPistaAleatoria() {
    int indicePistaDestino = rand() % 10;
    return aleatorio->encontra(indicePistaDestino);
  }

  void switchStatus() {
    aberta = !getStatus();
  }

  bool getStatus() {
    return aberta;
  }

}