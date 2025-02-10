#pragma once
#include "Obstaculo.hpp"
#define LARGURA_ESPINHO 64.0f
#define ALTURA_ESPINHO 64.0f

namespace Entidades
{
    namespace Obstaculos
    {
        class Espinho : public Obstaculo
        {
        private:
            bool mortal;

        public:
            Espinho(const sf::Vector2f posicao);
            ~Espinho();
            bool getMortal();
            void executar();
            void obstacular(Entidades::Jogador *pJogador);
            void salvar();
            void atualizar(float dt);
            void inicializar();
        };
    }
}