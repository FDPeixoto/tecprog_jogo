#pragma once
#include <Inimigo.hpp>
#include "stdafx.h"

namespace Entidades{
    namespace Inimigos{
        class Durahan:public Inimigo{
            private:
                bool antidoto_mortal;
            public:
                Durahan();
                Durahan(const sf::Vector2f posicao);
                ~Durahan();
                void salvar();
                void salvarDataBuffer();
                void executar();
                void danificar(Entidades::Jogador* pJogador);
                void golpeMortal();
                void setAntidotoMortal(bool flg);
                //bool getVivo();, pega direto de personagem mesmo
                void colisao(Entidade *outraEntidade);
        };
    }
}