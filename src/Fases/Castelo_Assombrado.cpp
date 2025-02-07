#include "Castelo_Assombrado.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

namespace Fases
{
    Castelo_Assombrado::Castelo_Assombrado() : Fase(IDCASTELOASSOMBRADO),fundo(ALTURA_JANELA,LARGURA_JANELA, sf::Vector2f(0.0f, 0.0f), true ), maxChefoes(5), vetorDurahan(), it_D(0), maxEsp(3), it_Esp(0),maxM(3), it_M(0),maxP(3), it_P(0)
    {
        //Fase::proximaFase();
        srand((unsigned int)time(NULL));
        cont_D = (rand() % (2)) + 3;
        srand((unsigned int)time(NULL));
        maxM = (rand() % (2)) + 3;
        srand((unsigned int)time(NULL));
        maxEsp = (rand() % (2)) + 3;
        srand((unsigned int)time(NULL));
        maxP = (rand() % (10)) + 10;
        srand((unsigned int)time(NULL));
        aleatoriedadeP=(rand() % (3))+1;
         
        criarMapa();
        //, cont_D(2)

        vetorDurahan.clear();
    }

    Castelo_Assombrado::~Castelo_Assombrado()
    {
        for (std::vector<Entidades::Inimigos::Durahan *>::iterator it = vetorDurahan.begin(); it != vetorDurahan.end(); ++it)
        {
            delete *it;
        }
        vetorDurahan.clear();
    }

    void Castelo_Assombrado::criarInimDificil(const sf::Vector2f posicao)
    {
        it_D++;
        Entidades::Inimigos::Durahan *durahan = new Entidades::Inimigos::Durahan(posicao);
        if (durahan != nullptr)
        {
            // pD=durahan;
            // durahan->setCor(sf::Color::Magenta);
            if (Fase::getJogador1() != nullptr)
            {
                durahan->setJogador1(getJogador1());
            }
            if (Fase::getJogador2() != nullptr)
            {
                durahan->setJogador2(getJogador2());
            }
            vetorDurahan.push_back(durahan);
            durahan->setMediator(pGerenciadorColisao);
            listaPersonagens->incluirEntidade(durahan);
            pGerenciadorColisao->adicionarInimigo(durahan);
            // num_Durahan++; lemnrando que isso está em fase
        }
    }
    void Castelo_Assombrado::criarEspinho(const sf::Vector2f posicao)
    {
        Entidades::Obstaculos::Espinho *plataforma = new Entidades::Obstaculos::Espinho(posicao);
        if (plataforma != nullptr)
        {
            plataforma->setMediator(dynamic_cast<Gerenciadores::Mediator *>(pGerenciadorColisao));
            listaObstaculos->incluirEntidade(plataforma);
            pGerenciadorColisao->adicionarObstaculo(plataforma);
        }
    }
    void Castelo_Assombrado::criarMapa()
    {           
        std::ifstream arquivo;
        std::string linha;
        arquivo.open("src/Fases/TesteSegundaFase.txt");
        if (!arquivo.is_open())
        {
            std::cout << "NAo abriu o arquivo .txt Pantano_Maldito" << std::endl;
            exit(1);
        }
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


    void Castelo_Assombrado::executar()
    {
        pGerenciadorGrafico->desenharEntidade(&fundo);
        Fase::executar();

        for (int i = 0; i < cont_D; i++)
        {
            if (vetorDurahan[i] != nullptr)
            {
                pGerenciadorGrafico->desenharList(vetorDurahan[i]->getListaProjetil());
            }
        }
        if(completou==true){ }
    }
    void Castelo_Assombrado::criarEntidade(char letra, const sf::Vector2f posicao)
    {
        switch (letra)
        {
        case ('j'):
        {
            criarJogador(sf::Vector2f(posicao.x * 64.f, posicao.y * 64.f));
        }
        break;
        case ('m'):
        {
            criarMinion(sf::Vector2f(posicao.x * 64.f, posicao.y * 64.f));
        }
        break;

        case ('d'):
        {
            if (it_D < cont_D)
            {
                criarInimDificil(sf::Vector2f(posicao.x * 64.f, posicao.y * 64.f));
            }
            else
            {
            }
        }
        break;
        case ('s'):
        {
            criarEspinho(sf::Vector2f(posicao.x * 64.f, posicao.y * 64.f));
        }
        break;
        case ('&'):
        {
            if((it_P<maxP)&&(((it_P+1)%aleatoriedadeP)!=0))
            criarPlataforma(sf::Vector2f(posicao.x * 64.f, posicao.y * 64.f), true);
            it_P++;
        }
        break;
        case ('#'):
        {
            criarPlataforma(sf::Vector2f(posicao.x * 64.f, posicao.y * 64.f), true);
        }
        break;
        }
    }

}