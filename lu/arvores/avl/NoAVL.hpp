/* Copyright [2015] <marcelinol>
 * NoAVL.hpp
 */

#ifndef NO_AVL_HPP
#define NO_AVL_HPP
#include <vector>
#include <cstdlib>

template <typename T>
class NoAVL  {
 private:
    int altura;  //!< Representa a altura do nó AVL
    T* dado;
    NoAVL<T>* esquerda;
    NoAVL<T>* direita;
    std::vector<NoAVL<T>* > elementos;

 public:
    explicit NoAVL(const T& data) {
      altura = 1;
      dado = new T(data);
      esquerda = 0;
      direita = 0;
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

    T* busca(const T& dado, NoAVL<T>* arv) {
      if (arv != NULL) {
        if (dado == *arv->getDado()) {
          return arv->getDado();
        } else {
          if (dado > *arv->getDado()) {
            arv->busca(dado, arv->getDireita());
          } else {
            arv->busca(dado, arv->getEsquerda());
          }
        }
      } else {
        throw("erro");
      }
    }

    void preOrdem(NoAVL<T>* nodo) {
      if (nodo != NULL) {
        elementos.push_back(nodo);
        if (nodo->getEsquerda() != NULL) {
          preOrdem(nodo->getEsquerda());
        }
        if (nodo->getDireita() != NULL) {
          preOrdem(nodo->getDireita());
        }
      }
      elementos.end();
    }

    void emOrdem(NoAVL<T>* nodo) {
      if (nodo->getEsquerda() != NULL) {
        emOrdem(nodo->getEsquerda());
      }
      elementos.push_back(nodo);
      if (nodo->getDireita() != NULL) {
        emOrdem(nodo->getDireita());
      }
      elementos.end();
    }

    void posOrdem(NoAVL<T>* nodo) {
      if (nodo != NULL) {
        if (nodo->getEsquerda() != NULL) {
          posOrdem(nodo->getEsquerda());
        }
        if (nodo->getDireita() != NULL) {
          posOrdem(nodo->getDireita());
        }
        elementos.push_back(nodo);
      }
      elementos.end();
    }
};

#endif /* NO_AVL_HPP */
