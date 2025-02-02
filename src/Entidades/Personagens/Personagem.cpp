#include "Personagem.hpp"

namespace Entidades
{
  Personagem::Personagem(const sf::Vector2f tamanho, const sf::Vector2f posicao, const int ID) : Entidade(tamanho, posicao, ID), vivo(true), num_vidas(5), velocidade(0.0f, 0.0f), noChao(false), pulando(true)
  {
    if (!font.loadFromFile("Fonte/DejaVuSans.ttf"))
    {
      // Erro ao carregar a fonte
    }
    textoVida.setFont(font);
    textoVida.setCharacterSize(40);           // Tamanho da fonte
    textoVida.setFillColor(sf::Color::White); // Cor do texto
    textoVida.setPosition(100.f, 100.f);      // Posição do texto na janela
    textoVida.setString("Vida: " + std::to_string(num_vidas));
  }

  Personagem::~Personagem() {}
  void Personagem::setVelocidade(sf::Vector2f vel)
  {
    velocidade = vel;
  }

  void Personagem::atualizarPosicao(float dt)
  {
    /*float ds = velocidade.x * dt;//ou velocidadeFinal.x
    corpo.move(ds, 0.f);*/

    // return; estava no peixoto
  }
  void Personagem::setNumVidas(int n)
  {
    num_vidas = n;
  }
  const int Personagem::getNumVidas()
  {
    return num_vidas;
  }
  sf::Text Personagem::getTextoVida()
  {
    std::string vidaStr = "Vida: " + std::to_string(num_vidas); // Concatena a string
    textoVida.setString(vidaStr);
    return (textoVida);
  }
  void Personagem::setPosTexto(int x, int y)
  {
    textoVida.setPosition(x, y);
  }
  bool Personagem::getVivo()
  {
    return vivo;
  }
  void Personagem::setVivo(bool v)
  {
    vivo = v;
  }

  void Personagem::checarForaDaJanela()
  {
    if (pos.x < 0.f)
    {
      setPos(sf::Vector2f(0.f, pos.y));
    }
    else if (pos.x + tam.x > LARGURA_JANELA)
    {
      setPos(sf::Vector2f(LARGURA_JANELA - tam.x, pos.y));
    }
    if (pos.y < 0.f)
    {
      setPos(sf::Vector2f(pos.x, 0.f));
    }
    else if (pos.y + tam.y > ALTURA_JANELA)
    {
      setPos(sf::Vector2f(pos.x, ALTURA_JANELA - tam.y));
    }
  }
}