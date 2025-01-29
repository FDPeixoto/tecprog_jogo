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
        criarJogador(sf::Vector2f(100.0f, 0.0f));
        criarJogador(sf::Vector2f(300.0f, 0.0f));
        criarMinion(sf::Vector2f(300.0f, 300.0f));
        criarPlataforma(sf::Vector2f(150.0f, 300.0f));
        criarPlataforma(sf::Vector2f(250.0f, 400.0f));
        criarPlataforma(sf::Vector2f(350.0f, 300.0f));
    }
}



