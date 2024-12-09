
  class Elementos;

  class Lista{
  private:
    *Elemento<TL> pPrimeiro;
    *Elemento<TL> pUltimo;
  public:
    Lista(){
      pPrimeiro = NULL;
      pUlitmo = NULL;
    }
    ~Lista();
    void incluir(*TL p);
    void limpar();
  }
