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
  * Destrutor. Destrutor de um evento.
  */
  virtual ~Evento() { }
};
#endif
