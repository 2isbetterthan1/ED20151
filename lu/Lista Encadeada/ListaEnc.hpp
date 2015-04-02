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
    Lista *lista;
    lista = new Lista();
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

  }
	void eliminaDoInicio(){

  }
	// posicao
	void adicionaNaPosicao(const T& dado, int pos){

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

  }
	bool maior(T dado1, T dado2){

  }
	bool menor(T dado1, T dado2){

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
