/*#pragma once
#include "Entidade.hpp"
#include "stdafx.h"

namespace Entidades{
    class BolaCanhao: public Entidade{
        private:
        float vxP;
        sf::Vector2f velocidade;
        bool direita;

        public:
        BolaCanhao();
        BolaCanhao(const sf::Vector2f posicao);
        ~BolaCanhao();
        //void atirar(Jogador* pAlvo);
        void atirar(const sf::Vector2f posCanhao, bool direita);
        void executar();
        void atualizar(float dt);
        void atualizarPosicao(float dt);
        void colisao(Entidade *outraEntidade);
        void salvar();
        void inicializar();
        void setVelocidade(sf::Vector2f vel);
    };
}*/