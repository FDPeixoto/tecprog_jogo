#include "ListaEntidades.hpp"

namespace Listas{
    ListaEntidades::ListaEntidades(): listaEnt()
    {
    }

    ListaEntidades::~ListaEntidades()
    {
    }


    void ListaEntidades::incluirEntidade(Entidades::Entidade *pEnte)
    {
        if(pEnte != nullptr){
            listaEnt.incluirElemento(&pEnte);
        }
    }

    void ListaEntidades::removerEntidade(Entidades::Entidade *pEnte)
    {
        if(pEnte != nullptr){
            for(Lista<Entidades::Entidade*>::Iterator it = listaEnt.inicio(); it !=  listaEnt.fim(); it++){
                if(**it == pEnte){
                    listaEnt.removerElemento(&pEnte);
                    break;
                }
            }
        }
    }

    Lista<Entidades::Entidade*> ListaEntidades::getListaEnt()
    {
        return listaEnt;
    }

}