#include <iostream>
#include <sstream>  // Incluindo sstream para o uso de std::ostringstream
#include "Entidade.hpp"
namespace Entidades{

  Entidade::Entidade(const sf::Vector2f tamanho, const sf::Vector2f posicao, const int ID): Ente(ID), corpo(sf::RectangleShape(tamanho)), pos(posicao) {
    corpo.setPosition(pos);
  }

  Entidade::~Entidade()
  {
  }

  void Entidade::setCor(sf::Color cor){
    corpo.setFillColor(cor);
  }

  const sf::RectangleShape Entidade::getCorpo()
  {
    return corpo;
  }

  void Entidade::setPos(sf::Vector2f posicao){
    corpo.setPosition(posicao);
  }

  const sf::Vector2f Entidade::getTam(){
    return tam;
  }

  void Entidade::moverCorpo(sf::Vector2f posicao){
    corpo.move(posicao);
  }

  void Entidade::renderizar()
  {
    return;
  }

  void Entidade::setMediator(Gerenciadores::Mediator *mediator)
  {
    pMediator = mediator;
    if(pMediator != nullptr){
      pMediator->registrarEntidade(this);
    }
  }

  const sf::Vector2f Entidade::getPos()
  {
    return corpo.getPosition();
  }

  void Entidade::verificarColisao() {
    if (pMediator != nullptr) {
        pMediator->notificar(this, "verificarColisao");
    }
  }

}