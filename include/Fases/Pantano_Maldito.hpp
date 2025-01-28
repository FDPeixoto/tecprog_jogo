#pragma once
#include "Fase.hpp"
#include "stdafx.h"

namespace Fases{
    class Pantano_Maldito: public Fase{
        private:
        const int maxInimMedios;

        public:
        Pantano_Maldito();
        ~Pantano_Maldito();
        void criarInimMedios();
        void criarInimigos();
        void criarObstaculos();
        const int getMaxInimMedios();
        void criarMapa();
        void criarEntidade(char letra, const sf::Vector2f posicao);
    };

}