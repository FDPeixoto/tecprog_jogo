#include "Medievo.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>


Medievo::Medievo(): 
    pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()), 
    //pGerenciadorColisao(pGerenciadorColisao->getGerenciadorColisao()),
    pGerenciadorEvento(pGerenciadorEvento->getGerenciadorEvento())
    {
        executar();
    }

Medievo::~Medievo(){
    //pGerenciadorColisao = nullptr;
    pGerenciadorGrafico = nullptr;
    pGerenciadorEvento = nullptr;
}

void Medievo::executar(){
    float elapsedTime = 0.0f;

    while(pGerenciadorGrafico->getJanela()->isOpen()){

        pGerenciadorGrafico->getJanela()->clear();

        pGerenciadorEvento->executar();

        primeiraFase.executar();
        pGerenciadorGrafico->getJanela()->display();

        elapsedTime = clock.getElapsedTime().asSeconds();

        // Se o tempo transcorrido for maior ou igual ao delayTime
        if (elapsedTime >= DELTATIME) {
            clock.restart();
        }
        
    }
}

