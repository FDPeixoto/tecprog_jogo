#include "Ente.hpp"
Ente::Ente() {}
Ente::Ente(int ID) : id(ID) {}
Ente::~Ente()
{
}

void Ente::desenhar() {};
const int Ente::getID() { return id; }
