#include "MenuInicialState.hpp"

namespace States
{
    namespace Menus
    {
        MenuInicialState::MenuInicialState() : MenuState(IDMENUINICIALSTATE)
        {

            Botao *botao1 = new Botao(1, "Start", []()
                                      { std::cout << "Start pressed!" << std::endl; }, {LARGURA_JANELA / 2.0f - 100.f, ALTURA_JANELA / 2.0f - 50.f}, {200, 50});
            Botao *botao2 = new Botao(2, "Options", []()
                                      { std::cout << "Options pressed!" << std::endl; }, {LARGURA_JANELA / 2.0f - 100.f, ALTURA_JANELA / 2.0f + 100.f - 50.f}, {200, 50});
            Botao *botao3 = new Botao(3, "Exit", []()
                                      { std::cout << "Exit pressed!" << std::endl; }, {LARGURA_JANELA / 2.0f - 100.f, ALTURA_JANELA / 2.0f + 200.f - 50.f}, {200, 50});

            botoes.push_back(botao1);
            botoes.push_back(botao2);
            botoes.push_back(botao3);
        }
    }
}