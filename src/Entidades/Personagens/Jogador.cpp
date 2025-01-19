#include "Jogador.hpp"
#include "stdafx.h"
 

 namespace Entidades{
    Jogador::Jogador(const sf::Vector2f posicao): 
    Personagem(sf::Vector2f(JOGADORLARGURA, JOGADORALTURA) , posicao, JOGADOR), pontos(0), numero_baixas(0), espada (false), magia (false), antidoto (false){
        setVelocidade(sf::Vector2f(0.1f, 0.1f));
    }
  Jogador::~Jogador(){}
  void Jogador::setTeclas(sf::Keyboard::Key esquerda, sf::Keyboard::Key direita, sf::Keyboard::Key pulo){
    teclaEsquerda=esquerda;
    teclaDireita=direita;
    teclaPulo=pulo;
  }

  /*
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
            retangulo.move(-200.f * deltaTime, 0.f);//Parece que o -200 .f é  a velocidade do x, os parâmetros são (x,y)
        if (sf::Keyboard::isKeyPressed(teclaDireita) && retangulo.getPosition().x + retangulo.getSize().x < 800.f)
            retangulo.move(200.f * deltaTime, 0.f);

        if (sf::Keyboard::isKeyPressed(teclaPulo) && (noChao || !pulando)) {
            velocidadeY = puloForca;
            noChao = false;
            pulando = !noChao;
        }
  }
  */

  void Jogador::salvarDataBuffer(){}
  void Jogador::mover(){

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        corpo.move(-velocidade.x, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        corpo.move(velocidade.x, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        corpo.move(0.f, -velocidade.y);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        corpo.move(0.f, velocidade.y);
    }
  }
  void Jogador::executar() {}
  void Jogador::salvar(){}
  void Jogador::colisao(Entidade *outraEntidade, sf::Vector2f distancia)
  {
  }
 }
