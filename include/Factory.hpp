#pragma once 
#include "Jogador.hpp"
#include "Plataforma.hpp"
#include "Caixa.hpp"
#include "Espinho.hpp"
#include "Minion.hpp"
#include "Esqueleto.hpp"
#include "Ogro.hpp"

class Factory{
    public:
    virtual Entidades::Entidade* create(const int id, sf::Vector2f posicao, bool Castelo=true);
};