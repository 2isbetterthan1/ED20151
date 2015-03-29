/* Copyright [2015] <marcelinol>
 * Lista.hpp
 */

template <typename T>

#define MAX 1000

/**
* Classe Lista. Uma Lista é um conjunto de dados dispostos
* e/ou acessáveis em uma sequência determinada.
*/
  class Lista {
   private:
    int fimDaLista;
    int maximoDeElementos = MAX;
    T* dados = new T[maximoDeElementos];

   public:
   /**
   * Construtor. Construtor de uma Lista
   */
    Lista() {
     inicializaLista();
    }

    /**
    * Construtor. Construtor de uma Lista
    */
    explicit Lista<T>(int tam) {
      maximoDeElementos = tam;
      inicializaLista();
    }

    /**
    * Função adiciona. Adiciona um elemento no final da lista.
    */
    void adiciona(T dado) {
      if (listaCheia()) {
        throw "Lista Cheia";
      }
      fimDaLista++;
      dados[fimDaLista] = dado;
    }

    /**
    * Função adiciona no início. Adiciona um elemento no início da lista.
    */
    void adicionaNoInicio(T dado) {
      adicionaNaPosicao(dado, 0);
    }

    /**
    * Função adiciona na posição. Adiciona um elemento em uma posição
    * específica da fila, não podendo deixar espaços vazios entre os elementos.
    */
    void adicionaNaPosicao(T dado, int destino) {
      if (listaCheia()) {
        throw "Lista Cheia";
      }
      if (destino > fimDaLista + 1 || destino < 0) {
        throw "Erro de Posicao";
      }

      fimDaLista++;
      int posicao = fimDaLista;

      while (posicao > destino) {
        dados[posicao] = dados[posicao -1];
        posicao--;
      }
      dados[destino] = dado;
    }

    /**
    * Função adiciona em ordem. Adiciona um elemento na lista
    * logo após um elemento menor do que ele.
    */
    void adicionaEmOrdem(T dado) {
      if (listaCheia()) {
        throw "Lista Cheia";
      }
      int posicao = 0;
      while (posicao <= fimDaLista && maior(dado, dados[posicao])) {
        posicao++;
      }
      adicionaNaPosicao(dado, posicao);
    }

    /**
    * Função retira. Retira o último elemento da lista.
    */
    T retira() {
      return retiraDaPosicao(fimDaLista);
    }

    /**
    * Função retira do início. Retira o primeiro elemento da lista.
    */
    T retiraDoInicio() {
      return retiraDaPosicao(0);
    }

    /**
    * Função retira da posição. Retira um elemento
    * de uma posição específica da lista.
    */
    T retiraDaPosicao(int destino) {
      if (listaVazia()) {
        throw "Lista Vazia";
      }
      if (destino < 0 || destino > fimDaLista) {
        throw "Erro de posicao";
      }
      T retirado = dados[destino];
      for (int posicao = destino; posicao < fimDaLista; posicao++) {
        dados[posicao] = dados[posicao + 1];
      }
      fimDaLista--;
      return retirado;
    }

    /**
    * Função retira específico. Retira um dado elemento da lista.
    */
    T retiraEspecifico(T dado) {
      return retiraDaPosicao(posicao(dado));
    }

    /**
    * Função posicao. descobre a posição de um elemento na lista.
    */
    int posicao(T dado) {
      int posicao = 0;
      while (posicao <= fimDaLista && (dado != dados[posicao])) {
        posicao += 1;
      }
      if (posicao > fimDaLista) {
        throw "Item não encontrado";
      } else {
        return posicao;
      }
    }

    /**
    * Função contem. Verifica se determinado elemento está na lista.
    */
    bool contem(T dado) {
      if (listaVazia()) {
        throw "Lista Vazia";
      }
      for (int posicao = 0; posicao <= fimDaLista; posicao++) {
        if (igual(dados[posicao], dado)) {
          return true;
        }
      }
      return false;
    }

    /**
    * Função igual. Verifica se dois elementos são iguais
    */
    bool igual(T dado1, T dado2) {
      return dado1 == dado2 ? true : false;
    }

    /**
    * Função maior. Verifica se um dado é maior do que outro.
    */
    bool maior(T dado1, T dado2) {
      return dado1 > dado2;
    }

    /**
    * Função menor. Verifica se um dado é menor do que outro.
    */
    bool menor(T dado1, T dado2) {
      return dado1 < dado2;
    }

    /**
    * Função lista cheia. Verifica se a lista está cheia.
    */
    bool listaCheia() {
      return fimDaLista == (maximoDeElementos - 1);
    }

    /**
    * Função lista vazia. Verifica se a lista está vazia.
    */
    bool listaVazia() {
      return fimDaLista == -1;
    }

    /**
    * Função inicializa lista. Define o índice
    * do último elemento da lista como -1.
    */
    void inicializaLista() {
      fimDaLista = -1;
    }

    /**
    * Função destroiLista. Define o índice
    * do último elemento da lista como -1.
    */
    void destroiLista() {
      fimDaLista = -1;
    }
  };
