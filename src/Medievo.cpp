#include "Medievo.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

Medievo::Medievo() : pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()),
                     pGerenciadorEvento(pGerenciadorEvento->getGerenciadorEvento()),
                     pGerenciadorEstado(pGerenciadorEstado->getGerenciadorEstado()),
                     pGerenciadorColisao(pGerenciadorColisao->getGerenciadorColisao())


{
    executar();
}

Medievo::~Medievo()
{
     pGerenciadorColisao = nullptr;
    pGerenciadorGrafico = nullptr;
    pGerenciadorEvento = nullptr;
}

void Medievo::executar()
{
    pGerenciadorEstado->addState(IDMENUINICIALSTATE);

    while (pGerenciadorGrafico->getJanela()->isOpen())
    {

        pGerenciadorGrafico->getJanela()->clear();

        pGerenciadorEstado->executar();

        pGerenciadorEvento->executar();

        pGerenciadorGrafico->getJanela()->display();
    }
}
