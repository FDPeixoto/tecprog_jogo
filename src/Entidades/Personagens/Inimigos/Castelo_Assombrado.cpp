#include "Castelo_Assombrado.hpp"
namespace Fases{
        Castelo_Assombrado::Castelo_Assombrado(): maxChefoes(1), Fase(){
        }
        Castelo_Assombrado::~Castelo_Assombrado(){}
        void Castelo_Assombrado::criarInimDificil(const sf::Vector2f posicao){}
        void Castelo_Assombrado::criarInimigos(){}
        void Castelo_Assombrado::criarObstaculos(){}
        const int Castelo_Assombrado::getMaxChefoes(){
            return maxChefoes;
        }
        void Castelo_Assombrado::criarMapa(){}
        void Castelo_Assombrado::criarEntidade(char letra, const sf::Vector2f posicao){}

}