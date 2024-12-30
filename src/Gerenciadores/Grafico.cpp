/*#include "Gerenciadores/Grafico.h"

#include <cstring>
#include <iostream>

#define LARGURA 1280
#define ALTURA 720

namespace Gerenciadores {

    /* Singleton design pattern - Only one instance will be created */
    //Grafico* Grafico::instancia = nullptr;

    /* Returns a pointer to the Graphics. */
    //Grafico* Grafico::getInstancia() {
      //  if (instancia == nullptr) {
            //instancia = new Graphics();
        //}
        //return instancia;
    //}

    /*Grafico::Grafico() :
    window(new sf::RenderWindow(sf::VideoMode(LARGURA, ALTURA), "Jogo", sf::Style::Titlebar | sf::Style::Close)),
    view(sf::Vector2f(LARGURA/ 2, ALTURA/ 2), sf::Vector2f(LARGURA, ALTURA)),
    MapaTexturas(),
    fontsMap() { }

    Grafico::~Grafico() {
        std::map<const char*, sf::Texture*>::iterator it;

        for (it = mapTexturas.begin(); it != mapTexturas.end(); ++it) {
            delete (it->second);
        }

        delete (window);
    }

    /* Give a pointer to a body and it will be drawn to the screen. */
    /*void Grafico::render(sf::RectangleShape* body) {
        window->draw(*body);
    }

    /* Give a pointer to a Text and it will be drawn to the screen */
    /*void Grafico::render(sf::Text* text) {
        window->draw(*text);
    }

    /* Display everything that was drawn. */
    /*void Grafico::display() {
        if (isWindowOpen())
            window->display();
    }

    /* Clear the window to re-display stuff. */
    /*void Grafico::clear() {
        if (isWindowOpen())
            window->clear();
    }

    /* Returns if the window is open. */
    /*bool Grafico::isWindowOpen() const {
        return window->isOpen();
    }

    /* CAUTION: Call the close window function - SFML window will close. */
    /*void Grafico::closeWindow() {
        window->close();
    }

    /* Sets window size to its parameters */
    /*void Grafico::setWindowSize(Matematica::CoordU size) {
        window->setSize(sf::Vector2u(size.x, size.y));
        view.setSize(size.x, size.y);
        window->setView(view);
    }

    /* Returns the window size. */
    /*Matematica::CoordU Grafico::getWindowSize() const {
        return Math::CoordU(window->getSize().x, window->getSize().y);
    }

    /* Returns the top left position of screen. */
    /*Matematica::CoordF Grafico::getTopLeftPosition() const {
        return Math::CoordF(window->getView().getCenter().x - window->getSize().x / 2, window->getView().getCenter().y - window->getSize().y / 2);
    }

    /* Changes the view position. */
    /*void Grafico::centerView(Matematica::CoordF pos) {
        view.setCenter(sf::Vector2f(pos.x, pos.y));
        window->setView(view);
    }

    /* Returns a texture to be used by an entity. */
    /*sf::Texture* Grafico::loadTexture(const char* caminho) {
        /* Tries to find an existing texture linked by the path to it. */
        /*std::map<const char*, sf::Texture*>::iterator it = mapTexturas.begin();
        while (it != mapTexturas.end()) {
            if (!strcmp(it->first, caminho))
                return it->second;
            it++;
        }

        /* If not found, must load it. */
        /*sf::Texture* tex = new sf::Texture();

        if (!tex->loadFromFile(caminho)) {
            std::cout << "ERRO ao carregar o caminho da textura " << path << std::endl;
            exit(1);
        }

        maptexturas.insert(std::pair<const char*, sf::Texture*>(path, tex));

        return tex;
    }

    /* Returns a font pointer to be used by texts. */
    //sf::Font* Grafico::loadFont(const char* caminho) {
        /* Tries to find an existing font linked by the path to it */
        /*std::map<const char*, sf::Font*>::iterator it = fontsMap.begin();
        while (it != fontsMap.end()) {
            if (!strcmp(it->first, caminho))
                return it->second;
            it++;
        }

        /* If not found, must load it. */
        /*sf::Font* font = new sf::Font();

        if (!font->loadFromFile(caminho)) {
            std::cout << "ERRO ao carregar a fonte " << caminho << std::endl;
            exit(1);
        }

        fontsMap.insert(std::pair<const char*, sf::Font*>(caminho, font));

        return font;
    }

    sf::RenderWindow* Graphics::getWindow() const {
        return window;
    }

} // namespace Gerenciadores

*/