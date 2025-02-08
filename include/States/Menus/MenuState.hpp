// MenuState.hpp
#pragma once
#include "State.hpp"
#include "Ente.hpp"
#include "Botao.hpp"
#include "Grafico.hpp"
#include <vector>

namespace States
{
    namespace Menus
    {
        class MenuState : public State, public Ente
        {
        protected:
            std::vector<Botao *> botoes;
            Gerenciadores::Grafico *pGrafico;

        public:
            MenuState(int id);
            virtual ~MenuState();

            // Override BOTH desenhar() implementations
            void desenhar() override;

            // Optional: Override executar() from Ente
            void executar() override;

            Fases::Fase *getFase();
        };
    }

}