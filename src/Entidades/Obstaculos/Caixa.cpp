#include "Caixa.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Caixa::Caixa(const sf::Vector2f posicao) : lado(48.f), Obstaculo(sf::Vector2f(48.f, 48.f), posicao, true, IDCAIXA)
        {
            velocidade = sf::Vector2f(0.f, 0.f);
            textura.loadFromFile("Texturas/caixa.png");
            setCor(sf::Color::White); // cor anterior: (6, 64, 43)
            Entidade::carregarTextura(&textura);
            noChao = false;
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
            // Apply horizontal velocidade
            // Apply gravity if not on the ground
            velocidade.y += GRAVIDADE;
            if (velocidade.y > VELOCIDADETERIMNAL)
            {
                velocidade.y = VELOCIDADETERIMNAL;
            }

            if (noChao)
            {
                velocidade.y += FNORMAL;
            }

            // Optional: Add friction to stop horizontal movement over time
            corpo.move(velocidade.x * dt, velocidade.y * dt);
            noChao = false;
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
            // Get player's movement direction (e.g., from player input)
            float playerDirX = pJogador->getVelocidade().x; // Assume getDirecao() returns movement input

            if (playerDirX > 0)
            {
                velocidade.x = 50.f;
            }
            else
            {
                velocidade.x = 50.f;
            }
            // Apply a push force to the box based on player direction
            velocidade.x = 0.f; // Adjust 200.f to control push strength
        }
        void Caixa::setNoChao(bool chao)
        {
            noChao = chao;
        }
        void Caixa::setVelocidade(sf::Vector2f vel)
        {
            velocidade = vel;
        }
        void Caixa::colisao(Entidade *outraEntidade)
        {
            Obstaculo::colisao(outraEntidade);

            if ((outraEntidade->getID() == IDPLATAFORMA) || (outraEntidade->getID() == IDESPINHO))
            {
                sf::Vector2f pos1 = getCorpo().getPosition();
                sf::Vector2f pos2 = outraEntidade->getCorpo().getPosition();

                sf::Vector2f tam1 = getCorpo().getSize();
                sf::Vector2f tam2 = outraEntidade->getCorpo().getSize();

                sf::Vector2f distancia(fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)), fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f)));

                float overlapX = std::min(pos1.x + tam1.x, pos2.x + tam2.x) - std::max(pos1.x, pos2.x);
                float overlapY = std::min(pos1.y + tam1.y, pos2.y + tam2.y) - std::max(pos1.y, pos2.y);
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
                        setNoChao(true);
                    }
                    else
                    {
                        // Player is below the platform
                        setPos(sf::Vector2f(pos1.x, pos2.y + tam2.y));
                        // velocidade.y = 0; // Stop vertical movement
                    }
                }
            }
            else if (outraEntidade->getID() == IDCAIXA)
            {
                sf::Vector2f pos1 = getCorpo().getPosition();
                sf::Vector2f pos2 = outraEntidade->getCorpo().getPosition();

                sf::Vector2f tam1 = getCorpo().getSize();
                sf::Vector2f tam2 = outraEntidade->getCorpo().getSize();

                sf::Vector2f distancia(fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)), fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f)));

                float overlapX = std::min(pos1.x + tam1.x, pos2.x + tam2.x) - std::max(pos1.x, pos2.x);
                float overlapY = std::min(pos1.y + tam1.y, pos2.y + tam2.y) - std::max(pos1.y, pos2.y);
                if (overlapX < overlapY)
                {
                    // Horizontal collision
                    if (pos1.x < pos2.x)
                    {
                        // Player is to the left of the minion
                        setPos(sf::Vector2f(pos2.x - tam1.x, pos1.y));
                        if (velocidade.x != 0.f)
                        {
                            outraEntidade->setPos(sf::Vector2f(pos2.x + overlapX, pos2.y));
                        }
                    }
                    else
                    {
                        // Player is to the right of the minion
                        setPos(sf::Vector2f(pos2.x + tam2.x, pos1.y));
                        if (velocidade.x != 0)
                        {
                            outraEntidade->setPos(sf::Vector2f(pos2.x - overlapX, pos2.y));
                        }
                    }
                }
                else
                {
                    // Vertical collision
                    if (pos1.y < pos2.y)
                    {
                        // Player is above the minion
                        setPos(sf::Vector2f(pos1.x, pos2.y - tam1.y));
                        noChao = true;
                    }
                    else
                    {
                        // Player is below the minion
                        setPos(sf::Vector2f(pos1.x, pos2.y + tam2.y));
                    }
                }
            }
        }
    }
}
