#include "Jogador.hpp"
#include "stdafx.h"
 

 namespace Entidades{
    Jogador::Jogador(const sf::Vector2f posicao): 
    Personagem(sf::Vector2f(JOGADORLARGURA, JOGADORALTURA) , posicao, IDJOGADOR), pontos(0), numero_baixas(0), espada (false), magia (false), antidoto (false){
        setVelocidade(sf::Vector2f(0.1f, 0.1f));
    }
  Jogador::~Jogador(){}
  void Jogador::setTeclas(sf::Keyboard::Key esquerda, sf::Keyboard::Key direita, sf::Keyboard::Key pulo){
    teclaEsquerda=esquerda;
    teclaDireita=direita;
    teclaPulo=pulo;
  }

      void Jogador::atualizar(float dt){
        //ou float dt=relogio.getElapsedTime().asSeconds();
        //Andando só na horizontal por enquanto
        float ds=velocidade.x*dt;//ou velocidadeFinal.x
        if(paraEsquerda){
          ds=ds*(-1);
        }
        corpo.move(ds,0.0f);
            return;
    }
    void Jogador::andar(const bool paraEsquerda){
        atacando = false;
        andando = true;
        this->paraEsquerda = paraEsquerda;
            
    }
    void Jogador::parar(){
        andando=false;
    }
    const bool Jogador::getAndando() const{
        return andando;
    }


    void Jogador::salvarDataBuffer(){}
    void Jogador::mover(){

    if (sf::Keyboard::isKeyPressed(teclaEsquerda)){
        corpo.move(-velocidade.x, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(teclaDireita)){
        corpo.move(velocidade.x, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(teclaPulo)){
        corpo.move(0.f, -velocidade.y);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        corpo.move(0.f, velocidade.y);
    }
    }
    void Jogador::executar() {}
    void Jogador::salvar(){}
    void Jogador::colisao(Entidade *outraEntidade)
    {
        int id = outraEntidade->getID();
        sf::Vector2f overlap(
                getCorpo().getGlobalBounds().left + getCorpo().getGlobalBounds().width - outraEntidade->getCorpo().getGlobalBounds().left,
                getCorpo().getGlobalBounds().top + getCorpo().getGlobalBounds().height - outraEntidade->getCorpo().getGlobalBounds().top
                );
        switch (id){
            case IDOBSTACUlO:
                setPos(sf::Vector2f (getCorpo().getPosition().x, outraEntidade->getCorpo().getPosition().y - getCorpo().getSize().y));
                velocidade.y = 0;
                break;
            case IDINIMIGO: 
                if (std::abs(overlap.x) > std::abs(overlap.y)) {
                    if (overlap.y > 0)
                        outraEntidade->setPos(sf::Vector2f(outraEntidade->getCorpo().getPosition().x, getCorpo().getPosition().y + getCorpo().getSize().y));
                    else
                        outraEntidade->setPos(sf::Vector2f(outraEntidade->getCorpo().getPosition().x, getCorpo().getPosition().y - outraEntidade->getCorpo().getSize().y));
                } else {
                    if (overlap.x > 0)
                        outraEntidade->setPos(sf::Vector2f(getCorpo().getPosition().x + getCorpo().getSize().x, outraEntidade->getCorpo().getPosition().y));
                    else
                        outraEntidade->setPos(sf::Vector2f(getCorpo().getPosition().x - outraEntidade->getCorpo().getSize().x, outraEntidade->getCorpo().getPosition().y));
                }
                break;
            default:
                break;
        }
    }
    void Jogador::inicializar()
        {
            return;
        }
}
