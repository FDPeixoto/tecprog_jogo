#pragma once

#include <iostream>

#include "Ente.h"
#include "Entidade.h"

class Entidade::Ente{

protected:
  int x;
  int y;
  ostream buffer;

public:
  Entidade(): Ente(){}
  virtual ~Entidade();
  virtual void executar() = 0;
  virtual void salvar() = 0;
  void salvarDataBuffer();
}
