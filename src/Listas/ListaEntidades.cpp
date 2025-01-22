#include "ListaEntidades.hpp"

namespace Listas{
    ListaEntidades::ListaEntidades(): listaEnt(new Listas::Lista<Entidades::Entidade>())
    {
    }

    ListaEntidades::~ListaEntidades()
    {
    }


    void ListaEntidades::incluirEntidade(Entidades::Entidade *pEnte)
    {
        if(pEnte != nullptr){
            listaEnt->incluirElemento(pEnte);
        }
    }

    Lista<Entidades::Entidade>* ListaEntidades::getListaEnt()
    {
        return listaEnt;
    }

}