#include "../../include/Fases/Pantano_Maldito.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

Fases::Pantano_Maldito::Pantano_Maldito(): maxInimMedios(1)
{
}

Fases::Pantano_Maldito::~Pantano_Maldito()
{
}
void Fases::Pantano_Maldito::executar()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jogadores");

    const float gravidade = 500.f;
    //const float puloForca = -std::sqrt(2 * gravidade * 2 * 50.f);

    Personagens::Jogador* jogador1=new Personagens::Jogador();
    jogador1->setX(375.f);
    jogador1->setY(475.f);
    jogador1->setTeclas(sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Up);

    Personagens::Jogador* jogador2=new Personagens::Jogador();
    jogador2->setX(200.f);
    jogador2->setY(475.f);
    jogador2->setTeclas(sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::W);

    jogador2->setCor(sf::Color::Yellow);
    
    //Inimigo inimigo(100.f, 100.f, 50.f, gravidade);

    sf::RectangleShape plataforma(sf::Vector2f(800.f, 50.f));
    plataforma.setFillColor(sf::Color::Green);
    plataforma.setPosition(0.f, 550.f);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        bool noChaoAzul = false;
        bool noChaoAmarelo = false;

        jogador1->atualizar(deltaTime, noChaoAzul, plataforma, gravidade);
        jogador2->atualizar(deltaTime, noChaoAmarelo, plataforma, gravidade);

        //inimigo.atualizar(deltaTime, jogadorAzul, jogadorAmarelo, plataforma);

        window.clear();
        window.draw(plataforma);
        jogador1->desenhar(window);
        jogador2->desenhar(window);
        //inimigo.desenhar(window);
        window.display();
    }
   
}
void Fases::Pantano_Maldito::criarInimMedios()
{
}
void Fases::Pantano_Maldito::criarInimigos()
{
    criarInimFaceis();
    criarInimMedios();
}
void Fases::Pantano_Maldito::criarObstaculos()
{
    criarObstFaceis();
    criarObstMedios();
}
bool Fases::Pantano_Maldito::completou()
{
}
const int Fases::Pantano_Maldito::getMaxInimMedios()
{
    return maxInimMedios;
}
