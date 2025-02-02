/*#include <Portal.hpp>

namespace Entidades{
    namespace Obstaculos{
        Portal::Portal(const sf::Vector2f tamanho, const sf::Vector2f posicao): Obstaculo(tamanho, posicao, true){
            inicializar();
        }
        Portal::~Portal(){}
        bool Portal::getMortal(){return mortal;}
        void Portal::executar(){
        }
        void Portal::ativarObstaculo(Entidades::entidade* pJogador){
            Obstacular(pJogador);
        }
        void Portal::Obstacular(Entidades::entidade* pJogador){
            sf::Vector2f posIn(POSICAO_INICIAL_X, POSICAO_INICIAL_Y);
            pJogador->setPos(posIn);
        }
        void Portal::inicializar(){
            setID(IDPORTAL);
        }
    }
}*/