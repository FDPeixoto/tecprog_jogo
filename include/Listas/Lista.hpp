//O código do Giovani foi tulizado como inspiração: https://github.com/Giovanenero/JogoPlataforma2D-Jungle/blob/main/Jungle%2B%2B/include/Lista/Lista.hpp
//O codigo do professor Jean Simao tambem foi utilizado como inspiracao
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
        Elemento<TE>* pAnte;
      public:
        Elemento(): pInfo(nullptr), pProx(nullptr), pAnte(nullptr){}

        Elemento(TE* info): pInfo(info), pProx(nullptr), pAnte(nullptr){}
        
        ~Elemento(){
          pInfo = nullptr;
          pProx = nullptr;
          pAnte = nullptr;
        }

        void setInfo(TE* p){pInfo = p;}
        
        TE* getInfo(){return pInfo;}

        void setProx(Elemento<TE>* pP){pProx = pP;}
        
        const Elemento<TE>* getProx(){return pProx;}

        void setAnte(Elemento<TE>* pA){}
        
        const Elemento<TE>* getAnte(){return pAnte;}
    };

  private:
    Elemento<TL>* pPrimeiro;
    Elemento<TL>* pAtual;
    int tam;

  public:
    Lista(): pPrimeiro(nullptr), pAtual(nullptr){tam = 0;}
    
    ~Lista(){
      Elemento<TL>* aux = pPrimeiro;
      while (aux != nullptr)
      {
        pPrimeiro = aux->getProx();
        delete aux;
        aux = pPrimeiro;
      }
    }

    Elemento<TL>* getPrimeiro(){return pPrimeiro;}
    
    Elemento<TL>* getAtual(){return pAtual;}

    Elemento<TL>* getTam(){return tam;}

    void limpar(){
      
    }

    void incluirElemento(TL* pElemento){
      if (pElemento != nullptr)
      {
        Elemento<TL>* pAux = new Elemento<TL>();
        pAux->setInfo(pElemento);
        pAux->setProx(nullptr);
        pAux->setAnte(nullptr);
        if (pPrimeiro == nullptr)
        {
          pPrimeiro = pAux;
          pAtual = pPrimeiro;		
        }
        else
        {
          pAtual->setProx( pAux);
          pAux->setAnte( pAtual );
          pAtual = pAux;
        }
        tam++;
      }
    }
  };
}