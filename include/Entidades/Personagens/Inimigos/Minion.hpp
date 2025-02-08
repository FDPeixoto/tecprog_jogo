#pragma once
#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "stdafx.h"
namespace Entidades{
    namespace Inimigos{
        class Minion: public Inimigo{
            private:
            bool super;

            public:
            Minion();
            Minion(const sf::Vector2f posicao);
            ~Minion();
            void salvar();
            void salvarDataBuffer();
        };
    }
}