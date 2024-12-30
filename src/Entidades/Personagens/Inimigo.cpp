# pragma once
#include "Jogador.hpp"
#include "Personagem.hpp"
#include "Inimigo.hpp"


    class Inimigo: public Personagens::Personagem{
        protected:
        int nivel_maldade;

        public:
        Inimigo(): nivel_maldade(0){}
        ~Inimigo(){}
        void salvarDataBuffer(){}
        virtual void executar(){}
        virtual void danificar(Personagens::Jogador* p){}
        void set_nivel_maldade(int n){
            if((n>0)&&(n<5)){
                nivel_maldade=n;
            }
        }
        const int get_nivel_maldade(){
            return (nivel_maldade);
        }

    };
