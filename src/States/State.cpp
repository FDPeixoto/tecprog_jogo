#include "State.hpp"
#include "Fase.hpp"
#include "Pantano_Maldito.hpp"
#include "Castelo_Assombrado.hpp"
#include "Estado.hpp"

namespace States
{
    State::State(const int ID) : identificador(ID), pEstado(pEstado->getGerenciadorEstado()) {}
    State::~State() {}
    void State::desenhar()
    {
        return;
    }
    void State::setRemover(const bool remover) { this->remover = remover; }
    const bool State::getRemover() { return remover; }
    int State::getIdentificador()
    {
        return identificador;
    }
}
