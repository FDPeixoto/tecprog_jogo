#pragma once
#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "stdafx.h"
namespace Entidades{
    namespace Inimigos{
        class Minion: public Inimigo{
            private:
            static int tam_grupo;

            public:
            Minion();
            Minion(const sf::Vector2f posicao);
            ~Minion();
            void salvar();
            void salvarDataBuffer();
            static int get_tam_grupo();
        };
    }
}