#include <iostream>
#include <sstream>  // Incluindo sstream para o uso de std::ostringstream
#include "Entidade.hpp"
namespace Entidades{

  Entidade::Entidade(const sf::Vector2f tamanho, const sf::Vector2f posicao, const int ID): Ente(ID), corpo(sf::RectangleShape(tamanho)), pos(posicao), ativo(true) {
    if(ID_PROJETIL==ID){
      ativo=false;
    }
    corpo.setPosition(pos);
  }

  Entidade::~Entidade()
  {
  }

  void Entidade::setCor(sf::Color cor){
    corpo.setFillColor(cor);
  }
  sf::Color Entidade::getCor(){
    return corpo.getFillColor();
  }

  const sf::RectangleShape Entidade::getCorpo()
  {
    return corpo;
  }

  void Entidade::setPos(sf::Vector2f posicao){
    corpo.setPosition(posicao);
    //pos = posicao;
  }

  const sf::Vector2f Entidade::getTam(){
    return tam;
  }

  void Entidade::moverCorpo(sf::Vector2f posicao){
    corpo.move(posicao);
  }
  /*void Entidade::atualizar(float dt){
    
        if(noChao && pulando){
            velocidade.y = -120.f;
            corpo.move(0.f, velocidade.y *  dt);
            pulando = false;
            noChao = false;
        }
        //ou float dt=relogio.getElapsedTime().asSeconds();
        //Andando só na horizontal por enquanto
        
        if(!noChao){
            velocidade.y += 1.f;
            if(velocidade.y > 300.f){velocidade.y = 300.f;}
        }
        else{
            velocidade.y = 0;
        }
        noChao = false;
        corpo.move(velocidade.x * dt, velocidade.y *  dt);
        //setPos(sf::Vector2f(corpo.getPosition().x + velocidade.x * dt, corpo.getPosition().y + velocidade.y * dt));
  }*/

  void Entidade::renderizar()
  {
    return;
  }
  /*void Entidade::ativarObstaculo(Entidades::entidade* pJogador){
    return;
  }*/
  void Entidade::setMediator(Gerenciadores::Mediator *mediator)
  {
    pMediator = mediator;
    if(pMediator != nullptr){
      pMediator->registrarEntidade(this);
    }
  }

  sf::Vector2f Entidade::getPos()
  {
    return pos;
  }

  void Entidade::mover(sf::Vector2f posicao){
    corpo.move(posicao);
  }

  void Entidade::verificarColisao() {
    if (pMediator != nullptr) {
        pMediator->notificar(this, "verificarColisao");
    }
  }
  void Entidade::setAtivo(bool flg){
    ativo=flg;
  }
  void Entidade::atirar(const sf::Vector2f posInimigo, bool direita){
    return;
  }
  bool Entidade::getAtivo(){
    return ativo;
  }
  bool Entidade::getVivo(){
    return false;
  }
  void Entidade::setVivo(bool v){
    return;
  }
  bool Entidade::getAtacando(){
    return false;
  }
  void Entidade::setAtacando(bool v){
    return;
  }
  void Entidade::mudarLargura(int l){
    corpo.setSize(sf::Vector2f(200.f, 50.f));
  }

}