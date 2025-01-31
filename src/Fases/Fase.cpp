
#include "Fase.hpp"



namespace Fases{
    Fase::Fase(const int idFase): 
        Ente(idFase), 
        listaPersonagens(new Listas::ListaEntidades()), 
        listaObstaculos(new Listas::ListaEntidades()), 
        pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()), 
        pGerenciadorEvento(pGerenciadorEvento->getGerenciadorEvento()),
        pGerenciadorColisao(pGerenciadorColisao->getGerenciadorColisao()),
        pJogador1(nullptr), pJogador2(nullptr), quantidadeJogadores(0)
    {
        pGerenciadorColisao->setMoveis(listaPersonagens);
        pGerenciadorColisao->setFixos(listaObstaculos);
    }
    
    Fase::~Fase(){
        pGerenciadorGrafico = nullptr;
        pJogador1 = nullptr;
        pJogador2 = nullptr;
        delete listaPersonagens;
        delete listaObstaculos;
    }
    
    void Fase::setJogador1(Entidades::Jogador *pJogador){pJogador1 = pJogador;}
    
    Entidades::Jogador* Fase::getJogador1(){return pJogador1;}
    
    void Fase::setJogador2(Entidades::Jogador *pJogador){pJogador2 = pJogador;}

    Entidades::Jogador* Fase::getJogador2(){return pJogador2;}

    bool Fase::getCompletou()
    {
        return completou;
    }

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
            listaPersonagens->incluirEntidade(minion);
            minion->setMediator(dynamic_cast<Gerenciadores::Mediator*> (pGerenciadorColisao));
            if(getJogador1() != nullptr){setJogador1(getJogador1());}
            if(getJogador2() != nullptr){setJogador2(getJogador2());}
        }
    }
    
    void Fase::criarPlataforma(const sf::Vector2f posicao)
    {
        Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(100.f, 100.f, posicao);
        if(plataforma != nullptr){
            plataforma->setMediator(dynamic_cast<Gerenciadores::Mediator*> (pGerenciadorColisao));
            listaObstaculos->incluirEntidade(plataforma);
        }
    }
    
    void Fase::criarEspinho(const sf::Vector2f posicao)
    {
        Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(50.f, 50.f, posicao);
        if(plataforma != nullptr){
            plataforma->setMediator(dynamic_cast<Gerenciadores::Mediator*> (pGerenciadorColisao));
            listaObstaculos->incluirEntidade(plataforma);
        }
    }

    void Fase::desenhar()
    {
        pGerenciadorGrafico->desenharListaEntidades(listaPersonagens);
        pGerenciadorGrafico->desenharListaEntidades(listaObstaculos); 
    }

    void Fase::executar(){
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
        pGerenciadorGrafico->resetarRelogio();
        desenhar();
    }
}
