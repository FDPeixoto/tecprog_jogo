
#include "MenuState.hpp"

namespace States
{
    namespace Menus
    {
        MenuState::MenuState(int id)
            : State(id),
              Ente(id),
              pGrafico(pGrafico->getGerenciadorGrafico())
        {
        }

        MenuState::~MenuState()
        {
            for (std::vector<Botao *>::iterator iterator = botoes.begin(); iterator != botoes.end(); iterator++)
            {
                delete (*iterator);
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

                sf::FloatRect bounds = titulo.getLocalBounds();
                titulo.setOrigin(bounds.width / 2, bounds.height / 2);
                titulo.setPosition(pGrafico->getJanela()->getSize().x / 2.0f, 100.0f);
            }
        }

        void MenuState::desenhar()
        {

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