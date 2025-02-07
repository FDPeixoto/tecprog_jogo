#include "Fase.hpp"
#include "../../include/nlohmann/json.hpp" // Incluindo a biblioteca JSON
using json = nlohmann::json;

/*#include <nlohmann/json.hpp>

using json = nlohmann::json;*/
#define LARGURA 1280
#define ALTURA 720

namespace Fases
{
    Fase::Fase(const int idFase) : Ente(idFase),
                                   listaPersonagens(new Listas::ListaEntidades()),
                                   listaObstaculos(new Listas::ListaEntidades()),
                                   pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()),
                                   pGerenciadorEvento(pGerenciadorEvento->getGerenciadorEvento()),
                                   pGerenciadorColisao(pGerenciadorColisao->getGerenciadorColisao()),
                                   pJogador1(nullptr), pJogador2(nullptr), quantidadeJogadores(0), pFundo(nullptr), completou(false),
                                   pontosJ1(0), pontosJ2(0) //, vetorPortal()
    {
        pGerenciadorColisao->setMoveis(listaPersonagens);
        pGerenciadorColisao->setFixos(listaObstaculos);
        pGerenciadorColisao->limparListas();
        fonte.loadFromFile("Fonte/DejaVuSans.ttf");
    }

    Fase::~Fase()
    {
        /*for (std::vector<Entidades::Obstaculos::Portal*>::iterator it = vetorPortal.begin();it != vetorPortal.end();++it) {
            delete *it;
        }*/
        pGerenciadorGrafico = nullptr;
        pJogador1 = nullptr;
        pJogador2 = nullptr;
        quantidadeJogadores = 0;
        delete listaPersonagens;
        delete listaObstaculos;

        // vetorPortal.clear();
        // listP.clear();
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

    /*void Fase::salvarRanking(const std::string& arquivo) {
        json ranking;

        // 🔹 1. Tenta abrir e carregar o arquivo existente
        std::ifstream arquivoExistente(arquivo);
        if (arquivoExistente.is_open()) {
            try {
                arquivoExistente >> ranking;
            } catch (const std::exception& e) {
                //std::cerr << "Erro ao carregar o arquivo JSON: " << e.what() << std::endl;
                ranking = json::array(); // Se houver erro, inicializa um array vazio
            }
            arquivoExistente.close();
        } else {
            ranking = json::array(); // Se o arquivo não existir, inicia como array vazio
        }

        // 🔹 2. Captura a pontuação dos jogadores
        int pontosJogador1 = getPontosJogador1();
        int pontosJogador2 = getPontosJogador2();

        json jogo;
        jogo["nomePartida"] = nomePartida;
        jogo["jogadores"] = {
            {{"nome", "1"}, {"pontuacao", pontosJogador1}},
            {{"nome", "2"}, {"pontuacao", pontosJogador2}}
        };

        // 🔹 3. Adiciona a nova partida ao ranking
        ranking.push_back(jogo);

        // 🔹 4. Ordena todas as partidas pela **melhor pontuação geral**
        std::sort(ranking.begin(), ranking.end(), [](const json& a, const json& b) {
            int maxA = std::max(a["jogadores"][0]["pontuacao"], a["jogadores"][1]["pontuacao"]);
            int maxB = std::max(b["jogadores"][0]["pontuacao"], b["jogadores"][1]["pontuacao"]);
            return maxA > maxB; // Ordem decrescente
        });

        // 🔹 5. Mantém apenas os 5 melhores registros
        if (ranking.size() > 5) {
            ranking.erase(ranking.begin() + 5, ranking.end());
        }

        // 🔹 6. Salva o ranking atualizado no arquivo
        std::ofstream arquivoSaida(arquivo);
        if (!arquivoSaida) {
            //std::cerr << "Erro ao abrir o arquivo para escrita!" << std::endl;
            return;
        }
        arquivoSaida << ranking.dump(4); // Formatação bonita
        arquivoSaida.close();
        //pGerenciadorGrafico->fecharJanela(); //Para debugar
        }*/
    void Fase::salvarRanking(const std::string &arquivo, int pJ1, int pJ2)
    {
        json ranking;

        // 🔹 1. Tenta abrir e carregar o arquivo existente
        std::ifstream arquivoExistente(arquivo);
        if (arquivoExistente.is_open())
        {
            try
            {
                arquivoExistente >> ranking;
            }
            catch (const std::exception &e)
            {
                ranking = json::array(); // Se houver erro, inicializa um array vazio
            }
            arquivoExistente.close();
        }
        else
        {
            ranking = json::array(); // Se o arquivo não existir, inicia como array vazio
        }

        // 🔹 2. Captura a pontuação dos jogadores
        int pontosJogador1 = getPontosJogador1();
        int pontosJogador2 = getPontosJogador2();
        pontosJogador1 = pontosJogador1 + pJ1;
        pontosJogador2 = pontosJogador2 + pJ2;

        // 🔹 3. Verifica se a partida já existe no ranking
        bool partidaExistente = false;
        for (auto &jogo : ranking)
        {
            // Verifica se o nome da partida já está no ranking
            if (jogo["nomePartida"] == nomePartida)
            {
                // Se o nome da partida já existe, verifica se a pontuação é a mesma
                int pontuacaoJogador1Existente = std::max(jogo["jogadores"][0]["pontuacao"], jogo["jogadores"][1]["pontuacao"]);
                if (pontuacaoJogador1Existente == std::max(pontosJogador1, pontosJogador2))
                {
                    partidaExistente = true; // A partida existe e a pontuação é a mesma, não adiciona
                    return;
                }
            }
        }

        // 🔹 4. Se a partida não existe ou a pontuação for diferente, adiciona ao ranking
        if (!partidaExistente)
        {
            json jogo;
            jogo["nomePartida"] = nomePartida;
            jogo["jogadores"] = {
                {{"nome", "1"}, {"pontuacao", pontosJogador1}},
                {{"nome", "2"}, {"pontuacao", pontosJogador2}}};

            // 🔹 5. Adiciona a nova partida ao ranking
            ranking.push_back(jogo);

            // 🔹 6. Ordena todas as partidas pela **melhor pontuação geral**
            std::sort(ranking.begin(), ranking.end(), [](const json &a, const json &b)
                      {
                          int maxA = std::max(a["jogadores"][0]["pontuacao"], a["jogadores"][1]["pontuacao"]);
                          int maxB = std::max(b["jogadores"][0]["pontuacao"], b["jogadores"][1]["pontuacao"]);
                          return maxA > maxB; // Ordem decrescente
                      });

            // 🔹 7. Mantém apenas os 5 melhores registros
            if (ranking.size() > 5)
            {
                ranking.erase(ranking.begin() + 5, ranking.end());
            }
        }

        // 🔹 8. Salva o ranking atualizado no arquivo
        std::ofstream arquivoSaida(arquivo);
        if (!arquivoSaida)
        {
            return;
        }
        arquivoSaida << ranking.dump(4); // Formatação bonita
        arquivoSaida.close();

        // mostrarRanking(pGerenciadorGrafico->getJanela());
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
            janela->draw(textoRanking);  // Modificado para usar o ponteiro
            yPos += 30;

            for (const auto& jogador : ranking[i]["jogadores"]) {
                texto = jogador["nome"].get<std::string>() + " - " +
                        std::to_string(jogador["pontuacao"].get<int>());
                textoRanking.setString(texto);
                textoRanking.setPosition(50, yPos);
                janela->draw(textoRanking);  // Modificado para usar o ponteiro
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
            jogador->setCor(sf::Color::White); // Blue
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
        else if (quantidadeJogadores == 1)
        {
            Entidades::Jogador *jogador = new Entidades::Jogador(posicao, true);
            jogador->setCor(sf::Color::White); // Green
            if (jogador != nullptr)
            {
                listaPersonagens->incluirEntidade(jogador);
                setJogador2(jogador);
                pGerenciadorEvento->setJogador2(jogador);
                pGerenciadorColisao->adicionarJogador(jogador);
                jogador->setMediator(pGerenciadorColisao);
                //  jogador->setMediator(dynamic_cast<Gerenciadores::Mediator*> (pGerenciadorColisao));
            }
            quantidadeJogadores++;
        }
    }

    void Fase::criarMinion(const sf::Vector2f posicao)
    {
        Entidades::Inimigos::Minion *minion = new Entidades::Inimigos::Minion(posicao);
        minion->setCor(sf::Color::Red);
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

    void Fase::criarPlataforma(const sf::Vector2f posicao)
    {
        Entidades::Obstaculos::Plataforma *plataforma = new Entidades::Obstaculos::Plataforma(posicao); // a plaforma era 100.0f e 100.0f
        if (plataforma != nullptr)
        {
            // plataforma->setCor(sf::Color::White);
            plataforma->setMediator(dynamic_cast<Gerenciadores::Mediator *>(pGerenciadorColisao));
            listaObstaculos->incluirEntidade(plataforma);
            pGerenciadorColisao->adicionarObstaculo(plataforma);
        }
    }
    void Fase::criarPlataformaBase(const sf::Vector2f posicao)
    {
        Entidades::Obstaculos::Plataforma *plataforma = new Entidades::Obstaculos::Plataforma(60.0f, LARGURA, posicao);
        if (plataforma != nullptr)
        {
            // sf::Color verdeEscuro(0, 100, 0); // verde escuro
            // plataforma->setCor(verdeEscuro);
            listaObstaculos->incluirEntidade(plataforma);
            pGerenciadorColisao->adicionarObstaculo(plataforma);
            plataforma->setMediator(dynamic_cast<Gerenciadores::Mediator *>(pGerenciadorColisao));
        }
    }

    void Fase::criarPlataforma(const sf::Vector2f posicao, float altura, float largura)
    {
        Entidades::Obstaculos::Plataforma *plataforma = new Entidades::Obstaculos::Plataforma(altura, largura, posicao);
        if (plataforma != nullptr)
        {
            // sf::Color verdeEscuro(0, 100, 0); // verde escuro
            // plataforma->setCor(verdeEscuro);
            listaObstaculos->incluirEntidade(plataforma);
            pGerenciadorColisao->adicionarObstaculo(plataforma);
            plataforma->setMediator(dynamic_cast<Gerenciadores::Mediator *>(pGerenciadorColisao));
        }
    }
    void Fase::criarPlataformaF(const sf::Vector2f posicao, float altura, float largura)
    {
        Entidades::Obstaculos::Plataforma *plataforma = new Entidades::Obstaculos::Plataforma(altura, largura, posicao);
        if (plataforma != nullptr)
        {
            // sf::Color verdeEscuro(0, 100, 0); // verde escuro
            // plataforma->setCor(verdeEscuro);
            // listaObstaculos->incluirEntidade(plataforma);
            pFundo = plataforma;
            pGerenciadorGrafico->desenharEntidade(plataforma);
            // pGerenciadorGrafico->display();
        }
    }

    void Fase::criarBordaH(const sf::Vector2f posicao, sf::Color cor)
    {
        Entidades::Obstaculos::Plataforma *borda = new Entidades::Obstaculos::Plataforma(ALTURA, TAM_BORDA, posicao);
        if (borda != nullptr)
        {
            // borda->setCor(cor);
            listaObstaculos->incluirEntidade(borda);
        }
    }
    void Fase::criarBordaV(const sf::Vector2f posicao, sf::Color cor)
    {
        Entidades::Obstaculos::Plataforma *borda = new Entidades::Obstaculos::Plataforma(TAM_BORDA, LARGURA, posicao);
        if (borda != nullptr)
        {
            // borda->setCor(cor);
            listaObstaculos->incluirEntidade(borda);
        }
    }

    void Fase::criarEspinho(const sf::Vector2f posicao)
    {
        Entidades::Obstaculos::Espinho *plataforma = new Entidades::Obstaculos::Espinho(posicao);
        if (plataforma != nullptr)
        {
            plataforma->setMediator(dynamic_cast<Gerenciadores::Mediator *>(pGerenciadorColisao));
            listaObstaculos->incluirEntidade(plataforma);
            pGerenciadorColisao->adicionarObstaculo(plataforma);
        }
    }
    void Fase::criarCaixa(const sf::Vector2f posicao)
    {
        Entidades::Obstaculos::Caixa *caixa = new Entidades::Obstaculos::Caixa(posicao + sf::Vector2f(0.f, 16.f));
        if (caixa != nullptr)
        {
            caixa->setMediator(dynamic_cast<Gerenciadores::Mediator *>(pGerenciadorColisao));
            listaObstaculos->incluirEntidade(caixa);
            pGerenciadorColisao->adicionarObstaculo(caixa);
        }
    }
    void Fase::criarCanhao(const sf::Vector2f posicao)
    {
        Entidades::Obstaculos::Canhao *canhao = new Entidades::Obstaculos::Canhao(posicao);
        if ((canhao) != nullptr)
        {
            listaObstaculos->incluirEntidade(canhao);
            pGerenciadorColisao->adicionarObstaculo(canhao);
            canhao->setMediator(pGerenciadorColisao);
        }
    }
    /*void Fase::criarPortal(const sf::Vector2f posicao)
    {
        Entidades::Obstaculos::Canhao* portal = new Entidades::Obstaculos::Canhao(LARGURA_CANHAO, ALTURA_CANHAO, posicao);
        if((portal) != nullptr){
            //sf::Color roxa(128, 0, 128);  // roxo
            portal->setCor(sf::Color::Cyan);
            listaObstaculos->incluirEntidade(portal);
        }
    }*/
    void Fase::desenhar()
    {
        pGerenciadorGrafico->desenharListaEntidades(listaPersonagens);
        pGerenciadorGrafico->desenharListaEntidades(listaObstaculos);
    }

    void Fase::executar()
    {
        eliminarPersonagensMortos();
        // atualizando os pontos caso os jogaores morram durante a partida
        pontosJ1 = getPontosJogador1();
        pontosJ2 = getPontosJogador2();

        // listaObstaculos->executar();
        if (pGerenciadorColisao->getListaMoveis() != listaPersonagens)
        {
            pGerenciadorColisao->setMoveis(listaPersonagens);
        }
        if (pGerenciadorColisao->getListaFixos() != listaObstaculos)
        {
            pGerenciadorColisao->setFixos(listaObstaculos);
        }
        listaObstaculos->executar();
        listaPersonagens->executar();
        pGerenciadorColisao->executar();

        float variacaoTempo = pGerenciadorGrafico->getRelogio()->getElapsedTime().asSeconds();
        listaPersonagens->atualizar(variacaoTempo);
        // listP->atualizar();
        pGerenciadorGrafico->resetarRelogio();
        // int v1=pJogador1->getNumVidas();
        // int v2=pJogador2->getNumVidas();
        // pGerenciadorGrafico->desenharTexto("Vida: " + std::to_string(v1));
        // pGerenciadorGrafico->desenharTexto("Vida: " + std::to_string(v2));
        /*if (clock.getElapsedTime().asSeconds() >= 5.f) {  // Se passaram 5 segundos
            pD->atirar();
            clock.restart();  // Reinicia o relógio para a próxima verificação
        }*/

        // pGerenciadorGrafico->mostrarRanking();
        pGerenciadorGrafico->desenharTexto(pJogador1->getTextoVida());
        pGerenciadorGrafico->desenharTexto(pJogador2->getTextoVida());
        // pGerenciadorGrafico->desenharTexto(pGerenciadorEvento->getTextoEntrada());
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
        if ((pJogador1 != nullptr))
        {
            sf::Vector2f posJ1 = pJogador1->getCorpo().getPosition();
            if (posJ1.x >= (LARGURA_JANELA / 2))
            {
                return false;
            }
        }
        else if (pJogador2 != nullptr)
        {
            sf::Vector2f posJ2 = pJogador2->getCorpo().getPosition();
            if (posJ2.x >= (LARGURA_JANELA / 2))
            {
                return false;
            }
        }
        return false;
    }

    void Fase::eliminarPersonagensMortos()
    {
        for (auto itPersonagem = listaPersonagens->getListaEnt().inicio(); itPersonagem != listaPersonagens->getListaEnt().fim(); itPersonagem++)
        {
            if (!(*itPersonagem)->getVivo())
            {
                listaPersonagens->removerEntidade((*itPersonagem));
                pGerenciadorColisao->removerEntidade(*itPersonagem);
            }
        }
    }
}
