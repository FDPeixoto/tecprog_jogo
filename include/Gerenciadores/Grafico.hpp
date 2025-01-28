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
            sf::Clock relogio;

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
            sf::Clock *getRelogio();
            void desenharCorpo(sf::RectangleShape corpo);
            void desenharTexto(sf::Text texto);
            void desenharEntidade(Entidades::Entidade *entidade);
            void desenharListaEntidades(Listas::ListaEntidades *lista);
            void setRelogio(sf::Clock *clock);
            void resetarRelogio();
    };
}