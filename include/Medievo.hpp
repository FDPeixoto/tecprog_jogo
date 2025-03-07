#pragma once

#include "Grafico.hpp"
#include "Colisao.hpp"
#include "Evento.hpp"
#include "Estado.hpp"

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

class Medievo
{
private:
    Gerenciadores::Grafico *pGerenciadorGrafico;
    Gerenciadores::Colisao *pGerenciadorColisao;
    Gerenciadores::Evento *pGerenciadorEvento;
    Gerenciadores::Estado *pGerenciadorEstado;

public:
    Medievo();
    ~Medievo();
    void executar();
};
