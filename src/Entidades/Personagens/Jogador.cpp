#pragma once
#include "../include/Entidades/Personagens/Jogador.hpp"
#include "Jogador.hpp"
 
 namespace Personagens{
  Jogador::Jogador(): Entidade(), pontos(0), numero_baixas(0), espada (false), magia (false), antidoto (false) 
  {
        retangulo.setSize(sf::Vector2f(50.f, 50.f));
        retangulo.setFillColor(sf::Color::Blue);
        retangulo.setPosition(x, y);
        velocidadeY = 0.f;
        noChao = false;
        pulando = false;
        puloForca= -std::sqrt(2 * 500.f * 2 * 50.f);//500.f eh a gravidade
  }
  Jogador::~Jogador(){}
  void Jogador::setTeclas( sf::Keyboard::Key esquerda, sf::Keyboard::Key direita, sf::Keyboard::Key pulo){
    teclaEsquerda=esquerda;
    teclaDireita=direita;
    teclaPulo=pulo;
  }
  void Jogador::atualizar(float deltaTime, bool& noChao, sf::RectangleShape& plataforma, float gravidade) {
        velocidadeY += gravidade * deltaTime;
        retangulo.move(0.f, velocidadeY * deltaTime);

        if (retangulo.getPosition().y + retangulo.getSize().y >= plataforma.getPosition().y) {
            retangulo.setPosition(retangulo.getPosition().x, plataforma.getPosition().y - retangulo.getSize().y);
            velocidadeY = 0.f;
            noChao = true;
            pulando = false;
        }

        if (sf::Keyboard::isKeyPressed(teclaEsquerda) && retangulo.getPosition().x > 0.f)
            retangulo.move(-200.f * deltaTime, 0.f);
        if (sf::Keyboard::isKeyPressed(teclaDireita) && retangulo.getPosition().x + retangulo.getSize().x < 800.f)
            retangulo.move(200.f * deltaTime, 0.f);

        if (sf::Keyboard::isKeyPressed(teclaPulo) && (noChao || !pulando)) {
            velocidadeY = puloForca;
            noChao = false;
            pulando = !noChao;
        }
    }

    void Jogador::desenhar(sf::RenderWindow& window) {
        window.draw(retangulo);
    }

    sf::RectangleShape& Jogador::getRetangulo() {
        return retangulo;
    }

  void Jogador::salvarDataBuffer(){}
  void Jogador::mover(){}
  void Jogador::executar() {}
  void Jogador::salvar(){}
 }

 void Personagens::Jogador::setCor(sf::Color c)
 {
     cor=c;
      getRetangulo().setFillColor(c);
 }
