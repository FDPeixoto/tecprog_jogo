#pragma once
#include "Jogador.hpp"
class Jogador:public Entidade{
protected:
  int pontos;
  int numero_baixas;
  bool espada;
  bool magia;
  bool antidoto;

public:
  Jogador(): Entidade(), pontos(0), numero_baixas(0), espada (false), magia (false), antidoto (false){};
  ~Jogador(){};
  void salvarDataBuffer(){};
  virtual void mover(){};
  virtual void executar() {};
};