#pragma once
#include "Fase.hpp"
#include "Plataforma.hpp"
#include "stdafx.h"
#include <vector>

namespace Fases{
    class Castelo_Assombrado: public Fase{
        private:
        const int maxChefoes;
        int  maxEsp;
        int it_Esp;
        int maxM;
        int it_M;
        int maxP;
        int it_P;
        std::vector<Entidades::Inimigos::Durahan*> vetorDurahan;
        int cont_D;
        int it_D;
        int aleatoriedadeP;
        Entidades::Obstaculos::Plataforma fundo;

        public:
        Castelo_Assombrado();
        ~Castelo_Assombrado();
        void criarInimDificil(const sf::Vector2f posicao);
        void criarEspinho(const sf::Vector2f posicao);
        const int getMaxChefoes();
        void criarMapa();
        void criarEntidade(char letra, const sf::Vector2f posicao);
        void executar();

    };
}