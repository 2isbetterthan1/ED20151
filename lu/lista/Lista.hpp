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
      throw "Lista Cheia"
    }
    adicionaNaPosicao(dado, fimDaLista); //SE A LISTA ESTIVER VAZIA, VAI
    //COLOCAR NA POSICAO[-1]
  }

  void adicionaNoInicio(T dado) {
    adicionaNaPosicao(dado, 0);
  }

  void adicionaNaPosicao(T dado, int posicao) {
    if (listaCheia()) {
      throw "Lista Cheia";
    }
    if (posicao > fimDaLista || posicao < 0) {
      throw "Erro de Posicao"
    }

    fimDaLista++;
    int ultimoDaLista = fimDaLista;

    for (ultimoDaLista; ultimoDaLista > posicao; ultimoDaLista--) {
      dados[ultimoDaLista] = dados[ultimoDaLista - 1];
    }
    dados[posicao] = dado;
  }

  void adicionaEmOrdem(T dado) {}

  T retira() {
    return retiraDaPosicao(fimDaLista);
  }

  T retiraDoInicio() {
    return retiraDaPosicao(posicao(0));
  }

  T retiraDaPosicao(int posicao) {
    if (listaVazia()) {
      throw "Lista Vazia";
    }
    T retirado = dados[posicao];
    int contador = posicao;
    for (contador; contador < fimDaLista; contador++) {
      dados[contador] = dados[contador + 1];
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
   if(posicao > fimDaLista) {
     throw "Item não encontrado";
   } else {
     return posicao;
   }
  }

  bool contem(T dado) {
   if (listaVazia()) {
     throw "Lista Vazia";
   }
   for (int contador = 0; contador < fimDaLista; contador++) {
     if (dados[contador] == dado) {
       return true;
     }
   }
   return false;
  }

  bool igual(T dado1, T dado2) {
   return if (dado1 == dado2);
  }

  bool maior(T dado1, T dado2) {
   return if (dado1 > dado2);
  }

  bool menor(T dado1, T dado2) {
   return if (dado1 < dado2);
  }

  bool listaCheia() {
   return if (fimDaLista == maximoDeElementos);
  }

  bool listaVazia() {
   return if (fimDaLista == -1);
  }

  void inicializaLista() {
   fimDaLista = -1;
  }

  void destroiLista() {
   fimDaLista = -1;
  }
 };
