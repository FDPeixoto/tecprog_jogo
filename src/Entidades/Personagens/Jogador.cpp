#include "Jogador.hpp"

namespace Entidades
{
    Jogador::Jogador(const sf::Vector2f posicao, bool jogador2) : Personagem(sf::Vector2f(JOGADORLARGURA, JOGADORALTURA), posicao, IDJOGADOR), pontos(0), numero_baixas(0), espada(false), magia(false), antidoto(false), ehJogador2(jogador2), pulando(false)
    {
        if (jogador2)
        {
            if (!textura.loadFromFile("Texturas/jogador2.png"))
            {
            }
            setCor(sf::Color::Transparent);
            setPosTexto(330.f, 200.f);
            Entidade::carregarTextura(&textura);
        }
        else
        {
            if (!textura.loadFromFile("Texturas/jogador1.png"))
            {
            }
            setCor(sf::Color::Transparent);
            Entidade::carregarTextura(&textura);
        }
        setVelocidade(sf::Vector2f(0.f, 0.f));
    }

    Jogador::~Jogador() {}

    void Jogador::atualizar(float dt)
    {
        // verificarColisao();

        tempoDesdeUltimoAtaque += dt;
        if (tempoDesdeUltimoAtaque >= cooldownAtaque)
        {
            podeAtacar = true;
            tempoDesdeUltimoAtaque -= cooldownAtaque;
        }
        if (noChao && pulando)
        {
            velocidade.y = -VELOCIDADE_PULO * 2.4f;
            corpo.move(0.f, velocidade.y * dt);
            pulando = false;
            noChao = false;
        }
        // ou float dt=relogio.getElapsedTime().asSeconds();
        // Andando só na horizontal por enquanto

        if (!noChao)
        {
            velocidade.y += 5.f;
            if (velocidade.y > 300.f)
            {
                velocidade.y = 300.f;
            }
        }
        else
        {
            velocidade.y = 0;
        }
        noChao = false;
        corpo.move(velocidade.x * dt, velocidade.y * dt);
        checarForaDaJanela();
        // setPos(sf::Vector2f(corpo.getPosition().x + velocidade.x * dt, corpo.getPosition().y + velocidade.y * dt));
    }

    void Jogador::andar(const bool ehEsquerda)
    {
        atacando = false;
        andando = true;

        // Update velocity
        velocidade.x = ehEsquerda ? -300.0f : 300.0f;

        // Only flip if changing direction
        if (paraEsquerda != ehEsquerda)
        {
            paraEsquerda = ehEsquerda;

            // Get current position and bounds
            sf::Vector2f pos = corpo.getPosition();
            sf::FloatRect bounds = corpo.getLocalBounds();

            if (paraEsquerda)
            {
                // Move origin to the right side before flipping
                corpo.setOrigin(bounds.width, 0);
                corpo.setScale(-1.f, 1.f);
            }
            else
            {
                // Move origin back to the left side before flipping back
                corpo.setOrigin(0, 0);
                corpo.setScale(1.f, 1.f);
            }

            // Keep the position the same
            corpo.setPosition(pos);
        }
    }
    void Jogador::parar()
    {
        andando = false;
        velocidade.x = 0.0f;
    }
    const bool Jogador::getAndando() const
    {
        return andando;
    }

    void Jogador::salvarDataBuffer() {}

    void Jogador::executar()
    {
        /*std::string vidaStr = "Vida: " + std::to_string(num_vidas);  // Concatena a string
        textoVida.setString(vidaStr);
        return (textoVida);*/
        pontos = pontos + 1;
    }

    void Jogador::salvar() {}

    void Jogador::colisao(Entidade *outraEntidade)
    {
        sf::Vector2f pos1 = getCorpo().getPosition();
        sf::Vector2f pos2 = outraEntidade->getCorpo().getPosition();

        sf::Vector2f tam1 = getCorpo().getSize();
        sf::Vector2f tam2 = outraEntidade->getCorpo().getSize();

        sf::Vector2f distancia(fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)), fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f)));

        float overlapX = std::min(pos1.x + tam1.x, pos2.x + tam2.x) - std::max(pos1.x, pos2.x);
        float overlapY = std::min(pos1.y + tam1.y, pos2.y + tam2.y) - std::max(pos1.y, pos2.y);

        int ID = outraEntidade->getID();
        if (ID == IDMINION || ID == IDESQUELETO || ID == IDDURAHAN || ID == IDCAIXA)
        {
            // Determine the axis of least penetration
            if (overlapX < overlapY)
            {
                // Horizontal collision
                if (pos1.x < pos2.x)
                {
                    // Player is to the left of the minion
                    setPos(sf::Vector2f(pos2.x - tam1.x, pos1.y));
                    if (getAndando())
                    {
                        outraEntidade->setPos(sf::Vector2f(pos2.x + overlapX, pos2.y));
                    }
                }
                else
                {
                    // Player is to the right of the minion
                    setPos(sf::Vector2f(pos2.x + tam2.x, pos1.y));
                    if (getAndando())
                    {
                        outraEntidade->setPos(sf::Vector2f(pos2.x - overlapX, pos2.y));
                    }
                }
            }
            else
            {
                // Vertical collision
                if (pos1.y < pos2.y)
                {
                    // Player is above the minion
                    setPos(sf::Vector2f(pos1.x, pos2.y - tam1.y));
                    noChao = true;
                }
                else
                {
                    // Player is below the minion
                    setPos(sf::Vector2f(pos1.x, pos2.y + tam2.y));
                }
            }
        }
        if (ID == IDPLATAFORMA || ID == IDESPINHO || ID == IDCANHAO)
        {
            // Calculate the intersection depth on both axes

            // Determine the axis of least penetration
            if (overlapX < overlapY)
            {
                // Horizontal collision
                if (pos1.x < pos2.x)
                {
                    // Player is to the left of the platform
                    setPos(sf::Vector2f(pos2.x - tam1.x, pos1.y));
                }
                else
                {
                    // Player is to the right of the platform
                    setPos(sf::Vector2f(pos2.x + tam2.x, pos1.y));
                }
            }
            else
            {
                // Vertical collision
                if (pos1.y < pos2.y)
                {
                    // Player is above the platform
                    setPos(sf::Vector2f(pos1.x, pos2.y - tam1.y));
                    velocidade.y = 0; // Stop vertical movement
                    noChao = true;    // Player is on the ground
                }
                else
                {
                    // Player is below the platform
                    setPos(sf::Vector2f(pos1.x, pos2.y + tam2.y));
                    velocidade.y = 0; // Stop vertical movement
                }
            }
        }
        if (ID == ID_PROJETIL)
        {
            if (outraEntidade->getAtivo())
            {
                tomarDano(1);
                outraEntidade->setPos(sf::Vector2f(10000.f, 10000.f));
                outraEntidade->setAtivo(false);
            }
        }
    }
    void Jogador::inicializar()
    {
        return;
    }
    void Jogador::pular()
    {
        pulando = true;
    }
    void Jogador::setAtacando(bool v)
    {
        atacando = v;
    }
    bool Jogador::getAtacando()
    {
        return atacando;
    }
    int Jogador::getPontos()
    {
        return pontos;
    }
    void Jogador::setPontos(int p)
    {
        pontos = p;
    }
    void Jogador::atacar()
    {
        if (podeAtacar)
        {
            if (pMediator)
            {
                pMediator->notificar(this, "ataqueDoJogador");
            }
            podeAtacar = false;
        }
        atacando = true;
    }
}
