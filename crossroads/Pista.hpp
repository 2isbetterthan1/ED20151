#define TAMANHOCARRO 7
class Pista : public FilaEnc {
private:
  bool aberta;
  bool sumidouro;
  double frequenciaEntradaDeCarros;
  double tamanho;     //  EM METROS
  double velocidade;  //  EM METROS POR SEGUNDO
  double tempoPercorrimento;
  Pilha aleatorio<Pista>;
public:

  Pista(bool aberta, bool sumidouro, double frequenciaEntradaDeCarros, double tamanho, double velocidade) {
    this->aberta = aberta;
    this->sumidouro = sumidouro;
    this->frequenciaEntradaDeCarros = frequenciaEntradaDeCarros;
    this->tamanho = tamanho;
    this->velocidade = velocidade;
    setTempoPercorrimento();
  }

  void setTempoPercorrimento() {
    this->tempoPercorrimento = (this->tamanho)/(this->velocidade);
  }

  double getFrequenciaEntradaDeCarros () {
    return this->frequenciaEntradaDeCarros;
  }

  bool isSumidouro() {
    return this->sumidouro;
  }

  double getTempoPercorrimento() {
    return this->tempoPercorrimento;
  }

  bool getStatus() {
    return this->aberta;
  }

  bool lotada() {
    int tamanhoDaFila = getSize();
    double ocupado = tamanhoDaFila*(TAMANHOCARRO + 3);
    return ocupado > (tamanho - (TAMANHOCARRO + 3)
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
  
  void criaPilhaAleatoria(prob1, prob2, prob3, primeiraOpcao, segundaOpcao, terceiraOpcao) {
    aleatorio = new Pilha<Pista>;
   
    for (int i = 0; i < prob1; i++) {
      aleatorio.empilha(primeiraOpcao);
    }
   
    for (int i = 0; i < prob2; i++) {
      aleatorio.empilha(segundaOpcao);
    }

    for (int i = 0; i < prob2; i++) {
      aleatorio.empilha(terceiraOpcao);
    }
  }

  Pista getPistaAleatoria() {
    int indicePistaDestino = rand() % 10;
    return aleatorio->encontra(indicePistaDestino);
  }

  void switchStatus() {
    this->aberta = !getStatus();
  }

}