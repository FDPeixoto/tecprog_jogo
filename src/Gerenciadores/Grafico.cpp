#include <iostream>

#include "../../include/Gerenciadores/Grafico.hpp"
#include "../../include/Entidades/Entidade.hpp"
#include "../../include/Listas/ListaEntidades.hpp"
#include "../../include/Listas/Lista.hpp"
#include "Grafico.hpp"
#define LARGURA 1280
#define ALTURA 720



namespace Gerenciadores{
    Grafico* Grafico::pGrafico = nullptr;
}
Gerenciadores::Grafico::Grafico(): 
    janela(new sf::RenderWindow(sf::VideoMode(LARGURA, ALTURA), "Medievo++")),
    panorama(sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(LARGURA, ALTURA)))
    {}

Gerenciadores::Grafico::~Grafico(){
    if(janela != nullptr){
        delete(janela);
        janela = nullptr;
    }
}

Gerenciadores::Grafico* Gerenciadores::Grafico::getGerenciadorGrafico(){
    if(pGrafico == nullptr){
        pGrafico = new Grafico();
    }
    return pGrafico;
}

sf::RenderWindow* Gerenciadores::Grafico::getJanela(){
    return janela;
}

void Gerenciadores::Grafico::redimensionarJanela (){
    float proporcaoJanela = float(janela->getSize().x) / float(janela->getSize().y);
    panorama.setSize(LARGURA * proporcaoJanela, ALTURA);
}

void Gerenciadores::Grafico::limparJanela(){
    janela->clear();
}

void Gerenciadores::Grafico::mostrarJanela(){
    janela->display();
}

void Gerenciadores::Grafico::desenharCorpo(sf::RectangleShape corpo)
{
    janela->draw(corpo);
}


void Gerenciadores::Grafico::desenharListaEntidades(Listas::ListaEntidades *listaDeEntidades){
    Listas::Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* pEleAux = nullptr;
    Entidades::Entidade* pEntAux = nullptr;
    pEleAux = listaDeEntidades->getListaEnt()->getPrimeiro();
    while (pEleAux != nullptr){
        pEntAux = pEleAux->getInfo();
        desenharCorpo(pEntAux->getCorpo());
        pEleAux = pEleAux->getProx();
    }
}