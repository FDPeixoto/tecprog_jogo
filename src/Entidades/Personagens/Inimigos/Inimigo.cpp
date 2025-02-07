#include "Jogador.hpp"
#include "stdafx.h"
#include <Inimigos/Inimigo.hpp>

#include <stdlib.h>
#include <time.h>
#include "Inimigo.hpp"

namespace Entidades
{
    namespace Inimigos
    {
        // Movement states
        Inimigo::Inimigo(const sf::Vector2f tamanho, const sf::Vector2f posicao, const int ID) : Personagem(tamanho, posicao, ID), nivel_maldade(0)
        {
            pJogador1 = nullptr;
            pJogador2 = nullptr;

            stateTimer = 0.0f;
            stateDuration = 0.0f;
            srand(static_cast<unsigned int>(time(NULL))); // Seed the random number generator
            int randomState = rand() % 3;                 // 0: IDLE, 1: WALKING_LEFT, 2: WALKING_RIGHT
            switch (randomState)
            {
            case 0:
                currentState = MovementState::IDLE; // Idle for 1-3 seconds
                break;
            case 1:
                currentState = MovementState::WALKING_LEFT; // Walk left for 2-6 seconds
                break;
            case 2:
                currentState = MovementState::WALKING_RIGHT; // Walk right for 2-6 seconds
                break;
            }
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
        }

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
            tempoDesdeUltimoAtaque += dt;
            if (tempoDesdeUltimoAtaque >= cooldownAtaque)
            {
                podeAtacar = true;
                tempoDesdeUltimoAtaque -= cooldownAtaque;
            }

            // Apply gravity
            if (!noChao)
            {
                velocidade.y += 5.0f; // Apply gravity scaled by dt
                if (velocidade.y > 100.f)
                {
                    velocidade.y = 100.f; // Limit falling speed
                }
            }
            else
            {
                velocidade.y = 0; // Stop vertical movement when on the ground
                noChao = false;
            }

            // Update movement state
            if (!perseguindo)
            {
                stateTimer += dt;
                if (stateTimer >= stateDuration)
                {
                    changeState();
                }

                // Move the enemy based on the current state
                switch (currentState)
                {
                case MovementState::WALKING_LEFT:
                    velocidade.x = -VELOCIDADEX_DU; // Move left
                    break;
                case MovementState::WALKING_RIGHT:
                    velocidade.x = VELOCIDADEX_DU; // Move right
                    break;
                case MovementState::IDLE:
                    velocidade.x = 0; // Stop moving
                    break;
                }
            }
            perseguindo = false;
            // Move the enemy
            corpo.move(velocidade.x * dt, velocidade.y * dt);
        }

        void Inimigo::mover()
        {
            sf::Vector2f posInimigo = corpo.getPosition();
            if ((pJogador1 != nullptr) && (pJogador2 != nullptr))
            {
                sf::Vector2f posJogador1 = pJogador1->getCorpo().getPosition();
                sf::Vector2f posJogador2 = pJogador2->getCorpo().getPosition();

                float distx1 = fabs(posJogador1.x - posInimigo.x);
                float distx2 = fabs(posJogador2.x - posInimigo.x);

                if (distx1 <= distx2)
                {
                    if (distx1 <= RAIO_PERSEGUIR_X)
                    {
                        perseguir(posJogador1, posInimigo);
                        perseguindo = true;
                    }
                }
                else if (distx2 <= RAIO_PERSEGUIR_X)
                {
                    perseguir(posJogador2, posInimigo);
                    perseguindo = true;
                }
            }
            else if (pJogador1 != nullptr)
            {
                sf::Vector2f posJogador1 = pJogador1->getCorpo().getPosition();
                if ((fabs(posJogador1.x - posInimigo.x) <= RAIO_PERSEGUIR_X))
                {
                    perseguir(posJogador1, posInimigo);
                    perseguindo = true;
                }
            }
            else if (pJogador2 != nullptr)
            {
                sf::Vector2f posJogador2 = pJogador2->getCorpo().getPosition();
                if (fabs(posJogador2.x - posInimigo.x) <= RAIO_PERSEGUIR_X)
                {
                    perseguir(posJogador2, posInimigo);
                    perseguindo = true;
                }
            }

            // Only flip if changing direction
            if (velocidade.x < 0.f)
            {

                // Get current position and bounds
                sf::Vector2f pos = corpo.getPosition();
                sf::FloatRect bounds = corpo.getLocalBounds();

                if (velocidade.x < 0.f)
                {
                    // Move origin to the right side before flipping
                    corpo.setOrigin(bounds.width, 0);
                    corpo.setScale(-1.f, 1.f);
                }
                else
                {
                    // Move origin back to the left side before flipping back
                    corpo.setOrigin(0, 0);
                    corpo.setScale(1.f, 1.f);
                }

                // Keep the position the same
                corpo.setPosition(pos);
            }
        }

