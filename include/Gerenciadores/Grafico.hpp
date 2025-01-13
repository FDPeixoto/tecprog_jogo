#pragma once

#include "Matematica/CoordTL.h"
#include <SFML/Graphics.hpp>
#include "../../include/Listas/ListaEntidades.hpp"
#include "../../include/Listas/Lista.hpp"

#include <map>

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
            static Grafico* getGerenciadorGrafico(){
                if(pGrafico == nullptr){
                    return new Grafico();
                }
            }
            sf::RenderWindow* getJanela();
            void limparJanela();
            void redimensionarJanela();
            void mostrarJanela();
            void desenharEntidade(sf::RectangleShape corpo);
            void desenharListaEntidades(Listas::ListaEntidades *listaDeEntidades);

    };
}