#pragma once
#include "Personagem.hpp"
class Personagem: public Entidade{
protected:
  int num_vidas;
  int velocidade;
public:
  Personagem(int vidas = 5, int vel = 10){
    num_vidas = vidas;
    velocidade = vel;
  }
  ~Personagem(){};
  void salvarDataBuffer(){};
  virtual void mover(){};
  virtual void executar() {};
};