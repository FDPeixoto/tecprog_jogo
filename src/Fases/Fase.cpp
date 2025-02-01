#include "Fase.hpp"
#define LARGURA 1280
#define ALTURA 720


namespace Fases{
    Fase::Fase(const int idFase): 
        Ente(idFase), 
        listaPersonagens(new Listas::ListaEntidades()), 
        listaObstaculos(new Listas::ListaEntidades()), 
        pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()), 
        pGerenciadorEvento(pGerenciadorEvento->getGerenciadorEvento()),
        pGerenciadorColisao(pGerenciadorColisao->getGerenciadorColisao()),
        pJogador1(nullptr), pJogador2(nullptr), quantidadeJogadores(0)//, vetorPortal()
    {
        pGerenciadorColisao->setMoveis(listaPersonagens);
        pGerenciadorColisao->setFixos(listaObstaculos);
        //vetorPortal.clear();
    }
    
    Fase::~Fase(){
        /*for (std::vector<Entidades::Obstaculos::Portal*>::iterator it = vetorPortal.begin();it != vetorPortal.end();++it) {
            delete *it; 
        }*/
        pGerenciadorGrafico = nullptr;
        pJogador1 = nullptr;
        pJogador2 = nullptr;
        delete listaPersonagens;
        delete listaObstaculos;

        //vetorPortal.clear();
        //listP.clear();
    }
    
    void Fase::setJogador1(Entidades::Jogador *pJogador){pJogador1 = pJogador;}
    
    Entidades::Jogador* Fase::getJogador1(){return pJogador1;}
    
    void Fase::setJogador2(Entidades::Jogador *pJogador){pJogador2 = pJogador;}

    Entidades::Jogador* Fase::getJogador2(){return pJogador2;}

    bool Fase::getCompletou()
    {
        return completou;
    }
    /*void setListP(sf::list<Entidades::Entidade*>& l){
        listP=l;
    }*/

    void Fase::criarJogador(const sf::Vector2f posicao)
    {
        if(quantidadeJogadores == 0){
            Entidades::Jogador* jogador = new Entidades::Jogador(posicao, false);
            jogador->setCor(sf::Color::Blue);
            if(jogador != nullptr){
                listaPersonagens->incluirEntidade(jogador);
                setJogador1(jogador);
                pGerenciadorEvento->setJogador1(jogador);
            }
            quantidadeJogadores++; 
        }
        else if(quantidadeJogadores == 1){
            Entidades::Jogador* jogador = new Entidades::Jogador(posicao, true);
            jogador->setCor(sf::Color::Green);
            if(jogador != nullptr){
                listaPersonagens->incluirEntidade(jogador);
                setJogador2(jogador);
                pGerenciadorEvento->setJogador2(jogador);
                //jogador->setMediator(dynamic_cast<Gerenciadores::Mediator*> (pGerenciadorColisao));
            }
            quantidadeJogadores++;
        }
    }

    void Fase::criarMinion(const sf::Vector2f posicao)
    {
        Entidades::Inimigos::Minion* minion = new Entidades::Inimigos::Minion(posicao);
        minion->setCor(sf::Color::Red);
        if(minion != nullptr){
            minion->setCor(sf::Color::Red);
            minion->setMediator(dynamic_cast<Gerenciadores::Mediator*> (pGerenciadorColisao));
            if(getJogador1() != nullptr){minion->setJogador1(getJogador1());}
            if(getJogador2() != nullptr){minion->setJogador2(getJogador2());}
            listaPersonagens->incluirEntidade(minion);
        }
    }
    
    void Fase::criarPlataforma(const sf::Vector2f posicao)
    {
        Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(50.0f, 50.0f, posicao);//a plaforma era 100.0f e 100.0f
        if(plataforma != nullptr){
            plataforma->setCor(sf::Color::White);
            plataforma->setMediator(dynamic_cast<Gerenciadores::Mediator*> (pGerenciadorColisao));
            listaObstaculos->incluirEntidade(plataforma);
        }
    }
    void Fase::criarPlataformaBase(const sf::Vector2f posicao)
    {
        Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(60.0f, LARGURA, posicao);
        if(plataforma != nullptr){
            sf::Color verdeEscuro(0, 100, 0);  // verde escuro
            plataforma->setCor(verdeEscuro);
            listaObstaculos->incluirEntidade(plataforma);
        }
    }
    void Fase::criarBordaH(const sf::Vector2f posicao, sf::Color cor)
    {
        Entidades::Obstaculos::Plataforma* borda = new Entidades::Obstaculos::Plataforma(ALTURA, TAM_BORDA, posicao);
        if(borda != nullptr){
            borda->setCor(cor);
            listaObstaculos->incluirEntidade(borda);
        }
    }
    void Fase::criarBordaV(const sf::Vector2f posicao, sf::Color cor)
    {
        Entidades::Obstaculos::Plataforma* borda = new Entidades::Obstaculos::Plataforma(TAM_BORDA, LARGURA, posicao);
        if(borda != nullptr){
            borda->setCor(cor);
            listaObstaculos->incluirEntidade(borda);
        }
    }
    
    void Fase::criarEspinho(const sf::Vector2f posicao)
    {
        Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(LARGURA_ESPINHO, ALTURA_ESPINHO, posicao);
        if(plataforma != nullptr){
            sf::Color laranja(255, 111, 0);  // RGB (255, 165, 0) - um laranja padrão
            plataforma->setCor(laranja);
            plataforma->setMediator(dynamic_cast<Gerenciadores::Mediator*> (pGerenciadorColisao));
            listaObstaculos->incluirEntidade(plataforma);
        }
    }
    void Fase::criarCanhao(const sf::Vector2f posicao)
    {
        Entidades::Obstaculos::Canhao* canhao = new Entidades::Obstaculos::Canhao(LARGURA_CANHAO, ALTURA_CANHAO, posicao);
        if((canhao) != nullptr){
            sf::Color roxa(128, 0, 128);  // roxo
            canhao->setCor(roxa);
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

    void Fase::executar(){
        //listaObstaculos->executar();
        if(pGerenciadorColisao->getListaMoveis() != listaPersonagens){
            pGerenciadorColisao->setMoveis(listaPersonagens);
        }
        if(pGerenciadorColisao->getListaFixos() != listaObstaculos){
            pGerenciadorColisao->setFixos(listaObstaculos);
        }
        listaObstaculos->executar();
        listaPersonagens->executar();
        pGerenciadorColisao->executar();

        float variacaoTempo = pGerenciadorGrafico->getRelogio()->getElapsedTime().asSeconds();
        listaPersonagens->atualizar(variacaoTempo);
        //listP->atualizar();
        pGerenciadorGrafico->resetarRelogio();
        //int v1=pJogador1->getNumVidas();
        //int v2=pJogador2->getNumVidas();
        //pGerenciadorGrafico->desenharTexto("Vida: " + std::to_string(v1));
        //pGerenciadorGrafico->desenharTexto("Vida: " + std::to_string(v2));
        /*if (clock.getElapsedTime().asSeconds() >= 5.f) {  // Se passaram 5 segundos
            pD->atirar();
            clock.restart();  // Reinicia o relógio para a próxima verificação
        }*/
        pGerenciadorGrafico->desenharTexto(pJogador1->getTextoVida());
        pGerenciadorGrafico->desenharTexto(pJogador2->getTextoVida());
        desenhar();
    }
    void Fase::proximaFase(){
        pJogador1=nullptr;
        pJogador2=nullptr;
        quantidadeJogadores=0;
    }
    
}
