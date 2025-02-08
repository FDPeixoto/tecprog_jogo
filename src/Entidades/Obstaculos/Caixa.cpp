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
            setPos(sf::Vector2f(pos.x + velocidade.x * dt, pos.y));

            // Apply gravity if not on the ground
            if (!noChao)
            {
                velocidade.y += 400.f * dt; // Simulate gravity
                setPos(sf::Vector2f(pos.x, pos.y + velocidade.y * dt));
            }
            else
            {
                velocidade.y = 0.f; // Reset vertical velocidade when grounded
            }

            // Optional: Add friction to stop horizontal movement over time
            velocidade.x *= 0.9f;
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

            // Apply a push force to the box based on player direction
            velocidade.x = 200.f; // Adjust 200.f to control push strength
        }
        void Caixa::colisao(Entidade *outraEntidade)
        {
            Obstaculo::colisao(outraEntidade);
        }

    }
}
