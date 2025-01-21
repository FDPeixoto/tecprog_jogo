#include "Inimigo.hpp"
#include "stdafx.h"

namespace Entidades{
 
    Inimigo::Inimigo(const sf::Vector2f tamanho, const sf::Vector2f posicao): Personagem(tam, posicao, IDINIMIGO), nivel_maldade(0){}
    Inimigo::~Inimigo(){}
    void Inimigo::salvarDataBuffer(){}
    //void Inimigo::executar(){}
    //void Inimigo::danificar(Personagens::Jogador* p){}
    void Inimigo::set_nivel_maldade(int n){
        if((n>0)&&(n<5)){
            nivel_maldade=n;
        }
    }
    const int Inimigo:: get_nivel_maldade(){
        return (nivel_maldade);
    }
}
