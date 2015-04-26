/* Copyright [2015] <LeoSL>
 * Lista.hpp
 */
template <typename T>

#define MAXLISTA 100

/**
* Classe Lista. Uma Lista é um conjunto de dados dispostos e/ou acessáveis em uma sequência determinada.
* Este conjunto de dados pode possuir uma ordem intrínseca ou extrínseca.
*/
class Lista {
 private:
  int inicio = 0;
  int pos;
  int ultimo;
  int tam = MAXLISTA;
  T* dados = new T[tam];

 public:
/**
* Construtor. Construtor de uma Lista
*/
  Lista() {
    init();
  }

/**
* Construtor. Construtor de uma Lista com tipos genéricos.
*/
  explicit Lista<T>(int size) {
    tam = size;
    init();
  }

/**
* Função init. Serve para inicializar uma Fila.
*/
  void init() {
    ultimo = -1;
  }

/**
* Função adiciona. Adiciona um dado na última posição da Lista.
*/
  void adiciona(T dado) {
    excecaoListaCheia();
    ultimo++;
    dados[ultimo] = dado;
  }

/**
* Função adicionaNoInicio. Adiciona um dado na primeira posição da Lista.
*/
  void adicionaNoInicio(T dado) {
    adicionaNaPosicao(dado, inicio);
  }

/**
* Função retiraDoInicio. Retira um dado da primeira posição da Lista.
*/
  T retiraDoInicio() {
    return retiraDaPosicao(inicio);
  }

/**
* Função listaCheia. Retorna um valor verdadeiro se o ponteiro da lista for igual ao máximo do vetor instanciado na construção da Lista.
*/
  bool listaCheia() {
    return ultimo == (tam - 1);
  }

/**
* Função listaVazia. Retorna um valor verdadeiro se o ponteiro da lista for igual a -1.
*/
  bool listaVazia() {
    return ultimo == -1;
  }

/**
* Função destroiLista. Retorna a posição do ponteiro para -1, reinicializando a lista.
*/
  void destroiLista() {
    init();
  }

/**
* Função contem. Retorna um valor verdadeiro se o dado passado como argumento estiver contido na lista.
*/
  bool contem(T dado) {
    excecaoListaVazia();
    pos = 0;
    while (!(igual(dados[pos], dado)) && pos <= ultimo) {
      pos++;
    }
    return !(pos > ultimo);
  }

/**
* Função igual. Retorna um valor verdadeiro se os dados passados como parâmetros forem iguais entre si.
*/
  bool igual(T dado1, T dado2) {
    return dado1 == dado2;
  }

/**
* Função menor. Retorna um valor verdadeiro se o primeiro dado passado como argumento for menor que o outro.
*/
  bool menor(T dado1, T dado2) {
    return !(maior(dado1, dado2));
  }

/**
* Função maior. Retorna um valor verdadeiro se o primeiro dado passado como argumento for maior que o outro.
*/
  bool maior(T dado1, T dado2) {
    return dado1 > dado2;
  }

/**
* Função posicao. Retorna um valor inteiro que indica a posição do dado passado como argumento.
*/
  int posicao(T dado) {
    excecaoListaVazia();
    pos = 0;
    while ((pos <= ultimo) && !(igual(dados[pos], dado))) {
      pos++;
    }

    if (pos > ultimo) {
      throw("Não existe este elemento na Lista!");
    }

    return pos;
  }

/**
* Função retira. Retira da lista o seu último elemento.
*/
  T retira() {
    excecaoListaVazia();
    return retiraDaPosicao(ultimo);
  }

/**
* Função adicionaEmOrdem. Adiciona elementos em ordem.
* A função percorre a lista e verifica se o dado passado é maior ou menor que cada um dos elementos da lista. 
*/
  void adicionaEmOrdem(T dado) {
    excecaoListaCheia();
    pos = 0;
    while (pos <= ultimo && maior(dado, dados[pos])) {
      pos++;
    }
    return adicionaNaPosicao(dado, pos);
  }

/**
* Função adicionaNaPosicao. Adiciona o elemento passado na posição também passada como argumento.
* A função também verifica se o destino passado é válido.
*/
  void adicionaNaPosicao(T dado, int destino) {
    excecaoListaCheia();

    if (destino < 0 || destino > ultimo + 1) {
      throw("Posicao Invalida!");
    }

    ultimo++;
    pos = ultimo;

    while ((pos > destino)) {
      dados[pos] = dados[pos - 1];
      pos--;
    }

    dados[destino] = dado;
  }

/**
* Função retiraDaPosicao. Retira o elemento passado na posição também passada como argumento.
* A função também verifica se o destino passado é válido.
*/
  T retiraDaPosicao(int destino) {
    excecaoListaVazia();
    if (destino < 0 || destino > ultimo) {
      throw("Posicao Invalida!");
    }

    T dado = dados[destino];

    ultimo--;
    pos = destino;

    while (pos <= ultimo) {
      dados[pos] = dados[pos + 1];
      pos++;
    }

    return dado;
  }

  T encontraNaPosicao(int destino) {
    excecaoListaVazia();
    if (destino < 0 || destino > ultimo) {
      throw("Posicao Invalida!");
    }

    T dado = dados[destino-1];

    return dado;
  }

/**
* Função retiraEspecifico. Retira um dado específico da lista.
* A função também verifica se o o dado existe na lista.
*/
  T retiraEspecifico(T dado) {
    excecaoListaVazia();
    return retiraDaPosicao(posicao(dado));
  }

/**
* Função excecaoListaVazia. Estoura excecao no caso da lista estar vazia e interrompe seu funcionamento.
*/
  void excecaoListaVazia() {
    if (listaVazia()) {
      throw("Lista Vazia!");
    }
  }

/**
* Função excecaoListaCheia. Estoura excecao no caso da lista estar cheia e interrompe seu funcionamento.
*/
  void excecaoListaCheia() {
    if (listaCheia()) {
      throw("Lista Vazia!");
    }
  }
};
