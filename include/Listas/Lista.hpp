
//O código do Giovani foi tulizado como inspiração: https://github.com/Giovanenero/JogoPlataforma2D-Jungle/blob/main/Jungle%2B%2B/include/Lista/Lista.hpp
#pragma once
#include <iostream>

namespace Listas{

  template<class TL>
  class Lista{

    //Classe elemento eh aninhada 
    template<class TE>
    class Elemento{
      private:
        TE* pInfo;
        Elemento<TE>* pProx;
      public:
        Elemento(): pInfo(nullptr), pProx(nullptr){}
        ~Elemento();
        void incluir(TE* p){
          if(p != nullptr){pInfo = p;}
        }
        void setProx(Elemento<TE>* pE){
          if(pE != nullptr){pProx = pE;}
        }
        const Elemento<TE>* getProximo(){
          return pProx;
        }
    };

  Elemento<TL>* pAuxiliarPrimeiro; 
  Elemento<TL>* pAuxiliarUltimo;   

  private:
    Elemento<TL>* pPrimeiro, pUltimo;
  public:
    /*
    Lista();
    ~Lista();
    void incluir(TL* p);
    void removerElemento(TL* elem);
    void limpar();
    void listar();
    const int getTam(): */
  };
}