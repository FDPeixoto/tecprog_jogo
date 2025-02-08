#pragma once
#include "Ente.hpp"
#include <SFML/Graphics.hpp>
#include <functional>
#include <string>

namespace States
{
    namespace Menus
    {
        class Botao : public Ente
        {
        private:
            std::string label;
            std::function<void()> onClick;
            bool isSelected;
            sf::RectangleShape corpo;
            sf::Text texto;
            sf::Font fonte;

        public:
            Botao(int id, const std::string &text, std::function<void()> action, const sf::Vector2f &position, const sf::Vector2f &size);
            ~Botao();

            void desenhar(sf::RenderWindow *janela);
            void executar() override;

            void setSelected(bool selected);
            bool getSelected() const;
            void triggerAction();
        };
    }
}
