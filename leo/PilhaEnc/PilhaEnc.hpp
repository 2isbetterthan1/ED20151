template<typename T>

class PilhaEnc: public ListaEnc<T> {
 private:
  Elemento<T>* head;
  int index;

 public:
  PilhaEnc(): ListaEnc<T>::ListaEnc() {}

  ~PilhaEnc() {
    destroiPilhaEnc();
  }

  bool pilhaVazia() {
    if (index == -1) {
      return true;
    } else {
      return false;
    }
  }

  void empilha(const T& dado) {

  }

  T desempilha() {

  }

  T topo() {

  }

  void limparPilha() {

  }

  void destroiPilhaEnc() {

  }
};
