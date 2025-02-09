#include "../include/Entidades/Obstaculos/Plataforma.hpp"
#include "Plataforma.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Plataforma::Plataforma(float alt, float larg, sf::Vector2f posicao, bool Castelo) : Obstaculo(sf::Vector2f(larg, alt), posicao, false, IDPLATAFORMA), largura(larg)
        {
            // setCor(sf::Color(6, 64, 43)); // Verde Escuro
            // if (!textura.loadFromFile("Texturas/plataforma-64x64.png")) {}
            // Entidade::carregarTextura(&textura);
            if (Castelo)
            {
                textura.loadFromFile("Texturas/testeFundo1.png");
            }
            else
            {
                textura.loadFromFile("Texturas/PantanoMaldito.png");
            }
            setCor(sf::Color::White); // cor anterior: (6, 64, 43)
            Entidade::carregarTextura(&textura);
        }
        Plataforma::Plataforma(sf::Vector2f posicao, bool Castelo) : Obstaculo(sf::Vector2f(64.f, 64.f), posicao, false, IDPLATAFORMA)
        {
            if (Castelo)
            {
                textura.loadFromFile("Texturas/plataforma-64x64.png");
            }
            else
            {
                textura.loadFromFile("Texturas/PlataformaPantano.png");
            }
            setCor(sf::Color::White); // cor anterior: (6, 64, 43)
            Entidade::carregarTextura(&textura);
        }
        Plataforma::~Plataforma() {}
        void Plataforma::executar()
        {
            return;
        }
        void Plataforma::obstacular(Entidades::Jogador *pJogador)
        {
            sf::Vector2f pos1 = pJogador->getCorpo().getPosition();
            sf::Vector2f pos2 = getCorpo().getPosition();

            sf::Vector2f tam1 = pJogador->getCorpo().getSize();
            sf::Vector2f tam2 = getCorpo().getSize();

            sf::Vector2f distancia(fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)), fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f)));

            float overlapX = std::min(pos1.x + tam1.x, pos2.x + tam2.x) - std::max(pos1.x, pos2.x);
            float overlapY = std::min(pos1.y + tam1.y, pos2.y + tam2.y) - std::max(pos1.y, pos2.y);

            if (overlapX < overlapY)
            {
                // Horizontal collision
                if (pos1.x < pos2.x)
                {
                    // Player is to the left of the platform
                    pJogador->setPos(sf::Vector2f(pos2.x - tam1.x, pos1.y));
                }
                else
                {
                    // Player is to the right of the platform
                    pJogador->setPos(sf::Vector2f(pos2.x + tam2.x, pos1.y));
                }
            }
            else
            {
                // Vertical collision
                if (pos1.y < pos2.y)
                {
                    // Player is above the platform
                    pJogador->setPos(sf::Vector2f(pos1.x, pos2.y - tam1.y));
                    pJogador->setNoChao(true); // Player is on the ground
                    pJogador->setVelocidade(sf::Vector2f(pJogador->getVelocidade().x, 0.f));
                }
                else
                {
                    // Player is below the platform
                    pJogador->setPos(sf::Vector2f(pos1.x, pos2.y + tam2.y));
                    pJogador->setVelocidade(sf::Vector2f(pJogador->getVelocidade().x, 0.f));
                }
            }
        }
        const float Plataforma::getAltura() { return altura; }
        const float Plataforma::getLargura() { return largura; }
        void Plataforma::salvar()
        {
            return;
        }
        void Plataforma::atualizar(float dt)
        {
            float velocidadeY = GRAVIDADE;
            velocidadeY += FNORMAL;
            corpo.move(0.f, velocidadeY);
        }
        void Plataforma::inicializar()
        {
            return;
        }
    }
}