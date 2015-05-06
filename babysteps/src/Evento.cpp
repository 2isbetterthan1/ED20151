/* Copyright [2015] <LeoSL and marcelinol>
 * Evento.cpp
 */

#ifndef EVENTO_HPP
#define EVENTO_HPP

class Evento {
private:
  double tempo;

public:

  /**
  * Função getTime. Informa o tempo em que esse evento ocorrerá.
  */
  virtual double getTime();

  /**
  * Função executa. Realiza as atividades do evento corrente.
  */
  virtual void executa();

  /**
  * Função igual. Retorna um valor booleano verdadeiro caso dois dados comparados sejam iguais.
  */
    bool igual(Evento dado2) {
      return tempo == dado2.getTime();
    }
  /**
  * Função maior. Retorna um valor booleano verdadeiro caso o primeiro elemento (argumento) seja maior que o segundo (argumento).
  */
    bool maior(Evento dado2) {
      return tempo > dado2.getTime();
    }
  /**
  * Função menor. Retorna um valor booleano verdadeiro caso o primeiro elemento (argumento) seja menor que o segundo (argumento).
  */
    bool menor(Evento dado2) {
      return tempo < dado2.getTime();
    }

  /**
  * Destrutor. Destrutor de um evento.
  */
  virtual ~Evento() { }
};
#endif
