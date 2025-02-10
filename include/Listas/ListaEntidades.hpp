#pragma once
#include "Lista.hpp"
#include "../Entidades/Entidade.hpp"
namespace Listas
{
    class ListaEntidades
    {
    private:
        Lista<Entidades::Entidade> listaEnt;

    public:
        ListaEntidades();
        ~ListaEntidades();
        void incluirEntidade(Entidades::Entidade *pEnte);
        void removerEntidade(Entidades::Entidade *pEnte);
        void remover(Entidades::Entidade *Ente);
        void executar();
        void limparLista();
        void atualizar(float dt);
        Entidades::Entidade *operator[](int pos);
        Lista<Entidades::Entidade> &getListaEnt();
    };
}