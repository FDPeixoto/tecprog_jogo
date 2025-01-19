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


void Listas::ListaEntidades::incluirEntidade(Entidades::Entidade *pEnte)
{
    if(pEnte != nullptr){
        listaEnt.incluirElemento(pEnte);
    }
}

Listas::Lista<Entidades::Entidade> Listas::ListaEntidades::getListaEnt()
{
    return listaEnt;
}
