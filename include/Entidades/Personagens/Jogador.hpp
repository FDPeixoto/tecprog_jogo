#pragma once
#include "Personagem.hpp"

#include <cmath>
namespace Entidades{
  class Jogador: public Personagem{
  protected:
    int pontos;
    int numero_baixas;
    bool espada;
    bool magia;
    bool antidoto;
    bool pulando;

    sf::Keyboard::Key teclaEsquerda;
    sf::Keyboard::Key teclaDireita;
    sf::Keyboard::Key teclaPulo;

  public:
    Jogador(const sf::Vector2f posicao);
    ~Jogador();
    void setTeclas(sf::Keyboard::Key esquerda, sf::Keyboard::Key direita, sf::Keyboard::Key pulo);
    void atualizar(float deltaTime, bool& noChao, sf::RectangleShape& plataforma, float gravidade);
    void salvarDataBuffer();
    virtual void mover();
    virtual void executar();
    virtual void salvar();
    void colisao(Entidade* outraEntidade);
    void atualizar(float dt);
    void inicializar();   
  };
}