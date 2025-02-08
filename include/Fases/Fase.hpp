
#pragma once

#include "ListaEntidades.hpp"
#include "Grafico.hpp"
#include "Jogador.hpp"
#include "Minion.hpp"
#include "Plataforma.hpp"
#include "Evento.hpp"
#include "Ogro.hpp"
#include "Colisao.hpp"
#include "Espinho.hpp"
#include "Caixa.hpp"
#include <fstream>
#include <vector>
#include <string>
#include "Factory.hpp"

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
        Entidades::Jogador *pJogador1;
        Entidades::Jogador *pJogador2;
        int quantidadeJogadores;
        bool doisJogadores;
        bool completou;
        int pontosJ1;
        int pontosJ2;
        Factory factory;

    public:
        // Fase();
        Fase(const int idFase, bool temSegundoJogador);
        Fase(const int idFase);
        virtual ~Fase();
        virtual void criarMapa() = 0;
        void setJogador1(Entidades::Jogador *pJogador);
        Entidades::Jogador *getJogador1();
        void setJogador2(Entidades::Jogador *pJogador);
        Entidades::Jogador *getJogador2();
        bool getCompletou();
        //void salvarRanking(const std::string &arquivo, int pJ1, int pJ2);
        int getPontosJogador1() const;
        int getPontosJogador2() const;
        //void setNomePartida(const std::string nome);

        void criarJogador(const sf::Vector2f posicao);
        void criarMinion(const sf::Vector2f posicao);
        void criarPlataforma(const sf::Vector2f posicao, bool Castelo);

        void desenhar();
        void executar();
        void proximaFase();
        bool completouFase();
        void eliminarPersonagensMortos();
        
    };
}


