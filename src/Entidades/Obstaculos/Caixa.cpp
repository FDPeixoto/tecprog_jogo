#include "Caixa.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Caixa::Caixa(const sf::Vector2f posicao) : lado(48.f), Obstaculo(sf::Vector2f(48.f, 48.f), posicao, true, IDCAIXA)
        {
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
            if (!noChao)
            {
                setPos(sf::Vector2f(pos.x, pos.y + 400.f * dt));
            }
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
        }

    }
}
