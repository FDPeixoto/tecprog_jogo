#pragma once
#include <Obstaculo.hpp>
#define LARGURA_CANHAO 64.0f
#define ALTURA_CANHAO 64.0f
// #include "BolaCanhao.hpp"
namespace Entidades
{
    namespace Obstaculos
    {
        class Canhao : public Obstaculo
        {
        private:
            int velocidade_inicial;
            int lancamentos;
            int it;
            int aleatorio;
            bool jaLancou;
            // std::list<Entidades::Entidade*> listaBolasCanhao;
        public:
            Canhao(const sf::Vector2f posicao);
            ~Canhao();
            // void criarBolasCanhao();
            void obstacular(Entidades::Jogador *pJogador);
            void lancar(Entidades::Jogador *pJogador);
            void virtual executar();
            virtual void salvar();
            void virtual atualizar(float dt);
            void virtual colisao(Entidade *outraEntidade);
            virtual void inicializar();
            virtual void atualizarPosicao(float dt);
        };
    }
}