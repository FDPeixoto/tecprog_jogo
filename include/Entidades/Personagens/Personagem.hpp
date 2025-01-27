#pragma once
#include "Entidade.hpp"
namespace Entidades{
  class Personagem:public Entidade{
  protected:
    int num_vidas;
    sf::Vector2f velocidade;
    bool noChao;
  public:
    Personagem(const sf::Vector2f tamanho, const sf::Vector2f posicao, const int ID);
    ~Personagem();
    //virtual void mover() = 0;
    virtual void executar() = 0;
    virtual void salvar()= 0;
    void setVelocidade(sf::Vector2f vel);
    void atualizarPosicao(float dt);
  };
}