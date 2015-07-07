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

    virtual ~NoAVL();

    int getAltura() {
      return this->altura;
    }

    int maxAltura() {
      int alturaEsquerda = 0;
      int alturaDireita = 0;

      if (this->getEsquerda != NULL) {
        alturaEsquerda = this->esquerda.getAltura();
      }
      if (this->getDireita != NULL) {
        alturaDireita = this->direita.getAltura();
      }

      if (alturaEsquerda == 0 && alturaDireita == 0) {
        return 0;
      }

      if (alturaEsquerda > alturaDireita) {
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
      novoNoh->altura = novoNoh->maxAltura();
      arv->altura = arv->maxAltura() + 1;

      // ROTAÇÕES
      NoAVL<T>* filhoDireita = arv->direita;
      NoAVL<T>* filhoEsquerda = arv->esquerda;

      if (filhoEsquerda == NULL) {
        filhoEsquerda = new NoAVL<T>(0);
      }
      if (filhoDireita == NULL) {
        filhoDireita = new NoAVL<T>(0);
      }

      if ( !( filhoDireita.isBalanced() ) ) {
        filhoDireita->balance();
      } else if( !( filhoEsquerda.isBalanced() ) ) {
        filhoEsquerda->balance();
      } else if( !( arv.isBalanced() ) ) {
        arv->balance();
      }
      return novoNoh;
    }

    NoAVL<T>* balance() {
      int fatBal = this->getFatBal();

      // Esquerda desbalanceada
      if (fatBal > 0) {
        int fatBalFilho = this->esquerda.getFatBal();
        if (fatBalFilho > 0) { // Rotação Simples à Direita
          this->rotacaoSimplesDireita();
        } else { // Rotação Dupla (Rotação Simples Esquerda) + (Rotação Simples Direita)
          NoAVL<T>* rotacionado = this->esquerda.rotacaoSimplesEsquerda();
          this->esquerda = rotacionado;
          this->rotacaoSimplesDireita();
        }
      } else { // fatBal < 0 - Direita desbalanceada
        int fatBalFilho = this->direita.getFatBal();
        if (fatBalFilho < 0) { // Rotação Simples à Esquerda
          this->rotacaoSimplesEsquerda();
        } else { // Rotação Dupla (Rotação Simples Direita) + (Rotação Simples Esquerda)
          NoAVL<T>* rotacionado = this->direita.rotacaoSimplesDireita();
          this->direita = rotacionado;
          this->rotacaoSimplesEsquerda();
        }
    }

    NoAVL<T>* rotacaoSimplesEsquerda() {
      NoAVL<T>* filhoDireita = this->direita;
      filhoDireita->esquerda = this;
      this->direita = NULL;
      this->esquerda = NULL;
      return filhoDireita;
    }

    NoAVL<T>* rotacaoSimplesDireita() {
      NoAVL<T>* filhoEsquerda = arv->esquerda;
      filhoEsquerda->direita = this;
      this->direita = NULL;
      this->esquerda = NULL;
      return filhoEsquerda;
    }

    int getFatBal() {
      int alturaEsquerda = -1;
      int alturaDireita = -1;
      if (this->esquerda != NULL) {
        alturaEsquerda = this->esquerda.getAltura();
      }
      if (this->direita != NULL) {
        alturaDireita = this->direita.getAltura();
      }
      return  alturaEsquerda - alturaDireita;
    }

    bool isBalanced(NoAVL<T>* arv) {
      int fatBal = arv->getFatBal();
      bool response = fatBal > -2 && fatBal < 2;
      return response;
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
