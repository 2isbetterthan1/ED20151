/* Copyright [2015] <marcelinol>
 * Fila.hpp
 */

template <typename T>

/**
* Classe Fila. Uma fila é uma lista linear na qual o primeiro elemento a entrar é o primeiro elemento a sair.
*/
  class Fila  {
   private:
    int fimDaFila;
    int maximoDeElementos;
    T* dados = new T[maximoDeElementos];

   public:
   /**
   * Construtor. Construtor de uma Fila
   */
    Fila() {
      maximoDeElementos = 10;
      inicializaFila();
    }


    Fila<T> (int tam) {
      maximoDeElementos = tam;
      inicializaFila();
    }

    /**
    * Função inclui. Insere um elemento no final da fila se ela não estiver cheia.
    * @param dado Elemento a ser inserido na fila.
    */
    void inclui(T dado) {
      if (filaCheia()) {
       throw "Fila Cheia";
      }
      fimDaFila += 1;
        dados[fimDaFila] = dado;
    }

    /**
    * Função retira. Retira um elemento do início da fila se ela não estiver
    * vazia. Itera sobre os demais para fazer a fila andar.
    * @return elemento retirado do final da fila.
    */
    T retira() {
      if (filaVazia()) {
       throw "Fila Vazia";
      }
      T retirado = dados[0];
      fimDaFila -= 1;
      for (int i = 0; i < (maximoDeElementos -1); i++) {
       dados[i] = dados[i+1];
      }
      return retirado;
    }

    /**
    * Função ultimo. Lê o valor que está no final da fila se ela não estiver vazia.
    * @return último valor da fila.
    */
    T ultimo() {
      if (filaVazia()) {
        throw "Fila Vazia";
      }
      return dados[fimDaFila];
    }


    /**
    * Função getUltimo. Vê qual é o índice do último elemento da fila.
    * @return valor de elementos na fila - 1.
    */
    int getUltimo() {
      if (filaVazia()) {
        throw "Fila Vazia";
      }
      return fimDaFila;
    }

    /**
    * Função fileCheia. Verifica se a fila está cheia.
    * @return verdadeiro se a fila estiver cheia, falso se não estiver cheia.
    */
    bool filaCheia() {
      return fimDaFila == maximoDeElementos - 1;
    }

    /**
    * Função filaVazia. Verifica se a fila está vazia.
    * @return verdadeiro se a fila estiver vazia, falso se não estiver vazia.
    */
    bool filaVazia() {
      return fimDaFila == -1;
    }

    /**
    * Função inicializaFila. Deixa a fila vazia.
    */
    void inicializaFila() {
      fimDaFila = -1;
    }
  };
