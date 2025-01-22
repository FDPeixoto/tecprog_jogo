#include <Obstaculo.hpp>
#include <stdafx.h>

namespace Entidades{
    namespace Obstaculos{
        Obstaculo::Obstaculo(const sf::Vector2f tamanho, const sf::Vector2f posicao, bool causaDano): Entidade(tamanho, posicao, IDOBSTACUlO), danoso(causaDano){}
        Obstaculo::~Obstaculo(){}
    }
}
