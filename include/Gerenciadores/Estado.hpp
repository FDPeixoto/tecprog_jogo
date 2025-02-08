#pragma once
#include "State.hpp"
#include "Grafico.hpp"
#include <stack>
#include "stdafx.h"
#include "CarregarSaveState.hpp"
#include "FaseState.hpp"
#include "LeaderboardState.hpp"
#include "MenuFasesState.hpp"
#include "MenuInicialState.hpp"
#include "MenuJogadoresState.hpp"
#include "PauseState.hpp"

namespace Gerenciadores
{
    class Estado
    {
    private:
        std::stack<States::State *> pilhaStates;

        static Estado *pEstado;
        Estado();

    public:
        ~Estado();
        static Estado *getGerenciadorEstado();
        void executar();
        void addState(const int ID);
        void removerState();
        States::State *getStateAtual();
        int getIdentificadorAtual();
    };
}