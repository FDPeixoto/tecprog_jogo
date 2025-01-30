#pragma once
#include <Inimigo.hpp>
#include "Projetil.hpp"
#include "stdafx.h"
#include "ListaEntidades.hpp"
#include <list>

namespace Entidades{
    namespace Inimigos{
        class Durahan:public Inimigo{
            private:
                bool antidoto_mortal;
                std::list<Entidades::Entidade*> listaProjetil;
                int tiros;
                int it;
                int aleatorio;
            public:
                Durahan();
                Durahan(const sf::Vector2f posicao);
                ~Durahan();
                void salvar();
                void salvarDataBuffer();
                void executar();
                void danificar(Entidades::Jogador* pJogador);
                void golpeMortal();
                void atirar();
                void setAntidotoMortal(bool flg);
                //bool getVivo();, pega direto de personagem mesmo
                void colisao(Entidade *outraEntidade);
                std::list<Entidades::Entidade*>& getListaProjetil();
                void criarProjetil();
        };
    }
}