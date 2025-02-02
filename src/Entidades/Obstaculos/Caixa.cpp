#include "Caixa.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Caixa::Caixa(const sf::Vector2f posicao) : lado(32.f), Obstaculo(sf::Vector2f(lado, lado), posicao, true, IDCAIXA)
        {
            setCor(sf::Color::Yellow);
        }
        Caixa::~Caixa() {}
        float Caixa::getLado()
        {
            return lado;
        }

    }

}
