
#pragma once


#include "ListaEntidades.hpp"
#include "Grafico.hpp"
#include "Jogador.hpp"
#include "Minion.hpp"
#include "Plataforma.hpp"
#include "Evento.hpp"
#include "Canhao.hpp"
#include "Durahan.hpp"
#include "Colisao.hpp"
//#include <vector>

namespace Gerenciadores{
    class Evento;
}

namespace Fases{
    class Fase: public Ente{

        protected:
        Gerenciadores::Grafico* pGerenciadorGrafico;
        Gerenciadores::Evento* pGerenciadorEvento;
        Gerenciadores::Colisao* pGerenciadorColisao;
        Listas::ListaEntidades* listaPersonagens;
        Listas::ListaEntidades* listaObstaculos;
        //std::list<Entidades::Entidade*> listP;
        Entidades::Jogador* pJogador1;
        Entidades::Jogador* pJogador2;
        int quantidadeJogadores;
        bool completou;
        //std::vector<Entidades::Obstaculos::Durahan*> vetorPortal;
        //sf::Clock clock;
        public:
        //Fase();
        Fase(const int idFase);
        ~Fase();
        virtual void criarMapa() = 0;
        virtual void criarInimigos()=0;
        virtual void criarObstaculos()=0;
        //virtual void criarEntidade(char letra, const sf::Vector2f posicao) = 0;


        void setJogador1(Entidades::Jogador* pJogador);
        Entidades::Jogador* getJogador1();
        void setJogador2(Entidades::Jogador* pJogador);
        Entidades::Jogador* getJogador2();
        bool getCompletou();
        
        void criarJogador(const sf::Vector2f posicao);
        void criarMinion(const sf::Vector2f posicao);
        void criarPlataforma(const sf::Vector2f posicao);
        void criarPlataformaBase(const sf::Vector2f posicao);
        void criarBordaH(const sf::Vector2f posicao, sf::Color cor);
        void criarBordaV(const sf::Vector2f posicao, sf::Color cor);
        //Está ao contrário as funções BordaV cria Horizontal e BordaH, vertical
        void criarEspinho(const sf::Vector2f posicao);
        void criarCanhao(const sf::Vector2f posicao);
        
        void desenhar();
        void executar();
        void criarCenario();

        void proximaFase();
        //Set list P..........
    };
}

