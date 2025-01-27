#pragma once

#include "Grafico.hpp"
#include "Colisao.hpp"
#include "Evento.hpp"
#include "Pantano_Maldito.hpp"
#include "Jogador.hpp"


#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

class Medievo {
    private:
    Gerenciadores::Grafico* pGerenciadorGrafico;
    //Gerenciadores::Colisao* pGerenciadorColisao;
    Gerenciadores::Evento* pGerenciadorEvento;
    Fases::Pantano_Maldito primeiraFase;

    public:
    Medievo();
    ~Medievo();
    void executar();
};
