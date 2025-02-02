#include "Jogador.hpp"
#include "stdafx.h"
#include <Inimigos/Inimigo.hpp>

#include <stdlib.h>
#include <time.h>
// #include <cstdlib>
// #include <ctime>

namespace Entidades
{
    namespace Inimigos
    {
        Inimigo::Inimigo(const sf::Vector2f tamanho, const sf::Vector2f posicao, const int ID) : Personagem(tamanho, posicao, ID), nivel_maldade(0)
        {
            moveAleatorio = rand() % FAIXA_ALEATORIO;
            pJogador1 = nullptr;
            pJogador2 = nullptr;
            iteracoes = 0;
        }
        Inimigo::~Inimigo()
        {
            pJogador1 = nullptr;
            pJogador2 = nullptr;
        }

        void Inimigo::setJogador1(Entidades::Jogador *pJogador)
        {
            pJogador1 = pJogador;
        }
        Entidades::Jogador *Inimigo::getJogador1()
        {
            return pJogador1;
        }
        void Inimigo::setJogador2(Entidades::Jogador *pJogador)
        {
            pJogador2 = pJogador;
        }
        Entidades::Jogador *Inimigo::getJogador2()
        {
            return pJogador2;
        }
        void Inimigo::salvarDataBuffer() {}
        void Inimigo::executar()
        {
            mover();
            // moverAleatorio();
        }
        // void Inimigo::danificar(Personagens::Jogador* p){}
        void Inimigo::set_nivel_maldade(int n)
        {
            if ((n > 0) && (n < 5))
            {
                nivel_maldade = n;
            }
        }
        const int Inimigo::get_nivel_maldade()
        {
            return (nivel_maldade);
        }
        void Inimigo::inicializar()
        {
            return;
        }
        void Inimigo::atualizar(float dt)
        {
            if (noChao && pulando)
            {
                velocidade.y = -VELOCIDADE_PULO;
                corpo.move(0.f, velocidade.y * dt);
                pulando = false;
                noChao = false;
            }
            // ou float dt=relogio.getElapsedTime().asSeconds();
            // Andando só na horizontal por enquanto

            if (!noChao)
            {
                velocidade.y += 1.f;
                if (velocidade.y > 300.f)
                {
                    velocidade.y = 300.f;
                }
            }
            else
            {
                velocidade.y = 0;
            }
            noChao = false;
            corpo.move(velocidade.x * dt, velocidade.y * dt);
            // setPos(sf::Vector2f(corpo.getPosition().x + velocidade.x * dt, corpo.getPosition().y + velocidade.y * dt));
        }

        void Inimigo::mover()
        {
            sf::Vector2f posInimigo = corpo.getPosition();
            if ((pJogador1 != nullptr) && (pJogador2 != nullptr))
            {
                sf::Vector2f posJogador1 = pJogador1->getCorpo().getPosition();
                sf::Vector2f posJogador2 = pJogador2->getCorpo().getPosition();

                float distx1 = fabs(posJogador1.x - posInimigo.x);
                float disty1 = fabs(posJogador1.y - posInimigo.y);

                float distx2 = fabs(posJogador2.x - posInimigo.x);
                float disty2 = fabs(posJogador2.y - posInimigo.y);

                if (distx1 <= distx2)
                {
                    if (distx1 <= RAIO_PERSEGUIR_X)
                    {
                        perseguir(posJogador1, posInimigo);
                    }
                }
                else if (distx2 <= RAIO_PERSEGUIR_X)
                {
                    perseguir(posJogador2, posInimigo);
                }
                else
                {
                    moverAleatorio();
                }
            }

            else if (pJogador1 != nullptr)
            {
                sf::Vector2f posJogador1 = pJogador1->getCorpo().getPosition();
                // if((fabs(posJogador.x-posInimigo.x)>= RAIO_PERSEGUIR_X)||(fabs(posJogador.y-posInimigo.y)>=RAIO_PERSEGUIR_Y)){
                if ((fabs(posJogador1.x - posInimigo.x) <= RAIO_PERSEGUIR_X))
                {
                    perseguir(posJogador1, posInimigo);
                }
                else
                {
                    moverAleatorio();
                }
            }
            else if (pJogador2 != nullptr)
            {
                sf::Vector2f posJogador2 = pJogador2->getCorpo().getPosition();
                if (fabs(posJogador2.x - posInimigo.x) <= RAIO_PERSEGUIR_X)
                {
                    perseguir(posJogador2, posInimigo);
                }
                else
                {
                    moverAleatorio();
                }
            }
            // não sei se o else aqui embaixo é o suficiente
            else
            {
                moverAleatorio();
            }
        }

        void Inimigo::perseguir(sf::Vector2f posJogador, sf::Vector2f posInimigo)
        {
            if ((posJogador.x - posInimigo.x) >= 0.0f)
            { // significa que o jogador está a direita
                // corpo.move(velocidade.x,0.0f);
                this->velocidade.x = 50.0f;
            }
            else
            {
                this->velocidade.x = -50.0f;
                // corpo.move(-velocidade.x,0.0f);
            }
            /*if(posJogador.y-posInimigo.y>=0.0f){//significa que o jogador está acima
                corpo.move(0.0f,velocidade.y);
            }
            else{
                corpo.move(0.0f,-velocidade.y);
            }*/
        }
        void Inimigo::moverAleatorio()
        {
            iteracoes++;
            // if(iteracoes>50){
            if (moveAleatorio == 0)
            {
                // corpo.move((velocidade.x), 0.0f);
                velocidade.x = VELOCIDADEY_DU;
            }
            else if (moveAleatorio == 1)
            {
                velocidade.x = -VELOCIDADEY_DU;
                // corpo.move((-velocidade.x), 0.0f);
            }
            //}
            /*else if(moveAleatorio==2){
                corpo.move(0.0f,velocidade.y);
            }
            else if(moveAleatorio==3){
                corpo.move(0.0f,-velocidade.y);
            }*/

            /*if(intervalo>=2.0f){
                moveAleatorio=rand()%FAIXA_ALEATORIO;
                relogio.restart();
            }*/
            if (iteracoes >= 10)
            { // 200
                srand((unsigned int)time(NULL));
                // Gera um número aleatório entre 0 e 99
                moveAleatorio = rand() % FAIXA_ALEATORIO;
                iteracoes = 0;
            }
        }

        void Inimigo::colisao(Entidade *outraEntidade)
        {
            int id = outraEntidade->getID();
            sf::Vector2f pos1 = getCorpo().getPosition();
            sf::Vector2f pos2 = outraEntidade->getCorpo().getPosition();

            sf::Vector2f tam1 = getCorpo().getSize();
            sf::Vector2f tam2 = outraEntidade->getCorpo().getSize();

            sf::Vector2f distancia(fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)), fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f)));

            int ID = outraEntidade->getID();
            switch (ID)
            {
            case IDPLATAFORMA:
                if (pos1.x > pos2.x && pos1.x < pos2.x + tam2.x)
                {
                    setPos(sf::Vector2f(pos2.x + tam2.x, pos1.y));
                }
                else if (pos1.x + tam1.x > pos2.x)
                {
                    setPos(sf::Vector2f(pos2.x - tam1.x, pos1.y));
                }
                if (pos1.y < pos2.y)
                {
                    setPos(sf::Vector2f(pos1.x, pos2.y - tam1.y));
                    velocidade.y = 0;
                    noChao = true;
                }
                break;
            }
        }
    }

}
