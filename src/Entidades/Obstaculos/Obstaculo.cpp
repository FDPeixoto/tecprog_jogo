#include <Obstaculo.hpp>
#include <stdafx.h>
#include "Caixa.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Obstaculo::Obstaculo(const sf::Vector2f tamanho, const sf::Vector2f posicao, bool causaDano, const int ID) : Entidade(tamanho, posicao, ID), danoso(causaDano) {}
        Obstaculo::~Obstaculo() {}
        void Obstaculo::atualizarPosicao(float dt)
        {
            return; // não faz nada
        }
        void Obstaculo::colisao(Entidade *outraEntidade)
        {
            if (outraEntidade->getID() == IDJOGADOR)
            {
                obstacular(static_cast<Entidades::Jogador *>(outraEntidade));
            }
            if (getID() == IDCAIXA && outraEntidade->getID() == IDPLATAFORMA)
            {
                sf::Vector2f pos1 = getCorpo().getPosition();
                sf::Vector2f pos2 = outraEntidade->getCorpo().getPosition();

                sf::Vector2f tam1 = getCorpo().getSize();
                sf::Vector2f tam2 = outraEntidade->getCorpo().getSize();

                sf::Vector2f distancia(fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)), fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f)));

                float overlapX = std::min(pos1.x + tam1.x, pos2.x + tam2.x) - std::max(pos1.x, pos2.x);
                float overlapY = std::min(pos1.y + tam1.y, pos2.y + tam2.y) - std::max(pos1.y, pos2.y);
                if (outraEntidade->getID() == IDPLATAFORMA)
                {
                    // Calculate the intersection depth on both axes

                    // Determine the axis of least penetration
                    if (overlapX < overlapY)
                    {
                        // Horizontal collision
                        if (pos1.x < pos2.x)
                        {
                            // Player is to the left of the platform
                            setPos(sf::Vector2f(pos2.x - tam1.x, pos1.y));
                        }
                        else
                        {
                            // Player is to the right of the platform
                            setPos(sf::Vector2f(pos2.x + tam2.x, pos1.y));
                        }
                    }
                    else
                    {
                        // Vertical collision
                        if (pos1.y < pos2.y)
                        {
                            // Player is above the platform
                            setPos(sf::Vector2f(pos1.x, pos2.y - tam1.y));
                            // velocidade.y = 0; // Stop vertical movement
                            static_cast<Entidades::Obstaculos::Caixa *>(this)->setNoChao(true);
                        }
                        else
                        {
                            // Player is below the platform
                            setPos(sf::Vector2f(pos1.x, pos2.y + tam2.y));
                            // velocidade.y = 0; // Stop vertical movement
                        }
                    }
                }
            }
        }
    }
}
