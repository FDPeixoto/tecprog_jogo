#include "FaseState.hpp"
#include "Pantano_Maldito.hpp"
#include "Castelo_Assombrado.hpp"

namespace States{
    FaseState::FaseState(const int idFase): State(IDFASESTATE){
        if(idFase == IDPANTANOMALDITO){
            pFase = new Fases::Pantano_Maldito();
        }
        else if(idFase == IDCASTELOASSOMBRADO){
            pFase = new Fases::Castelo_Assombrado();
        }
        else{
            //Id de fase nao identificado
        }
    }
    FaseState::~FaseState(){
        if(pFase != nullptr){
            delete(pFase);
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
    }
}