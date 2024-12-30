
class Ente{
protected:
  int id;
  //static *Gerenciador_Grafico pGG;
  //*Figura pFig;

public:
  static int id_global;
  Ente();
  virtual ~Ente();
  virtual void executar();
  void desenhar();
};