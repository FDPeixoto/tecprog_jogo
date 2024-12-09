class Elemento{
private:
  Elemento<TE>* pProx;
  TE* pinfo;
public:
  Elemento(){
    pProx = NULL;
    pinfo = NULL;
  }
  ~Elemento();
  void incluir(TE* p){
    if(p != NULL){
      pinfo = p;
    }
  }
  setProx(Elemento<TE>* pE){
    if(pE != NULL){
      pProx = pE;
    }
  }
  const Elemento<TE>* getProximo(){return pProx;}
}
