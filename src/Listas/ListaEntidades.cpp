#include "ListaEntidades.hpp"

/*
void Listas::ListaEntidades::executar()
{
int tam = listaEnt.getTam();
    Entidade* aux = nullptr;
        for(int i = 0; i < tam; i++){
            
            aux = listaEnt.operator[](i);
            aux->executar();
                
        }
}

const int Listas::ListaEntidades::getTam(){
    return listaEnt.getTam();
 }

 Entidade *Listas::ListaEntidades::operator[](int pos)
 {
    return listaEnt.operator[](pos);
 }

void Listas::ListaEntidades::limparLista(){
    listaEnt.limpar();
}*/

Listas::ListaEntidades::ListaEntidades()
{
}

Listas::ListaEntidades::~ListaEntidades()
{
}


void Listas::ListaEntidades::incluirEntidade(Entidade *pEnte)
{
    if(pEnte != nullptr){
        listaEnt.incluirElemento(pEnte);
    }
}

void Listas::ListaEntidades::desenharEntidades(sf::RenderWindow& window){
    Lista<Entidade>::Elemento<Entidade>* pEleAux = nullptr;
    Entidade* pEntAux = nullptr;
    pEleAux = listaEnt.getPrimeiro();
    while (pEleAux != nullptr){
        pEntAux = pEleAux->getInfo();
        pEntAux->desenhar(window);
        pEleAux = pEleAux->getProx();
    }
} 