#include "../include/Medievo.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

    float Medievo::distance(const sf::Vector2f& a, const sf::Vector2f& b) {
            return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
    Medievo::Medievo(): pJog1(nullptr),pJog2(nullptr), primeiraFase(){

    }
    Medievo::~Medievo(){
        if(pJog1){
            delete(pJog1);
        }
        if(pJog2){
            delete(pJog2);
        }
        pJog1=nullptr;
        pJog2=nullptr;
    }
    void Medievo::executar(){
        primeiraFase.executar();
    }
    void Medievo::setJog(Personagens::Jogador* p, int num){
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


