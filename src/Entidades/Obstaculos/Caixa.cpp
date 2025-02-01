#include "Caixa.hpp"

namespace Obstaculos{
    Caixa::Caixa( const sf::Vector2f posicao): Obstaculo(const sf::Vector2f(ALTURACAIXA,ALTURACAIXA), posicao, true){
        srand((unsigned int)time(NULL));  
        largura= (rand() % (FAIXA_ALEATORIO*10))+50;
        mudarLargura(largura);
    }
    Caixa::~Caixa(){}
    int Caixa::getLargura(){
        return largura;
    }
    int Caixa::getLargura(){}

}
