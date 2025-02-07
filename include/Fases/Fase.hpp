
#pragma once

#include "ListaEntidades.hpp"
#include "Grafico.hpp"
#include "Jogador.hpp"
#include "Minion.hpp"
#include "Plataforma.hpp"
#include "Evento.hpp"
#include "Durahan.hpp"
#include "Colisao.hpp"
#include "Espinho.hpp"
#include "Caixa.hpp"
#include <fstream>
#include <vector>
#include <string>

namespace Gerenciadores
{
    class Evento;
}

namespace Fases
{
    class Fase : public Ente
    {

    protected:
        Gerenciadores::Grafico *pGerenciadorGrafico;
        Gerenciadores::Evento *pGerenciadorEvento;
        Gerenciadores::Colisao *pGerenciadorColisao;
        Listas::ListaEntidades *listaPersonagens;
        Listas::ListaEntidades *listaObstaculos;
        // std::list<Entidades::Entidade*> listP;
        Entidades::Jogador *pJogador1;
        Entidades::Jogador *pJogador2;
        Entidades::Obstaculos::Plataforma *pFundo;
        int quantidadeJogadores;
        bool completou;
        int maxMinio;
        int maxCaixa;
        int maxEspinho;
        std::string nomePartida;
        sf::Font fonte;
        int pontosJ1;
        int pontosJ2;

    public:
        // Fase();
        Fase(const int idFase);
        ~Fase();
        virtual void criarMapa() = 0;
        virtual void criarInimigos() = 0;
        virtual void criarObstaculos() = 0;
        // virtual void criarEntidade(char letra, const sf::Vector2f posicao) = 0;

        void setJogador1(Entidades::Jogador *pJogador);
        Entidades::Jogador *getJogador1();
        void setJogador2(Entidades::Jogador *pJogador);
        Entidades::Jogador *getJogador2();
        bool getCompletou();
        void salvarRanking(const std::string &arquivo, int pJ1, int pJ2);
        int getPontosJogador1() const;
        int getPontosJogador2() const;
        void setNomePartida(const std::string nome);

        void criarJogador(const sf::Vector2f posicao);
        void criarMinion(const sf::Vector2f posicao);
        void criarPlataforma(const sf::Vector2f posicao, bool Castelo);
       // void criarPlataformaBase(const sf::Vector2f posicao);
        //void criarPlataforma(const sf::Vector2f posicao, float largura, float altura);
       // void criarPlataformaF(const sf::Vector2f posicao, float largura, float altura);
        //void criarBordaH(const sf::Vector2f posicao, sf::Color cor);
        //void criarBordaV(const sf::Vector2f posicao, sf::Color cor);
        // Está ao contrário as funções BordaV cria Horizontal e BordaH, vertical
        void criarEspinho(const sf::Vector2f posicao);
        void criarCaixa(const sf::Vector2f posicao);
        
        void desenhar();
        void executar();
        void criarCenario();

        void proximaFase();
        bool completouFase();
        void eliminarPersonagensMortos();
        // void mostrarRanking(sf::RenderWindow* janela);
        //  Set list P..........
    };
}
