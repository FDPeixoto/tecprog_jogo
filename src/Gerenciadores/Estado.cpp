#include "Estado.hpp"


namespace Gerenciadores{
    Estado* Estado::pEstado = nullptr;

    Estado::Estado(): pilhaStates(){}

    Estado::~Estado()
    {
        while(!pilhaStates.empty()){
            delete(pilhaStates.top());
            pilhaStates.top() = nullptr;
            pilhaStates.pop();
        }

        if(pEstado != nullptr){
            delete(pEstado);
            pEstado = nullptr;
        }
    }

    Estado *Estado::getGerenciadorEstado()
    {
        if(pEstado == nullptr){
            pEstado = new Estado();
        }
        return pEstado;
    }
    void Estado::removerState()
    {
        if(pilhaStates.top() != nullptr){
            delete(pilhaStates.top());
            pilhaStates.top() = nullptr;
            pilhaStates.pop();
        }

        if(pilhaStates.empty()){
            Gerenciadores::Grafico* pGrafico = Gerenciadores::Grafico::getGerenciadorGrafico();
            pGrafico->fecharJanela();
        }
    }

    States::State *Estado::getStateAtual(){return pilhaStates.top();}

    void Estado::executar(){
        if(!pilhaStates.empty()){
            pilhaStates.top()->executar();
        }
    }

}