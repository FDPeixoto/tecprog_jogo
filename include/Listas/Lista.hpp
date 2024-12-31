
//O código do Giovani foi tulizado como inspiração: https://github.com/Giovanenero/JogoPlataforma2D-Jungle/blob/main/Jungle%2B%2B/include/Lista/Lista.hpp
#pragma once
#include "Elemento.hpp"
#include <iostream>

namespace Listas{

  template<class TL>
  class Lista{
    private:
      *Elemento<TL> pPrimeiro;
      *Elemento<TL> pUltimo;
      unsigned int tam;
    public:
      Lista();
      ~Lista();
      void incluir(TL* p);
      void removerElemento(TL* elem);
      void limpar();
      void listar();
  };

  template<class TL>
  Lista<TL>::Lista():
  pInicio(nullptr), pUltimo(nullptr), tam(0)
  {
  }

  template<class TL>
  Lista<TL>::~Lista()
  {
   limpar();
  }
  
  // Implementação da função incluir
  template<class TL>
  //void incluir(*TL p);
  void Lista<TL>::incluir(TL* p) {
    if(p==nullptr){
        std::cout<<"ERROR: Nao pode inserir elemento nulo"<<std::endl;
        exit(1);
    }
    Elemento<TL>* novoElemento = new Elemento<TL>(p);
    if(novoElemento==nullptr){
      std::cout << "ERROR::Elemento alocado eh null" << std::endl;
        exit(1);
    }
    if (pUltimo != nullptr) {
      pUltimo->proximo = novoElemento;
    }
    pUltimo = novoElemento;//O pUltimo eh null, posso inserir nesse local
    if (pPrimeiro == nullptr) {
      pPrimeiro = novoElemento;
    }
    tam++;
  }
  template<class TL>
  void Lista<TL>::removerElemento(TL* elem) {
    if(elem==nullptr){
      std::cout << "ERROR::Elemento para remocao eh null" << std::endl;
      exit(1);
    }
    Elemento<TL>* atual = pPrimeiro;
    Elemento<TL>* anterior = nullptr;

    while (atual != nullptr && atual->pInfo != elem) {
      anterior = atual;
      atual = atual->proximo;
    }

    if (atual != nullptr) {//achei o elemnto e a lista nao acabou
      if (anterior != nullptr) {
        anterior->proximo = atual->proximo;
      } else {
        pPrimeiro = atual->proximo;
      }

      if (atual == pUltimo) {
        pUltimo = anterior;
      }

      delete atual;
    }
  }

   template<class TL>
  void Lista<TL>::limpar() {
    Elemento<TL>* atual = pPrimeiro;
    while (atual != nullptr) {
      Elemento<TL>* temp = atual;
      atual = atual->proximo;
      delete temp;  
    }
    pPrimeiro = nullptr;
    pUltimo = nullptr;
  }

  template<class TL>
  void Lista<TL>::listar() {
    Elemento<TL>* atual = pPrimeiro;
    if(atual==nullptr){
      std::cout << "  A lista esta vazia" << std::endl;
    }
    while (atual != nullptr) {
      std::cout << *(atual->pInfo) << ",   ";
      atual = atual->proximo;
    }
    std::cout << "  Acabou a lista" << std::endl;
  }

}