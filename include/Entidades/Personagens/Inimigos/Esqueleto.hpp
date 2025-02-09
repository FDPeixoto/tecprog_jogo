#pragma once
#include <Inimigo.hpp>
#include "stdafx.h"

namespace Entidades
{
    namespace Inimigos
    {
        class Esqueleto : public Inimigo
        {
        private:
            float alcanceExtra;

        public:
            Esqueleto();
            Esqueleto(const sf::Vector2f posicao);
            ~Esqueleto();
            void salvar();
            void salvarDataBuffer();
            void executar();
            void danificar(Entidades::Jogador *pJogador);
            bool foraPantano();
            // void colisao(Entidade *outraEntidade);
        };
    }
}