        void Inimigo::atacar()
        {
            if (podeAtacar)
            {
                if (pMediator)
                {
                    pMediator->notificar(this, "ataqueDoInimigo");
                }
                podeAtacar = false;
            }
        }

        void Inimigo::perseguir(sf::Vector2f posJogador, sf::Vector2f posInimigo)
        {
            float deltaX = posJogador.x - posInimigo.x;

            // Smoothly adjust velocity towards the player
            if (deltaX < 0)
            {
                velocidade.x = -VELOCIDADEX_DU; // Move left
            }
            else
            {
                velocidade.x = VELOCIDADEX_DU; // Move right
            }
        }

        void Inimigo::changeState()
        {
            // Randomly choose a new state
            int randomState = rand() % 3; // 0: IDLE, 1: WALKING_LEFT, 2: WALKING_RIGHT
            switch (randomState)
            {
            case 0:
                currentState = MovementState::IDLE;
                stateDuration = 1.0f + (rand() % 3); // Idle for 1-3 seconds
                break;
            case 1:
                currentState = MovementState::WALKING_LEFT;
                stateDuration = 1.0f + (rand() % 3); // Walk left for 2-6 seconds
                break;
            case 2:
                currentState = MovementState::WALKING_RIGHT;
                stateDuration = 1.0f + (rand() % 3); // Walk right for 2-6 seconds
                break;
            }

            // Reset the state timer
            stateTimer = 0.0f;
        }

        void Inimigo::moverAleatorio()
        {
            return;
        }

        void Inimigo::colisao(Entidade *outraEntidade)
        {
            sf::Vector2f pos1 = getCorpo().getPosition();
            sf::Vector2f pos2 = outraEntidade->getCorpo().getPosition();

            sf::Vector2f tam1 = getCorpo().getSize();
            sf::Vector2f tam2 = outraEntidade->getCorpo().getSize();

            float overlapX = std::min(pos1.x + tam1.x, pos2.x + tam2.x) - std::max(pos1.x, pos2.x);
            float overlapY = std::min(pos1.y + tam1.y, pos2.y + tam2.y) - std::max(pos1.y, pos2.y);

            int ID = outraEntidade->getID();
            if (ID == IDPLATAFORMA || ID == IDESPINHO || ID == IDCANHAO)
            {
                if (overlapX < overlapY)
                {
                    if (pos1.x < pos2.x)
                    {
                        setPos(sf::Vector2f(pos2.x - tam1.x, pos1.y));
                    }
                    else
                    {
                        setPos(sf::Vector2f(pos2.x + tam2.x, pos1.y));
                    }
                }
                else
                {
                    if (pos1.y < pos2.y)
                    {
                        setPos(sf::Vector2f(pos1.x, pos2.y - tam1.y));
                        noChao = true;
                    }
                    else
                    {
                        setPos(sf::Vector2f(pos1.x, pos2.y + tam2.y));
                    }
                }
            }
        }
    }
}