#pragma once
#include "Entidade.h"
class Personagem: public Entidade{
protected:
  int num_vidas;
  int velocidade;
public:
  Personagem(int vidas = 5, int vel = 10){
    num_vidas = vidas;
    velocidade = vel;
  }
  ~Personagem();
  salvarDataBuffer();
  virtual void mover();
  virtual void executar() = 0;
}
