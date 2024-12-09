class Elemento{
private:
  Elemento<TE>* pProx;
  TE* pinfo;
public:
  Elemento();
  ~Elemento();
  void incluir(TE* p);
  setProx(Elemento<TE>* pE);
  const Elemento<TE>* getProximo();
}
