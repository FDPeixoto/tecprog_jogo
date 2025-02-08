#pragma once
#include "Fase.hpp"
#include "Plataforma.hpp"
#include "stdafx.h"
#include <vector>

namespace Fases
{
    class Castelo_Assombrado : public Fase
    {
    private:
        int maxEsp;
        int it_Esp;
        int maxM;
        int it_M;
        int maxP;
        int it_P;
        std::vector<Entidades::Inimigos::Ogro*> vetorOgro;
        int maxOgros;
        int it_Ogros;
        int aleatoriedadeP;
        sf::RectangleShape fundo;
        sf::Texture textura;

    public:
        Castelo_Assombrado(bool temSegundoJogador);
        ~Castelo_Assombrado();
        void criarInimDificil(const sf::Vector2f posicao);
        void criarEspinho(const sf::Vector2f posicao);
        void criarMapa();
        void criarEntidade(char letra, const sf::Vector2f posicao);
        void executar();
    };
}