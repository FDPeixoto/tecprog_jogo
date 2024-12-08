class Ente{
private:
  int id;

public:
  static int id_global;
  Ente();
  virtual ~Ente();
  virtual void executar();
  void desenhar();
}
