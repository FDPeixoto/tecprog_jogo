#include "Ente.h"

class Ente{
protected:
  int id;
  //static *Gerenciador_Grafico pGG;
  //*Figura pFig;

public:
  static int id_global;
  Ente(){
    id = id_global;
    id_global++;
  }
  virtual ~Ente(){
    //pGG = NULL;
    //pFig = NULL;
  }
  virtual void executar() = 0;
  void desenhar(){}
}
