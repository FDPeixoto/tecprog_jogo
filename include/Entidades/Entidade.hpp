#pragma once

#include "Ente.hpp"
#include <iostream>
#include <sstream>  // Incluindo sstream para o uso de std::ostringstream

class Entidade: public Ente{

protected:
  float x; //era int
  float y; //era int
  std::ostringstream buffer;  // Usando std::ostringstream em vez de std::ostream

public:
  Entidade();
  virtual ~Entidade();
    void setX(float pos);
  void setY(float pos);
  virtual void executar() = 0;
  virtual void salvar() = 0;
  void salvarDataBuffer();
};