#pragma once
#include "Obstaculo.hpp"
#include <stdlib.h>
#include <time.h>

namespace Entidades
{
    namespace Obstaculos
    {
        class Caixa : public Obstaculo
        {
        private:
            float lado;
            bool noChao;
            sf::Vector2f velocidade;

        public:
            Caixa(const sf::Vector2f posicao);
            ~Caixa();
            float getLado();
            void virtual executar();
            virtual void salvar();
            void virtual atualizar(float dt);
            virtual void inicializar();
            virtual void atualizarPosicao(float dt);
            void Obstacular(Entidades::Jogador *pJogador);
            void obstacular(Entidades::Jogador *pJogador);
            void colisao(Entidade *outraEntidade) override;
            void setNoChao(bool chao);
            void setVelocidade(sf::Vector2f vel);
        };
    }
}
