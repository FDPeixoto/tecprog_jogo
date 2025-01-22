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
    pGerenciadorColisao->setListaEntidades(listaDeEntidades);
    sf::Clock clock;
    Entidades::Jogador* jogador1 = new Entidades::Jogador(sf::Vector2f(0.0f, 0.0f));
    setJog(jogador1, 1);
    pJog1->setCor(sf::Color::Blue);
    pJog1->setTeclas(sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Up);

    Entidades::Jogador* jogador2 = new Entidades::Jogador(sf::Vector2f(200.0f, 0.0f));
    setJog(jogador2, 2);
    pJog2->setCor(sf::Color::Red);
    pJog2->setTeclas(sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::W);

    listaDeEntidades->incluirEntidade(pJog1);
    listaDeEntidades->incluirEntidade(pJog2);
    
    while (pGerenciadorGrafico->getJanela()->isOpen()) {
        sf::Event event;
        while (pGerenciadorGrafico->getJanela()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                pGerenciadorGrafico->getJanela()->close();
        }
        pGerenciadorGrafico->getJanela()->clear();
        pJog1->mover();
        pJog2->mover();
        pGerenciadorColisao->executar();
        pGerenciadorGrafico->desenharListaEntidades(listaDeEntidades);
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


