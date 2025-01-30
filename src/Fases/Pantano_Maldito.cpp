#include "Pantano_Maldito.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#define TAM_JOGADORX 50.0f
#define TAM_JOGADORY 100.0f

namespace Fases{
    Pantano_Maldito::Pantano_Maldito(): Fase(), maxInimMedios(5),pD(nullptr)
    {
        criarMapa();
    }

    Pantano_Maldito::~Pantano_Maldito(){
        pD=nullptr;
    }

    void Pantano_Maldito::criarInimMedio(const sf::Vector2f posicao)
    {
        Entidades::Inimigos::Esqueleto* esqueleto = new Entidades::Inimigos::Esqueleto(posicao);
        if(esqueleto != nullptr){
            esqueleto->setCor(sf::Color::Cyan);
            //if(Fase::getJogador1() != nullptr){esquelto->setJogador1(getJogador1());}
            //if(Fase::getJogador2() != nullptr){esqueleto->setJogador2(getJogador2());}
            listaPersonagens->incluirEntidade(esqueleto);
        }

    }
    void Pantano_Maldito::criarInimDificil(const sf::Vector2f posicao)
    {
        Entidades::Inimigos::Durahan* durahan = new Entidades::Inimigos::Durahan(posicao);
        if(durahan != nullptr){
            pD=durahan;
            durahan->setCor(sf::Color::Magenta);
            if(Fase::getJogador1() != nullptr){durahan->setJogador1(getJogador1());}
            if(Fase::getJogador2() != nullptr){durahan->setJogador2(getJogador2());}
            listaPersonagens->incluirEntidade(durahan);
            //num_Durahan++; lemnrando que isso está em fase
        }

    }
    void Pantano_Maldito::setpD(Entidades::Inimigos::Durahan* pDurahan){
        pD=pDurahan;
    }
    Entidades::Inimigos::Durahan* Pantano_Maldito::getpD(){
        return pD;
    }
    void Pantano_Maldito::criarInimigos()
    {
        //criarInimFaceis();
        //criarInimMedios();
    }
    void Pantano_Maldito::criarObstaculos()
    {
        //criarObstFaceis();
    }

    const int Pantano_Maldito::getMaxInimMedios(){return maxInimMedios;}

    void Pantano_Maldito::criarMapa()
    {
        //criarJogador(sf::Vector2f(0.0f, 0.0f));
        //criarJogador(sf::Vector2f(200.0f, 0.0f));
        criarBordaH(sf::Vector2f(0.0f, 0.0f), sf::Color::Yellow);
        criarBordaH(sf::Vector2f(1270.0f, 0.0f), sf::Color::Yellow);
        criarBordaV(sf::Vector2f(0.0f, 0.0f), sf::Color::Yellow);
        criarBordaV(sf::Vector2f(0.0f,710.0f), sf::Color::Yellow);

        criarPlataformaBase(sf::Vector2f(0.0f,660));
        //Está ao contrário as funções BordaV cria Horizontal e BordaH, vertical
        
        std::ifstream arquivo;
        std::string linha;
        arquivo.open("src/Fases/TestePrimeiraFase.txt");
        if(!arquivo.is_open()){
            std::cout<<"NAo abriu o arquivo .txt Pantano_Maldito"<<std::endl;
            exit(1);
        }
        int j=0;
        while(std::getline(arquivo,linha)){
            for(int i=0; i<linha.size();i++){
                if(linha[i]!=' '){
                    criarEntidade(linha[i],sf::Vector2f(i,j));
                }
            }
            j++;
        }arquivo.close();

        //Pega a lista de porjétil que tem no Durahan
        //
        
    }
    void Pantano_Maldito::executar(){
        Fase::executar();
        if(pD!= nullptr){
            pGerenciadorGrafico->desenharList(pD->getListaProjetil());
        }
    }
    
    void Pantano_Maldito::criarEntidade(char letra, const sf::Vector2f posicao){
        switch(letra){
            case('j'):{
                criarJogador(sf::Vector2f(posicao.x*TAM_JOGADORX, posicao.y*TAM_JOGADORX));
            }break;
            case('m'):{
                criarMinion(sf::Vector2f(posicao.x*TAM_JOGADORX, posicao.y*TAM_JOGADORX));
            }break;
            case('e'):{
                criarInimMedio(sf::Vector2f(posicao.x*TAM_JOGADORX, posicao.y*TAM_JOGADORX));
            }break;
            case('d'):{
                criarInimDificil(sf::Vector2f(posicao.x*TAM_JOGADORX, posicao.y*TAM_JOGADORX));
            }break;
            case('b'):{
                criarPlataforma(sf::Vector2f(posicao.x*TAM_JOGADORX, posicao.y*TAM_JOGADORX));
            }break;
            case('s'):{
                criarEspinho(sf::Vector2f(posicao.x*TAM_JOGADORX, posicao.y*TAM_JOGADORX));
            }break;
            case('c'):{
                criarCanhao(sf::Vector2f(posicao.x*TAM_JOGADORX, posicao.y*TAM_JOGADORX));
            }break;
        }
    }

}


/*float x=posicao.x*TAM_JOGADORX;
                float y=posicao.y*TAM_JOGADORY;
                criarJogador(sf::Vector2f(x,y));*/
                /*criarJogador(sf::Vector2f(posicao.x*TAM_JOGADORX, posicao.y*TAM_JOGADORY));*/
