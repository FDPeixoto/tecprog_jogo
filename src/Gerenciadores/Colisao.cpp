#include "Colisao.hpp"
#include <Medievo.hpp>

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
        for (std::vector<Entidades::Entidade*>::iterator it = vectorEntidades.begin(); it != vectorEntidades.end(); ++it) {
            Entidades::Entidade* entidade = *it;
            entidade->verificarColisao();
        }
    }
    void Colisao::registrarEntidade(Entidades::Entidade *entity)
    {
        vectorEntidades.push_back(entity);
    }
    void Colisao::notificar(Entidades::Entidade *sender, const std::string &evento)
    {
        if(evento == "verificarColisao"){
           for (std::vector<Entidades::Entidade*>::iterator it = vectorEntidades.begin(); it != vectorEntidades.end(); ++it) {
                Entidades::Entidade* entidade = *it;{
                    if(sender != entidade){
                        if(sender->getCorpo().getGlobalBounds().intersects(entidade->getCorpo().getGlobalBounds())){
                            sender->colisao(entidade);
                        }
                    }
                }
            }
       }
    }
}
