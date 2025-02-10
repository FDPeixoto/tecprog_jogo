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
    cooldownAtaque = 1.0f; // precisa de 3 segundos para aacar novamente;
    tempoDesdeUltimoAtaque = 0.f;
    podeAtacar = true;
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
    textoVida.setPosition(sf::Vector2f(50.f, 50.f));
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

  void Personagem::atacar(int dano, Personagem *personagem)
  {
    personagem->setNumVidas(getNumVidas() - dano);
    if (personagem->getNumVidas() <= 0)
    {
      personagem->setNumVidas(0);
      personagem->setVivo(false);
    }
  }

  void Personagem::tomarDano(int dano)
  {
    setNumVidas(getNumVidas() - dano);
    if (getNumVidas() <= 0)
    {
      setNumVidas(0);
      setVivo(false);
      setPos(sf::Vector2f(2000.f, 2000.f));
    }
  }

  sf::Vector2f Personagem::getVelocidade()
  {
    return velocidade;
  }

  void Personagem::checarForaDaJanela()
  {
    sf::Vector2f posicao = corpo.getPosition();
    sf::Vector2f tamanho = corpo.getSize();

    if (posicao.x < 0.f)
    {
      posicao.x = 0.f;
    }
    else if (posicao.x + tamanho.x > LARGURA_JANELA)
    {
      posicao.x = LARGURA_JANELA - tamanho.x;
    }

    if (posicao.y < 0.f)
    {
      posicao.y = 0.f;
      velocidade.y = 0.f;
    }
    else if (posicao.y + tamanho.y > ALTURA_JANELA)
    {
      posicao.y = ALTURA_JANELA - tamanho.y;
    }

    setPos(posicao);
  }

  void Personagem::setNoChao(bool chao)
  {
    noChao = chao;
  }

}