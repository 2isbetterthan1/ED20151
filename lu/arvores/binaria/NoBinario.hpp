/* Copyright [2015] <marcelinol>
 * NoBinario.hpp
 */

#ifndef NO_BINARIO_HPP
#define NO_BINARIO_HPP

#include <cstdlib>
#include <vector>

template <typename T>
class NoBinario {
 protected:
    T* dado;
    NoBinario<T>* esquerda;
    NoBinario<T>* direita;
    std::vector<NoBinario<T>* > elementos;  //!< Elementos acessados durante
                                            // o percurso realizado

 public:
    NoBinario<T>(const T& dado) {
      this->dado = dado;
      this->esquerda = NULL;
      this->direita = NULL;
    };

    virtual ~NoBinario();

    T* getDado() {
      return this->dado;
    };

    std::vector< NoBinario<T>* > getElementos() {
      return this->elementos;
    };

    NoBinario<T>* getEsquerda() {
      return this->esquerda;
    };

    NoBinario<T>* getDireita() {
      return this->direita;
    };

    T* busca(const T& dado, NoBinario<T>* arv) {
      while (arv != NULL && arv->getDado() != dado) {
        if (arv->getDado() < dado) {
          arv = arv->getDireita();
        } else {
          arv = arv->getEsquerda();
        }
      }
      return arv;
    };

    NoBinario<T>* inserir(const T& dado, NoBinario<T>* arv) {
      NoBinario<T>* novo = new NoBinario<T>(dado); //NAO SEI INSTANCIAR SACARALHA
      if (dado < arv->getDado()) {
        if (arv->getEsquerda() == NULL) {
          novo = arv;
          // novo->dado = dado; //JÁ COLOQUEI O DADO PELO CONSTRUTOR NA PRIMEIRA LINHA
          novo->esquerda = NULL;
          novo->direita = NULL;
          arv->esquerda = novo;
        } else {
          arv = inserir(arv->getEsquerda(), dado);
        }
      } else {
        if (arv->getDireita() == NULL) {
          novo = arv;
          // novo->dado = dado; //JÁ COLOQUEI O DADO PELO CONSTRUTOR NA PRIMEIRA LINHA
          novo->esquerda = NULL;
          novo->direita = NULL;
          arv->direita = novo;
        } else {
          arv = inserir(arv->getDireita(), dado);
        }
      }
    };

    NoBinario<T>* remover(NoBinario<T>* arv, const T& dado) {
      NoBinario<T>* temp = new NoBinario<T>(NULL);
      NoBinario<T>* filho = new NoBinario<T>(NULL;)
      if (arv == NULL) {
        return arv;
      } else {
        if (dado < arv->getDado()) {
          arv->getEsquerda() = remover(dado, arv->getEsquerda());
          return arv;
        } else {
          if (dado > arv->getDado()) {
            arv->getDireita() = remover(dado, arv->getDireita());
            return arv;
          } else {
            if (arv->getDireita() != NULL && arv->getEsquerda() != NULL) {
              temp = minimo(arv->getDireita());
              arv->dado = temp->getDado();
              arv->direita = remover(arv->getDado(), arv->getDireita());
              return arv;
            } else {
              temp = arv;
              if (arv->getDireita() != NULL) {
                filho = arv->getDireita();
                return filho;
              } else {
                if (arv->getEsquerda() != NULL) {
                  filho = arv->getEsquerda();
                  return filho;
                } else {
                  // LIBERE ARV???
                  return NULL;
                }
              }
            }
          }
        }
      }
    };

    NoBinario<T>* minimo(NoBinario<T>* nodo);

    void preOrdem(NoBinario<T>* nodo) {
      if (novo != NULL) {
        printf(noto->getDado());
        preOrdem(nodo->getEsquerda());
        preOrdem(nodo->getDireita());
      }
    };

    void emOrdem(NoBinario<T>* nodo) {
      if (nodo != NULL) {
        emOrdem(nodo->getEsquerda());
        printf(nodp>getDado());
        emOrdem(nodo->getDireita());
      }
    };

    void posOrdem(NoBinario<T>* nodo) {
      if (nodo != NULL) {
        posOrdem(nodo->getEsquerda());
        posOrdem(nodo->getDireita());
        printf(nodo->getDado());

      }
    };
};

#endif
