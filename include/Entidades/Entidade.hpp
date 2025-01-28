#pragma once

#include "Ente.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>  // Incluindo sstream para o uso de std::ostringstream
#include <Mediator.hpp>
#include <stdafx.h>

namespace Entidades{
  class Entidade: public Ente{

    protected:
      std::ostringstream buffer;  // Usando std::ostringstream em vez de std::ostream
      sf::RectangleShape corpo;
      sf::Vector2f pos;
      sf::Vector2f tam;
      Gerenciadores::Mediator* pMediator;
      bool ativo;

    public:
      Entidade(const sf::Vector2f tamanho, const sf::Vector2f posicao, const int ID);
      virtual ~Entidade();
      virtual void executar() = 0;
      virtual void salvar() = 0;
      void salvarDataBuffer();
      void setCor(sf::Color cor);
      const sf::RectangleShape getCorpo();
      void setPos(sf::Vector2f posicao);
      const sf::Vector2f getPos();
      void verificarColisao();
      const sf::Vector2f getTam();
      void moverCorpo(sf::Vector2f posicao);
      virtual void colisao(Entidade *outraEntidade) = 0;
      virtual void renderizar();
      virtual void atualizar(float dt) = 0;
      virtual void inicializar() = 0;   
      void setMediator(Gerenciadores::Mediator* mediator);
      virtual void atualizarPosicao(float dt) = 0;
      void setAtivo(bool flg);
  };
}