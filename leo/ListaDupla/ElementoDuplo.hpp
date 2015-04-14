/* Copyright [2015] <LeoSL>
 * Elemento.hpp
 */
#ifndef ELEMENTODUPLO_HPP
#define ELEMENTODUPLO_HPP

template<typename T>

/**
* Classe ElementoDuplo. Cada elemento de lista referencia o próximo elemento e só é alocado dinamicamente quando necessário.
*/
class ElementoDuplo {
 private:
  T *info;
  ElementoDuplo<T>* _antecedent;
  ElementoDuplo<T>* _next;

 public:
/**
* Construtor. Construtor de um elemento.
*/
  ElementoDuplo(const T& info, ElementoDuplo<T>* antecedent, ElementoDuplo<T>* next) : info(new T(info)), _antecedent(antecedent), _next(next) {}
/**
* Destrutor. Destrutor de um elemento.
*/
  ~ElementoDuplo() {
    delete info;
  }
/**
* Função getProximo. Retorna a referência do próximo elemento da lista encadeada.
*/
  ElementoDuplo<T>* getProximo() {
    return _next;
  }
/**
* Função getBack. Retorna a referência do elemento anterior da lista encadeada.
*/
  ElementoDuplo<T>* getBack() {
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
  void setProximo(ElementoDuplo<T>* next) {
    _next = next;
  }
/**
* Função setAnterior. Grava a referência ao elemento anterior da lista encadeada.
*/
  void setAnterior(ElementoDuplo<T>* antecedent) {
    _antecedent = antecedent;
  }
};

#endif
