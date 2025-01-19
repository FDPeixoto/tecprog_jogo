#pragma once

#include "Fases/Pantano_Maldito.hpp"
#include "../../include/Gerenciadores/Grafico.hpp"
#include "Jogador.hpp"


#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
class Medievo {
    private:
    Entidades::Jogador* pJog1;
    Entidades::Jogador* pJog2;
    //Fases::Pantano_Maldito primeiraFase;
    Gerenciadores::Grafico* pGerenciadorGrafico;

    public:
    float distance(const sf::Vector2f& a, const sf::Vector2f& b);
    Medievo();
    ~Medievo();
    void executar();
    void setJog(Entidades::Jogador *p, int num);
};
