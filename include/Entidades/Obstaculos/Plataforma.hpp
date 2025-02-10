#ifndef PLATAFORMA_HPP
#define PLATAFORMA_HPP

#include <SFML/Graphics.hpp>
#include "Obstaculo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma : public Obstaculo
        {
        private:
            float largura;
            float altura;

        public:
            Plataforma(float alt, float larg, sf::Vector2f posicao, bool Castelo);
            Plataforma(sf::Vector2f posicao, bool Castelo);
            ~Plataforma();
            void executar();
            void obstacular(Entidades::Jogador *pJogador);
            const float getAltura();
            const float getLargura();
            void salvar();
            void atualizar(float dt);
            void inicializar();
        };
    }
}

#endif