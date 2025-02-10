#include "Espinho.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Espinho::Espinho(const sf::Vector2f posicao) : Obstaculo(sf::Vector2(ALTURA_ESPINHO, LARGURA_ESPINHO), posicao, true, IDESPINHO)
        {
            textura.loadFromFile("Texturas/espinho.png");
            setCor(sf::Color::White);
            Entidade::carregarTextura(&textura);
            srand((unsigned int)time(NULL));
            mortal = (rand() % 10 == 0); // So mortal 10% das vezes
        }
        Espinho::~Espinho() {}
        bool Espinho::getMortal() { return mortal; }
        void Espinho::executar() {}
        void Espinho::obstacular(Entidades::Jogador *pJogador)
        {
            if (pJogador->getUltimoDano() > 2.0f)
            {
                if (getMortal())
                {
                    pJogador->tomarDano(pJogador->getNumVidas());
                }
                else
                {
                    pJogador->tomarDano(1);
                }
                pJogador->setUltimoDano(0.f);
            }
        }
        void Espinho::salvar()
        {
        }
        void Espinho::atualizar(float dt)
        {
        }
        void Espinho::inicializar()
        {
        }
    }
}