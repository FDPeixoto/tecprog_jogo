#include "Ente.hpp"

  Ente::Ente(int ID): id(ID){}
  Ente::~Ente(){
      // pGG = NULL;
      
    //pFig = NULL;
  }
  void Ente::executar() {};
  void Ente::desenhar(){};
const int Ente::getID(){return id;}
