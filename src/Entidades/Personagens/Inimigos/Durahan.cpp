#include "Durahan.hpp"

namespace Entidades{
    namespace Inimigos{
        Durahan::Durahan(const sf::Vector2f posicao): Inimigo(sf::Vector2f(DURAHANLARGURA,DURAHANALTURA ), posicao){
            velocidade = sf::Vector2f(VELOCIDADEX_DU,VELOCIDADEY_DU );
            antidoto_mortal=false;
        }
        Durahan::~Durahan(){
            antidoto_mortal=false;
        }
        void Durahan::salvar(){}
        void Durahan::salvarDataBuffer(){}
        void Durahan::executar(){}
        void Durahan::danificar(Entidades::Jogador* pJogador){}
        void Durahan::golpeMortal(){}
        void Durahan::setAntidotoMortal(bool flg){
            antidoto_mortal=flg;
        }
        void Durahan::colisao(Entidade *outraEntidade){}
        };
    }
}