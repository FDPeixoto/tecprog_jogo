#pragma once
#include "Lista.hpp"
#include "../Entidades/Entidade.hpp"
namespace Listas{
    class ListaEntidades{
        private:
        Lista<Entidade> listaEnt;
        
        public:
        ListaEntidades();
        ~ListaEntidades();
        void incluirEntidade(Entidade* pEnte);
        void desenharEntidades(sf::RenderWindow& window);
        void remover(Entidade* Ente);
        void executar();
        void limparLista();
        Entidade* operator[](int pos);
    };
}