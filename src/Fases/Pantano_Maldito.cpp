#include "Pantano_Maldito.hpp"

namespace Fases{
    Pantano_Maldito::Pantano_Maldito(): Fase(), maxInimMedios(5)
    {
        criarMapa();
    }

    Pantano_Maldito::~Pantano_Maldito(){}

    void Pantano_Maldito::criarInimMedios()
    {

    }
    void Pantano_Maldito::criarInimigos()
    {
        //criarInimFaceis();
        //criarInimMedios();
    }
    void Pantano_Maldito::criarObstaculos()
    {
        //criarObstFaceis();
    }

    const int Pantano_Maldito::getMaxInimMedios(){return maxInimMedios;}

    void Pantano_Maldito::criarMapa()
    {
        criarJogador(sf::Vector2f(0.0f, 0.0f));
        criarJogador(sf::Vector2f(200.0f, 0.0f));
    }
}



