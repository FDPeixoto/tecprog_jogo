# pragma once
#include "Jogador.hpp"
#include "Personagem.hpp"
#include "stdafx.h"

namespace Entidades{
    namespace Inimigos{
        class Inimigo: public Personagem{
            protected:
            int nivel_maldade;
            int moveAleatorio;
            Entidades::Jogador* pJogador1;
            Entidades::Jogador* pJogador2;
            sf::Clock relogio;
            int iteracoes;



            public:
            Inimigo(const sf::Vector2f tamanho, const sf::Vector2f posicao);
            ~Inimigo();
            void setJogador1(Entidades::Jogador* pJogador);
            Entidades::Jogador* getJogador1();
            void setJogador2(Entidades::Jogador* pJogador);
            Entidades::Jogador* getJogador2();

            void salvarDataBuffer();
            //virtual void executar()=0;
            //virtual void danificar(Jogador* p);
            void perseguir (sf::Vector2f posJogador, sf::Vector2f posInimigo);
            void set_nivel_maldade(int n);
            const int get_nivel_maldade();
            //virtual void executar()=0;
            void executar();
            virtual void atualizar(float dt);
            void inicializar();
            void mover();
            //void andar():
            virtual void moverAleatorio();

        };
    }
}