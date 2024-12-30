# pragma once
#include "Jogador.hpp"
#include "Personagem.hpp"

namespace Personagens{
    class Inimigo: public Personagem{
        protected:
        int nivel_maldade;

        public:
        Inimigo();
        ~Inimigo();
        void salvarDataBuffer();
        virtual void executar()=0;
        virtual void danificar(Jogador* p);
        void set_nivel_maldade(int n);
        const int get_nivel_maldade();

    };
}