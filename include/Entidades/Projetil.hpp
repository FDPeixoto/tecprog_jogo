#pragma once
#include "Entidade.hpp"
#include "stdafx.h"

namespace Entidades{
    class Projetil: public Entidade{
        private:
        float vxP;
        sf::Vector2f velocidade;

        public:
        Projetil();
        Projetil(const sf::Vector2f posicao);
        ~Projetil();
        //void atirar(Jogador* pAlvo);
        void atirar(const sf::Vector2f posInimigo);
        void executar();
        void atualizar(float dt);
        void atualizarPosicao(float dt);
        void colisao(Entidade *outraEntidade);
        void salvar();
        void inicializar();
        void setVelocidade(sf::Vector2f vel);
    };
}