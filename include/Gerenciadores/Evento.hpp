#pragma once
#include "Grafico.hpp"
#include "Estado.hpp"
#include "Fase.hpp"
#include <fstream>
//#include <vector>
#include <string>

namespace Gerenciadores{
    class Evento{
        private:
            Grafico* pGerenciadorGrafico;
            Estado* pEstado;
            Fases::Fase* pFase;
            Entidades::Jogador* pJog1;
            Entidades::Jogador* pJog2;
            static Evento* pGerenciadorEvento;    
            Evento();
        public:
            ~Evento();
            static Evento* getGerenciadorEvento();
            //void setNomePartida(const std::string nome);
            //sf::Text getTextoEntrada();
            void setJogador1(Entidades::Jogador* jogador);
            void setJogador2(Entidades::Jogador* jogador);
            void verificaTeclaPressionada(sf::Keyboard::Key tecla);
            void verificaTeclaSolta(sf::Keyboard::Key tecla);
            void executar(); 
                   
    };
}