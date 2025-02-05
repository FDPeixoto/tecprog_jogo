#include "State.hpp"
#include "Fase.hpp"
#include "Pantano_Maldito.hpp"
#include "Castelo_Assombrado.hpp"

namespace States{
    State::State(const int ID): Ente(ID){}
    State::~State(){}
    void State::desenhar()
    {
        return;
    }
    void State::setRemover(const bool remover) { this->remover = remover; }
    const bool State::getRemover(){return remover;}
}
