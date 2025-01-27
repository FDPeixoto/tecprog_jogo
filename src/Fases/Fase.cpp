
#include "Fase.hpp"
#define LARGURA 1280
#define ALTURA 720
#define TAM_BORDA 10

namespace Fases{
    Fase::Fase(): 
        Ente(), 
        listaPersonagens(new Listas::ListaEntidades()), 
        listaObstaculos(new Listas::ListaEntidades()), 
        pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()), 
        pGerenciadorEvento(pGerenciadorEvento->getGerenciadorEvento()),
        pJogador1(nullptr), pJogador2(nullptr), quantidadeJogadores(0)
    {}
    
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
            }
            quantidadeJogadores++;
        }
    }

    void Fase::criarMinion(const sf::Vector2f posicao)
    {
        Entidades::Inimigos::Minion* minion = new Entidades::Inimigos::Minion(posicao);
        if(minion != nullptr){
            listaPersonagens->incluirEntidade(minion);
            if(getJogador1() != nullptr){setJogador1(getJogador1());}
            if(getJogador2() != nullptr){setJogador2(getJogador2());}
        }
    }
    
    void Fase::criarPlataforma(const sf::Vector2f posicao)
    {
        Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(50.0f, 50.0f, posicao);
        if(plataforma != nullptr){
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
        Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(50.f, 50.f, posicao);
        if(plataforma != nullptr){
            listaObstaculos->incluirEntidade(plataforma);
        }
    }

    void Fase::desenhar()
    {
        pGerenciadorGrafico->desenharListaEntidades(listaPersonagens);
        pGerenciadorGrafico->desenharListaEntidades(listaObstaculos); 
    }

    void Fase::executar(){
        listaObstaculos->executar();
        listaPersonagens->executar();

        float variacaoTempo = pGerenciadorGrafico->getRelogio()->getElapsedTime().asSeconds();
        listaPersonagens->atualizar(variacaoTempo);
        pGerenciadorGrafico->resetarRelogio();
        desenhar();
    }
}
