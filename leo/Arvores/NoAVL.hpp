/* Copyright [2015] <LeoSL>
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

    virtual ~NoAVL() {
      delete this;
    }

    int getAltura() {
      return this->altura;
    }

    int maxAltura(NoAVL<T>* arv) const {
      int alturaEsquerda = 0;
      int alturaDireita = 0;

      if (arv->getEsquerda() != NULL) {
        alturaEsquerda = arv->esquerda->getAltura();
      }
      if (arv->getDireita() != NULL) {
        alturaDireita = arv->direita->getAltura();
      }

      if (alturaEsquerda == 0 && alturaDireita == 0) {
        return 0;
      } else if (alturaEsquerda > alturaDireita) {
        return alturaEsquerda;
      } else {
        return alturaDireita;
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

      // ATRIBUIÇÃO DE ALTURAS
      novoNoh->altura = maxAltura(novoNoh);
      arv->altura = maxAltura(arv) + 1;

      // ROTAÇÕES
      NoAVL<T>* filhoDireita = arv->direita;
      NoAVL<T>* filhoEsquerda = arv->esquerda;

      if (filhoEsquerda == NULL) {
        filhoEsquerda = new NoAVL<T>(0);
      }
      if (filhoDireita == NULL) {
        filhoDireita = new NoAVL<T>(0);
      }

      if (!(isBalanced(filhoDireita))) {
        balance(filhoDireita);
      } else if (!(isBalanced(filhoEsquerda))) {
        balance(filhoEsquerda);
      } else if (!(isBalanced(arv))) {
        balance(arv);
      }
      return novoNoh;
    }

    bool isBalanced(NoAVL<T>* arv) const {
      int fatBal = getFatBal(arv);
      bool response = fatBal > -2 && fatBal < 2;
      if (response) {
        return true;
      } else {
        return false;
      }
    }

    int getFatBal(NoAVL<T>* arv) const {
      int alturaEsquerda = 0;
      int alturaDireita = 0;
      if (arv->esquerda != NULL) {
        alturaEsquerda = arv->esquerda->getAltura() + 1;
      }
      if (arv->direita != NULL) {
        alturaDireita = arv->direita->getAltura() + 1;
      }
      return  alturaEsquerda - alturaDireita;
    }

    NoAVL<T>* balance(NoAVL<T>* arv) {
      int fatBal = getFatBal(arv);

      // Esquerda desbalanceada
      if (fatBal > 0) {
        int fatBalFilho = getFatBal(arv->esquerda);
        if (fatBalFilho > 0) {  // Rotação Simples à Direita
          rotacaoSimplesDireita(arv);
        } else {  // Rotação Dupla RotaçãoSimplesEsquerda/RotaçãoSimplesDireita
          rotacaoSimplesEsquerda(arv->esquerda);
          rotacaoSimplesDireita(arv);
        }
      } else {  // fatBal < 0 - Direita desbalanceada
        int fatBalFilho = getFatBal(arv->direita);
        if (fatBalFilho < 0) {  // Rotação Simples à Esquerda
          rotacaoSimplesEsquerda(arv);
        } else {  // Rotação Dupla RotaçãoSimplesDireita/RotaçãoSimplesEsquerda
          rotacaoSimplesDireita(arv->direita);
          rotacaoSimplesEsquerda(arv);
        }
      }
      return arv;
    }

    void rotacaoSimplesEsquerda(NoAVL<T>* raiz) {
      NoAVL<T>* aux;
      aux = raiz->direita;
      raiz->direita = aux->esquerda;
      aux->esquerda = raiz;
      if (aux->esquerda->esquerda == NULL && aux->esquerda->direita == NULL) {
        // caso o nó seja uma folha
        aux->esquerda->altura = 0;
      } else {
        aux->esquerda->altura = maxAltura(aux->esquerda) + 1;
      }
      aux->altura = maxAltura(aux) + 1;
      raiz = aux;
    }

    void rotacaoSimplesDireita(NoAVL<T>* raiz) {
      NoAVL* aux;
      aux = raiz->esquerda;
      raiz->esquerda = aux->direita;
      aux->direita = raiz;
      if (aux->direita->esquerda == NULL && aux->direita->direita == NULL) {
        // caso o nó seja uma folha
        aux->direita->altura = 0;
      } else {
        aux->direita->altura = maxAltura(aux->direita) + 1;
      }
      aux->altura = maxAltura(aux) + 1;
      raiz = aux;
    }

    NoAVL<T>* remover(NoAVL<T>* arv, const T& dado) {
      return arv;
    }

    NoAVL<T>* minimo(NoAVL<T>* nodo) {
      return nodo;
    }

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
      return arv->getDado();
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
