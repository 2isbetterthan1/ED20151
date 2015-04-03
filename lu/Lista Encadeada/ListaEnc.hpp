#include "Elemento.hpp"

template<typename T>
class ListaEnc {

public:
	ListaEnc(){
    Elemento *dados;
    int tamanho;
  }
	~ListaEnc(){

  }

	// inicio

  Lista* criaLista() {
    Lista *lista;           //WAT
    lista = new Elemento(); //cabeça da lista?
    if (lista != NULL) {
      setSize(0); //OU tamanho = 0; ???
      dados = NULL;
    }
    return lista;
  }

	void adicionaNoInicio(const T& dado){
    Elemento *novoElemento;
    novoElemento = new Elemento();
    if (novoElemento == NULL) {
      throw "Lista Cheia";
    } else {
      novoElemento->setProximo(*dados);
      novoElemento->setInfo(*dado);
      setSize(getSize() + 1);
    }
  }

	T retiraDoInicio(){
    if (listaVazia()) {
      return NULL;
    }

    Elemento *saiu;
    T *volta;
    saiu = *dados;
    volta = saiu->getInfo();
    dados = saiu->getNext();
    setSize(getSize() - 1);
    delete saiu; // ???
    return volta;
  }

	void eliminaDoInicio(){
    Elemento *saiu;
    if (listaVazia()) {
      return NULL;
    }
    saiu = *dados;
    dados = saiu->getNext();
    setSize(getSize() -1);
    delete saiu->getInfo();
    delete saiu;
  }

	// posicao
	void adicionaNaPosicao(const T& dado, int pos){
    Elemento *novo, *anterior;
    if(pos > getSize() + 1) {
      throw "Erro de posição";
    }
    if(pos == 0) {
      adicionaNoInicio(dado);
    } else {
      novo = new Elemento();
      if (novo == NULL) {
        throw "Lista Cheia";
      }
      anterior = *dados;
      for (counter = 0; counter < posicao - 2; counter++) {
        anterior = *(anterior->getNext());
        novo->setNext()
      }
    }
  }

	int posicao(const T& dado) const{

  }
	T* posicaoMem(const T& dado) const{

  }
	bool contem(const T& dado){

  }
	T retiraDaPosicao(int pos){

  }
	//fim
	void adiciona(const T& dado){

  }
	T retira(){

  }
	// especifico
	T retiraEspecifico(const T& dado)
	void adicionaEmOrdem(const T& data){

  }

	bool listaVazia() const{
    return getSize() == 0;
  }

	bool igual(T dado1, T dado2){
    return dado1 == dado2;
  }

	bool maior(T dado1, T dado2){
    return dado1 > dado2;
  }

	bool menor(T dado1, T dado2){
    return dado1 < dado2;
  }
  
	void destroiLista(){

  }

  int getSize() {
    return size;
  }

  void setSize(int new_size) {
    size = new_size;
  }

  T getHead(){
    return head;
  }

  void setHead(T *new_head){
    head = *new_head
  }

private:
	Elemento<T>* head;
	int size;
