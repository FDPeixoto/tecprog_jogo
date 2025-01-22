#include <Plataforma.hpp>

namespace Entidades{
    namespace Obstaculos{
        Plataforma::Plataforma(float alt, float larg, sf::Vector2f posicao): Obstaculo(sf::Vector2f(larg, alt), posicao, false), largura(larg){}
        Plataforma::~Plataforma(){}
        const float Plataforma::getAltura(){return altura;}
        const float Plataforma::getLargura(){return largura;}
    }
}