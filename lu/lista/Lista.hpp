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

 	explicit Lista(int tam)
 	void adiciona(T dado)
 	void adicionaNoInicio(T dado)
 	void adicionaNaPosicao(T dado, int posicao)
 	void adicionaEmOrdem(T dado)
 	T retira()
 	T retiraDoInicio()
 	T retiraDaPosicao(int posicao)
 	T retiraEspecifico(T dado)
 	int posicao(T dado)

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
