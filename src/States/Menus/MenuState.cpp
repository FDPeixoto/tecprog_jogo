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

        void MenuState::inicializarTitulo(const std::string &texto, unsigned tamanhoFonte)
        {
            if (pGrafico)
            {

                if (!fonte.loadFromFile("Fonte/DejaVuSans.ttf"))
                {
                    std::cerr << "Erro ao carregar a fonte!" << std::endl;
                    return;
                }

                titulo.setFont(fonte);
                titulo.setString(texto);
                titulo.setCharacterSize(tamanhoFonte);
                titulo.setFillColor(sf::Color::White);

                // Center title horizontally
                sf::FloatRect bounds = titulo.getLocalBounds();
                titulo.setOrigin(bounds.width / 2, bounds.height / 2);
                titulo.setPosition(pGrafico->getJanela()->getSize().x / 2.0f, 100.0f);
            }
        }

        void MenuState::desenhar()
        {
            // 1. Draw Ente's base properties (if needed)
            // sf::RectangleShape quadrado(sf::Vector2f(100.f, 100.f), sf::Vector2f(100.f, 100.f));
            // 2. Draw all UI elements
            pGrafico->getJanela()->draw(titulo);
            for (auto &botao : botoes)
            {

                botao->desenhar(pGrafico->getJanela());
            }
        }

        void MenuState::executar()
        {
            desenhar();
            for (auto &element : botoes)
            {
                element->executar();
            }
        }
        Fases::Fase *MenuState::getFase()
        {
            return nullptr;
        }
    }
}