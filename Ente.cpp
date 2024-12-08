class Ente{
private:
  int id;

public:
  static int id_global;
  Ente(){
    id  
  }
  virtual ~Ente(){

  }
  virtual void executar() = 0;

  void desenhar(){
    
  }
}
