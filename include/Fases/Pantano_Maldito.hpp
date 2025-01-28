#pragma once
#include "Fase.hpp"
#include "stdafx.h"
#include "Esqueleto.hpp"
#include "Durahan.hpp"//para teste

namespace Fases{
    class Pantano_Maldito: public Fase{
        private:
        const int maxInimMedios;

        public:
        Pantano_Maldito();
        ~Pantano_Maldito();
        void criarInimMedio(const sf::Vector2f posicao);
        void criarInimigos();
        void criarObstaculos();
        const int getMaxInimMedios();
        void criarMapa();
        void criarEntidade(char letra, const sf::Vector2f posicao);


        void criarInimDificil(const sf::Vector2f posicao);
    };

}