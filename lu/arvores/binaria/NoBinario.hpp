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
  T *dado;
  NoBinario<T>* esquerda;
  NoBinario<T>* direita;
  std::vector<NoBinario<T>* > elementos;
  typename std::vector<NoBinario<T>*>::iterator i = elementos.begin();

 public:
  NoBinario<T>(const T& data) {
    dado = new T(data);
    esquerda = 0;
    direita = 0;
  }

  virtual ~NoBinario() {
    delete this->dado;
  }

  T* getDado() {
    return this->dado;
  }

  void setDado(T data) {
    this->dado = *data;
  }

  NoBinario<T>* inserir(const T& dado, NoBinario<T>* arv) {
    NoBinario<T>* novoNoh = new NoBinario<T>(dado);
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
    return novoNoh;
  }

  NoBinario<T>* getEsquerda() {
    return this->esquerda;
  }

  NoBinario<T>* getDireita() {
    return this->direita;
  }

  T* busca(const T& dado, NoBinario<T>* arv) {
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
    NoBinario<T>* temp = new NoBinario<T>(0);
    NoBinario<T>* filho = new NoBinario<T>(0);
    if (arv == NULL) {
      return arv;
    } else {
      if (dado < *arv->getDado()) {
        arv->esquerda = remover(arv->getEsquerda(), dado);
        return arv;
      } else {
        if (dado > *arv->getDado()) {
          arv->direita = remover(arv->getDireita(), dado);
          return arv;
        } else {
          if (arv->getDireita() != NULL && arv->getEsquerda() != NULL) {
            temp = minimo(arv->getDireita());
            arv->dado = temp->getDado();
            arv->direita = remover(arv->getDireita(), *arv->getDado());
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
                arv->~NoBinario();
                return NULL;
              }
            }
          }
        }
      }
    }
  }

  void addElemento(NoBinario<T>* nodo) {
    elementos += nodo;
  }

  void preOrdem(NoBinario<T>* nodo) {
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

  void emOrdem(NoBinario<T>* nodo) {
    if (nodo->getEsquerda() != NULL) {
      emOrdem(nodo->getEsquerda());
    }
    elementos.push_back(nodo);
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
      elementos.push_back(nodo);
    }
    elementos.end();
  }
};

#endif
