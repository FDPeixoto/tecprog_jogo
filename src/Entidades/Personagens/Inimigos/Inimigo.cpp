#include "Jogador.hpp"
#include "stdafx.h"
#include <Inimigos/Inimigo.hpp>

#include <stdlib.h>
#include <time.h>

namespace Entidades{
    namespace Inimigos{
        Inimigo::Inimigo(const sf::Vector2f tamanho, const sf::Vector2f posicao): Personagem(tam, posicao, IDINIMIGO), nivel_maldade(0){
            moveAleatorio=rand()%4;
        }
        Inimigo::~Inimigo(){}

        void Inimigo::setJogador1(Entidades::Jogador* pJogador){
            pJogador1 = pJogador;
        }
        Entidades::Jogador* Inimigo::getJogador1(){
            return pJogador1;
        }
        void Inimigo::setJogador2(Entidades::Jogador* pJogador){
            pJogador2 = pJogador;
        }
        Entidades::Jogador* Inimigo::getJogador2(){
            return pJogador2;
        }
        void Inimigo::salvarDataBuffer(){}
        //void Inimigo::executar(){}
        //void Inimigo::danificar(Personagens::Jogador* p){}
        void Inimigo::set_nivel_maldade(int n){
            if((n>0)&&(n<5)){
                nivel_maldade=n;
            }
        }
        const int Inimigo:: get_nivel_maldade(){
            return (nivel_maldade);
        }
        void Inimigo::inicializar()
        {
            return;
        }
        void Inimigo::atualizar(float dt){
            return;
        }

        void Inimigo::mover(){
            sf::Vector2f posJogador = pJogador1->getCorpo().getPosition();
            sf::Vector2f posInimigo= corpo.getPosition();
            if(fabs(posJogador.x-posInimigo.x>= RAIO_PERSEGUIR_X)||fabs(posJogador.y-posInimigo.y>=RAIO_PERSEGUIR_Y)){
                perseguir(posJogador, posInimigo);
            }
            else{
                moverAleatorio();
            }
        }
        void Inimigo::perseguir(sf::Vector2f posJogador, sf::Vector2f posInimigo){
            if(posJogador.x-posInimigo.x>=0.0f){//significa que o jogador está a direita
                corpo.move(velocidade.x,0.0f);
            }
            else{
                corpo.move(-velocidade.x,0.0f);
            }
            if(posJogador.y-posInimigo.y>=0.0f){//significa que o jogador está acima
                corpo.move(0.0f,velocidade.y);
            }
            else{
                corpo.move(0.0f,-velocidade.y);
            }
        }
        void Inimigo::moverAleatorio(){
            if(moveAleatorio==0){
                corpo.move(velocidade.x,0.0f);
            }
            else if(moveAleatorio==1){
                corpo.move(-velocidade.x,0.0f);
            }
            else if(moveAleatorio==2){
                corpo.move(0.0f,velocidade.y);
            }
            else if(moveAleatorio==3){
                corpo.move(0.0f,-velocidade.y);
            }
            float intervalo=relogio.getElapsedTime().asSeconds();
            if(intervalo>=2.0f){
                moveAleatorio=rand()%4;
                relogio.restart();
            }
        }
    }
    
}
