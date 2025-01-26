#pragma once
#include "Grafico.hpp"

namespace Gerenciadores{
    class Evento{
        private:
         Gerenciadores::Grafico* pGerenciadorGrafico;
        //static GerenciadorEstado* pGerenciadorEstado;
        Entidades::Jogador* jog1;
        Entidades::Jogador* jog2;
        static Evento* pGerenciadorEvento;
        Evento();
        public:
        ~Evento();
        static Evento* getGerenciadorEvento();
        void setJogador1(Entidades::Jogador* jog);
        void setJogador2(Entidades::Jogador* jog);
        void verificaTeclaPressionada(sf::Keyboard::Key tecla);
        void verificaTeclaSolta(sf::Keyboard::Key tecla);
        void executar();            
    };
}