#include <Obstaculo.hpp>
#include <stdafx.h>

namespace Entidades
{
    namespace Obstaculos
    {
        Obstaculo::Obstaculo(const sf::Vector2f tamanho, const sf::Vector2f posicao, bool causaDano, const int ID) : Entidade(tamanho, posicao, ID), danoso(causaDano) {}
        Obstaculo::~Obstaculo() {}
        void Obstaculo::atualizarPosicao(float dt)
        {
            return; // não faz nada
        }
    }
}
