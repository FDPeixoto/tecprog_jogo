#include <Espinho.hpp>

namespace Entidades{
    namespace Obstaculos{
        Espinho::Espinho(const sf::Vector2f tamanho, const sf::Vector2f posicao): Obstaculo(tamanho, posicao, true){}
        Espinho::~Espinho(){}
        bool Espinho::getMortal(){return mortal;}
        void Espinho::executar(){}
        void Espinho::Obstacular(Entidades::Jogador* pJogador){}
    }
}