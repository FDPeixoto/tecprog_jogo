#include "Evento.hpp"

namespace Gerenciadores{
    Evento* Evento::pGerenciadorEvento = nullptr;

    Evento::Evento(): pJog1(nullptr), pJog2(nullptr), pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()), pEstado(pEstado->getGerenciadorEstado()){}
    Evento::~Evento(){
        pGerenciadorGrafico = nullptr;
        //pEstado = nullptr;
        pJog1 = nullptr;
        pJog2 = nullptr;
    }

    Evento *Evento::getGerenciadorEvento()
    {
        if(pGerenciadorEvento == nullptr){
            pGerenciadorEvento = new Evento();
        }
        return pGerenciadorEvento;
    }

    void Evento::setJogador1(Entidades::Jogador* jogador){
        pJog1 = jogador;
    }
    void Evento::setJogador2(Entidades::Jogador* jogador){
        pJog2 = jogador;
    }


    void Evento::verificaTeclaPressionada(sf::Keyboard::Key tecla){
        if(tecla==sf::Keyboard::A){
            if(pJog2 != nullptr){pJog2->andar(true);}
        }
        else if(tecla==sf::Keyboard::D){
            if(pJog2 != nullptr){pJog2->andar(false);}
        }
        else if(tecla==sf::Keyboard::W){
            if(pJog2 != nullptr){pJog2->pular();}
        }
        else if(tecla==sf::Keyboard::Left){
            if(pJog1 != nullptr){pJog1->andar(true);}
        }
        else if(tecla==sf::Keyboard::Right){
            if(pJog1 != nullptr){pJog1->andar(false);}
        }
        else if(tecla==sf::Keyboard::Up){
            if(pJog1 != nullptr){pJog1->pular();}
        }
        else if(tecla==sf::Keyboard::M){
            if(pJog1 != nullptr){pJog1->setAtacando(true);}
        }
        else if(tecla==sf::Keyboard::S){
            if(pJog2 != nullptr){pJog2->setAtacando(true);}
        }
        else if(tecla==sf::Keyboard::Escape){
            pEstado->removerState();
        }
        else if(tecla ==sf::Keyboard::Num1){
            pEstado->addState(IDCASTELOASSOMBRADO);
        }
        else if(tecla ==sf::Keyboard::Num2){
            pEstado->addState(IDPANTANOMALDITO);
        }
    }

    void Evento::verificaTeclaSolta(sf::Keyboard::Key tecla){
        if( (tecla==sf::Keyboard::A)||(tecla==sf::Keyboard::D)){
            if(pJog2 != nullptr){pJog2->parar();}
        }
        if(tecla==sf::Keyboard::S){
            if(pJog2 != nullptr){pJog2->setAtacando(false);}
        }
        if( (tecla==sf::Keyboard::Left)||(tecla==sf::Keyboard::Right)){
            if(pJog1 != nullptr){pJog1->parar();}
        }
        if(tecla==sf::Keyboard::M){
            if(pJog1 != nullptr){pJog1->setAtacando(false);}
        }
    }
    void Evento::executar(){
        sf::Event evento;
        while(pGerenciadorGrafico->getJanela()->pollEvent(evento)){
            if(evento.type == sf::Event::KeyPressed){
                verificaTeclaPressionada(evento.key.code);
            }
            else if(evento.type==sf::Event::KeyReleased){
                verificaTeclaSolta(evento.key.code);
            }
            else if(evento.type==sf::Event::Closed){
                pGerenciadorGrafico->fecharJanela();
            }
        }
    }
    
}
    
    