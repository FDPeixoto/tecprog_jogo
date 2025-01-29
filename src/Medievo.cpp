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
    while(pGerenciadorGrafico->getJanela()->isOpen()){

        pGerenciadorGrafico->getJanela()->clear();

        pGerenciadorEvento->executar();

        primeiraFase.executar();
        pGerenciadorGrafico->getJanela()->display();
        std::cout << "Hello, World!" << std::endl;
    }
}

