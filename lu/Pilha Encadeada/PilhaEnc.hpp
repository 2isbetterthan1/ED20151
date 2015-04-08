pesquisar no google:
how to remap a method in c++ with private inheritance
calling inherited constructor

template<typename T>
class PilhaEnc: private ListaEnc<T>{
 public:
    PilhaEnc() : LiscaEnc() {}
    ~PilhaEnc() {
      limparPilha();
    }
    void empilha(const T& dado): adicionaNoInicio(const T& dado) {}
    T desempilha(): retiraDoInicio() {}
	T topo() {
    // implementar
  }
	void limparPilha(): ~ListaEnc() {}
	bool PilhaVazia(): listaVazia() {}
};
