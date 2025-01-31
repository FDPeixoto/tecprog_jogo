#pragma once
#include "Personagem.hpp"
#include "stdafx.h"
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
    bool atacando;
    bool andando;
    bool paraEsquerda;
    bool ehJogador2;

  public:
    Jogador(const sf::Vector2f posicao, bool jogador2);
    ~Jogador();
    void setTeclas(sf::Keyboard::Key esquerda, sf::Keyboard::Key direita, sf::Keyboard::Key pulo);
    void atualizar(float deltaTime, bool& noChao, sf::RectangleShape& plataforma, float gravidade);
    void salvarDataBuffer();
    void executar();
    void salvar();
    void andar(const bool paraEsquerda);
    const bool getAndando() const;
    void parar();
    void colisao(Entidade* outraEntidade);
    void atualizar(float dt);
    void inicializar();  
    void pular(); 
  };
}