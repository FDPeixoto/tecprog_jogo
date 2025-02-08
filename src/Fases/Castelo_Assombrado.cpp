#include "Castelo_Assombrado.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

namespace Fases
{
    Castelo_Assombrado::Castelo_Assombrado(bool temSegundoJogador) :  Fase(IDCASTELOASSOMBRADO, temSegundoJogador),fundo(sf::Vector2f(LARGURA_JANELA, ALTURA_JANELA)), vetorDurahan(), it_Ogros(0), maxEsp(3), it_Esp(0),maxM(3), it_M(0),maxP(3), it_P(0)
    {
        fundo.setPosition(0.0f, 0.0f);
        textura.loadFromFile("Texturas/testeFundo1.png");
        fundo.setTexture(&textura);
        //Fase::proximaFase();
        srand((unsigned int)time(NULL));
        maxEsp = (rand() % (3)) + 3;
        srand((unsigned int)time(NULL));
        maxOgros = (rand() % (3)) + 3;
        srand((unsigned int)time(NULL));
        maxM = (rand() % (3)) + 3;
        srand((unsigned int)time(NULL));
        maxP = (rand() % (10)) + 10;
        srand((unsigned int)time(NULL));
        aleatoriedadeP = (rand() % (3)) + 1;

        criarMapa();
        //, maxOgros(2)

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
        it_Ogros++;
        Entidades::Inimigos::Durahan *durahan = new Entidades::Inimigos::Durahan(posicao);
        if (durahan != nullptr)
        {
            // pD=durahan;
            // durahan->setCor(sf::Color::Magenta);
            if (pJogador1 != nullptr)
            {
                durahan->setJogador1(pJogador1);
            }
            if (pJogador2 != nullptr)
            {
                durahan->setJogador2(pJogador2);
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
            std::cout << "NAo abriu o arquivo .txt Castelo Assombrado" << std::endl;
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
        pGerenciadorGrafico->desenharCorpo(fundo);
        Fase::executar();

        for (int i = 0; i < maxOgros; i++)
        {
            if (vetorDurahan[i] != nullptr)
            {
                pGerenciadorGrafico->desenharList(vetorDurahan[i]->getListaProjetil());
            }
        }
        if (completou == true)
        {
        }
    }
    void Castelo_Assombrado::criarEntidade(char letra, const sf::Vector2f posicao)
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
            if(it_M< maxM){
                criarMinion(sf::Vector2f((posicao.x * 64.f)+ mudancaPos, posicao.y * 64.f));
                srand((unsigned int)time(NULL));
                mudancaPos = (rand() % (4)) *16;
                it_M++;
            }
        }
        break;

        case ('d'):
        {
            if (it_Ogros < maxOgros)
            {
                criarInimDificil(sf::Vector2f((posicao.x * 64.f)+mudancaPos, posicao.y * 64.f));
                srand((unsigned int)time(NULL));
                mudancaPos = (rand() % (4)) *16;
                //O it_Ogros++, está dentro da função
            }
            else
            {
            }
        }
        break;
        case ('s'):
        {
            if(it_Esp<maxEsp){
                criarEspinho(sf::Vector2f((posicao.x * 64.f)+mudancaPos, posicao.y * 64.f));
                it_Esp++;
                srand((unsigned int)time(NULL));
                mudancaPos = (rand() % (4)) *16;
            }
        }
        break;
        case ('&'):
        {
            if ((it_P < maxP) && (((it_P + 1) % aleatoriedadeP) != 0))
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