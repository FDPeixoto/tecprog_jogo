#include <Fase.hpp>
#include <Jogador.hpp>
#include <Minion.hpp>
#include <Plataforma.hpp>


namespace Fases{
    Fase::Fase(): Ente(){}
    Fase::~Fase(){}
    void Fase::criarJogador(const sf::Vector2f posicao){
        Entidades::Jogador* jogador = new Entidades::Jogador(posicao);
        if(jogador != nullptr){
            listaPersonagens->incluirEntidade(jogador);
        } 
    }
    void Fase::criarMinion(const sf::Vector2f posicao)
    {
        Entidades::Inimigos::Minion* minion = new Entidades::Inimigos::Minion(posicao);
        if(minion != nullptr){
            listaPersonagens->incluirEntidade(minion);
        }
    }
    void Fase::criarPlataforma(const sf::Vector2f posicao)
    {
        Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(50.f, 50.f, posicao);
        if(plataforma != nullptr){
            listaObstaculos->incluirEntidade(plataforma);
        }
    }
    void Fase::criarEspinho(const sf::Vector2f posicao)
    {
        Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(50.f, 50.f, posicao);
        if(plataforma != nullptr){
            listaObstaculos->incluirEntidade(plataforma);
        }
    }
    void Fase::criarEntidade(char letra, const sf::Vector2f posicao)
    {
        
    }
    void Fase::executar()
    {
    }
    void Fase::desenhar()
    {
    }
}
