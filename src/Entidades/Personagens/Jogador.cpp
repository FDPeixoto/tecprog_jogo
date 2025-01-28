#include "Jogador.hpp"
#include "stdafx.h"
 

 namespace Entidades{
    Jogador::Jogador(const sf::Vector2f posicao, bool jogador2): 
        Personagem(sf::Vector2f(JOGADORLARGURA, JOGADORALTURA), posicao, IDJOGADOR),
        pontos(0), numero_baixas(0), espada (false), magia (false), antidoto (false), ehJogador2(ehJogador2)
    {
        if(jogador2){
            setCor(sf::Color::Green);
        }
        else{
            setCor(sf::Color::Blue);
        }
        setVelocidade(sf::Vector2f(0.f, 0.f));
    }

    Jogador::~Jogador() {}

    void Jogador::atualizar(float dt){
        //ou float dt=relogio.getElapsedTime().asSeconds();
        //Andando só na horizontal por enquanto
        float ds = velocidade.x * dt;//ou velocidadeFinal.x
        corpo.move(ds, 0.f);
    }

    void Jogador::andar(const bool ehEsquerda){
        atacando = false;
        andando = true;
        paraEsquerda = ehEsquerda;
        if(paraEsquerda){
            velocidade.x = -500.0f;
        }
        else{
            velocidade.x = 500.f;
        }
    }
    void Jogador::parar(){
        andando = false;
        velocidade.x = 0.0f;
    }
    const bool Jogador::getAndando() const{
        return andando;
    }


    void Jogador::salvarDataBuffer(){}

    void Jogador::executar() { }
    
    void Jogador::salvar(){}

    void Jogador::colisao(Entidade *outraEntidade)
    {
        int id = outraEntidade->getID();
        sf::Vector2f overlap(
                getCorpo().getGlobalBounds().left + getCorpo().getGlobalBounds().width - outraEntidade->getCorpo().getGlobalBounds().left,
                getCorpo().getGlobalBounds().top + getCorpo().getGlobalBounds().height - outraEntidade->getCorpo().getGlobalBounds().top
                );
        switch (id){
            case IDOBSTACUlO:
                setPos(sf::Vector2f (getCorpo().getPosition().x, outraEntidade->getCorpo().getPosition().y - getCorpo().getSize().y));
                velocidade.y = 0;
                break;
            case IDINIMIGO: 
                if (std::abs(overlap.x) > std::abs(overlap.y)) {
                    if (overlap.y > 0)
                        outraEntidade->setPos(sf::Vector2f(outraEntidade->getCorpo().getPosition().x, getCorpo().getPosition().y + getCorpo().getSize().y));
                    else
                        outraEntidade->setPos(sf::Vector2f(outraEntidade->getCorpo().getPosition().x, getCorpo().getPosition().y - outraEntidade->getCorpo().getSize().y));
                } else {
                    if (overlap.x > 0)
                        outraEntidade->setPos(sf::Vector2f(getCorpo().getPosition().x + getCorpo().getSize().x, outraEntidade->getCorpo().getPosition().y));
                    else
                        outraEntidade->setPos(sf::Vector2f(getCorpo().getPosition().x - outraEntidade->getCorpo().getSize().x, outraEntidade->getCorpo().getPosition().y));
                }
                break;
            default:
                break;
        }
    }
    void Jogador::inicializar()
    {
        return;
    }
}
