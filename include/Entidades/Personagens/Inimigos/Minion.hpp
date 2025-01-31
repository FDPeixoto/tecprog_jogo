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
            //void mover(); deixa de Inimigos
            //void executar();
            void atualizar(float deltaTime, Entidades::Jogador* jogador1, Entidades::Jogador* jogador2, sf::RectangleShape& plataforma);
            static int get_tam_grupo();
            //void colisao(Entidade *outraEntidade);
        };
    }
}