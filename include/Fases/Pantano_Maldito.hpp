#pragma once
#include "Fase.hpp"
#include "stdafx.h"
#include "Esqueleto.hpp"
#include "Durahan.hpp"//para teste
#include <vector>

namespace Fases{
    class Pantano_Maldito: public Fase{
        private:
        const int maxInimMedios;
        //Entidades::Inimigos::Durahan* pD;
        std::vector<Entidades::Inimigos::Durahan*> vetorDurahan;
        int cont_D;
        int it_D;
        

        public:
        Pantano_Maldito();
        ~Pantano_Maldito();
        void criarInimMedio(const sf::Vector2f posicao);
        void criarInimigos();
        void criarObstaculos();
        const int getMaxInimMedios();
        void criarMapa();
        void criarEntidade(char letra, const sf::Vector2f posicao);
        void executar();


        void criarInimDificil(const sf::Vector2f posicao);
        void setpD(Entidades::Inimigos::Durahan* pDurahan);
        Entidades::Inimigos::Durahan* getpD();
    };

}