#include <Obstaculo.hpp>
#pragma once
namespace Entidades{
    namespace Obstaculos{
        class Espinho: public Obstaculo{
            private: 
                bool mortal;
            public:
                Espinho(const sf::Vector2f tamanho, const sf::Vector2f posicao);
                ~Espinho();
                bool getMortal();
                void executar();
                void Obstacular(Entidades::Jogador* pJogador);
        };
    }
}