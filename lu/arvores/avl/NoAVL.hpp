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
      altura = 0;
      dado = new T(data);
      esquerda = 0;
      direita = 0;
    }

    virtual ~NoAVL();

    int getAltura() {
      int alturaEsquerda = calcAltura(this->esquerda);
      int alturaDireita = calcAltura(this->direita);
      if (alturaEsquerda > alturaDireita) {
        return alturaEsquerda;
      } else if (alturaDireita > alturaEsquerda){
        return alturaDireita;
      } else {
        return 0;
      }
    }

    int calcAltura(NoAVL<T>* subarvore) {
      if (subarvore == NULL) {
        return -1;
      } else {
        return subarvore->getAltura();
      }
    }

    std::vector<NoAVL<T>* > getElementos();
    NoAVL<T>* getEsquerda() {
      return this->esquerda;
    }

    NoAVL<T>* getDireita() {
      return this->direita;
    }

    NoAVL<T>* inserir(const T& dado, NoAVL<T>* arv) {
      NoAVL<T>* novoNoh = new NoAVL<T>(dado);
      novoNoh->altura = arv->getAltura + 1;
      if (dado > *arv->getDado()) {
        if (arv->getDireita() == 0) {
          arv->direita = novoNoh;
        } else {
          arv->getDireita()->inserir(dado, arv->getDireita());
        }
      } else {
        if (dado < *arv->getDado()) {
          if (arv->getEsquerda() == 0) {
            arv->esquerda = novoNoh;
          } else {
            arv->getEsquerda()->inserir(dado, arv->getEsquerda());
          }
        }
      }
      if (!isBalanced()) {
        //ROTACIONA
      }

      return novoNoh;
    }

    bool isBalanced(NoAVL<T>* arv) {
      int alturaEsquerda = calcAltura(this->esquerda);
      int alturaDireita = calcAltura(this->direita);

      return (alturaEsquerda - alturaDireita) < 2
    }

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
