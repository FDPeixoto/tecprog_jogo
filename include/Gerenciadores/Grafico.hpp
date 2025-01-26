#pragma once

#include "Matematica/CoordTL.h"
#include <SFML/Graphics.hpp>
#include "../../include/Listas/ListaEntidades.hpp"
#include "../../include/Listas/Lista.hpp"
#include "Entidade.hpp"
#include "Entidades/Personagens/Jogador.hpp"

#include <map>
#include <Personagem.hpp>

namespace Gerenciadores{
    class Grafico{
        private:
            sf::RenderWindow* janela;
            sf::View panorama;   

            //Singleton    
            static Grafico* pGrafico;
            Grafico();
        public:
            ~Grafico();
            static Grafico* getGerenciadorGrafico();
            sf::RenderWindow* getJanela();
            void limparJanela();
            void redimensionarJanela();
            void mostrarJanela();
            void fecharJanela();
            void desenharCorpo(sf::RectangleShape corpo);
            void desenharListaEntidades(Listas::ListaEntidades *listaMoveis, Listas::ListaEntidades *listaFixos);
    };
}