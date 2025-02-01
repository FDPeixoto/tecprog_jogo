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
    Listas::ListaEntidades *Colisao::getListaMoveis()
    {
        return listaMoveis;
    }
    Listas::ListaEntidades *Colisao::getListaFixos()
    {
        return listaFixos;
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

    bool Colisao::checarColisao(Entidades::Entidade *entidade1, Entidades::Entidade *entidade2) {
        return entidade1->getCorpo().getGlobalBounds().intersects(entidade2->getCorpo().getGlobalBounds());
    }
    void Colisao::executar(){
        for(Listas::Lista<Entidades::Entidade>::Iterator it1 = listaMoveis->getListaEnt().inicio(); it1 != listaMoveis->getListaEnt().fim(); it1++){
            if(*it1 != nullptr){
                for(Listas::Lista<Entidades::Entidade>::Iterator it2 = listaMoveis->getListaEnt().inicio(); it2 != listaMoveis->getListaEnt().fim(); it2++){
                    if(*it2 != nullptr){
                        if(it1 != it2){
                            if(checarColisao(*it1, *it2)){
                                (*it1)->colisao(*it2);
                            }
                        }
                    }
                }
            }
        }

        for(Listas::Lista<Entidades::Entidade>::Iterator it1 = listaMoveis->getListaEnt().inicio(); it1 != listaMoveis->getListaEnt().fim(); it1++){
            if(*it1 != nullptr){
                for(Listas::Lista<Entidades::Entidade>::Iterator it2 = listaFixos->getListaEnt().inicio(); it2 != listaFixos->getListaEnt().fim(); it2++){
                    if(*it2 != nullptr){
                        if(checarColisao(*it1, *it2)){
                                (*it1)->colisao(*it2);
                        }
                    }
                }
            }
        }
        /*for(Listas::Lista<Entidades::Entidade>::Iterator it1 = listaMoveis->getListaEnt().inicio(); it1 != listaMoveis->getListaEnt().fim(); it1++){
            if(*it1 != nullptr){
                if(((*it1)->getID()==IDJOGADOR)&& ((*it1)->getAtacando()==true))
                for(Listas::Lista<Entidades::Entidade>::Iterator it2 = listaMoveis->getListaEnt().inicio(); it2 != listaMoveis->getListaEnt().fim(); it2++){
                    if(*it2 != nullptr){
                        if((*it2)->getID()==IDINIMIGO){
                            //sf::Vector2f dist(fabs(*it2)->getPos()-(*it1)->getPos());
                            //float dist_x=fabs((*it2)
                            sf::Vector2f dist = ((*it2)->getPos() - (*it1)->getPos());
                            dist.x = std::fabs(dist.x);  // Aplica o valor absoluto no componente x
                            dist.y = std::fabs(dist.y);  // Aplica o valor absoluto no componente y
                            if((it1 != it2)&&(dist.x<=RAIO_ATAQUE)){
                                (*it2)->setVivo(false);
                            }
                        }
                    }
                }
            }
        }*/
        for (Listas::Lista<Entidades::Entidade>::Iterator it1 = listaMoveis->getListaEnt().inicio(); it1 != listaMoveis->getListaEnt().fim(); it1++) {
            if (*it1 != nullptr) {
                if (((*it1)->getID() == IDJOGADOR) && ((*it1)->getAtacando() == true)) {
                    for (Listas::Lista<Entidades::Entidade>::Iterator it2 = listaMoveis->getListaEnt().inicio(); it2 != listaMoveis->getListaEnt().fim(); it2++) {
                        if (*it2 != nullptr) {
                            if ((*it2)->getID() == IDINIMIGO) {
                                sf::Vector2f dist = (*it2)->getPos() - (*it1)->getPos();
                                dist.y = 0; // Ignora a componente Y

                                // Agora você está verificando apenas a distância no eixo X
                                if ((*it1)->getID() != (*it2)->getID() && std::fabs(dist.x) <= RAIO_ATAQUE) {
                                    (*it2)->setVivo(false); // Destrói o inimigo
                                }
                            }
                        }
                    }
                }
            }
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
                            sender->setCor(sf::Color::Red);
                        }
                    }
                }
            }
       }
    }
}
