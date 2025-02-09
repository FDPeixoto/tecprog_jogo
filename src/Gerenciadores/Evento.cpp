#include "Evento.hpp"
#include "FaseState.hpp"
#include "../../include/nlohmann/json.hpp" // Incluindo a biblioteca JSON
using json = nlohmann::json;

namespace Gerenciadores
{
    Evento *Evento::pGerenciadorEvento = nullptr;

    Evento::Evento() : pJog1(nullptr), pJog2(nullptr), pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()), pEstado(pEstado->getGerenciadorEstado()), pFase(nullptr) {}
    Evento::~Evento()
    {
        pGerenciadorGrafico = nullptr;
        // pEstado = nullptr;
        pJog1 = nullptr;
        pJog2 = nullptr;
    }

    Evento *Evento::getGerenciadorEvento()
    {
        if (pGerenciadorEvento == nullptr)
        {
            pGerenciadorEvento = new Evento();
        }
        return pGerenciadorEvento;
    }

    void Evento::setJogador1(Entidades::Jogador *jogador)
    {
        pJog1 = jogador;
    }
    void Evento::setJogador2(Entidades::Jogador *jogador)
    {
        pJog2 = jogador;
    }

    void Evento::verificaTeclaPressionada(sf::Keyboard::Key tecla)
    {
        int idEstado = pEstado->getStateAtual()->getIdentificador();
        if (idEstado == IDMENUINICIALSTATE)
        {
            if (tecla == sf::Keyboard::Num1)
            {
                pEstado->addState(IDPANTANOMALDITOUM);
            }
            else if (tecla == sf::Keyboard::Num2)
            {
                pEstado->addState(IDPANTANOMALDITODOIS);
            }
            else if (tecla == sf::Keyboard::Num3)
            {
                pEstado->addState(IDCASTELOASSOMBRADOUM);
            }
            else if (tecla == sf::Keyboard::Num4)
            {
                pEstado->addState(IDCASTELOASSOMBRADODOIS);
            }
        }

        if (idEstado == IDFASESTATE)
        {
            if (tecla == sf::Keyboard::A)
            {
                if (pJog2 != nullptr)
                {
                    pJog2->andar(true);
                }
            }
            else if (tecla == sf::Keyboard::D)
            {
                if (pJog2 != nullptr)
                {
                    pJog2->andar(false);
                }
            }
            else if (tecla == sf::Keyboard::W)
            {
                if (pJog2 != nullptr)
                {
                    pJog2->pular();
                }
            }
            else if (tecla == sf::Keyboard::Left)
            {
                if (pJog1 != nullptr)
                {
                    pJog1->andar(true);
                }
            }
            else if (tecla == sf::Keyboard::Right)
            {
                if (pJog1 != nullptr)
                {
                    pJog1->andar(false);
                }
            }
            else if (tecla == sf::Keyboard::Up)
            {
                if (pJog1 != nullptr)
                {
                    pJog1->pular();
                }
            }
            else if (tecla == sf::Keyboard::M)
            {
                if (pJog1 != nullptr)
                {
                    pJog1->atacar();
                }
            }
            else if (tecla == sf::Keyboard::S)
            {
                if (pJog2 != nullptr)
                {
                    pJog2->atacar();
                }
            }
            else if (tecla == sf::Keyboard::Q)
            {
                pGerenciadorGrafico->mostrarRanking();
            }
            else if (tecla == sf::Keyboard::Escape)
            {
                pEstado->addState(IDPAUSESTATE);
            }
        }
        if (idEstado == IDPAUSESTATE)
        {
            if (tecla == sf::Keyboard::Escape)
            {
                pEstado->removerState();
            }
        }

        if (tecla == sf::Keyboard::BackSpace)
        {
            pEstado->removerState();
        }
    }

    void Evento::verificaTeclaSolta(sf::Keyboard::Key tecla)
    {
        if ((tecla == sf::Keyboard::A) || (tecla == sf::Keyboard::D))
        {
            if (pJog2 != nullptr)
            {
                pJog2->parar();
            }
        }
        if (tecla == sf::Keyboard::S)
        {
            if (pJog2 != nullptr)
            {
                pJog2->setAtacando(false);
            }
        }
        if ((tecla == sf::Keyboard::Left) || (tecla == sf::Keyboard::Right))
        {
            if (pJog1 != nullptr)
            {
                pJog1->parar();
            }
        }
        if (tecla == sf::Keyboard::M)
        {
            if (pJog1 != nullptr)
            {
                pJog1->setAtacando(false);
            }
        }
    }

    void Evento::executar()
    {
        int pontuacaoJ1 = 0;
        int pontuacaoJ2 = 0;
        if (pEstado->getStateAtual()->getIdentificador() == IDFASESTATE)
        {
            pFase = pEstado->getStateAtual()->getFase();
        }
        else
        {
            pFase = nullptr;
        }
        sf::Event evento;
        while (pGerenciadorGrafico->getJanela()->pollEvent(evento))
        {

            if (evento.type == sf::Event::KeyPressed)
            {
                verificaTeclaPressionada(evento.key.code);
            }
            else if (evento.type == sf::Event::KeyReleased)
            {
                verificaTeclaSolta(evento.key.code);
            }
            else if (evento.type == sf::Event::Closed)
            {
                pGerenciadorGrafico->fecharJanela();
            }
            // salvarNaFase();

            if (pFase != nullptr)
            {
                if (pFase->completouFase() == true)
                {

                    if (pFase->getID() == IDPANTANOMALDITO)
                    {
                        // pFase->setNomePartida("Pantano Maldito2");
                        // pFase->salvarRanking("ranking.json");
                        pontuacaoJ1 = pFase->getPontosJogador1();
                        pontuacaoJ2 = pFase->getPontosJogador2();
                        if (pJog2 != nullptr)
                        {
                            pEstado->addState(IDCASTELOASSOMBRADODOIS);
                        }
                        else
                        {
                            pEstado->addState(IDCASTELOASSOMBRADOUM);
                        }
                    }
                    else
                    { // eh o castelo assombrado
                        pFase->setNomePartida("Nome da Partida aqui");
                        pFase->salvarRanking("ranking.json", pontuacaoJ1, pontuacaoJ2);
                        pGerenciadorGrafico->fecharJanela();
                    }
                }

                else if (pFase->getGameOver())
                {
                    pFase->setNomePartida("Nome da Partida aqui");
                    pFase->salvarRanking("ranking.json", pontuacaoJ1, pontuacaoJ2);
                    pGerenciadorGrafico->fecharJanela();
                }
            }
        }
    }
}
