#pragma once
#include "../include/Entidades/Entidade.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
namespace Personagens{
class Jogador:public Entidade{
protected:
  int pontos;
  int numero_baixas;
  bool espada;
  bool magia;
  bool antidoto;

  sf::RectangleShape retangulo;
    sf::Color cor;
    float velocidadeY;
    bool noChao;
    bool pulando;

    sf::Keyboard::Key teclaEsquerda;
    sf::Keyboard::Key teclaDireita;
    sf::Keyboard::Key teclaPulo;
    float puloForca;

public:
  Jogador();
  ~Jogador();
  void setTeclas( sf::Keyboard::Key esquerda, sf::Keyboard::Key direita, sf::Keyboard::Key pulo);
  void atualizar(float deltaTime, bool& noChao, sf::RectangleShape& plataforma, float gravidade);
  void desenhar(sf::RenderWindow& window);
  sf::RectangleShape& getRetangulo();
  void salvarDataBuffer();
  void setCor(sf::Color c);
  virtual void mover();
  virtual void executar();
  virtual void salvar();
};
}