#include "MenuInicialState.hpp"

namespace States
{
    namespace Menus
    {
        MenuInicialState::MenuInicialState() : MenuState(IDMENUINICIALSTATE)
        {
            inicializarTitulo("Medievo++", 80);

            Botao *botao1 = new Botao(1, "[1] - Pantano_Maldito 1 Jogador", []()
                                      { std::cout << "Start pressed!" << std::endl; }, {LARGURA_JANELA / 2.0f - 200.f, ALTURA_JANELA / 2.0f - 50.f}, {400, 50});
            Botao *botao2 = new Botao(2, "[2] - Pantano_Maldito 2 Jogadores", []()
                                      { std::cout << "Options pressed!" << std::endl; }, {LARGURA_JANELA / 2.0f - 200.f, ALTURA_JANELA / 2.0f + 100.f - 50.f}, {400, 50});
            Botao *botao3 = new Botao(3, "[3] - Castelo_Assombrado 1 Jogador", []()
                                      { std::cout << "Exit pressed!" << std::endl; }, {LARGURA_JANELA / 2.0f - 200.f, ALTURA_JANELA / 2.0f + 200.f - 50.f}, {400, 50});
            Botao *botao4 = new Botao(3, "[4] - Castelo_Assombrado 2 Jogadores", []()
                                      { std::cout << "Exit pressed!" << std::endl; }, {LARGURA_JANELA / 2.0f - 200.f, ALTURA_JANELA / 2.0f + 300.f - 50.f}, {400, 50});

            botoes.push_back(botao1);
            botoes.push_back(botao2);
            botoes.push_back(botao3);
            botoes.push_back(botao4);
        }
    }
}