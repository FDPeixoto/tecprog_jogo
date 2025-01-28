#pragma once
#include "Fase.hpp"
#include "stdafx.h"

namespace Fases{
    class Castelo_Assombrado: public Fase{
        private:
            const int maxChefoes;
        public:
        Castelo_Assombrado();
        ~Castelo_Assombrado();
        void criarInimDificil(const sf::Vector2f posicao);
        void criarInimigos();
        void criarObstaculos();
        const int getMaxChefoes();
        void criarMapa();
        void criarEntidade(char letra, const sf::Vector2f posicao);

    };
}