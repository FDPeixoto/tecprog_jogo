#include "Botao.hpp"

namespace States
{
    namespace Menus
    {
        Botao::Botao(int id, const std::string &textStr, std::function<void()> action, const sf::Vector2f &position, const sf::Vector2f &size)
            : Ente(id), label(textStr), onClick(action), isSelected(false)
        {

            // Load font (Ensure font file exists in the project directory)
            fonte.loadFromFile("Fonte/DejaVuSans.ttf");

            // Set up the button corpo
            corpo.setSize(size);
            corpo.setPosition(position);
            corpo.setFillColor(sf::Color::White); // Default color
            corpo.setOutlineColor(sf::Color::Black);
            corpo.setOutlineThickness(2.0f);

            // Set up the text
            texto.setFont(fonte);
            texto.setString(label);
            texto.setCharacterSize(20);
            texto.setFillColor(sf::Color::Black);

            // Center text inside button
            sf::FloatRect textBounds = texto.getLocalBounds();
            texto.setPosition(
                position.x + (size.x - textBounds.width) / 2.0f,
                position.y + (size.y - textBounds.height) / 2.0f);
        }
        Botao::~Botao()
        {
        }
        void Botao::desenhar(sf::RenderWindow *janela)
        {
            janela->draw(corpo);
            janela->draw(texto);
        }

        void Botao::executar()
        {
            return;
        }
    }
}