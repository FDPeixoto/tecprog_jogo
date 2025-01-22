#include "Evento.hpp"
    /*Evento* GerenciadorEvento::pGerenciadorEvento = nullptr;
    Grafico* GerenciadorEvento::pGerenciadorGrafico = Grafico::getGerenciadorGrafico();
    Estado* GerenciadorEvento::pGerenciadorEstado = Estado::getGerenciadorEstado();*/
Gerenciadores::Evento::Evento(){
    pGerenciadorGrafico=getGerenciadorGrafico();

}
Gerenciadores::Evento::~Evento(){
    pGerenciadorGrafico=nullptr;
    jog1=nullptr;
    jog2=nullptr;

}
void Gerenciadores::Evento::setJogador1(Entidades::Jogador jog){
    jog1=jog;
}
void Gerenciadores::Evento::setJogador2(Entidades::Jogador jog){
    jog2=jog;
}
void Gerenciadores::Evento::verificaTeclaPressionada(sf::Keyboard::Key tecla){
    if(tecla==sf::Keyboard::A){
        jog2->andar(true);//esta indo para a esquerda
    }
    else if(tecla==sf::Keyboard::D){
        jog2->andar(false);
    }
    else if(tecla==sf::Keyboard::Left){
        jog1->andar(true);//esta indo para a esquerda
    }
    else if(tecla==sf::Keyboard::Right){
        jog1->andar(false);
    }
    else if(tecla==sf::Keyboard::Escape){
        pGerenciadorGrafico->fecharJanela();
    }
}
void Gerenciadores::Evento::verificaTeclaSolta(sf::Keyboard::Key tecla){
    if( (tecla==sf::Keyboard::A)||(tecla==sf::Keyboard::D)){
        jog2->parar();
    }
    if( (tecla==sf::Keyboard::Left)||(tecla==sf::Keyboard::Right)){
        jog1->parar();
    }
}
void Gerenciadores::Evento:executar(){
    sf::Event evento;
    while(pGerenciadorGrafico->getJanela()->pollEvent(evento)){
        if(evento.type==sf::Event::KeyPressed()){
            verificaTeclaPressionada(evento.key.code);
        }
        else if(evento.type==sf::Event::KeyRelease()){
            verificaTeclaSolta(evento.key.code);
        }
        else if(evento.type==sf::Event::Closed){
            pGerenciadorGrafico->fecharJanela():
        }
    }
}