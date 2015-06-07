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

    };
    virtual ~NoBinario();
    T* getDado();
    std::vector< NoBinario<T>* > getElementos();
    NoBinario<T>* getEsquerda();
    NoBinario<T>* getDireita();

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
