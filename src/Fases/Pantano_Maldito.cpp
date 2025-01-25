#include "../include/Fases/Pantano_Maldito.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

Fases::Pantano_Maldito::Pantano_Maldito(): Fase(), maxInimMedios(1)
{
    criarJogador(sf::Vector2f(0.0f, 0.0f));
    criarJogador(sf::Vector2f(200.0f, 0.0f));
}

Fases::Pantano_Maldito::~Pantano_Maldito()
{
}
void Fases::Pantano_Maldito::executar()
{
    pGerenciadorGrafico->getJanela()->clear();
    
    for(Listas::Lista<Entidades::Entidade>::Iterator it = listaPersonagens->getListaEnt().inicio(); it != listaPersonagens->getListaEnt().fim(); it++){
        if(*it != nullptr){
            pGerenciadorGrafico->getJanela()->draw((*it)->getCorpo());
        }
    }

    for(Listas::Lista<Entidades::Entidade>::Iterator it = listaObstaculos->getListaEnt().inicio(); it != listaObstaculos->getListaEnt().fim(); it++){
        if(*it != nullptr){
            pGerenciadorGrafico->getJanela()->draw((*it)->getCorpo());
        }
    }
}
void Fases::Pantano_Maldito::criarInimMedios()
{
}
void Fases::Pantano_Maldito::criarInimigos()
{
    //criarInimFaceis();
    //criarInimMedios();
}
void Fases::Pantano_Maldito::criarObstaculos()
{
    //criarObstFaceis();
}
bool Fases::Pantano_Maldito::completou()
{
    return true;
}
const int Fases::Pantano_Maldito::getMaxInimMedios()
{
    return maxInimMedios;
}