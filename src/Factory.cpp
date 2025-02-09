#include "Factory.hpp"
Entidades::Entidade* Factory::create(const int id, sf::Vector2f posicao, bool Castelo) {

    if(id == IDPLATAFORMA){
        return new Entidades::Obstaculos::Plataforma(posicao, Castelo);
    }
    else if ( id == IDCAIXA){
        return new Entidades::Obstaculos::Caixa(posicao);
    }
    else if( id == IDESPINHO){
        return new Entidades::Obstaculos::Espinho(posicao);
    }
    if (id == IDMINION) {
        return new Entidades::Inimigos::Minion(posicao); 
    } 
    else if ( id == IDESQUELETO){
        return new Entidades::Inimigos::Esqueleto(posicao);
    }
    else if( id == IDOGRO){
        return new Entidades::Inimigos::Ogro(posicao);
    }
    else {
        // Caso o id não seja reconhecido, você pode retornar nullptr ou lançar uma exceção
        return nullptr;
    }
}