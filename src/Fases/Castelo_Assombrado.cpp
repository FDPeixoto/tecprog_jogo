#include "Castelo_Assombrado.hpp"

namespace Fases{
    Castelo_Assombrado::Castelo_Assombrado(): Fase(IDCASTELOASSOMBRADO), maxChefoes(5)
    {
        Fase::proximaFase();
        criarMapa();
    }

    Castelo_Assombrado::~Castelo_Assombrado()
    {
    }

    void Castelo_Assombrado::criarInimigos()
    {
        //criarInimFaceis();
        //criarInimMedios();
    }
    void Castelo_Assombrado::criarObstaculos()
    {
        //criarObstFaceis();
    }

    void Castelo_Assombrado::criarMapa(){
        criarJogador(sf::Vector2f(300.0f, 0.0f));
        criarJogador(sf::Vector2f(100.0f, 0.0f));
        criarMinion(sf::Vector2f(300.0f, 300.0f));
        criarPlataforma(sf::Vector2f(100.0f, 100.0f));
        criarPlataforma(sf::Vector2f(200.0f, 200.0f));
        criarPlataforma(sf::Vector2f(300.0f, 300.0f));
    }
}