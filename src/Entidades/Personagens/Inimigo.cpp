//#include "../include/Entidades/Personagens/Jogador.hpp"
//#include "../include/Entidades/Personagens/Personagem.hpp"
#include "../../../include/Entidades/Personagens/Inimigo.hpp"

namespace Personagens{
 
    Inimigo::Inimigo(): nivel_maldade(0){}
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