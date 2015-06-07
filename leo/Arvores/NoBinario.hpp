/* Copyright [2015] <LeoSL>
 * NoBinario.hpp
 */
#ifndef NO_BINARIO_HPP
#define NO_BINARIO_HPP

#include <cstdlib>
#include <vector>

template <typename T>
class NoBinario {
 protected:
  T *dado;
  NoBinario<T>* esquerda;
  NoBinario<T>* direita;
  std::vector<NoBinario<T>* > elementos;
  typename std::vector<NoBinario<T>*>::iterator i;

 public:
  NoBinario<T>(const T& data) {
    dado = new T(data);
    esquerda = NULL;
    direita = NULL;
  }

  virtual ~NoBinario() {
    elementos;
  }

  T* getDado() {
    return this->dado;
  }

  void setDado(T data) {
    this->dado = *data;
  }

  NoBinario<T>* inserir(const T& dado, NoBinario<T>* arv) {
    NoBinario<T>* novoNoh = new NoBinario<T>(dado);
    if (dado != 0) {
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
    } else {
      if (dado == *arv->getDado()) {
        return arv;
      } else {
        throw("erro");
      }
    }
    return novoNoh;
  }

  NoBinario<T>* getEsquerda() {
    return this->esquerda;
  }

  NoBinario<T>* getDireita() {
    return this->direita;
  }

  T* busca(const T& dado, NoBinario<T>* arv) {
    if (dado != 0 && arv != NULL) {
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

  NoBinario<T>* minimo(NoBinario<T>* nodo) {
    if (nodo->getEsquerda() == NULL) {
      return nodo;
    } else {
      nodo->minimo(nodo->getEsquerda());
    }
  }

  std::vector< NoBinario<T>* > getElementos() {
    return this->elementos;
  }

  NoBinario<T>* remover(NoBinario<T>* arv, const T& dado) {
  }

  void preOrdem(NoBinario<T>* nodo) {
    if (nodo != NULL) {
      // adiciona em elementos
      i = elementos.begin();
      i = elementos.insert(i, nodo);
      if (nodo->getEsquerda() != NULL) {
        preOrdem(nodo->getEsquerda());
      }
      if (nodo->getDireita() != NULL) {
        preOrdem(nodo->getDireita());
      }
    }
    elementos.end();
  }

  void emOrdem(NoBinario<T>* nodo) {
    if (nodo->getEsquerda() != NULL) {
      emOrdem(nodo->getEsquerda());
    }
    i = elementos.begin();
    i = elementos.insert(i, nodo);
    if (nodo->getDireita() != NULL) {
      emOrdem(nodo->getDireita());
    }
    elementos.end();
  }

  void posOrdem(NoBinario<T>* nodo) {
    if (nodo != NULL) {
      if (nodo->getEsquerda() != NULL) {
        posOrdem(nodo->getEsquerda());
      }
      if (nodo->getDireita() != NULL) {
        posOrdem(nodo->getDireita());
      }
      i = elementos.begin();
      i = elementos.insert(i, nodo);
    }
    elementos.end();
  }
};

#endif /* NO_BINARIO_HPP */

