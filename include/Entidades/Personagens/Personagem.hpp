#pragma once
#include "Entidade.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

namespace Entidades
{
  class Personagem : public Entidade
  {
  protected:
    int num_vidas;
    sf::Vector2f velocidade;
    bool noChao;
    bool pulando;
    sf::Font font;
    sf::Text textoVida;
    bool vivo;
    int dano;
    float cooldownAtaque;
    float tempoDesdeUltimoAtaque;
    bool podeAtacar;

  public:
    Personagem(const sf::Vector2f tamanho, const sf::Vector2f posicao, const int ID);
    ~Personagem();

    virtual void executar() = 0;
    virtual void salvar() = 0;
    void setVelocidade(sf::Vector2f vel);
    virtual void atualizarPosicao(float dt);
    void setNumVidas(int n);
    const int getNumVidas();

    void setVivo(bool v);
    bool getVivo();
    void setPosTexto(int x, int y);
    sf::Text getTextoVida();
    void atacar(int dano, Personagem *personagem);
    void tomarDano(int dano);
    virtual void atacar() = 0;
    sf::Vector2f getVelocidade();
    void checarForaDaJanela();
    void setNoChao(bool chao);
  };
}