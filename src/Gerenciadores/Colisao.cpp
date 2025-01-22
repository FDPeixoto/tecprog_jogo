#include "Colisao.hpp"

/*Codigo dos gerenciadores foi inspirado pelo monitor Giovani https://github.com/Giovanenero/JogoPlataforma2D-Jungle/blob/main/Jungle%2B%2B/src/Gerenciador/GerenciadorColisao.cpp */
namespace Gerenciadores{
    Colisao* Colisao::pColisao = nullptr;
    Colisao::Colisao()
    {
    }
    Colisao::~Colisao()
    {
    }
    Colisao *Colisao::getGerenciadorColisao()
    {
        if (pColisao == nullptr){
            pColisao = new Colisao();
        }
        return pColisao;
    }
    void Colisao::setListaEntidades(Listas::ListaEntidades *entidades)
    {
        listaDeEntidades = entidades;
    }
    const sf::Vector2f Colisao::calculaColisao(Entidades::Entidade *entidade1, Entidades::Entidade *entidade2) 
    {
        sf::Vector2f pos1 = entidade1->getPos();
        sf::Vector2f pos2 = entidade2->getPos();

        sf::Vector2f tam1 = entidade1->getTam();
        sf::Vector2f tam2 = entidade2->getTam();
        
        sf::Vector2f distanciaEntreCentros(
            fabs((pos1.x + tam1.x/2.0f) - (pos2.x + tam2.x/2.0f)),
            fabs((pos1.y + tam1.y/2.0f) - (pos2.y + tam2.y/2.0f))
        );
        sf::Vector2f somaMetadeRectangulo(tam1.x/2.0f + tam2.x/2.0f, tam1.y/2.0f + tam2.y/2.0f);
        return sf::Vector2f(distanciaEntreCentros.x - somaMetadeRectangulo.x, distanciaEntreCentros.y - somaMetadeRectangulo.y);
    }
    void Colisao::executar(){
        Listas::Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* pElem1 = nullptr;
        Listas::Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* pElem2 = nullptr;
        Entidades::Entidade* pEnt1 = nullptr;
        Entidades::Entidade* pEnt2 = nullptr;
        pElem1 = listaDeEntidades->getListaEnt()->getPrimeiro();
        while (pElem1 != nullptr){
            pEnt1 = pElem1->getInfo();
            pElem2 = pElem1->getProx();
            while(pElem2 != nullptr){
                pEnt2 = pElem2->getInfo();
                sf::Vector2f distanciaEntreEntidades = calculaColisao(pEnt1, pEnt2);
                sf::FloatRect intersec = pEnt1->getCorpo().getGlobalBounds();
                
                if(intersec.intersects(pEnt2->getCorpo().getGlobalBounds())){
                    pEnt1->colisao(pEnt2, distanciaEntreEntidades);
                }
                pElem2 = pElem2->getProx();
            }
            
            pElem1 = pElem1->getProx();
        }
    }
}


