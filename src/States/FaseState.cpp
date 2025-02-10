#include "FaseState.hpp"
#include "Pantano_Maldito.hpp"
#include "Castelo_Assombrado.hpp"

namespace States
{
    FaseState::FaseState(const int idFase) : State(IDFASESTATE)
    {
        if (idFase == IDPANTANOMALDITOUM)
        {
            pFase = new Fases::Pantano_Maldito(false);
        }
        else if (idFase == IDCASTELOASSOMBRADOUM)
        {
            pFase = new Fases::Castelo_Assombrado(false);
        }
        else if (idFase == IDPANTANOMALDITODOIS)
        {
            pFase = new Fases::Pantano_Maldito(true);
        }
        else if (idFase == IDCASTELOASSOMBRADODOIS)
        {
            pFase = new Fases::Castelo_Assombrado(true);
        }
        else
        {
                }
    }
    FaseState::~FaseState()
    {
        if (pFase != nullptr)
        {
            delete (pFase);
        }
        pFase = nullptr;
    }

    Fases::Fase *FaseState::getFase()
    {
        return pFase;
    }

    void FaseState::executar()
    {
        pFase->executar();
        /*if(pFase->getCompletou()==true){
            if(IDPANTANOMALDITO){
                Fase::Fase* Aux=pFase;
                pFase = new Fases::Castelo_Assombrado();
                delete aux
            }
        }*/
    }
}