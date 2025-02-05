#pragma once

#include <SFML/Graphics.hpp>
#include "../../include/Listas/ListaEntidades.hpp"
#include "../../include/Listas/Lista.hpp"
#include "Entidade.hpp"
#include "Entidades/Personagens/Jogador.hpp"

#include <list>
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
            void desenharList(std::list<Entidades::Entidade*>& list);
            void desenharListaEntidades(Listas::ListaEntidades *lista);
            void setRelogio(sf::Clock *clock);
            void resetarRelogio();
    };
}

class Botao {
private:
    sf::RectangleShape forma;
    sf::Text texto;
    float Posx; float Posy;

public:
    Botao(float x, float y, float largura, float altura, const std::string& rotulo, const sf::Font& fonte) {
        forma.setSize(sf::Vector2f(largura, altura));
        forma.setPosition(x, y);
        forma.setFillColor(sf::Color::Green);
        Posx=x;
        Posy=y;
       /* texto.setFont(fonte);
        texto.setString(rotulo);
        texto.setCharacterSize(24);
        texto.setFillColor(sf::Color::White);
        texto.setPosition(x + 10, y + 10);*/
    }

    bool foiClicado(const sf::RenderWindow* janela) {
    // Verifica se a janela não é nula antes de tentar acessar seus membros
    if (janela == nullptr) {
        return false;  // Caso a janela seja nula, retorna falso (não houve clique)
    }
    
    sf::Vector2i posicaoMouse = sf::Mouse::getPosition(*janela);  // Acessa a posição do mouse com o ponteiro
    return forma.getGlobalBounds().contains(static_cast<sf::Vector2f>(posicaoMouse)) &&
           sf::Mouse::isButtonPressed(sf::Mouse::Left);  // Verifica se o botão esquerdo está pressionado
    }

void setFonte( const std::string& rotulo, const sf::Font& fonte){
        texto.setFont(fonte);
        texto.setString(rotulo);
        texto.setCharacterSize(24);
        texto.setFillColor(sf::Color::White);
        texto.setPosition(Posx + 10, Posy + 10);
    }

    void desenhar(sf::RenderWindow* janela) {
        if (janela != nullptr) {  // Verifica se o ponteiro não é nulo
            janela->draw(forma);  // Desenha a forma usando o ponteiro
            janela->draw(texto);  // Desenha o texto usando o ponteiro
        }
    }

};