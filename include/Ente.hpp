#pragma once

class Ente
{
protected:
  int id;

public:
  static int id_global;
  Ente();
  Ente(int ID);
  virtual ~Ente();

  virtual void executar() = 0;
  void desenhar();
  const int getID();
};