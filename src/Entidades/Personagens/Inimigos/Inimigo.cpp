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

        Inimigo::Inimigo(const sf::Vector2f tamanho, const sf::Vector2f posicao, const int ID) : Personagem(tamanho, posicao, ID), nivel_maldade(0)
        {
            pJogador1 = nullptr;
            pJogador2 = nullptr;

            timerEstado = 0.0f;
            duracaoEstado = 0.0f;
            srand(static_cast<unsigned int>(time(NULL)));
            int estadoInicial = rand() % 3;
            switch (estadoInicial)
            {
            case 0:
                estadoAtual = EstadoMovimento::PARADO;
                break;
            case 1:
                estadoAtual = EstadoMovimento::ANDANDO_ESQUERDA;
                break;
            case 2:
                estadoAtual = EstadoMovimento::ANDANDO_DIREITA;
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
                tempoDesdeUltimoAtaque = 0.f;
            }

            sf::Vector2f posInimigo = corpo.getPosition();

            bool jogadorProximo = false;

            if (pJogador1 != nullptr)
            {
                sf::Vector2f posJogador1 = pJogador1->getCorpo().getPosition();
                float distancia = fabs(posJogador1.x - posInimigo.x);

                if (distancia <= getAlcance())
                {
                    jogadorProximo = true;
                }
            }

            if (pJogador2 != nullptr)
            {
                sf::Vector2f posJogador2 = pJogador2->getCorpo().getPosition();
                float distancia = fabs(posJogador2.x - posInimigo.x);

                if (distancia <= getAlcance())
                {
                    jogadorProximo = true;
                }
            }

            if (jogadorProximo)
            {
                atacar();
            }

            if (!noChao)
            {
                velocidade.y += 5.0f;
                if (velocidade.y > 100.f)
                {
                    velocidade.y = 100.f;
                }
            }
            else
            {
                velocidade.y = 0;
                noChao = false;
            }

            if (!perseguindo)
            {
                timerEstado += dt;
                if (timerEstado >= duracaoEstado)
                {
                    changeState();
                }

                switch (estadoAtual)
                {
                case EstadoMovimento::ANDANDO_ESQUERDA:
                    velocidade.x = -VELOCIDADEX_DU;
                    break;
                case EstadoMovimento::ANDANDO_DIREITA:
                    velocidade.x = VELOCIDADEX_DU;
                    break;
                case EstadoMovimento::PARADO:
                    velocidade.x = 0;
                    break;
                }
            }
            perseguindo = false;

            sf::Vector2f pos = corpo.getPosition();
            sf::FloatRect bounds = corpo.getLocalBounds();

            if (velocidade.x < 0.f)
            {

                corpo.setOrigin(bounds.width, 0);
                corpo.setScale(-1.f, 1.f);
            }
            else
            {

                corpo.setOrigin(0, 0);
                corpo.setScale(1.f, 1.f);
            }

            corpo.setPosition(pos);

            corpo.move(velocidade.x * dt, velocidade.y * dt);
            checarForaDaJanela();
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
                    if (distx1 <= RAIO_PERSEGUIR_X && distx1 >= 0.1f)
                    {
                        perseguir(posJogador1, posInimigo);
                        perseguindo = true;
                    }
                }
                else if (distx2 <= RAIO_PERSEGUIR_X && distx2 >= 0.1f)
                {
                    perseguir(posJogador2, posInimigo);
                    perseguindo = true;
                }
            }
            else if (pJogador1 != nullptr)
            {
                sf::Vector2f posJogador1 = pJogador1->getCorpo().getPosition();
                if ((fabs(posJogador1.x - posInimigo.x) <= RAIO_PERSEGUIR_X) && fabs(posJogador1.x - posInimigo.x) >= 0.1f)
                {
                    perseguir(posJogador1, posInimigo);
                    perseguindo = true;
                }
            }
            else if (pJogador2 != nullptr)
            {
                sf::Vector2f posJogador2 = pJogador2->getCorpo().getPosition();
                if (fabs(posJogador2.x - posInimigo.x) <= RAIO_PERSEGUIR_X && fabs(posJogador2.x - posInimigo.x) >= 0.1f)
                {
                    perseguir(posJogador2, posInimigo);
                    perseguindo = true;
                }
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

            if (deltaX < 0)
            {
                velocidade.x = -VELOCIDADEX_DU;
            }
            else
            {
                velocidade.x = VELOCIDADEX_DU;
            }
        }

        void Inimigo::changeState()
        {

            int randomState = rand() % 3;
            switch (randomState)
            {
            case 0:
                estadoAtual = EstadoMovimento::PARADO;
                duracaoEstado = 1.0f + (rand() % 3);
                break;
            case 1:
                estadoAtual = EstadoMovimento::ANDANDO_ESQUERDA;
                duracaoEstado = 1.0f + (rand() % 3);
                break;
            case 2:
                estadoAtual = EstadoMovimento::ANDANDO_DIREITA;
                duracaoEstado = 1.0f + (rand() % 3);
                break;
            }

            timerEstado = 0.0f;
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
            if (ID == IDPLATAFORMA || ID == IDESPINHO || ID == IDCAIXA)
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
        float Inimigo::getAlcance()
        {
            return alcance;
        }
        void Inimigo::setAlcance(float distancia)
        {
            alcance = distancia;
        }
    }
}