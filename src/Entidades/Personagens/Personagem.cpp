#include "Personagem.hpp"
namespace Entidades{
  Personagem::Personagem(const sf::Vector2f tamanho, const sf::Vector2f posicao, const int ID): Entidade(tamanho, posicao, ID), num_vidas(0), velocidade(0.0f, 0.0f), noChao(false){
  }
  Personagem::~Personagem(){}
  void Personagem::setVelocidade(sf::Vector2f vel){
    velocidade = vel;
  };
}