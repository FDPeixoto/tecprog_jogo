

namespace Listas{
  class Elementos;

  class Lista{
    private:
      *Elemento<TL> pPrimeiro;
      *Elemento<TL> pUltimo;
    public:
      Lista();
      ~Lista();
      void incluir(*TL p);
      void limpar();
  }
}
