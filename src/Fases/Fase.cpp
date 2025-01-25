#include <Fase.hpp>
#include <Jogador.hpp>
#include <Minion.hpp>
#include <Plataforma.hpp>


namespace Fases{
    Fase::Fase(): Ente(), listaPersonagens(new Listas::ListaEntidades()), listaObstaculos(new Listas::ListaEntidades()), pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()){}
    Fase::~Fase(){}
    void Fase::criarJogador(const sf::Vector2f posicao){
        if(quantidadeJogadores % 2 == 0){
            Entidades::Jogador* jogador = new Entidades::Jogador(posicao);
            jogador->setCor(sf::Color::Blue);
            jogador->setTeclas(sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Up);
            if(jogador != nullptr){
                listaPersonagens->incluirEntidade(jogador);
            }
            quantidadeJogadores++; 
        }
        else{
            Entidades::Jogador* jogador = new Entidades::Jogador(posicao);
            jogador->setCor(sf::Color::Green);
            jogador->setTeclas(sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::W);
            if(jogador != nullptr){
                listaPersonagens->incluirEntidade(jogador);
            }
            quantidadeJogadores++;
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
    void Fase::desenhar()
    {
    }
}
