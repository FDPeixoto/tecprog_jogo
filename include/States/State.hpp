#pragma once
#include "Ente.hpp"


namespace Fases {
    class Fase;
    class Pantano_Maldito;
    class Castelo_Assombrado;
}
namespace States{
    class State: public Ente{
        private:
            bool remover;
        
        public:
            State(const int ID);
            ~State();
            virtual void executar() = 0;
            virtual void desenhar();
            virtual Fases::Fase *getFase()=0;
            void setRemover(const bool remover);
            const bool getRemover();
    };
}