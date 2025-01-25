#include "../include/Medievo.hpp"
#include "../include/Fases/Pantano_Maldito.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Medievo.hpp"



float Medievo::distance(const sf::Vector2f& a, const sf::Vector2f& b) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
Medievo::Medievo(): pJog1(nullptr),pJog2(nullptr), listaDeEntidades(new Listas::ListaEntidades()), pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()), pGerenciadorColisao(pGerenciadorColisao->getGerenciadorColisao()){
}
Medievo::~Medievo(){
    if(pJog1){delete(pJog1);}
    if(pJog2){delete(pJog2);}
    pJog1=nullptr;
    pJog2=nullptr;
    delete listaDeEntidades;
}
void Medievo::executar(){
    while(pGerenciadorGrafico->getJanela()->isOpen()){
        sf::Clock clock;
        float dt;
        sf::Event event;
        while (pGerenciadorGrafico->getJanela()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                pGerenciadorGrafico->getJanela()->close();
        }
        primeiraFase.executar();
        pGerenciadorGrafico->getJanela()->display();
    }
    
}
void Medievo::setJog(Entidades::Jogador* p, int num){
    if(p!=nullptr){
        if(num==1){
            pJog1=p;
        }
        else if(num==2){
            pJog2=p;
        }
        else{
            std::cout<<"Numero nao eh valido para incializar ponteiro de jogador"<<std::endl;
        }
    }
}


