#pragma once
#include "Entidade.hpp"
#include <iostream> 
#include <SFML/Graphics.hpp>

namespace Entidades{
  class Personagem:public Entidade{
  protected:
    int num_vidas;
    sf::Vector2f velocidade;
    bool noChao;
    bool pulando;
    sf::Font font;
    sf::Text textoVida;
    bool vivo;
    
  public:
    Personagem(const sf::Vector2f tamanho, const sf::Vector2f posicao, const int ID);
    ~Personagem();
    //virtual void mover() = 0;
    virtual void executar() = 0;//ATUALIZADA A VIDA SÓ DO JOGADOR (inimigos também e entidade)
    virtual void salvar()= 0;
    void setVelocidade(sf::Vector2f vel);
    virtual void atualizarPosicao(float dt);
    void setNumVidas(int n);
    const int getNumVidas();
    //void mostrarNumVidas();
    void setPosTexto(int x, int y);
    sf::Text getTextoVida();
    bool getVivo();
    void setVivo(bool v);

    //SER IMPLEMETADO DEPOIS
    //virtual void getVivo()=0;
  };
}