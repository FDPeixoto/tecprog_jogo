# pragma once
#include "Jogador.hpp"
#include "Personagem.hpp"

#define RAIO_PERSEGUIR_X 200.0f
#define RAIO_PERSEGUIR_Y 200.0f

namespace Entidades{
    namespace Inimigos{
        class Inimigo: public Personagem{
            protected:
            int nivel_maldade;
            int moveAleatorio;
            Entidades::Jogador* jog;
            sf::Clock relogio;



            public:
            Inimigo(const sf::Vector2f tamanho, const sf::Vector2f posicao);
            ~Inimigo();
            void salvarDataBuffer();
            //virtual void executar()=0;
            //virtual void danificar(Jogador* p);
            void perseguir (sf::Vector2f posJogador, sf::Vector2f posInimigo);
            void set_nivel_maldade(int n);
            const int get_nivel_maldade();
            virtual void executar()=0;
            void atualizar(float dt);
            void inicializar();
            void mover();
            virtual void moverAleatorio();

        };
    }
}