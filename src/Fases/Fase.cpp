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
                                   pJogador1(nullptr), pJogador2(nullptr), quantidadeJogadores(0), pFundo(nullptr) //, vetorPortal()
    {
        pGerenciadorColisao->setMoveis(listaPersonagens);
        pGerenciadorColisao->setFixos(listaObstaculos);
         fonte.loadFromFile("Fonte/DejaVuSans.ttf");
            
    
    textoEntrada.setFont(fonte);
    textoEntrada.setCharacterSize(24);
    textoEntrada.setFillColor(sf::Color::White);
    textoEntrada.setPosition(50, 500);  // Posição na tela
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

void Fase::salvarRanking(const std::string& arquivo) {
    // Cria um objeto JSON para os jogadores
    json ranking;
    
    // Tenta abrir o arquivo para leitura
    std::ifstream arquivoExistente(arquivo);
    if (arquivoExistente.is_open()) {
        // Se o arquivo existir, carrega os dados
        arquivoExistente >> ranking;
        arquivoExistente.close();
    } else {
        // Caso o arquivo não exista, cria um novo arquivo com conteúdo JSON vazio
        std::ofstream novoArquivo(arquivo);
        novoArquivo << "[]";  // Cria um array JSON vazio
        novoArquivo.close();
    }

    // Adiciona a pontuação dos jogadores
   json jogo;
   int pontosJogador1=getPontosJogador1();
   int pontosJogador2=getPontosJogador2();

    jogo["nomePartida"] = nomePartida;
    jogo["jogadores"] = {
        {{"nome", "1"}, {"pontuacao", pontosJogador1}},
        {{"nome", "2"}, {"pontuacao", pontosJogador2}}
    };

    // Adiciona o objeto 'jogo' ao ranking
    ranking.push_back(jogo);

    // Ordena os jogadores pelo ranking (decrescente)
    std::sort(ranking.begin(), ranking.end(), [](const json& a, const json& b) {
        return a["jogadores"][0]["pontuacao"] > b["jogadores"][0]["pontuacao"];
    });

    // Limita a exibição aos 5 melhores
    if (ranking.size() > 5) {
        ranking.erase(ranking.begin() + 5, ranking.end()); // Remove os elementos extras
    }

    // Salva no arquivo
    std::ofstream arquivoSaida(arquivo);
    arquivoSaida << ranking.dump(4); // '4' é a indentação para uma saída bonita
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
        completouFase();
        
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
            sf::Vector2f posJ1=pJogador1->getPos();
            if(posJ1.x>=LARGURA_JANELA){
                    return true;
            }
        }
        else if(pJogador2!=nullptr){
            sf::Vector2f posJ2=pJogador2->getPos();
            if(posJ2.x>=LARGURA_JANELA){
                    return true;
            }
        }
        
            return false;
        
    }

}
