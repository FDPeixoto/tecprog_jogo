#pragma once
#include "Jogador.hpp"
#include "Personagem.hpp"
#include "stdafx.h"

enum class EstadoMovimento
{
    PARADO,
    ANDANDO_ESQUERDA,
    ANDANDO_DIREITA
};

namespace Entidades
{
    namespace Inimigos
    {
        class Inimigo : public Personagem
        {
        protected:
            int nivel_maldade;
            int moveAleatorio;
            Entidades::Jogador *pJogador1;
            Entidades::Jogador *pJogador2;
            sf::Clock relogio;
            int iteracoes;
            float tempoMudancaDirecao;
            float intervaloMudancaDirecao;
            EstadoMovimento estadoAtual;
            float timerEstado;
            float duracaoEstado;
            bool perseguindo;
            float alcance;

        public:
            Inimigo(const sf::Vector2f tamanho, const sf::Vector2f posicao, const int ID);
            virtual ~Inimigo();
            void setJogador1(Entidades::Jogador *pJogador);
            Entidades::Jogador *getJogador1();
            void setJogador2(Entidades::Jogador *pJogador);
            Entidades::Jogador *getJogador2();

            void salvarDataBuffer();

            void perseguir(sf::Vector2f posJogador, sf::Vector2f posInimigo);
            void changeState();
            void set_nivel_maldade(int n);
            const int get_nivel_maldade();

            void executar();
            virtual void atualizar(float dt);
            void inicializar();
            void mover();
            void atacar();

            virtual void moverAleatorio();
            void colisao(Entidade *outraEntidade);
            float getAlcance();
            void setAlcance(float distancia);
        };
    }
}