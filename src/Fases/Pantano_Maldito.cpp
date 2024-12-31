#include "../include/Fases/Pantano_Maldito.hpp"

Fases::Pantano_Maldito::Pantano_Maldito(): maxInimMedios(1)
{
}

Fases::Pantano_Maldito::~Pantano_Maldito()
{
}
void Fases::Pantano_Maldito::executar()
{
    
}
void Fases::Pantano_Maldito::criarInimMedios()
{
}
void Fases::Pantano_Maldito::criarInimigos()
{
    criarInimFaceis();
    criarInimMedios();
}
void Fases::Pantano_Maldito::criarObstaculos()
{
    criarObstFaceis();
    criarObstMedios();
}
bool Fases::Pantano_Maldito::completou()
{
}
const int Fases::Pantano_Maldito::getMaxInimMedios()
{
    return maxInimMedios;
}
