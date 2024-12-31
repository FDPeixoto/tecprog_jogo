//O código do Giovani foi utilizado como inspiração: https://github.com/Giovanenero/JogoPlataforma2D-Jungle/blob/main/Jungle%2B%2B/include/Lista/Elemento.hpp
#pragma once
#include <iostream>

namespace Lista{

    template <class TE>
    class Elemento{
    private:
        Elemento<TE>* pProx;
        TE* pInfo;
    public:
        Elemento();
        ~Elemento();
        void incluir(TE* p);
        void setProx(Elemento<TE>* pE);
        const Elemento<TE>* getProximo();
    };
    template<class TE>
    Elemento<TE>::Elemento():
    pProx(nullptr), pInfo(nullptr)
    {
    }
    template<class TE>
    Elemento<TE>::~Elemento()
    {
    }

    template<class TE>
    void Elemento<TE>::incluir(TE* p){
        this->elemento = elemento;
    }
    template<class TE>
    void Elemento<TE>::setProx(Elemento<TE>* pE){
        this->prox = prox;
    }
    template<class TE>
    const Elemento<TE>* Elemento<TE>::getProximo(){
        return prox;
    }

}