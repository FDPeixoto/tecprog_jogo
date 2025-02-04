#pragma once

namespace States
{
    class State
    {
    private:
        bool remover;
        const int identificador;

    public:
        State(const int ID);
        ~State();
        virtual void executar() = 0;
        virtual void desenhar();
        void setRemover(const bool remover);
        const bool getRemover();
    };
}