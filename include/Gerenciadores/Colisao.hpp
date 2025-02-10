#pragma once
#include "ListaEntidades.hpp"
#include "Lista.hpp"
#include <Mediator.hpp>
#include <math.h>
#include "Entidade.hpp"
#include "Jogador.hpp"
#include "Inimigo.hpp"
#include "Obstaculo.hpp"
#include <list>

namespace Gerenciadores
{
    class Colisao : public Mediator
    {
    private:
        std::vector<Entidades::Entidade *> vectorEntidades;
        std::list<Entidades::Jogador *> listJogadores;
        std::list<Entidades::Inimigos::Inimigo *> listInimigos;
        std::list<Entidades::Obstaculos::Obstaculo *> listObstaculos;
        Listas::ListaEntidades *todasEntidades;
        static Colisao *pColisao;
        Colisao();

    public:
        ~Colisao();
        static Colisao *getGerenciadorColisao();
        const sf::Vector2f calculaColisao(Entidades::Entidade *entidade1, Entidades::Entidade *entidade2);
        bool checarColisao(Entidades::Entidade *entidade1, Entidades::Entidade *entidade2);
        void executar();
        void registrarEntidade(Entidades::Entidade *entidade) override;
        void adicionarJogador(Entidades::Jogador *jogador);
        void adicionarInimigo(Entidades::Inimigos::Inimigo *inimigo);
        void adicionarObstaculo(Entidades::Obstaculos::Obstaculo *obstaculo);
        void notificar(Entidades::Entidade *sender, const std::string &evento);
        void removerEntidade(Entidades::Entidade *entidade);
        void limparListas();
    };
}