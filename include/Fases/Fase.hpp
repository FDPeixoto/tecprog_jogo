#pragma once
#include "ListaEntidades.hpp"
#include "Grafico.hpp"
#include "Jogador.hpp"
#include "Minion.hpp"
#include "Plataforma.hpp"
#include "Evento.hpp"
#include "Colisao.hpp"

namespace Fases{
    class Fase: public Ente{

        protected:
        Gerenciadores::Grafico* pGerenciadorGrafico;
        Gerenciadores::Evento* pGerenciadorEvento;
        Gerenciadores::Colisao* pGerenciadorColisao;
        Listas::ListaEntidades* listaPersonagens;
        Listas::ListaEntidades* listaObstaculos;
        Entidades::Jogador* pJogador1;
        Entidades::Jogador* pJogador2;
        int quantidadeJogadores;
        bool completou;

        public:
        Fase();
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
        void criarEspinho(const sf::Vector2f posicao);
        
        void desenhar();
        void executar();
        void criarCenario();
    };
}