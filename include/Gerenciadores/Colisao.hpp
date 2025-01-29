#pragma once
#include "ListaEntidades.hpp"
#include "Lista.hpp"
#include <Mediator.hpp>
#include <math.h>
#include "Entidade.hpp"

namespace Gerenciadores{
    class Colisao: public Mediator{
        private:
            Listas::ListaEntidades* listaMoveis;
            Listas::ListaEntidades* listaFixos;
            std::vector<Entidades::Entidade*> vectorEntidades;

            static Colisao* pColisao;
            Colisao();
        public:
            ~Colisao();
            static Colisao* getGerenciadorColisao();
            void setMoveis(Listas::ListaEntidades* moveis);
            void setFixos(Listas::ListaEntidades* fixos);
            const sf::Vector2f calculaColisao(Entidades::Entidade* entidade1, Entidades::Entidade* entidade2);
            bool checarColisao(Entidades::Entidade *entidade1, Entidades::Entidade *entidade2);
            void executar();
            void registrarEntidade(Entidades::Entidade* entidade) override;
            void notificar(Entidades::Entidade *sender, const std::string &evento);
    };
}