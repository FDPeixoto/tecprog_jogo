
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
            sf::Text titulo;
            sf::Font fonte;

            void inicializarTitulo(const std::string &texto, unsigned tamanhoFonte = 40);

        public:
            MenuState(int id);
            virtual ~MenuState();

            void desenhar() override;

            void executar() override;

            Fases::Fase *getFase();
        };
    }

}