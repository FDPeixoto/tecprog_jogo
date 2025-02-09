#pragma once
#include <Jogador.hpp>
namespace Entidades
{
    namespace Obstaculos
    {
        class Obstaculo : public Entidade
        {
        protected:
            bool danoso;

        public:
            Obstaculo(const sf::Vector2f tamanho, const sf::Vector2f posicao, bool causaDano, const int ID);
            ~Obstaculo();
            virtual void executar() = 0;
            virtual void obstacular(Entidades::Jogador *pJogador) = 0;
            void atualizarPosicao(float dt);
            void colisao(Entidade *outraEntidade);
        };
    }
}
