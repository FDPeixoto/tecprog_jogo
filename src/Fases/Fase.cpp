#include "Fase.hpp"
#include "../../include/nlohmann/json.hpp"
#include "Esqueleto.hpp"
using json = nlohmann::json;

namespace Fases
{
    Fase::Fase(const int idFase) : Ente(idFase), listaPersonagens(new Listas::ListaEntidades()),
                                   listaObstaculos(new Listas::ListaEntidades()), pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()),
                                   pGerenciadorEvento(pGerenciadorEvento->getGerenciadorEvento()), pGerenciadorColisao(pGerenciadorColisao->getGerenciadorColisao()),
                                   pJogador1(nullptr), pJogador2(nullptr), quantidadeJogadores(0), completou(false), pontosJ1(0), pontosJ2(0)
    {
        pGerenciadorColisao->limparListas();
        doisJogadores = false;
    }

    Fase::Fase(const int idFase, bool temSegundoJogador) : Ente(idFase), listaPersonagens(new Listas::ListaEntidades()),
                                                           listaObstaculos(new Listas::ListaEntidades()), pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()),
                                                           pGerenciadorEvento(pGerenciadorEvento->getGerenciadorEvento()), pGerenciadorColisao(pGerenciadorColisao->getGerenciadorColisao()),
                                                           pJogador1(nullptr), pJogador2(nullptr), quantidadeJogadores(0), completou(false), pontosJ1(0), pontosJ2(0), doisJogadores(temSegundoJogador)
    {
        pGerenciadorColisao->limparListas();
    }

    Fase::~Fase()
    {
        pGerenciadorGrafico = nullptr;
        if (pJogador1)
        {
            delete pJogador1;
            pJogador1 = nullptr;
        }
        if (pJogador2)
        {
            delete pJogador2;
            pJogador2 = nullptr;
        }
        quantidadeJogadores = 0;
        delete listaPersonagens;
        delete listaObstaculos;
    }

    void Fase::setJogador1(Entidades::Jogador *pJogador) { pJogador1 = pJogador; }

    Entidades::Jogador *Fase::getJogador1() { return pJogador1; }

    void Fase::setJogador2(Entidades::Jogador *pJogador) { pJogador2 = pJogador; }

    Entidades::Jogador *Fase::getJogador2() { return pJogador2; }
    int Fase::getPontosJogador1() const
    {
        if (pJogador1 != nullptr)
        {
            return pJogador1->getPontos();
        }
        return 0;
    }
    int Fase::getPontosJogador2() const
    {
        if (pJogador2 != nullptr)
        {
            return pJogador2->getPontos();
        }
        return 0;
    }

    bool Fase::getCompletou()
    {
        return completou;
    }
    void Fase::setNomePartida(const std::string nome)
    {
        nomePartida = nome;
    }

    void Fase::salvarRanking(const std::string &arquivo, int pJ1, int pJ2)
    {
        json ranking;
        std::ifstream arquivoExistente(arquivo);
        if (arquivoExistente.is_open())
        {
            try
            {
                arquivoExistente >> ranking;
            }
            catch (const std::exception &e)
            {
                ranking = json::array();
            }
            arquivoExistente.close();
        }
        else
        {
            ranking = json::array();
        }

        int pontosJogador1 = getPontosJogador1();
        int pontosJogador2 = getPontosJogador2();
        pontosJogador1 = pontosJogador1 + pJ1;
        pontosJogador2 = pontosJogador2 + pJ2;

        bool partidaExistente = false;
        for (auto &jogo : ranking)
        {

            if (jogo["nomePartida"] == nomePartida)
            {

                int pontuacaoJogador1Existente = std::max(jogo["jogadores"][0]["pontuacao"], jogo["jogadores"][1]["pontuacao"]);
                if (pontuacaoJogador1Existente == std::max(pontosJogador1, pontosJogador2))
                {
                    partidaExistente = true;
                    return;
                }
            }
        }

        if (!partidaExistente)
        {
            json jogo;
            jogo["nomePartida"] = nomePartida;
            jogo["jogadores"] = {
                {{"nome", "1"}, {"pontuacao", pontosJogador1}},
                {{"nome", "2"}, {"pontuacao", pontosJogador2}}};

            ranking.push_back(jogo);

            std::sort(ranking.begin(), ranking.end(), [](const json &a, const json &b)
                      {
                          int maxA = std::max(a["jogadores"][0]["pontuacao"], a["jogadores"][1]["pontuacao"]);
                          int maxB = std::max(b["jogadores"][0]["pontuacao"], b["jogadores"][1]["pontuacao"]);
                          return maxA > maxB; });

            if (ranking.size() > 5)
            {
                ranking.erase(ranking.begin() + 5, ranking.end());
            }
        }

        std::ofstream arquivoSaida(arquivo);
        if (!arquivoSaida)
        {
            return;
        }
        arquivoSaida << ranking.dump(4);
        arquivoSaida.close();
    }

    /*void Fase::mostrarRanking(sf::RenderWindow* janela) {
    std::ifstream arquivo("ranking.json");
    if (arquivo.is_open()) {
        json ranking;
        arquivo >> ranking;
        arquivo.close();

        sf::Text textoRanking;
        textoRanking.setFont(fonte);
        textoRanking.setCharacterSize(20);
        textoRanking.setFillColor(sf::Color::White);

        int yPos = 20;
        for (int i = 0; i < ranking.size(); ++i) {
            std::string texto = "Partida: " + ranking[i]["nomePartida"].get<std::string>();
            textoRanking.setString(texto);
            textoRanking.setPosition(50, yPos);
            janela->draw(textoRanking);
            yPos += 30;

            for (const auto& jogador : ranking[i]["jogadores"]) {
                texto = jogador["nome"].get<std::string>() + " - " +
                        std::to_string(jogador["pontuacao"].get<int>());
                textoRanking.setString(texto);
                textoRanking.setPosition(50, yPos);
                janela->draw(textoRanking);
                yPos += 40;
            }
            yPos += 20;
        }
    }
}*/

    void Fase::criarJogador(const sf::Vector2f posicao)
    {
        if (quantidadeJogadores == 0)
        {
            Entidades::Jogador *jogador = new Entidades::Jogador(posicao, false);
            jogador->setCor(sf::Color::White);
            if (jogador != nullptr)
            {
                listaPersonagens->incluirEntidade(jogador);
                setJogador1(jogador);
                pGerenciadorEvento->setJogador1(jogador);
                pGerenciadorColisao->adicionarJogador(jogador);
                jogador->setMediator(pGerenciadorColisao);
            }
            quantidadeJogadores++;
        }
        else if ((quantidadeJogadores == 1) && (doisJogadores))
        {
            Entidades::Jogador *jogador = new Entidades::Jogador(posicao, true);
            jogador->setCor(sf::Color::White);
            if (jogador != nullptr)
            {
                listaPersonagens->incluirEntidade(jogador);
                setJogador2(jogador);
                pGerenciadorEvento->setJogador2(jogador);
                pGerenciadorColisao->adicionarJogador(jogador);
                jogador->setMediator(pGerenciadorColisao);
            }
            quantidadeJogadores++;
        }
    }

    void Fase::criarMinion(const sf::Vector2f posicao)
    {
        Entidades::Inimigos::Minion *minion = static_cast<Entidades::Inimigos::Minion *>(factory.create(IDMINION, posicao));

        if (minion != nullptr)
        {
            minion->setCor(sf::Color::Red);
            minion->setMediator(dynamic_cast<Gerenciadores::Mediator *>(pGerenciadorColisao));
            pGerenciadorColisao->adicionarInimigo(minion);
            if (getJogador1() != nullptr)
            {
                minion->setJogador1(getJogador1());
            }
            if (getJogador2() != nullptr)
            {
                minion->setJogador2(getJogador2());
            }
            listaPersonagens->incluirEntidade(minion);
        }
    }

    void Fase::criarPlataforma(const sf::Vector2f posicao, bool Castelo)
    {
        Entidades::Obstaculos::Plataforma *plataforma = static_cast<Entidades::Obstaculos::Plataforma *>(factory.create(IDPLATAFORMA, posicao));
        if (plataforma != nullptr)
        {
            plataforma->setMediator(dynamic_cast<Gerenciadores::Mediator *>(pGerenciadorColisao));
            listaObstaculos->incluirEntidade(plataforma);
            pGerenciadorColisao->adicionarObstaculo(plataforma);
        }
    }

    void Fase::desenhar()
    {
        pGerenciadorGrafico->desenharListaEntidades(listaPersonagens);
        pGerenciadorGrafico->desenharListaEntidades(listaObstaculos);
    }

    void Fase::executar()
    {
        eliminarPersonagensMortos();

        listaObstaculos->executar();
        listaPersonagens->executar();
        pGerenciadorColisao->executar();

        float variacaoTempo = pGerenciadorGrafico->getRelogio()->getElapsedTime().asSeconds();
        listaPersonagens->atualizar(variacaoTempo);
        listaObstaculos->atualizar(variacaoTempo);
        pGerenciadorGrafico->resetarRelogio();
        if (pJogador1 != nullptr)
        {
            pGerenciadorGrafico->desenharTexto(pJogador1->getTextoVida(), sf::Vector2f(0.f, 10.f));
        }
        if (pJogador2 != nullptr)
        {
            pGerenciadorGrafico->desenharTexto(pJogador2->getTextoVida(), sf::Vector2f(200.f, 10.f));
        }

        desenhar();
    }
    void Fase::proximaFase()
    {
        pJogador1 = nullptr;
        pJogador2 = nullptr;
        quantidadeJogadores = 0;
    }
    bool Fase::completouFase()
    {

        gameOver = true;

        for (Listas::Lista<Entidades::Entidade>::Iterator itPersonagem = listaPersonagens->getListaEnt().inicio(); itPersonagem != listaPersonagens->getListaEnt().fim(); itPersonagem++)
            if (*itPersonagem)
            {
                if ((*itPersonagem)->getID() == IDMINION)
                {
                    if (static_cast<Entidades::Inimigos::Minion *>(*itPersonagem)->getVivo())
                    {
                        return false;
                    }
                }
                if ((*itPersonagem)->getID() == IDESQUELETO)
                {
                    if (static_cast<Entidades::Inimigos::Esqueleto *>(*itPersonagem)->getVivo())
                    {
                        return false;
                    }
                }
                if ((*itPersonagem)->getID() == IDOGRO)
                {
                    if (static_cast<Entidades::Inimigos::Ogro *>(*itPersonagem)->getVivo())
                    {
                        return false;
                    }
                }

                if ((*itPersonagem)->getID() == IDJOGADOR)
                {
                    if (static_cast<Entidades::Jogador *>(*itPersonagem)->getVivo())
                    {
                        gameOver = false;
                    }
                }
            }
        return true;
    }

    void Fase::eliminarPersonagensMortos()
    {
        for (Listas::Lista<Entidades::Entidade>::Iterator itPersonagem = listaPersonagens->getListaEnt().inicio(); itPersonagem != listaPersonagens->getListaEnt().fim(); itPersonagem++)
        {
            if (!(static_cast<Entidades::Personagem *>(*itPersonagem))->getVivo())
            {

                pGerenciadorColisao->removerEntidade(*itPersonagem);
            }
        }
    }
    bool Fase::getGameOver()
    {
        return gameOver;
    }
}
