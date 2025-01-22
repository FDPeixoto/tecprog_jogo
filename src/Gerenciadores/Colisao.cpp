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
    void Colisao::setMoveis(Listas::ListaEntidades *moveis)
    {
        listaMoveis = moveis;
    }
    void Colisao::setFixos(Listas::ListaEntidades *fixos)
    {
        listaFixos = fixos;
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
        for(Listas::Lista<Entidades::Entidade*>::Iterator it1 = listaMoveis->getListaEnt().inicio(); it1 != listaMoveis->getListaEnt().fim(); ++it1){
            if(it1 != nullptr){
                for(Listas::Lista<Entidades::Entidade*>::Iterator it2 = listaMoveis->getListaEnt().inicio(); it2 != listaMoveis->getListaEnt().fim(); ++it2){
                    if(it2 != nullptr){
                        if(it2 != it1){
                            if((*(*it1))->getCorpo().getGlobalBounds().intersects((*(*it2))->getCorpo().getGlobalBounds())){
                                (*(*it1))->colisao(*(*it2));
                            }
                        }
                    }
                }
            }
        }
        for(Listas::Lista<Entidades::Entidade*>::Iterator it1 = listaMoveis->getListaEnt().inicio(); it1 != listaMoveis->getListaEnt().fim(); ++it1){
            if(it1 != nullptr){
                for(Listas::Lista<Entidades::Entidade*>::Iterator it2 = listaFixos->getListaEnt().inicio(); it2 != listaFixos->getListaEnt().fim(); ++it2){
                    if(it2 != nullptr){
                        if(it2 != it1){
                            if((*(*it1))->getCorpo().getGlobalBounds().intersects((*(*it2))->getCorpo().getGlobalBounds())){
                                (*(*it1))->colisao(*(*it2));
                            }
                        }
                    }
                }
            }
        }
    }
}


