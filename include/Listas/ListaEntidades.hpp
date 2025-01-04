#pragma once
#include "Lista.hpp"
#include "../Entidades/Entidade.hpp"
namespace Listas{
    class ListaEntidades{
        private:
        Listas::Lista<Entidade> objLEs;
        
        public:
        ListaEntidades();
        ~ListaEntidades();
        void incluir(Entidade* entidade);
        void remover(Entidade* entidade);
        void executar();
        void limparLista();
        const int getTam();
        Entidade* operator[](int pos);
    };
}