#ifndef NO_AVL_HPP
#define NO_AVL_HPP
#include <vector>

template <typename T>
class NoAVL  {
 private:
    int altura;  //!< Representa a altura do nó AVL
    T* dado;
    NoAVL<T>* esquerda;
    NoAVL<T>* direita;
    std::vector<NoAVL<T>* > elementos;

 public:
    explicit NoAVL(const T& dado) {
      this->altura = 1;
      this->dado = dado;
      this->esquerda = NULL;
      this->direita = NULL;
    }

    virtual ~NoAVL();

    int getAltura() {
      return this->altura;
    }

    std::vector<NoAVL<T>* > getElementos();
    NoAVL<T>* getEsquerda() {
      return this->esquerda;
    }

    NoAVL<T>* getDireita() {
      return this->direita;
    }

    NoAVL<T>* inserir(const T& dado, NoAVL<T>* arv);
    NoAVL<T>* remover(NoAVL<T>* arv, const T& dado);
    NoAVL<T>* minimo(NoAVL<T>* nodo);
    T* getDado() {
      return this->dado;
    }

    T* busca(const T& dado, NoAVL<T>* arv);

    void preOrdem(NoBinario<T>* nodo) {
      if (novo != NULL) {
        printf(noto->getDado());
        preOrdem(nodo->getEsquerda());
        preOrdem(nodo->getDireita());
      }
    }

    void emOrdem(NoBinario<T>* nodo) {
      if (nodo != NULL) {
        emOrdem(nodo->getEsquerda());
        printf(nodp>getDado());
        emOrdem(nodo->getDireita());
      }
    }

    void posOrdem(NoBinario<T>* nodo) {
      if (nodo != NULL) {
        posOrdem(nodo->getEsquerda());
        posOrdem(nodo->getDireita());
        printf(nodo->getDado());

      }
    }
};

#endif /* NO_AVL_HPP */
