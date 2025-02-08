// MenuState.cpp
#include "MenuState.hpp"

namespace States
{
    namespace Menus
    {
        MenuState::MenuState(int id)
            : State(id), // Initialize State with ID
              Ente(id),  // Initialize Ente with same ID
              pGrafico(pGrafico->getGerenciadorGrafico())
        {
        }

        MenuState::~MenuState()
        {
            for (auto &element : botoes)
            {
                delete element;
            }
        }

        void MenuState::desenhar()
        {
            // 1. Draw Ente's base properties (if needed)
            // sf::RectangleShape quadrado(sf::Vector2f(100.f, 100.f), sf::Vector2f(100.f, 100.f));

            // 2. Draw all UI elements
            for (auto &botao : botoes)
            {
                sf::RenderWindow *janela = pGrafico->getJanela();
                botao->desenhar(janela);
            }
        }

        void MenuState::executar()
        {
            desenhar();
            // Update logic for menu and UI elements
            for (auto &element : botoes)
            {
                element->executar();
            }
        }
        Fases::Fase *MenuState::getFase()
        {
            return nullptr; // or return a valid Fase object if available
        }
    }
}