#pragma once
#include <Inimigo.hpp>
#include "Projetil.hpp"
#include "stdafx.h"
#include "ListaEntidades.hpp"
#include <list>

namespace Entidades
{
    namespace Inimigos
    {
        class Ogro : public Inimigo
        {
        private:
            std::list<Entidades::Entidade *> listaProjetil;
            int tiros;
            int it;
            int aleatorio;
            bool jaAtirou;

        public:
            Ogro(const sf::Vector2f posicao);
            ~Ogro();
            void salvar();
            void salvarDataBuffer();
            void executar();
            void atirar();
            // bool getVivo();, pega direto de personagem mesmo
            // void colisao(Entidade *outraEntidade);
            std::list<Entidades::Entidade *> &getListaProjetil();
            void criarProjetil();
            void atualizarListP(float dt);
            void atualizar(float dt);
            // DÁ PARA DEIXAR O PERSEGUIR DO INIMIGO MAIS GERAL E CHAMAR A FUNÇÃO PARA O DURRAHAN, MAS NO MOMENTO COPIEI MESMO
        };
    }
}