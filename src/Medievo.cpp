#include "../include/Medievo.hpp"
#include "Entidades/Entidade.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>


namespace Personagens{
  Jogador::Jogador(): Entidade(), pontos(0), numero_baixas(0), espada (false), magia (false), antidoto (false) 
  {
        retangulo.setSize(sf::Vector2f(50.f, 50.f));
        retangulo.setFillColor(sf::Color::Blue);
        retangulo.setPosition(x, y);
        velocidadeY = 0.f;
        noChao = false;
        pulando = false;
        puloForca= -std::sqrt(2 * 500.f * 2 * 50.f);//500.f eh a gravidade
  }
  Jogador::~Jogador(){}
  void Jogador::setTeclas( sf::Keyboard::Key esquerda, sf::Keyboard::Key direita, sf::Keyboard::Key pulo){
    teclaEsquerda=esquerda;
    teclaDireita=direita;
    teclaPulo=pulo;
  }
  void Jogador::atualizar(float deltaTime, bool& noChao, sf::RectangleShape& plataforma, float gravidade) {
        velocidadeY += gravidade * deltaTime;
        retangulo.move(0.f, velocidadeY * deltaTime);

        if (retangulo.getPosition().y + retangulo.getSize().y >= plataforma.getPosition().y) {
            retangulo.setPosition(retangulo.getPosition().x, plataforma.getPosition().y - retangulo.getSize().y);
            velocidadeY = 0.f;
            noChao = true;
            pulando = false;
        }

        if (sf::Keyboard::isKeyPressed(teclaEsquerda) && retangulo.getPosition().x > 0.f)
            retangulo.move(-200.f * deltaTime, 0.f);
        if (sf::Keyboard::isKeyPressed(teclaDireita) && retangulo.getPosition().x + retangulo.getSize().x < 800.f)
            retangulo.move(200.f * deltaTime, 0.f);

        if (sf::Keyboard::isKeyPressed(teclaPulo) && (noChao || !pulando)) {
            velocidadeY = puloForca;
            noChao = false;
            pulando = !noChao;
        }
    }

    void Jogador::desenhar(sf::RenderWindow& window) {
        window.draw(retangulo);
    }
    /*void Jogador::setCor(sf::Color& c){
      cor=c;
      getRetangulo().setFillColor(c);
    }*/

    sf::RectangleShape& Jogador::getRetangulo() {
        return retangulo;
    }

  void Jogador::salvarDataBuffer(){}
  void Jogador::mover(){}
  void Jogador::executar() {}
  void Jogador::salvar(){}
 }
  void Personagens::Jogador::setCor(sf::Color c)
 {
     cor=c;
      getRetangulo().setFillColor(c);
 }

 Entidade::Entidade(): Ente() {}
  Entidade::~Entidade(){}
  void Entidade::setX(float pos){
    x=pos;
  }
  void Entidade::setY(float pos){
    y=pos;
  }
  void Entidade::executar() {}
  void Entidade::salvar() {}
  void Entidade::salvarDataBuffer(){}

    float Medievo::distance(const sf::Vector2f& a, const sf::Vector2f& b) {
            return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
    Medievo::Medievo(): pJog1(nullptr),pJog2(nullptr){

/*class Inimigo {
public:
    Inimigo(float x, float y, float velocidade, float gravidade) : velocidade(velocidade), gravidade(gravidade) {
        retangulo.setSize(sf::Vector2f(50.f, 50.f));
        retangulo.setFillColor(sf::Color::Red);
        retangulo.setPosition(x, y);
        velocidadeY = 0.f;
    }

    void atualizar(float deltaTime, Jogador& jogador1, Jogador& jogador2, sf::RectangleShape& plataforma) {
        float dist1 = distance(retangulo.getPosition(), jogador1.getRetangulo().getPosition());
        float dist2 = distance(retangulo.getPosition(), jogador2.getRetangulo().getPosition());
        Jogador& alvo = (dist1 < dist2) ? jogador1 : jogador2;

        sf::Vector2f direcao = alvo.getRetangulo().getPosition() - retangulo.getPosition();
        float comprimento = std::sqrt(direcao.x * direcao.x + direcao.y * direcao.y);
        if (comprimento != 0.f) {
            direcao /= comprimento;
        }
        retangulo.move(direcao.x * velocidade * deltaTime, direcao.y * velocidade * deltaTime);

        velocidadeY += gravidade * deltaTime;
        retangulo.move(0.f, velocidadeY * deltaTime);

        if (retangulo.getPosition().y + retangulo.getSize().y >= plataforma.getPosition().y) {
            retangulo.setPosition(retangulo.getPosition().x, plataforma.getPosition().y - retangulo.getSize().y);
            velocidadeY = 0.f;
        }
    }

    void desenhar(sf::RenderWindow& window) {
        window.draw(retangulo);
    }

    sf::RectangleShape& getRetangulo() {
        return retangulo;
    }

private:
    sf::RectangleShape retangulo;
    float velocidade;
    float gravidade;
    float velocidadeY;
};*/

    sf::RenderWindow window(sf::VideoMode(800, 600), "Jogadores");

    const float gravidade = 500.f;
    //const float puloForca = -std::sqrt(2 * gravidade * 2 * 50.f);

    Personagens::Jogador* jogador1=new Personagens::Jogador();
    jogador1->setX(375.f);
    jogador1->setY(475.f);
    jogador1->setTeclas(sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Up);

    Personagens::Jogador* jogador2=new Personagens::Jogador();
    jogador2->setX(200.f);
    jogador2->setY(475.f);
    jogador2->setTeclas(sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::W);

    jogador2->setCor(sf::Color::Yellow);
    
    pJog1=jogador1;
    pJog2=jogador2;
    //Inimigo inimigo(100.f, 100.f, 50.f, gravidade);

    sf::RectangleShape plataforma(sf::Vector2f(800.f, 50.f));
    plataforma.setFillColor(sf::Color::Green);
    plataforma.setPosition(0.f, 550.f);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        bool noChaoAzul = false;
        bool noChaoAmarelo = false;

        jogador1->atualizar(deltaTime, noChaoAzul, plataforma, gravidade);
        jogador2->atualizar(deltaTime, noChaoAmarelo, plataforma, gravidade);

        //inimigo.atualizar(deltaTime, jogadorAzul, jogadorAmarelo, plataforma);

        window.clear();
        window.draw(plataforma);
        jogador1->desenhar(window);
        jogador2->desenhar(window);
        //inimigo.desenhar(window);
        window.display();
    }
    }
    Medievo::~Medievo(){
        if(pJog1){
            delete(pJog1);
        }
        if(pJog2){
            delete(pJog2);
        }
        pJog1=nullptr;
        pJog2=nullptr;
    }
    void Medievo::setJog(Personagens::Jogador* p, int num){
        if(p!=nullptr){
            if(num==1){
                pJog1=p;
            }
            else if(num==2){
                pJog2=p;
            }
            else{
                std::cout<<"Numero nao eh valido para incializar ponteiro de jogador"<<std::endl;
            }
        }
    }


