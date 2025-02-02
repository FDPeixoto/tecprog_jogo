#pragma once
#include "Obstaculo.hpp"
#include <stdlib.h>  
#include <time.h>

namespace Entidades{
    namespace Obstaculos{
        class Caixa: public Obstaculo{
    int largura;

    public:
    Caixa( const sf::Vector2f posicao);
    ~Caixa();
    int getLargura();

    };
    }
}
