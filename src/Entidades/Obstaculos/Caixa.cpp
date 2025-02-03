#include "Caixa.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Caixa::Caixa(const sf::Vector2f posicao) : lado(48.f), Obstaculo(sf::Vector2f(48.f, 48.f), posicao, true, IDCAIXA)
        {
            setCor(sf::Color(150, 75, 0)); // Marrom
        }
        Caixa::~Caixa() {}
        float Caixa::getLado()
        {
            return lado;
        }

        void Caixa::executar()
        {
        }

        void Caixa::salvar()
        {
        }

        void Caixa::atualizar(float dt)
        {
            if (!noChao)
            {
                setPos(sf::Vector2f(pos.x, pos.y + 400.f * dt));
            }
            noChao = false;
        }

        void Caixa::colisao(Entidade *outraEntidade)
        {
            // Get positions and sizes of the box and the other entity
            sf::Vector2f pos1 = getCorpo().getPosition();
            sf::Vector2f pos2 = outraEntidade->getCorpo().getPosition();

            sf::Vector2f tam1 = getCorpo().getSize();
            sf::Vector2f tam2 = outraEntidade->getCorpo().getSize();

            // Calculate the overlap between the box and the other entity
            float overlapX = std::min(pos1.x + tam1.x, pos2.x + tam2.x) - std::max(pos1.x, pos2.x);
            float overlapY = std::min(pos1.y + tam1.y, pos2.y + tam2.y) - std::max(pos1.y, pos2.y);

            // Check if there is a collision
            if (overlapX > 0 && overlapY > 0)
            {
                int ID = outraEntidade->getID();

                // Handle collision with a platform
                if (ID == IDPLATAFORMA)
                {
                    // Determine the axis of least penetration
                    if (overlapX < overlapY)
                    {
                        // Horizontal collision
                        if (pos1.x < pos2.x)
                        {
                            // Box is to the left of the platform
                            setPos(sf::Vector2f(pos2.x - tam1.x, pos1.y));
                        }
                        else
                        {
                            // Box is to the right of the platform
                            setPos(sf::Vector2f(pos2.x + tam2.x, pos1.y));
                        }
                    }
                    else
                    {
                        // Vertical collision
                        if (pos1.y < pos2.y)
                        {
                            // Box is above the platform
                            setPos(sf::Vector2f(pos1.x, pos2.y - tam1.y));
                            noChao = true;
                        }
                        else
                        {
                            // Box is below the platform
                            setPos(sf::Vector2f(pos1.x, pos2.y + tam2.y));
                        }
                    }
                }
            }
        }

        void Caixa::inicializar()
        {
        }

        void Caixa::atualizarPosicao(float dt)
        {
        }

        void Caixa::Obstacular(Entidades::Jogador *pJogador)
        {
        }

        void Caixa::obstacular(Entidades::Jogador *pJogador)
        {
        }

    }
}
