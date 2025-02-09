#include "Pantano_Maldito.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

namespace Fases
{

    Pantano_Maldito::Pantano_Maldito(bool temSegundoJogador) : Fase(IDPANTANOMALDITO, temSegundoJogador), fundo(ALTURA_JANELA, LARGURA_JANELA, sf::Vector2f(0.0f, 0.0f), false), maxInimMedios(5), it_D(0), cont_D(2)
    {
        Fase::proximaFase();
        /*srand((unsigned int)time(NULL));
        cont_D= (rand() % (FAIXA_ALEATORIO))+2; */
        criarMapa();
        //, cont_D(2)
    }

    Pantano_Maldito::~Pantano_Maldito()
    {
    }

    void Pantano_Maldito::criarInimMedio(const sf::Vector2f posicao)
    {
        Entidades::Inimigos::Esqueleto *esqueleto = new Entidades::Inimigos::Esqueleto(posicao);
        if (esqueleto != nullptr)
        {
            // esqueleto->setCor(sf::Color::Cyan);
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
    void Pantano_Maldito::criarInimDificil(const sf::Vector2f posicao)
    {
        it_D++;
        Entidades::Inimigos::Durahan *durahan = new Entidades::Inimigos::Durahan(posicao);
        if (durahan != nullptr)
        {
            if (Fase::getJogador1() != nullptr)
            {
                durahan->setJogador1(getJogador1());
            }
            if (Fase::getJogador2() != nullptr)
            {
                durahan->setJogador2(getJogador2());
            }
            listaPersonagens->incluirEntidade(durahan);
        }
    }
    const int Pantano_Maldito::getMaxInimMedios() { return maxInimMedios; }

    void Pantano_Maldito::criarMapa()
    {
        std::ifstream arquivo;
        std::string linha;
        arquivo.open("src/Fases/TestePrimeiraFase.txt");
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
    void Pantano_Maldito::executar()
    {
        pGerenciadorGrafico->desenharEntidade(&fundo);
        Fase::executar();
        verificarCompletou();
    }

    void Pantano_Maldito::criarEntidade(char letra, const sf::Vector2f posicao)
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
        case ('e'):
        {
            criarInimMedio(sf::Vector2f(posicao.x * 64.f, posicao.y * 64.f));
        }
        break;
        case ('b'):
        {
            criarCaixa(sf::Vector2f(posicao.x * 64.f, posicao.y * 64.f));
        }
        break;
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
