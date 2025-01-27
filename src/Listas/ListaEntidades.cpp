#include "ListaEntidades.hpp"

namespace Listas{
    ListaEntidades::ListaEntidades(): listaEnt()
    {
    }

    ListaEntidades::~ListaEntidades()
    {
    }


    void ListaEntidades::incluirEntidade(Entidades::Entidade* pEnte)
    {
        if(pEnte != nullptr){
            listaEnt.incluirElemento(pEnte);
        }
    }

    void ListaEntidades::removerEntidade(Entidades::Entidade *pEnte)
    {
        if(pEnte != nullptr){
            for(Lista<Entidades::Entidade>::Iterator it = listaEnt.inicio(); it !=  listaEnt.fim(); it++){
                if(*it == pEnte){
                    //listaEnt.removerElemento(pEnte);
                    break;
                }
            }
        }
    }
    void ListaEntidades::limparLista()
    {
        listaEnt.limpar();
    }

    void ListaEntidades::executar()
    {
        for(Lista<Entidades::Entidade>::Iterator it = listaEnt.inicio(); it != listaEnt.fim(); it++){
            if(*it != nullptr){
                (*it)->executar();
            }
        }
    }
    void ListaEntidades::atualizar(float dt)
    {
        for(Lista<Entidades::Entidade>::Iterator it = listaEnt.inicio(); it != listaEnt.fim(); it++){
            if(*it != nullptr){
                (*it)->atualizar(dt);
            }
        }
    }
    Lista<Entidades::Entidade> &ListaEntidades::getListaEnt()
    {
        return listaEnt;
    }

}