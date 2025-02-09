#include "Pantano_Maldito.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <exception>

namespace Fases
{

    Pantano_Maldito::Pantano_Maldito(bool temSegundoJogador) : Fase(IDPANTANOMALDITO, temSegundoJogador),fundo(sf::Vector2f(LARGURA_JANELA, ALTURA_JANELA)), maxCaixas(3), it_Caixas(0),maxM(3), it_M(0),maxP(3), it_P(0), maxEsqueletos(3), it_Esqueletos(0), aleatoriedadeP(5)
    {
        fundo.setPosition(0.0f, 0.0f);
        textura.loadFromFile("Texturas/PantanoMaldito.png");
        fundo.setTexture(&textura);
        //Fase::proximaFase();
        srand((unsigned int)time(NULL));
        maxCaixas = (rand() % (3)) + 3;
        srand((unsigned int)time(NULL));
        maxM = (rand() % (3)) + 3;
        srand((unsigned int)time(NULL));
        maxEsqueletos = (rand() % (3)) + 3;
        srand((unsigned int)time(NULL));
        maxP = (rand() % (10)) + 10;
        srand((unsigned int)time(NULL));
        aleatoriedadeP=(rand() % (3))+1;
        
        criarMapa();
    }

    Pantano_Maldito::~Pantano_Maldito()
    {
    }

    void Pantano_Maldito::criarInimMedio(const sf::Vector2f posicao)
    {
        Entidades::Inimigos::Esqueleto *esqueleto = static_cast<Entidades::Inimigos::Esqueleto*>(factory.create(IDESQUELETO, posicao));
        
        if (esqueleto != nullptr)
        {
            if (Fase::getJogador1() != nullptr)
            {
                esqueleto->setJogador1(getJogador1());
            }
            if (Fase::getJogador2() != nullptr)
            {
                esqueleto->setJogador2(getJogador2());
            }
            listaPersonagens->incluirEntidade(esqueleto);
            pGerenciadorColisao->adicionarInimigo(esqueleto);
            esqueleto->setMediator(pGerenciadorColisao);
        }
    }
    void Pantano_Maldito::criarCaixa(const sf::Vector2f posicao)
    {
        Entidades::Obstaculos::Caixa *caixa = static_cast<Entidades::Obstaculos::Caixa*>(factory.create(IDCAIXA, posicao));
        //chamava a construtora assim (posicao + sf::Vector2f(0.f, 16.f))
        if (caixa != nullptr)
        {
            caixa->setMediator(dynamic_cast<Gerenciadores::Mediator *>(pGerenciadorColisao));
            listaObstaculos->incluirEntidade(caixa);
            pGerenciadorColisao->adicionarObstaculo(caixa);
        }
    }

    void Pantano_Maldito::criarMapa()
    {
        std::ifstream arquivo;
        std::string linha;
        
        try
        {
            arquivo.open("src/Fases/TestePrimeiraFase.txt");
 
            int j = 0;
            while (std::getline(arquivo, linha))
            {
                for (int i = 0; i < linha.size(); i++)
                {
                    if (linha[i] != ' ')
                    {
                        criarEntidade(linha[i], sf::Vector2f(i, j));
                    }
                }
                j++;
            }
            
            arquivo.close();
        }
        catch (const std::exception &e)
        {
            return;
        }
    }
    void Pantano_Maldito::executar()
    {
        pGerenciadorGrafico->desenharCorpo(fundo);
        Fase::executar();
        verificarCompletou();
    }

    void Pantano_Maldito::criarEntidade(char letra, const sf::Vector2f posicao)
    {
        srand((unsigned int)time(NULL));
        int mudancaPos = (rand() % (4)) *16;
        switch (letra)
        {
        case ('j'):
        {
            criarJogador(sf::Vector2f(posicao.x * 64.f, posicao.y * 64.f));
        }
        break;
        case ('m'):
        {
            if(it_M < maxM){
            criarMinion(sf::Vector2f((posicao.x * 64.f)+ mudancaPos, posicao.y * 64.f));
            it_M++; 
            srand((unsigned int)time(NULL));
            mudancaPos = (rand() % (4)) *16;
            }
        }
        break;
        case ('e'):
        {
            if(it_Esqueletos < maxEsqueletos){
            criarInimMedio(sf::Vector2f((posicao.x * 64.f) + mudancaPos, posicao.y * 64.f));
            it_Esqueletos++;
            srand((unsigned int)time(NULL));
            mudancaPos = (rand() % (4)) *16;
            }
        }
        break;
        case ('b'):
        {
            if(it_Caixas < maxCaixas){
                criarCaixa(sf::Vector2f((posicao.x * 64.f)+ (mudancaPos*2), posicao.y * 64.f));
                it_Caixas++;
                srand((unsigned int)time(NULL));
                mudancaPos = (rand() % (4)) *16;
            }
        }
        break;
        case ('&'):
        {
            if((it_P<maxP)&&(((it_P+1)%aleatoriedadeP)!=0))
            criarPlataforma(sf::Vector2f(posicao.x * 64.f, posicao.y * 64.f), true);
            it_P++;
        }
        case ('#'):
        {
            criarPlataforma(sf::Vector2f(posicao.x * 64.f, posicao.y * 64.f), false);
        }
        break;
        }
    }
    void Pantano_Maldito::verificarCompletou()
    {

        if ((pJogador1 != nullptr))
        {
            sf::Vector2f posJ1 = pJogador1->getCorpo().getPosition();
            if (posJ1.x >= (LARGURA_JANELA / 2))
            {
                completou = true;
            }
        }
        else if (pJogador2 != nullptr)
        {
            sf::Vector2f posJ2 = pJogador2->getCorpo().getPosition();
            if (posJ2.x >= (LARGURA_JANELA / 2))
            {
                completou = true;
            }
        }

        // return false;
    }

}
