#include "Personagem.hpp"

namespace Entidades{
  Personagem::Personagem(const sf::Vector2f tamanho, const sf::Vector2f posicao, const int ID): Entidade(tamanho, posicao, ID), num_vidas(5), velocidade(0.0f, 0.0f), noChao(false){
    if (!font.loadFromFile("Fonte/DejaVuSans.ttf")) {
          // Erro ao carregar a fonte
    }
  textoVida.setFont(font);
  textoVida.setCharacterSize(40);  // Tamanho da fonte
  textoVida.setFillColor(sf::Color::White);  // Cor do texto
  textoVida.setPosition(100.f, 100.f);  // Posição do texto na janela
  textoVida.setString("Vida: " + std::to_string(num_vidas));
  
  }

  Personagem::~Personagem(){}
  void Personagem::setVelocidade(sf::Vector2f vel){
    velocidade = vel;
  }

  void Personagem::atualizarPosicao(float dt)
  {
      /*float ds = velocidade.x * dt;//ou velocidadeFinal.x
      corpo.move(ds, 0.f);*/

      //return; estava no peixoto

  }
  void Personagem::setNumVidas(int n){
    num_vidas=n;

  }
  const int Personagem::getNumVidas(){
      return num_vidas;
  }
  sf::Text Personagem::getTextoVida(){
    std::string vidaStr = "Vida: " + std::to_string(num_vidas);  // Concatena a string
    textoVida.setString(vidaStr); 
    return (textoVida);

  }
  void Personagem::setPosTexto(int x, int y){
    textoVida.setPosition(x, y);
  }
}