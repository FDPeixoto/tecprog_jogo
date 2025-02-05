#include "Medievo.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

Medievo::Medievo() : pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()),
                     // pGerenciadorColisao(pGerenciadorColisao->getGerenciadorColisao()),
                     pGerenciadorEvento(pGerenciadorEvento->getGerenciadorEvento()),
                     pGerenciadorEstado(pGerenciadorEstado->getGerenciadorEstado())

{
    executar();
}

Medievo::~Medievo()
{
    // pGerenciadorColisao = nullptr;
    pGerenciadorGrafico = nullptr;
    pGerenciadorEvento = nullptr;
}

void Medievo::executar()
{
    pGerenciadorEstado->addState(IDPANTANOMALDITO);

    // float elapsedTime = 0.0f;
    // primeiraFase.setListP();
    // pGerenciadorEstado->addState(IDCASTELOASSOMBRADO);

    while (pGerenciadorGrafico->getJanela()->isOpen())
    {

        pGerenciadorGrafico->getJanela()->clear();

        pGerenciadorEstado->executar();

        pGerenciadorEvento->executar();
        /*primeiraFase.executar();
        //primeiraFase.atualizarProj();
        pGerenciadorGrafico->getJanela()->display();

        elapsedTime = clock.getElapsedTime().asSeconds();

        // Se o tempo transcorrido for maior ou igual ao delayTime
        if (elapsedTime >= DELTATIME) {
            clock.restart();
        }*/

        pGerenciadorGrafico->getJanela()->display();
        std::cout << "Hello, World!" << std::endl;

    }
}
