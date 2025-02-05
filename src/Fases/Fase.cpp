#include "Fase.hpp"
#include "../../include/nlohmann/json.hpp"  // Incluindo a biblioteca JSON
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
                                   pJogador1(nullptr), pJogador2(nullptr), quantidadeJogadores(0), pFundo(nullptr), completou(false) //, vetorPortal()
    {
        pGerenciadorColisao->setMoveis(listaPersonagens);
        pGerenciadorColisao->setFixos(listaObstaculos);
         fonte.loadFromFile("Fonte/DejaVuSans.ttf");
            
    
    textoEntrada.setFont(fonte);
    textoEntrada.setCharacterSize(24);
    textoEntrada.setFillColor(sf::Color::White);
    textoEntrada.setPosition(50, 500);  // Posição na tela
    textoEntrada.setString("Nome da Partida: " + nomePartida);
        // vetorPortal.clear();
        capturandoNome=true;
    }

    Fase::~Fase()
    {
        /*for (std::vector<Entidades::Obstaculos::Portal*>::iterator it = vetorPortal.begin();it != vetorPortal.end();++it) {
            delete *it;
        }*/
        pGerenciadorGrafico = nullptr;
        pJogador1 = nullptr;
        pJogador2 = nullptr;
        quantidadeJogadores=0;
        delete listaPersonagens;
        delete listaObstaculos;

        // vetorPortal.clear();
        // listP.clear();
    }
     
   

    void Fase::setJogador1(Entidades::Jogador *pJogador) { pJogador1 = pJogador; }

    Entidades::Jogador *Fase::getJogador1() { return pJogador1; }

    void Fase::setJogador2(Entidades::Jogador *pJogador) { pJogador2 = pJogador; }

    Entidades::Jogador *Fase::getJogador2() { return pJogador2; }
    int Fase::getPontosJogador1() const { 
        if(pJogador1!= nullptr){
        return pJogador1->getPontos();
    } return 0;
    }
    int Fase::getPontosJogador2() const { 
        if(pJogador2!=nullptr){
        return pJogador2->getPontos();
    } 
    return 0;
    }

    bool Fase::getCompletou()
    {
        return completou;
    }
    void Fase::setNomePartida(const std::string nome){
        nomePartida=nome;
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
    void Fase::salvarRanking(const std::string& arquivo) {
    json ranking;

    // 🔹 1. Tenta abrir e carregar o arquivo existente
    std::ifstream arquivoExistente(arquivo);
    if (arquivoExistente.is_open()) {
        try {
            arquivoExistente >> ranking;
        } catch (const std::exception& e) {
            ranking = json::array(); // Se houver erro, inicializa um array vazio
        }
        arquivoExistente.close();
    } else {
        ranking = json::array(); // Se o arquivo não existir, inicia como array vazio
    }

    // 🔹 2. Captura a pontuação dos jogadores
    int pontosJogador1 = getPontosJogador1();
    int pontosJogador2 = getPontosJogador2();

    // 🔹 3. Verifica se a partida já existe no ranking
    bool partidaExistente = false;
    for (auto& jogo : ranking) {
        // Verifica se o nome da partida já está no ranking
        if (jogo["nomePartida"] == nomePartida) {
            // Se o nome da partida já existe, verifica se a pontuação é a mesma
            int pontuacaoJogador1Existente = std::max(jogo["jogadores"][0]["pontuacao"], jogo["jogadores"][1]["pontuacao"]);
            if (pontuacaoJogador1Existente == std::max(pontosJogador1, pontosJogador2)) {
                partidaExistente = true;  // A partida existe e a pontuação é a mesma, não adiciona
                return;
            }
        }
    }

    // 🔹 4. Se a partida não existe ou a pontuação for diferente, adiciona ao ranking
    if (!partidaExistente) {
        json jogo;
        jogo["nomePartida"] = nomePartida;
        jogo["jogadores"] = {
            {{"nome", "1"}, {"pontuacao", pontosJogador1}},
            {{"nome", "2"}, {"pontuacao", pontosJogador2}}
        };

        // 🔹 5. Adiciona a nova partida ao ranking
        ranking.push_back(jogo);

        // 🔹 6. Ordena todas as partidas pela **melhor pontuação geral**
        std::sort(ranking.begin(), ranking.end(), [](const json& a, const json& b) {
            int maxA = std::max(a["jogadores"][0]["pontuacao"], a["jogadores"][1]["pontuacao"]);
            int maxB = std::max(b["jogadores"][0]["pontuacao"], b["jogadores"][1]["pontuacao"]);
            return maxA > maxB; // Ordem decrescente
        });

        // 🔹 7. Mantém apenas os 5 melhores registros
        if (ranking.size() > 5) {
            ranking.erase(ranking.begin() + 5, ranking.end());
        }
    }

    // 🔹 8. Salva o ranking atualizado no arquivo
    std::ofstream arquivoSaida(arquivo);
    if (!arquivoSaida) {
        return;
    }
    arquivoSaida << ranking.dump(4); // Formatação bonita
    arquivoSaida.close();
}

    /*void setListP(sf::list<Entidades::Entidade*>& l){
        listP=l;
    }*/
    void mostrarRanking(sf::RenderWindow* janela, const sf::Font& fonte) {
    std::ifstream arquivo("ranking.json");
    if (arquivo.is_open()) {
        json ranking;
        arquivo >> ranking;
        arquivo.close();

        sf::Text textoRanking;
        textoRanking.setFont(fonte);
        textoRanking.setCharacterSize(24);
        textoRanking.setFillColor(sf::Color::White);

        int yPos = 50;
        for (int i = 0; i < ranking.size(); ++i) {
            std::string texto = "Partida: " + ranking[i]["nomePartida"].get<std::string>();
            textoRanking.setString(texto);
            textoRanking.setPosition(50, yPos);
            janela->draw(textoRanking);  // Modificado para usar o ponteiro
            yPos += 40;

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
}


    void Fase::criarJogador(const sf::Vector2f posicao)
    {
        if (quantidadeJogadores == 0)
        {
            Entidades::Jogador *jogador = new Entidades::Jogador(posicao, false);
            jogador->setCor(sf::Color::White);//Blue
            if (jogador != nullptr)
            {
                listaPersonagens->incluirEntidade(jogador);
                setJogador1(jogador);
                pGerenciadorEvento->setJogador1(jogador);
            }
            quantidadeJogadores++;
        }
        else if (quantidadeJogadores == 1)
        {
            Entidades::Jogador *jogador = new Entidades::Jogador(posicao, true);
            jogador->setCor(sf::Color::White);//Green
            if (jogador != nullptr)
            {
                listaPersonagens->incluirEntidade(jogador);
                setJogador2(jogador);
                pGerenciadorEvento->setJogador2(jogador);
                // jogador->setMediator(dynamic_cast<Gerenciadores::Mediator*> (pGerenciadorColisao));
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
        }
    }
    void Fase::criarPlataformaF(const sf::Vector2f posicao, float altura, float largura)
    {
        Entidades::Obstaculos::Plataforma *plataforma = new Entidades::Obstaculos::Plataforma(altura, largura, posicao);
        if (plataforma != nullptr)
        {
            // sf::Color verdeEscuro(0, 100, 0); // verde escuro
            // plataforma->setCor(verdeEscuro);
            //listaObstaculos->incluirEntidade(plataforma);
            pFundo=plataforma;
            pGerenciadorGrafico->desenharEntidade(plataforma);
            //pGerenciadorGrafico->display();
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
        }
    }
    void Fase::criarCaixa(const sf::Vector2f posicao)
    {
        Entidades::Obstaculos::Caixa *caixa = new Entidades::Obstaculos::Caixa(posicao + sf::Vector2f(0.f, 16.f));
        if (caixa != nullptr)
        {
            caixa->setMediator(dynamic_cast<Gerenciadores::Mediator *>(pGerenciadorColisao));
            listaObstaculos->incluirEntidade(caixa);
        }
    }
    void Fase::criarCanhao(const sf::Vector2f posicao)
    {
        Entidades::Obstaculos::Canhao *canhao = new Entidades::Obstaculos::Canhao(posicao);
        if ((canhao) != nullptr)
        {
            listaObstaculos->incluirEntidade(canhao);
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
    void Fase::registrarNomePartida(sf::Event& evento,sf::RenderWindow* janela){
        
        /*if (capturandoNome) {
                if (evento.type == sf::Event::TextEntered) {
                    if (evento.text.unicode == 13) {  // 13 é o código ASCII para Enter
                        setNomePartida(nomePartida);
                        salvarRanking("ranking.json");
                        capturandoNome = false;  // Termina a captura do nome
                    }
                    else if (evento.text.unicode < 128 && evento.text.unicode != 8) {  // Ignora backspace
                        nomePartida += static_cast<char>(evento.text.unicode);
                    }
                    else if (evento.text.unicode == 8 && nomePartida.size() > 0) {
                        nomePartida.pop_back();
                    }

                    textoEntrada.setString("Nome da Partida: " + nomePartida);
                }*/

                // Verifica se o botão foi clicado//Está em eventos agora
                /*if (botaoConfirmar.foiClicado(janela)) {
                    fase.setNomePartida(nomePartida);
                    fase.salvarRanking("ranking.json");
                    capturandoNome = false;
                }*/
            //}
        }
    

    void Fase::executar()
    {
        
        
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
        pGerenciadorGrafico->desenharTexto(pJogador1->getTextoVida());
        pGerenciadorGrafico->desenharTexto(pJogador2->getTextoVida());
        pGerenciadorGrafico->desenharTexto(pGerenciadorEvento->getTextoEntrada());
        desenhar();
    }
    void Fase::proximaFase()
    {
        pJogador1 = nullptr;
        pJogador2 = nullptr;
        quantidadeJogadores = 0;
    }
    bool Fase::completouFase(){
        if((pJogador1!=nullptr)){
            sf::Vector2f posJ1=pJogador1->getCorpo().getPosition();
            if(posJ1.x>=(LARGURA_JANELA/2)){
                    return true;
            }
        }
        else if(pJogador2!=nullptr){
            sf::Vector2f posJ2=pJogador2->getCorpo().getPosition();
            if(posJ2.x>=(LARGURA_JANELA/2)){
                    return true;
            }
        }
        
            return false;
        
    }

}
