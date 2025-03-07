

#pragma once
#include <iostream>
// A lista tem como base a Lista Template explicada pelo professor Dr. Jean M. Simao: https://pessoal.dainf.ct.utfpr.edu.br/jeansimao/Fundamentos2/LinguagemC++UML/Funda
// mentos2-SlidesC++10B-2020-07-20.pdf
namespace Listas
{

  template <class TL>
  class Lista
  {
  public:
    template <class TE>
    class Elemento
    {
    private:
      TE *pInfo;
      Elemento<TE> *pProx;
      Elemento<TE> *pAnte;

    public:
      Elemento() : pInfo(nullptr), pProx(nullptr), pAnte(nullptr) {}

      Elemento(TE *info) : pInfo(info), pProx(nullptr), pAnte(nullptr) {}

      ~Elemento()
      {
        pInfo = nullptr;
        pProx = nullptr;
        pAnte = nullptr;
      }

      void setInfo(TE *p) { pInfo = p; }

      TE *getInfo() { return pInfo; }

      void setProx(Elemento<TE> *pP) { pProx = pP; }

      Elemento<TE> *getProx() { return pProx; }

      void setAnte(Elemento<TE> *pA) { pAnte = pA; }

      Elemento<TE> *getAnte() { return pAnte; }
    };
    class Iterator
    {
    private:
      Elemento<TL> *pAtual;

    public:
      Iterator(Elemento<TL> *elemento) : pAtual(elemento) {}

      TL *operator*()
      {
        return pAtual->getInfo();
      }

      Iterator &operator++()
      {
        pAtual = pAtual->getProx();
        return *this;
      }

      Iterator operator++(int)
      {
        Iterator aux = *this;
        ++(*this);
        return aux;
      }

      bool operator==(const Iterator &pOutro) const
      {
        return pAtual == pOutro.pAtual;
      }
      bool operator!=(const Iterator &pOutro) const
      {
        return !(*this == pOutro);
      }
      friend class Lista;
    };

  private:
    Elemento<TL> *pPrimeiro;
    Elemento<TL> *pUltimo;
    int tam;

  public:
    Lista() : pPrimeiro(nullptr), pUltimo(nullptr) { tam = 0; }

    ~Lista()
    {
      limpar();
    }

    void incluirElemento(TL *pElemento)
    {
      if (pElemento != nullptr)
      {
        Elemento<TL> *pAux = new Elemento<TL>();
        pAux->setInfo(pElemento);
        pAux->setProx(nullptr);
        if (pPrimeiro == nullptr)
        {
          pAux->setAnte(nullptr);
          pPrimeiro = pAux;
          pUltimo = pPrimeiro;
        }
        else
        {
          pUltimo->setProx(pAux);
          pAux->setAnte(pUltimo);
          pUltimo = pAux;
        }
        tam++;
      }
    }

    void removerElemento(TL *pElemento)
    {
      if (pElemento == nullptr || pPrimeiro == nullptr)
      {
        return;
      }

      Elemento<TL> *aux = pPrimeiro;
      while (aux != nullptr && aux->getInfo() != pElemento)
      {
        aux = aux->getProx();
      }

      if (aux == nullptr)
      {
        return;
      }

      Elemento<TL> *ante = aux->getAnte();
      Elemento<TL> *prox = aux->getProx();

      if (ante != nullptr)
      {
        ante->setProx(prox);
      }
      else
      {
        pPrimeiro = prox;
      }

      if (prox != nullptr)
      {
        prox->setAnte(ante);
      }
      else
      {
        pUltimo = ante;
      }

      delete aux;
      tam--;
    }

    void limpar()
    {
      Elemento<TL> *aux = pPrimeiro;
      while (aux != nullptr)
      {
        pPrimeiro = aux->getProx();
        delete aux;
        aux = pPrimeiro;
      }
      tam = 0;
    }

    Iterator inicio() { return Iterator(pPrimeiro); }
    Iterator fim() { return Iterator(nullptr); }
    const int getTam() { return tam; }
  };
}