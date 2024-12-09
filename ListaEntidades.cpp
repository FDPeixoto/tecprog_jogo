
class ListaEntidades{
private:
  Lista<Entidade> LEs;
public:
  ListaEntidades(){
    LEs();
    LEs.limpar();
  }
  ~ListaEntidades();
  void incluir(Entidade* pE){
    if(pE != NULL){
      LEs.incluir(pE);
    } 
  }
  void percorrer();
}
