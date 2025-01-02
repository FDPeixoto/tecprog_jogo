#include "../../include/Entidades/Entidade.hpp"
#include <iostream>
#include <sstream>  // Incluindo sstream para o uso de std::ostringstream

  Entidade::Entidade(): Ente() {}
  void Entidade::setX(float pos){
    x=pos;
  }
  void Entidade::setY(float pos){
    y=pos;
  }
  Entidade::~Entidade(){};
  void Entidade::executar() {}
  void Entidade::salvar() {}
  void Entidade::salvarDataBuffer(){}