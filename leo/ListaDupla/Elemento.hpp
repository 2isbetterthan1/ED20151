/* Copyright [2015] <LeoSL>
 * Elemento.hpp
 */
#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP

template<typename T>

/**
* Classe Elemento. Cada elemento de lista referencia o próximo elemento e só é alocado dinamicamente quando necessário.
*/
class Elemento {
 private:
  T* info;
  Elemento<T>* _antecedent;
  Elemento<T>* _next;

 public:
/**
* Construtor. Construtor de um elemento.
*/
  Elemento(const T& info, Elemento<T>* next) : info(new T(info)), _next(next) {}
/**
* Destrutor. Destrutor de um elemento.
*/
  ~Elemento() {
    delete info;
  }
/**
* Função getProximo. Retorna a referência do próximo elemento da lista encadeada.
*/
  Elemento<T>* getProximo() {
    return _next;
  }
/**
* Função getBack. Retorna a referência do elemento anterior da lista encadeada.
*/
  Elemento<T>* getBack() {
    return _antecedent;
  }
/**
* Função getInfo. Retorna o valor do elemento de uma lista encadeada.
*/
  T getInfo() const {
    return *info;
  }
/**
* Função setInfo. Grava o valor (argumento) de um elemento de uma lista encadeada.
*/
  void setInfo(T* dado) {
    info = *dado;
  }
/**
* Função setProximo. Grava a referência ao próximo elemento da lista encadeada.
*/
  void setProximo(Elemento<T>* next) {
    _next = next;
  }
/**
* Função setAnterior. Grava a referência ao elemento anterior da lista encadeada.
*/
  void setAnterior(Elemento<T>* antecedent) {
    _antecedent = antecedent;
  }
};

#endif
