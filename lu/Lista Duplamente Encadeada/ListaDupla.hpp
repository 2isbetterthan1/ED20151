
class ListaDupla {
 private:
   Elemento<T>* head;
   int size;

 public:
	ListaDupla<T>() {
    criaLista();
  }

	~ListaDupla()

  void criaLista() {

  }
	void adicionaNoInicioDuplo(const T& dado)
	T retiraDoInicioDuplo()
	void eliminaDoInicioDuplo()
	void adicionaNaPosicaoDuplo(const T& dado, int pos)
	int posicaoDuplo(const T& dado) const
	T* posicaoMemDuplo(const T& dado) const
	bool contemDuplo(const T& dado)
	T retiraDaPosicaoDuplo(int pos)
	void adicionaDuplo(const T& dado)
	T retiraDuplo()
	T retiraEspecificoDuplo(const T& dado)
	T mostra(int pos)
	void adicionaEmOrdem(const T& data)
	int verUltimo()
	bool listaVazia() const
	bool igual(T dado1, T dado2)
	bool maior(T dado1, T dado2)
	bool menor(T dado1, T dado2)
	void destroiListaDuplo()
};
