#include "Castelo_Assombrado.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

namespace Fases
{
    Castelo_Assombrado::Castelo_Assombrado() : Fase(IDCASTELOASSOMBRADO), maxChefoes(5), vetorDurahan(), it_D(0)
    {
        //Fase::proximaFase();
        srand((unsigned int)time(NULL));
        cont_D = (rand() % (2)) + 3;
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
        /* for (std::vector<Entidades::Inimigos::Durahan*>::iterator it = vetorCanhao.begin();it != vetorCanhao.end();++it) {
             delete *it;
         }*/

        vetorDurahan.clear();
        // vetorCanhao.clear();
    }

    void Castelo_Assombrado::criarInimigos()
    {
        // criarInimFaceis();
        // criarInimMedios();
    }
    void Castelo_Assombrado::criarObstaculos()
    {
        // criarObstFaceis();
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
    /*void Fase::criarCanhao(const sf::Vector2f posicao)
    {
        Entidades::Obstaculos::Canhao* canhao = new Entidades::Obstaculos::Canhao(LARGURA_CANHAO, ALTURA_CANHAO, posicao);
        if((canhao) != nullptr){
            sf::Color roxa(128, 0, 128);  // roxo
            canhao->setCor(roxa);
            //vetorCanhao.push_back(canhao);
            listaObstaculos->incluirEntidade(canhao);
        }
    }*/

    void Castelo_Assombrado::criarMapa()
    {
        //criarPlataformaF(sf::Vector2f(0.0f,0.0f), ALTURA_JANELA, LARGURA_JANELA);
        // criarPlataformaBase(sf::Vector2f(0.0f,660));
        // Está ao contrário as funções BordaV cria Horizontal e BordaH, vertical

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

        
        // criarBordaH(sf::Vector2f(0.0f, 0.0f), sf::Color::Yellow);
        // criarBordaH(sf::Vector2f(1277.0f, 0.0f), sf::Color::Yellow);
        // criarBordaV(sf::Vector2f(0.0f, 0.0f), sf::Color::Yellow);

        // criarBordaV(sf::Vector2f(0.0f, 717.0f), sf::Color::Yellow);

        // Pega a lista de porjétil que tem no Durahan
        //
    }
     /*void Castelo_Assombrado::criarInimDificil(const sf::Vector2f posicao)
    {   
        it_D++;
        Entidades::Inimigos::Durahan* durahan = new Entidades::Inimigos::Durahan(posicao);
        if(durahan != nullptr){
            //pD=durahan;
            durahan->setCor(sf::Color::Magenta);
            if(Fase::getJogador1() != nullptr){durahan->setJogador1(getJogador1());}
            if(Fase::getJogador2() != nullptr){durahan->setJogador2(getJogador2());}
            vetorDurahan.push_back(durahan);
            listaPersonagens->incluirEntidade(durahan);
            //num_Durahan++; lemnrando que isso está em fase
        }
    }*/

    void Castelo_Assombrado::executar()
    {
        Fase::executar();

        /*if(pD!= nullptr){
            pGerenciadorGrafico->desenharList(pD->getListaProjetil());
        }*/
        for (int i = 0; i < cont_D; i++)
        {
            if (vetorDurahan[i] != nullptr)
            {
                pGerenciadorGrafico->desenharList(vetorDurahan[i]->getListaProjetil());
            }
        }
        if(completou==true){
            //mostrarRanking(pGerenciadorGrafico->getJanela());
        }
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
        case ('c'):
        {
            criarCanhao(sf::Vector2f(posicao.x * 64.f, posicao.y * 64.f));
        }
        break;
        case ('s'):
        {
            criarEspinho(sf::Vector2f(posicao.x * 64.f, posicao.y * 64.f));
        }
        break;
        case ('#'):
        {
            criarPlataforma(sf::Vector2f(posicao.x * 64.f, posicao.y * 64.f));
        }
        break;
        }
    }

}