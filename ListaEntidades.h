
class ListaEntidades{
private:
  Lista<Entidade> LEs;
public:
  ListaEntidades();
  ~ListaEntidades();
  void incluir(Entidade* pE);
  void percorrer();
}
