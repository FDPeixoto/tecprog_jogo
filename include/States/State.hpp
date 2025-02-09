#pragma once

namespace Fases
{
    class Fase;
    class Pantano_Maldito;
    class Castelo_Assombrado;
}

namespace Gerenciadores
{
    class Estado;
}
namespace States
{
    class State
    {
    private:
        bool remover;
        const int identificador;
        Gerenciadores::Estado *pEstado;

    public:
        State(const int ID);
        virtual ~State();
        virtual void executar() = 0;
        virtual void desenhar();
        virtual Fases::Fase *getFase() = 0;
        void setRemover(const bool remover);
        const bool getRemover();
        int getIdentificador();
    };
}