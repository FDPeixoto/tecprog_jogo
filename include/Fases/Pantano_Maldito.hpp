#pragma once
#include "Fase.hpp"
//#include "../Entidades/Entidade.hpp"
#include "Jogador.hpp"


namespace Fases{
    class Pantano_Maldito: public Fase{
        private:
        const int maxInimMedios;

        public:
        Pantano_Maldito();
        ~Pantano_Maldito();
        void executar();
        void criarInimMedios();
        bool completou();
        void criarInimigos();
        void criarObstaculos();
        const int getMaxInimMedios();
        
    };

}