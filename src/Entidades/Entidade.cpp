#include <iostream>
#include <sstream>  // Incluindo sstream para o uso de std::ostringstream
#include "Entidade.hpp"
namespace Entidades{
  
  Entidade::Entidade()
  {
  }

  Entidade::Entidade(const sf::Vector2f tamanho, const sf::Vector2f posicao, const int ID): Ente(), corpo(sf::RectangleShape(tamanho)), pos(posicao), identificador(ID) {
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

  const sf::Vector2f Entidade::getPos()
  {
    return pos;
  }

  const int Entidade::getID(){
    return identificador;
  }
}