#pragma once
#include "Ente.hpp"

namespace States{
    class State: public Ente{
        private:
            bool remover;
        
        public:
            State(const int ID);
            ~State();
            virtual void executar() = 0;
            virtual void desenhar();
            void setRemover(const bool remover);
            const bool getRemover();
    };
}