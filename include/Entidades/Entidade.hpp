#pragma once

#include "Ente.hpp"
#include "Entidade.hpp"
#include <iostream>
#include <sstream>  // Incluindo sstream para o uso de std::ostringstream

class Entidade: public Ente{

protected:
  int x;
  int y;
  std::ostringstream buffer;  // Usando std::ostringstream em vez de std::ostream

public:
  Entidade();
  virtual ~Entidade();
  virtual void executar() = 0;
  virtual void salvar() = 0;
  void salvarDataBuffer();
};