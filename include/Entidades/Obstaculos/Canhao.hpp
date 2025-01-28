#pragma once
#include <Obstaculo.hpp>

namespace Entidades{
    namespace Obstaculos{
        class Canhao: public Obstaculo{
            private:
                int velocidade_inicial;
            public:
                Canhao(float alt, float larg, const sf::Vector2f posicao);
                ~Canhao();
                void obstacular(Entidades::Jogador* pJogador);
                void lancar(Entidades::Jogador* pJogador);
                void virtual executar();
                virtual void salvar();
                void virtual atualizar(float dt);
                void virtual  colisao(Entidade *outraEntidade);
                virtual void inicializar();
                virtual void atualizarPosicao(float dt);
        };
    }
}