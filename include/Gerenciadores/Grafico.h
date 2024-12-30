#pragma once

#include "Matematica/CoordTL.h"
#include <SFML/Graphics.hpp>

#include <map>

namespace Gerenciadores {

    class Grafico {
    private:
        sf::RenderWindow* window;
        sf::View view;
        std::map<const char*, sf::Texture*> mapTexturas;
        std::map<const char*, sf::Font*> mapFontes;
        
        /* Singleton design pattern */
        static Gerenciadores::Grafico* instancia;
        Grafico();

    public:
        ~Grafico();

        static Grafico* getInstancia();

        void render(sf::RectangleShape* body);

        void render(sf::Text* text);

        void display();

        void clear();

        bool isWindowOpen() const;

        void closeWindow();

        void setWindowSize(/*Math::CoordU size*/);

        Matematica::CoordU getWindowSize() const;

        Matematica::CoordF getTopLeftPosition() const;

        void centerView(Matematica::CoordF pos);

        sf::Texture* loadTexture(const char* caminho);

        sf::Font* loadFont(const char* caminho);

        float updateDeltaTime();

        sf::RenderWindow* getWindow() const;

    };

} // namespace Gerenciadores