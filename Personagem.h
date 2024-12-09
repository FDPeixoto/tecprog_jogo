#pragma once
#include "Entidade.h"
class Personagem:public Entidade{
protected:
  int num_vidas;
  int velocidade;
public:
  Personagem();
  ~Personagem();
  salvarDataBuffer();
  virtual void mover();
  virtual void executar() = 0;
}
