#pragma once
#include "Fase.hpp"
#include "stdafx.h"
#include <vector>

namespace Fases{
    class Castelo_Assombrado: public Fase{
        private:
        const int maxChefoes;
        std::vector<Entidades::Inimigos::Durahan*> vetorDurahan;
        int cont_D;
        int it_D;
        //std::vector<Entidades::Inimigos::Durahan*> vetorCanhao;

        public:
        Castelo_Assombrado();
        ~Castelo_Assombrado();
        void criarInimDificil(const sf::Vector2f posicao);
        //void criarCanhao(const sf::Vector2f posicao);
        void criarInimigos();
        void criarObstaculos();
        const int getMaxChefoes();
        void criarMapa();
        void criarEntidade(char letra, const sf::Vector2f posicao);
        void executar();

    };
}