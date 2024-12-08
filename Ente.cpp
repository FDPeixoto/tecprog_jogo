#include "Ente.h"

class Ente{
private:
  int id;

public:
  static int id_global;
  Ente(){
    id = id_global;
    id_global++;
  }
  virtual ~Ente(){}
  virtual void executar() = 0;
  void desenhar(){}
}
