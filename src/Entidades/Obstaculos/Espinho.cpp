#include "Espinho.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Espinho::Espinho(const sf::Vector2f posicao) : Obstaculo(sf::Vector2(ALTURA_ESPINHO, LARGURA_ESPINHO), posicao, true, IDESPINHO)
        {
            setCor(sf::Color(128, 128, 128));
        }
        Espinho::~Espinho() {}
        bool Espinho::getMortal() { return mortal; }
        void Espinho::executar() {}
        void Espinho::obstacular(Entidades::Jogador *pJogador)
        {
            pJogador->tomarDano(pJogador->getNumVidas());
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
        void Espinho::Obstacular(Entidades::Jogador *pJogador)
        {
            pJogador->tomarDano(pJogador->getNumVidas());
        }
    }
}