/* Copyright [2015] <marcelinol>
 * Lista.hpp
 */

template <typename T>

  class Lista {
   private:
    int fimDaLista;
    int maximoDeElementos;
    T* dados = new T[maximoDeElementos];

   public:
    Lista() {
     maximoDeElementos = 10;
     inicializaLista();
    }

    explicit Lista(int tam) {
      maximoDeElementos = tam;
      inicializaLista();
    }

    void adiciona(T dado) {
      if (listaCheia()) {
        throw "Lista Cheia";
      }
      fimDaLista++;
      dados[fimDaLista] = dado;
    }

    void adicionaNoInicio(T dado) {
      adicionaNaPosicao(dado, 0);
    }

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

    T retira() {
      return retiraDaPosicao(fimDaLista);
    }

    T retiraDoInicio() {
      return retiraDaPosicao(0);
    }

    T retiraDaPosicao(int destino) {
      if (listaVazia()) {
        throw "Lista Vazia";
      }
      T retirado = dados[destino];
      for (int posicao = destino; posicao < fimDaLista; posicao++) {
        dados[posicao] = dados[posicao + 1];
      }
      fimDaLista--;
      return retirado;
    }

    T retiraEspecifico(T dado) {
      return retiraDaPosicao(posicao(dado));
    }

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

    bool contem(T dado) {
      if (listaVazia()) {
        throw "Lista Vazia";
      }
      for (int posicao = 0; posicao < fimDaLista; posicao++) {
        if (igual(dados[posicao], dado)) {
          return true;
        }
      }
      return false;
    }

    bool igual(T dado1, T dado2) {
      return dado1 == dado2 ? true : false;
    }

    bool maior(T dado1, T dado2) {
      return dado1 > dado2;
    }

    bool menor(T dado1, T dado2) {
      return dado1 < dado2;
    }

    bool listaCheia() {
      return fimDaLista == maximoDeElementos - 1;
    }

    bool listaVazia() {
      return fimDaLista == -1;
    }

    void inicializaLista() {
      fimDaLista = -1;
    }

    void destroiLista() {
      fimDaLista = -1;
    }
  };
