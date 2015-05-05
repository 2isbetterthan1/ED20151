/* Copyright [2015] <LeoSL and marcelinol>
 * Evento.cpp
 */

#ifndef EVENTO_HPP
#define EVENTO_HPP

class Evento {
private:
  double tempo;

public:
  virtual double getTime() = 0;
  virtual ~Evento() { }
};
#endif
