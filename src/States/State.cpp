#include "State.hpp"

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
