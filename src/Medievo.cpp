#include "Medievo.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>


Medievo::Medievo(): 
    pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()), 
    //pGerenciadorColisao(pGerenciadorColisao->getGerenciadorColisao()),
    pGerenciadorEvento(pGerenciadorEvento->getGerenciadorEvento()),
    pGerenciadorEstado(pGerenciadorEstado->getGerenciadorEstado())
    
    {
        executar();
    }

Medievo::~Medievo(){
    //pGerenciadorColisao = nullptr;
    pGerenciadorGrafico = nullptr;
    pGerenciadorEvento = nullptr;
}

void Medievo::executar(){
    pGerenciadorEstado->addState(IDCASTELOASSOMBRADO);
    while(pGerenciadorGrafico->getJanela()->isOpen()){

        pGerenciadorGrafico->getJanela()->clear();

        pGerenciadorEstado->executar();
        
        pGerenciadorEvento->executar();
        pGerenciadorGrafico->getJanela()->display();
        std::cout << "Hello, World!" << std::endl;
    }
}

