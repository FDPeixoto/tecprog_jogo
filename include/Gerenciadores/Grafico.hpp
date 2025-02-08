#pragma once

#include <SFML/Graphics.hpp>
#include "../../include/Listas/ListaEntidades.hpp"
#include "../../include/Listas/Lista.hpp"
#include "Entidade.hpp"
#include "Entidades/Personagens/Jogador.hpp"

#include <list>
#include <map>
#include <Personagem.hpp>

#include <fstream>
#include <vector>
#include <string>

namespace Gerenciadores
{
    class Grafico
    {
    private:
        sf::RenderWindow *janela;
        sf::View panorama;
        sf::Clock relogio;
        sf::Font fonte;

        // Singleton
        static Grafico *pGrafico;
        Grafico();

    public:
        ~Grafico();
        static Grafico *getGerenciadorGrafico();
        sf::RenderWindow *getJanela();
        void limparJanela();
        void redimensionarJanela();
        void mostrarJanela();
        void fecharJanela();
        sf::Clock *getRelogio();
        void desenharCorpo(sf::RectangleShape corpo);
        void desenharTexto(sf::Text texto, sf::Vector2f posicao);
        void desenharEntidade(Entidades::Entidade *entidade);
        void desenharList(std::list<Entidades::Entidade *> &list);
        void desenharListaEntidades(Listas::ListaEntidades *lista);
        void setRelogio(sf::Clock *clock);
        void resetarRelogio();
        void mostrarRanking();
        void setView(sf::View view);
        sf::Font getFonte();
    };
}
