#pragma once
#include "Personagem.hpp"
#include "stdafx.h"
#include <cmath>
namespace Entidades
{
  class Jogador : public Personagem
  {
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
    sf::Texture textura;
    float tempoDesteUltimoDano;

  public:
    Jogador(const sf::Vector2f posicao, bool jogador2);
    ~Jogador();
    void salvar();
    void salvarDataBuffer();
    void executar();
    void andar(const bool paraEsquerda);
    const bool getAndando() const;
    void parar();
    void colisao(Entidade *outraEntidade);
    void atualizar(float dt);
    void inicializar();
    void atacar();
    void pular();
    void setAtacando(bool v);
    bool getAtacando();
    int getPontos();
    void setPontos(int p);
    void setUltimoDano(float ultimoSofrido);
    float getUltimoDano();
  };
}