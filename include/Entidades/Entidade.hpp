#pragma once

#include "Ente.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <Mediator.hpp>
#include <stdafx.h>

namespace Entidades
{
  class Entidade : public Ente
  {

  protected:
    std::ostringstream buffer;
    sf::RectangleShape corpo;
    sf::Vector2f pos;
    sf::Vector2f tam;
    Gerenciadores::Mediator *pMediator;
    bool ativo;
    sf::Texture textura;

  public:
    Entidade(const sf::Vector2f tamanho, const sf::Vector2f posicao, const int ID);
    virtual ~Entidade();
    virtual void executar() = 0;
    virtual void salvar() = 0;
    void salvarDataBuffer();
    void setCor(sf::Color cor);
    sf::Color getCor();
    const sf::RectangleShape getCorpo();
    void setPos(sf::Vector2f posicao);
    sf::Vector2f getPos();
    const sf::Vector2f getTam();
    void verificarColisao();
    void moverCorpo(sf::Vector2f posicao);
    virtual void colisao(Entidade *outraEntidade) = 0;
    virtual void renderizar();
    virtual void atualizar(float dt) = 0;
    virtual void inicializar() = 0;
    void setMediator(Gerenciadores::Mediator *mediator);
    virtual void atualizarPosicao(float dt) = 0;
    void setAtivo(bool flg);
    bool getAtivo();
    virtual void atirar(const sf::Vector2f posInimigo, bool direita);
    void mover(sf::Vector2f posicao);

    virtual void setAtacando(bool v);
    virtual bool getAtacando();
    void mudarLargura(int l);
    virtual void carregarTextura(sf::Texture *text);
  };

}