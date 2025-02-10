#include "Estado.hpp"

namespace Gerenciadores
{
    Estado *Estado::pEstado = nullptr;

    Estado::Estado() : pilhaStates() {}

    Estado::~Estado()
    {
        while (!pilhaStates.empty())
        {
            delete (pilhaStates.top());
            pilhaStates.top() = nullptr;
            pilhaStates.pop();
        }

        if (pEstado != nullptr)
        {
            delete (pEstado);
            pEstado = nullptr;
        }
    }

    Estado *Estado::getGerenciadorEstado()
    {
        if (pEstado == nullptr)
        {
            pEstado = new Estado();
        }
        return pEstado;
    }
    void Estado::removerState()
    {
        if (pilhaStates.top() != nullptr)
        {
            delete (pilhaStates.top());
            pilhaStates.top() = nullptr;
            pilhaStates.pop();
        }

        if (pilhaStates.empty())
        {
            Gerenciadores::Grafico *pGrafico = Gerenciadores::Grafico::getGerenciadorGrafico();
            pGrafico->fecharJanela();
        }
    }

    States::State *Estado::getStateAtual() { return pilhaStates.top(); }

    void Estado::executar()
    {
        if (!pilhaStates.empty())
        {
            pilhaStates.top()->executar();
        }
    }

    int Estado::getIdentificadorAtual()
    {
        if (!pilhaStates.empty())
        {
            return pilhaStates.top()->getIdentificador();
        }
        return -1;
    }

    void Estado::addState(const int ID)
    {
        States::State *estado = nullptr;
        switch (ID)
        {
        case IDCARREGARSAVESTATE:
            break;

        case IDLEADERBOARDSTATE:

            break;
        case IDMENUFASESSTATE:

            break;
        case IDMENUINICIALSTATE:
            estado = new States::Menus::MenuInicialState();
            break;
        case IDMENUJOGADORESSTATE:

            break;
        case IDPAUSESTATE:
            estado = new States::Menus::PauseState();
            break;
        case IDPANTANOMALDITOUM:
            estado = new States::FaseState(IDPANTANOMALDITOUM);
            break;
        case IDCASTELOASSOMBRADOUM:
            estado = new States::FaseState(IDCASTELOASSOMBRADOUM);
            break;
        case IDPANTANOMALDITODOIS:
            estado = new States::FaseState(IDPANTANOMALDITODOIS);
            break;
        case IDCASTELOASSOMBRADODOIS:
            estado = new States::FaseState(IDCASTELOASSOMBRADODOIS);
            break;
        }

        if (estado != nullptr)
        {
            pilhaStates.push(estado);
        }
    }
}