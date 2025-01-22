#include <Canhao.hpp>

namespace Entidades{
    namespace Obstaculos{
        Canhao::Canhao(const sf::Vector2f tamanho, const sf::Vector2f posicao): Obstaculo(tam, posicao, false){}
        Canhao::~Canhao(){}
        void Canhao::obstacular(Entidades::Jogador *pJogador)
        {           
        }
         void Canhao::lancar(Entidades::Jogador * pJogador)
        {
        }
    }
}