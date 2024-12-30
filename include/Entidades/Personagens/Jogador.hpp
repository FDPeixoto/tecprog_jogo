#pragma once
#include "Entidade.hpp"
namespace Personagens{
class Jogador:public Entidade{
protected:
  int pontos;
  int numero_baixas;
  bool espada;
  bool magia;
  bool antidoto;

public:
  Jogador();
  ~Jogador();
  void salvarDataBuffer();
  virtual void mover();
  virtual void executar() = 0;
};
}