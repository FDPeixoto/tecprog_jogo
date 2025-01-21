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
            listaEnt.incluirElemento(pEnte);
        }
    }

    Lista<Entidades::Entidade> ListaEntidades::getListaEnt()
    {
        return listaEnt;
    }

}