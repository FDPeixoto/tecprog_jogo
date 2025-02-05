#pragma once

#include "State.hpp"

namespace Fases
{
    class Fase;
    class Pantano_Maldito;
    class Castelo_Assombrado;
}

namespace States
{
    class FaseState : public State
    {
    private:
        Fases::Fase *pFase;

    public:
        FaseState(const int idFase);
        ~FaseState();
        Fases::Fase *getFase();
        void executar();
        // void mudarEstadoObservador();
    };
}