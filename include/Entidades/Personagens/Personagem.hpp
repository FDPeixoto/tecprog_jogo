#pragma once
#include "Entidade.hpp"
class Personagem:public Entidade{
protected:
  int num_vidas;
  int velocidade;
public:
  Personagem();
  ~Personagem();
  void salvarDataBuffer();
  virtual void mover();
  virtual void executar() = 0;
};