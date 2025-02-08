#include "PauseState.hpp"

namespace States
{
    namespace Menus
    {
        PauseState::PauseState() : MenuState(IDPAUSESTATE)
        {
            inicializarTitulo("Pause", 60);
            Botao *botao1 = new Botao(1, "Retomar", []()
                                      { std::cout << "Start pressed!" << std::endl; }, {LARGURA_JANELA / 2.0f - 100.f, ALTURA_JANELA / 2.0f - 50.f}, {200, 50});
            Botao *botao2 = new Botao(2, "Sair", []()
                                      { std::cout << "Options pressed!" << std::endl; }, {LARGURA_JANELA / 2.0f - 100.f, ALTURA_JANELA / 2.0f + 100.f - 50.f}, {200, 50});

            botoes.push_back(botao1);
            botoes.push_back(botao2);
        }
    }
}